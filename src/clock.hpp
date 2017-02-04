#ifndef NBAVR_CLOCK_HPP
#define NBAVR_CLOCK_HPP

// Every clock cycle is 1 / freq seconds. (62.5ns at 16MHz)
// Every 64 clock cycles is a tick. (4us at 16MHz)
// Every 2^16 ticks is a tock. (262.144ms at 16MHz)
// Every 2^32 ticks the clock overflows. (4.77 hours at 16Mhz)

#define MAX_TICK_INTERRUPTS 10

#define DIVISOR 64UL
#define F_CPU_MHZ (F_CPU / 1000000UL)
#define OVERFLOW_TIME ((65536UL / F_CPU_MHZ) * DIVISOR)

#define US_TO_TICKS(us) (((us) + (DIVISOR / F_CPU_MHZ / 2)) / (DIVISOR / F_CPU_MHZ))
#define MS_TO_TICKS(ms) (US_TO_TICKS((ms) * 1000UL))

#define TICKS_TO_US(ts) ((ts) * (DIVISOR / F_CPU_MHZ))
#define TICKS_TO_MS(ts) (TICKS_TO_US(ts) / 1000UL)

#define TICKS_TO_TOCKS(t) (((t) + 32768UL) / 65536UL)
#define TOCKS_TO_TICKS(t) ((t) * 65536UL)

#define INTERRUPT_TICK_BUFFER 200
#define MIN_INTERRUPT_TICK 2

struct Clock {
    virtual uint16_t getTicks16() const = 0;
    virtual uint32_t getTicks() const = 0;
    virtual uint32_t getTicks_() const = 0;
    virtual uint16_t getTocks() const = 0;
    virtual bool addInterrupt(void (*callback)(void*), void* data, uint16_t delay) = 0;
    virtual bool addInterrupt_(void (*callback)(void*), void* data, uint16_t delay) = 0;
    virtual void enableHaltInterrupt(uint16_t timeout, void (*callback)(void*), void* data) = 0;
    virtual void disableHaltInterrupt() = 0;
};

template<class Timer>
class ClockT : public Clock {
    struct Interrupt {
        // The callback to use.
        void (*callback)(void*) = nullptr;
        // Data to pass into the callback.
        void* data = nullptr;
        // The tick at which to perform the callback.
        uint16_t tick = 0;
    };

    struct Queue {
        uint8_t size = 0;
        uint8_t head = 0;
        uint8_t tail = 0;
        Interrupt interrupts[MAX_TICK_INTERRUPTS];
    };

    uint16_t _tocks = 0;
    Queue _interrupts;
    void (*_haltCallback)(void*) = nullptr;
    void* _haltCallbackData = nullptr;

public:
    ClockT() {
        static_assert(Timer::getHardwareType() == HardwareType::TimerCounter, "ClockT requires a TimerCounter");
        static_assert(Timer::size() == 2, "ClockT requires a 16 bit TimerCounter");

        typename Timer::Config config;
        config.clockSelect = Timer::ClockSelect::Div64;
        config.overflowIntEnable = true;
        config.outputCompareAInterrupt = timerCounterOutputCompareA;
        config.outputCompareAInterruptData = this;
        config.outputCompareBInterrupt = timerCounterOutputCompareB;
        config.outputCompareBInterruptData = this;
        config.overflowInterrupt = timerCounterOverflow;
        config.overflowInterruptData = this;

        Timer::apply(config);
    }

    // Get the 16 bit hardware counter.
    force_inline uint16_t getTicks16() const override {
        return Timer::timerRegister();
    }

    // Get the 32 bit combined hardware and overflow counter.
    force_inline uint32_t getTicks() const override {
        atomic {
            return getTicks_();
        }

        return 0;
    }

    // Non-atomic version
    uint32_t getTicks_() const override {
        // Get the value of the counter.
        uint16_t low = getTicks16();
        // Get the value of the overflow counter.
        uint16_t high = _tocks;

        // Check if the counter has overflowed since atomic started.
        if(Timer::overflowIntFlag()) {
            // If it has then there is a possibility that the numbers are not synchronised.
            // Get the new counter value, and increment "high".
            low = getTicks16();
            high++;
        }

        return ((uint32_t)high << 16) | low;
    }

    force_inline uint16_t getTocks() const override {
        atomic {
            return _tocks;
        }

        return 0;
    }

    // Add a tick precision interrupt.
    force_inline bool addInterrupt(void (*callback)(void*), void* data, uint16_t delay) override {
        atomic {
            return addInterrupt_(callback, data, delay);
        }

        return false;
    }

    // Non-atomic version.
    bool addInterrupt_(void (*callback)(void*), void* data, uint16_t delay) override {
        uint16_t now = getTicks16();

        if(callback == nullptr) {
            return false;
        }

        // Check if queue is full.
        if(_interrupts.size >= MAX_TICK_INTERRUPTS) {
            return false;
        }

        // Enforce a minimum delay to prevent missed interrupts.
        if(delay < MIN_INTERRUPT_TICK) {
            delay = MIN_INTERRUPT_TICK;
        }

        // Ensure the delay isn't in the faked negative range.
        uint16_t limit = 0U - INTERRUPT_TICK_BUFFER - 1U;

        if(delay > limit) {
            delay = limit;
        }

        uint16_t interruptTick = now + delay;

        // Add the interrupt to the queue
        Interrupt interrupt = {callback, data, interruptTick};
        push(&_interrupts, now - INTERRUPT_TICK_BUFFER, interrupt);

        // Set the timer to the first interrupt.
        Timer::outputCompareARegister(peek(&_interrupts).tick);

        // If the queue was previously empty, clear the flag and enable interrupt.
        if(_interrupts.size == 1) {
            Timer::outputCompareAIntFlagClear();
            Timer::outputCompareAIntEnable(true);
        }

        return true;
    }

    force_inline void enableHaltInterrupt(uint16_t timeout, void (*callback)(void*), void* data) override {
        atomic {
            uint16_t tick = getTicks16() + timeout;
            Timer::outputCompareBRegister(tick);
            Timer::outputCompareBIntEnable(true);
            Timer::outputCompareBIntFlagClear();
            _haltCallback = callback;
            _haltCallbackData = data;
        }
    }

    force_inline void disableHaltInterrupt() override {
        atomic {
            Timer::outputCompareBIntEnable(false);
            Timer::outputCompareBIntFlagClear();
            _haltCallback = nullptr;
            _haltCallbackData = nullptr;
        }
    }

private:
    // Push an interrupt to the queue.
    // Check queue size before calling.
    static void push(Queue* queue, uint16_t base, Interrupt interrupt) {
        Interrupt* interrupts = queue->interrupts;

        interrupts[queue->tail] = interrupt;

        uint8_t t = queue->tail;
        uint8_t h = queue->head;

        queue->size++;
        queue->tail++;

        if(queue->tail >= MAX_TICK_INTERRUPTS) {
            queue->tail = 0;
        }

        while(t != h) {
            uint8_t p;

            if(t == 0) {
                p = MAX_TICK_INTERRUPTS - 1;
            } else {
                p = t - 1;
            }

            if(compare(base, interrupts[t].tick, interrupts[p].tick)) {
                Interrupt temp = interrupts[p];
                interrupts[p] = interrupts[t];
                interrupts[t] = temp;
            } else {
                break;
            }

            t = p;
        }
    }

    // Pop an interrupt from the queue.
    // Check queue size before calling.
    force_inline static void pop(Queue* queue) {
        queue->size--;
        queue->head++;

        if(queue->head >= MAX_TICK_INTERRUPTS) {
            queue->head = 0;
        }
    }

    // Look at the top interrupt in the queue.
    // Will return rubbish if the queue is empty.
    force_inline static Interrupt peek(Queue* queue) {
        return queue->interrupts[queue->head];
    }

    // Indicates which of b or c is closer to a.
    // true if b is sooner.
    // otherwise false.
    force_inline static bool compare(uint16_t a, uint16_t b, uint16_t c) {
        if((a > b) == (b >= c)) {
            return a < c;
        } else {
            return a > c;
        }
    }

    // Called when a tick interrupt occurs.
    static void timerCounterOutputCompareA(void* data) {
        ClockT* self = (ClockT*)data;

        loop: ;

        Interrupt interrupt = peek(&self->_interrupts);

        interrupt.callback(interrupt.data);

        pop(&self->_interrupts);

        if(self->_interrupts.size > 0) {
            uint16_t next = peek(&self->_interrupts).tick;

            Timer::outputCompareAIntFlagClear();
            Timer::outputCompareARegister(next);

            if(!compare(interrupt.tick, self->getTicks16() + 1, next)) {
                goto loop;
            }
        } else {
            Timer::outputCompareAIntEnable(false);
        }
    }

    static void timerCounterOutputCompareB(void* data) {
        // TODO disable output compare interrupt.
        ClockT* self = (ClockT*)data;

        void (*haltCallback)(void*) = self->_haltCallback;
        void* haltCallbackData = self->_haltCallbackData;

        self->disableHaltInterrupt();

        if(haltCallback != nullptr) {
            haltCallback(haltCallbackData);
        }
    }

    static void timerCounterOverflow(void* data) {
        ClockT* self = (ClockT*)data;

        self->_tocks++;
    }
};

#endif
