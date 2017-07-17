#ifndef NBAVR_STREAM_HPP
#define NBAVR_STREAM_HPP

template <class T>
class Stream {
    T* const bufferp;
    const uint8_t size;
    void (*flushFunc)(void*) = nullptr;
    void* flushData = nullptr;
    uint8_t head = 0;
    uint8_t tail = 0;
    bool full = false;

    protected:

    Stream(T* bufferp, uint8_t size, void (*flushFunc)(void*), void* flushData)
    : bufferp(bufferp), size(size), flushFunc(flushFunc), flushData(flushData) {
    }

    public:

    Stream(const Stream&) = delete;
    Stream& operator=(const Stream&) = delete;

    force_inline bool push(const T& in) {
        atomic {
            return push_(in);
        }

        return false;
    }

    force_inline bool pop(T* out) {
        atomic {
            return pop_(out);
        }

        return false;
    }

    force_inline bool peek(T* out) {
        atomic {
            return peek_(out);
        }

        return false;
    }

    force_inline bool push(const T* buffer, uint8_t count) {
        atomic {
            return push_(buffer, count);
        }

        return false;
    }

    force_inline bool pop(T* buffer, uint8_t count) {
        atomic {
            return pop_(buffer, count);
        }

        return false;
    }

    force_inline uint8_t used() const {
        atomic {
            return used_();
        }

        return 0;
    }

    force_inline uint8_t unused() const {
        atomic {
            return unused_();
        }

        return 0;
    }

    force_inline bool empty() const {
        atomic {
            return empty_();
        }

        return false;
    }

    force_inline bool clear() {
        atomic {
            return clear_();
        }

        return false;
    }

    bool push_(const T& in) {
        if(full || (size == 0)) {
            return false;
        }

        bufferp[head] = in;

        head += 1;

        if(head >= size) {
            head = 0;
        }

        if(head == tail) {
            full = true;
        }

        return true;
    }

    bool pop_(T* out) {
        if(empty_() || (out == nullptr)) {
            return false;
        }

        *out = bufferp[tail];

        tail += 1;

        if(tail >= size) {
            tail = 0;
        }

        full = false;

        return true;
    }

    force_inline bool peek_(T* out) {
        if(empty_() || (out == nullptr)) {
            return false;
        }

        *out = bufferp[tail];

        return true;
    }

    bool push_(const T* buffer, uint8_t count) {
        if((count > unused_()) || (size == 0) || (buffer == nullptr)) {
            return false;
        }

        for(uint8_t i = 0; i < count; i++) {
            bufferp[head] = buffer[i];

            head += 1;

            if(head >= size) {
                head = 0;
            }
        }

        if(head == tail) {
            full = true;
        }

        return true;
    }

    bool pop_(T* buffer, uint8_t count) {
        if((count > used_()) || (size == 0) || (buffer == nullptr)) {
            return false;
        }

        for(uint8_t i = 0; i < count; i++) {
            buffer[i] = bufferp[tail];

            tail += 1;

            if(tail >= size) {
                tail = 0;
            }
        }

        full = false;

        return true;
    }

    force_inline uint8_t used_() const {
        if(full) {
            return size;
        }

        if(head >= tail) {
            return head - tail;
        } else {
            return size - (tail - head);
        }
    }

    force_inline uint8_t unused_() const {
        if(full) {
            return 0;
        }

        if(head >= tail) {
            return size - (head - tail);
        } else {
            return tail - head;
        }
    }

    force_inline bool empty_() const {
        return !full && (head == tail);
    }

    force_inline bool clear_() {
        head = 0;
        tail = 0;
        full = false;

        return true;
    }

    force_inline void setFlush(void (*flushFunc)(void*), void* flushData) {
        this->flushFunc = flushFunc;
        this->flushData = flushData;
    }

    force_inline void flush() {
        if(flushFunc != nullptr) {
            flushFunc(flushData);
        }
    }
};

template <class T, uint8_t S>
class StreamBuffer : public Stream<T> {
    private:

    T buffer[S];

    public:

    StreamBuffer(void (*flushFunc)(void*) = nullptr, void* flushData = nullptr)
    : Stream<T>(buffer, S, flushFunc, flushData) {
    }
};

#endif
