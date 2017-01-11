#ifndef NBAVR_STREAM_HPP
#define NBAVR_STREAM_HPP

template <class T>
class Stream {
    T* const bufferp;
    const uint8_t size;
    void (*callback)(void*) = nullptr;
    void* callbackData = nullptr;
    uint8_t head = 0;
    uint8_t tail = 0;
    bool full = false;
    bool locked = false;

    protected:

    Stream(T* bufferp, uint8_t size, void (*callback)(void*), void* data)
    : bufferp(bufferp), size(size), callback(callback), callbackData(data) {
    }

    public:

    Stream(const Stream&) = delete;
    Stream& operator=(const Stream&) = delete;

    force_inline bool push(T& in) {
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

    force_inline bool push(T* buffer, uint8_t count) {
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

    bool push_(T& in) {
        if(full || locked || (size == 0)) {
            return false;
        }

        if(empty_() && (callback != nullptr)) {
            locked = true;
            callback(callbackData);
            locked = false;
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
        if(empty_() || locked || (out == nullptr)) {
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

    bool push_(T* buffer, uint8_t count) {
        if((count > unused_()) || locked || (size == 0) || (buffer == nullptr)) {
            return false;
        }

        if(empty_() && (callback != nullptr)) {
            locked = true;
            callback(callbackData);
            locked = false;
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
        if((count > used_()) || locked || (size == 0) || (buffer == nullptr)) {
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
        if(locked) {
            return false;
        }

        head = 0;
        tail = 0;
        full = false;

        return true;
    }

    force_inline void setCallback(void (*callback)(void*), void* data) {
        this->callback = callback;
        this->callbackData = data;
    }

    force_inline Stream<T>& operator<<(T in) {
        push(in);
        return *this;
    }
};

template <class T, uint8_t S>
class StreamBuffer : public Stream<T> {
    private:

    T buffer[S];

    public:

    StreamBuffer(void (*callback)(void*) = nullptr, void* data = nullptr)
    : Stream<T>(buffer, S, callback, data) {
    }
};

#endif
