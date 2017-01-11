#ifndef NBAVR_SERVO_HPP
#define NBAVR_SERVO_HPP

// Servo module has no setup because the list of servos may be initialised
//  before this setup is called, and the servos need to be remembered even if
//  this module is reset.

// Servos have a range of -128 to 127.
// Servo speed is a number between 0 and 255, slowest to fastest. Speed is the
//  maximum step size done each cycle.

#include <nbavr.hpp>

#define SERVO_MIN_TIME US_TO_TICKS(600)
#define SERVO_MAX_TIME US_TO_TICKS(2400)
#define SERVO_UPDATE_DELAY MS_TO_TICKS(20)

#define abs(n) ((n) < 0 ? -(n) : (n))

/// For controlling servo hardware.
class Servo {
    private:
        Clock& clock;
        Pin& _pin;
        bool _enabled = true;
        int8_t _positionCurrent = 0;
        int8_t _positionGoal = 0;
        uint8_t _speed = 255;

    public:
        Servo(Clock& clock, Pin pin) : clock(clock), _pin(pin) {
        }

//        void pin(Pin pin) { _pin = pin; }
//        Pin pin() { return _pin; }
        void enabled(bool enabled) { _enabled = enabled; }
        bool enabled() { return _enabled; }
        void position(int8_t position) { _positionGoal = position; }
        int8_t position() { return _positionGoal; }
        void speed(uint8_t speed) { _speed = speed; }
        uint8_t speed() { return _speed; }
        /// TODO Set pin high and create an interrupt to set pin low.
        void update() {
            if(_positionCurrent != _positionGoal) {
                int16_t step = _speed;
                int16_t diff = _positionCurrent - _positionGoal;
                diff = abs(diff);

                if(diff < step) {
                    _positionCurrent = _positionGoal;
                } else {
                    if(_positionGoal < _positionCurrent) {
                        step = -step;
                    }

                    _positionCurrent += step;
                }
            }
        }

        bool pulse() {
            int16_t middle = (SERVO_MAX_TIME + SERVO_MIN_TIME) / 2;
            int16_t range = SERVO_MAX_TIME - SERVO_MIN_TIME;
            int16_t adjust = _positionCurrent * (range / 256);

            int16_t ticks = middle + adjust;

            atomic {
                if(clock.addInterrupt_(end, &_pin, ticks)) {
                    _pin.value(Pin::Value::High);
                    return true;
                }
            }

            return false;
        }

        // FIXME How do I reference the wake function of ServoTask.
        static void end(void* data) {
            Pin* pin = (Pin*)data;

            pin->value(Pin::Value::Low);

//            wake();
        }
};

// Interface for fetching servos.
class Servos {
    public:
        // XXX Or maybe get, getNext, next, fetch?
        virtual Servo* create(Pin pin) = 0;
};

template <int8_t S>
class ServoManager : public Task, public Servos {
    Clock& clock;
    Servo servos[S];
    int8_t index;
    uint16_t start;

    public:

    // TODO Pass in the servo objects to manage as an array.
    ServoManager(Clock& clock) : clock(clock){
    }

    Servo* create(Pin pin) override {
        for(uint8_t i = 0; i < S; i++) {
            if(!servos[i].enabled()) {
                return &servos[i];
            }
        }

        return &servos[S - 1];
    }

    protected:

    void loop() override {
        if(index == 0) {
            start = clock.getTicks16();
        }

        if(index < S) {
            Servo& servo = servos[index];

            if(servo.enabled()) {
                servo.update();

                if(servo.pulse()) {
                    sleep();
                }
            }

            index += 1;
        } else {
            index = 0;

            uint16_t diff = clock.getTicks16() - start;

            if(diff < SERVO_UPDATE_DELAY) {
                delay(clock, SERVO_UPDATE_DELAY - diff);
            }
        }
    }
};

#endif
