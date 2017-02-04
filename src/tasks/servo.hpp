#ifndef NBAVR_SERVO_HPP
#define NBAVR_SERVO_HPP

// Servos have a range of -128 to 127.
// Servo speed is a number between 0 and 255, slowest to fastest. Speed is the
//  maximum step size done each cycle.

#include <nbavr.hpp>

#define SERVO_MIN_TIME US_TO_TICKS(600)
#define SERVO_MAX_TIME US_TO_TICKS(2400)
#define SERVO_UPDATE_DELAY MS_TO_TICKS(20)

struct Servo {
    virtual void enabled(bool enabled) = 0;
    virtual bool enabled() = 0;
    virtual void position(int8_t position) = 0;
    virtual int8_t position() = 0;
    virtual void speed(uint8_t speed) = 0;
    virtual uint8_t speed() = 0;
    virtual uint16_t update() = 0;
    virtual void pulseStart() = 0;
    virtual void pulseEnd() = 0;
};

template <class Pin>
class ServoT : public Servo {
    bool _enabled = true;
    int8_t _positionCurrent = 0;
    int8_t _positionGoal = 0;
    uint8_t _speed = 255;

public:
    ServoT() {
        static_assert(Pin::getHardwareType() == HardwareType::Pin, "ServoT requires a Pin");

        Pin::direction(Pin::Direction::Output);
        Pin::value(Pin::Value::Low);
    }

    void enabled(bool enabled) override {
        _enabled = enabled;
    }

    bool enabled() override {
        return _enabled;
    }

    void position(int8_t position) override {
        _positionGoal = position;
    }

    int8_t position() override {
        return _positionGoal;
    }

    void speed(uint8_t speed) override {
        _speed = speed;
    }

    uint8_t speed() override {
        return _speed;
    }

    uint16_t update() override {
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

        uint16_t middle = (SERVO_MAX_TIME + SERVO_MIN_TIME) / 2;
        uint16_t range = SERVO_MAX_TIME - SERVO_MIN_TIME;
        uint16_t adjust = _positionCurrent * (range / 256);

        uint16_t ticks = middle + adjust;

        return ticks;
    }

    void pulseStart() override {
        Pin::value(Pin::Value::High);
    }

    void pulseEnd() override {
        Pin::value(Pin::Value::Low);
    }
};

class ServoManager : public Task {
    Clock& _clock;
    Servo** _servos;
    const uint8_t _servoCount;
    int8_t index = 0;
    uint16_t start = 0;
    Servo* _activeServo = nullptr;

public:
    template <uint8_t S>
    ServoManager(Clock& clock, Servo* (&servos)[S]) : _clock(clock), _servos(servos), _servoCount(S) {
    }

private:
    void loop() override {
        if(index == 0) {
            start = _clock.getTicks16();
        }

        if(index < _servoCount) {
            _activeServo = _servos[index];

            if(_activeServo->enabled()) {
                uint16_t pulseLength = _activeServo->update();

                atomic {
                    if(_clock.addInterrupt_(end, this, pulseLength)) {
                        // _activeServo->pin() = Pin::Value::High;
                        _activeServo->pulseStart();
                        sleep();
                    }
                }
            }

            index += 1;
        } else {
            index = 0;

            uint16_t diff = _clock.getTicks16() - start;

            if(diff < SERVO_UPDATE_DELAY) {
                delay(_clock, SERVO_UPDATE_DELAY - diff);
            }
        }
    }

    static void end(void* data) {
        ServoManager* self = (ServoManager*)data;

        self->_activeServo->pulseEnd();

        self->wake();
    }
};

#endif
