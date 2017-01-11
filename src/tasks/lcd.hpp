#ifndef NBAVR_LCD_HPP
#define NBAVR_LCD_HPP

#include <nbavr.hpp>
// FIXME Shouldn't really be using these blocking calls...?
//#include <util/delay.h>

#define _delay_us(n)
#define _delay_ms(n)

// \r = clear display and return curser to home position.
// \n = move to start of next line, wrapping to first line.
// \v = move curser to the position defined by the next two bytes.
//  e.g. \v\1\2 = move to start of second line.
// \a = clear current line and put curser at start.

#define CLEAR_DISPLAY 0x01
#define CURSER_HOME 0x02
#define CURSER_START_LINE_ONE 0x80
#define CURSER_START_LINE_TWO 0xC0
#define CURSER_LEFT 0x10
#define CURSER_RIGHT 0x14
#define ENTRY_MODE_LEFT 0x04
#define ENTRY_MODE_RIGHT 0x06
#define ENTRY_MODE_LEFT_SCROLL 0x05
#define ENTRY_MODE_RIGHT_SCROLL 0x07
#define SCROLL_LEFT 0x18
#define SCROLL_RIGHT 0x1C
#define DISPLAY_OFF 0x08
#define DISPLAY_ON 0x0C
#define DISPLAY_ON_CURSER 0x0E
#define DISPLAY_ON_CURSER_BLINK 0x0F
#define FUNCTION_FOUR_BITS_TWO_LINES 0x28
#define SET_DDRAM_ADDRESS 0x80

class LCD : public Task {
    private:

    struct Range {
        uint8_t min;
        uint8_t max;
    };

    struct Coord {
        uint8_t x;
        uint8_t y;
    };

    const Range memoryMap[2] = {
        {0x00, 0x0f},
        {0x40, 0x4f}};
    static constexpr uint8_t lineCount = 2;
    static constexpr uint8_t lineLength = 16;

    typedef void (LCD::*StateFunction)();

    Clock& clock;
    StateFunction state;
    bool outOfBounds = false;
    Stream<char>& lcdout;
    Pin& _d4;
    Pin& _d5;
    Pin& _d6;
    Pin& _d7;
    Pin& _rw;
    Pin& _rs;
    Pin& _e;

    public:

    LCD(Clock& clock, Stream<char>& lcdout, Pin& d4, Pin& d5, Pin& d6, Pin& d7, Pin& rw, Pin& rs, Pin& e)
    : clock(clock), lcdout(lcdout), _d4(d4), _d5(d5), _d6(d6), _d7(d7), _rw(rw), _rs(rs), _e(e) {
        _rw = Pin::Direction::Output;
        _rs = Pin::Direction::Output;
        _e = Pin::Direction::Output;

        _rw = Pin::Value::Low;
        _rs = Pin::Value::Low;
        _e = Pin::Value::Low;

        state = &LCD::init0;

        delay(clock, MS_TO_TICKS(50));
    }

    protected:

    void loop() override {
        if(busy()) {
            return;
        }

        (this->*state)();
    }

    private:
        void run(void) {
            char byte;
            char x;
            char y;

            if(lcdout.pop(&byte)) {
                switch(byte) {
                case '\r':
                    sendByte(false, CLEAR_DISPLAY);
                    outOfBounds = false;
                    break;
                case '\n':
                    newLine();
                    outOfBounds = false;
                    break;
                case '\v':
                    if(lcdout.pop(&x) && lcdout.pop(&y)) {
                        setCurser(x - 1, y - 1);
                        outOfBounds = false;
                    }
                    break;
                case '\a':
                    state = &LCD::clearCurrentLine;
                    outOfBounds = false;
                    break;
                default:
                    if(!outOfBounds) {
                        writeCharacter(byte);
                    }
                }
            } else {
                delay(clock, MS_TO_TICKS(20));
            }
        }

        void writeCharacter(uint8_t character) {
            uint8_t address = getCurserAddress();
            Coord coord = addressToCoord(address);

            if(coord.x == lineLength - 1) {
                outOfBounds = true;
                state = &LCD::stepBack;
            }

            sendByte(true, character);
        }

        void setCurser(uint8_t x, uint8_t y) {
            setCurserAddress(coordToAddress(x, y));
        }

        void setCurserAddress(uint8_t address) {
            sendByte(false, SET_DDRAM_ADDRESS | address);
        }

        void newLine(void) {
            uint8_t address = getCurserAddress();
            Coord coord = addressToCoord(address);

            uint8_t y = (coord.y + 1) % lineCount;

            setCurserAddress(memoryMap[y].min);
        }

        bool busy(void) {
            uint8_t data = getByte(false);

            return data & _BV(7);
        }

        uint8_t getCurserAddress(void) {
            uint8_t data = getByte(false);

            return data & ~_BV(7);
        }

        uint8_t coordToAddress(uint8_t x, uint8_t y) {
            y = clip(y, (uint8_t)0, (uint8_t)(lineCount - 1));
            x = clip(x, (uint8_t)0, (uint8_t)(lineLength - 1));

            return memoryMap[y].min + x;
        }

        Coord addressToCoord(uint8_t address) {
            Coord coord = {0, 0};

            for(uint8_t i = 0; i < lineCount; i++) {
                if((address >= memoryMap[i].min) && (address <= memoryMap[i].max)) {
                    coord.x = (address - memoryMap[i].min);
                    coord.y = i;
                    break;
                }
            }

            return coord;
        }

        void clearCurrentLine(void) {
            uint8_t count = 255;
            uint8_t address = 0;

            if(count == 255) {
                address = getCurserAddress();
                Coord coord = addressToCoord(address);
                address = memoryMap[coord.y].min;
                setCurserAddress(address);
            } else if(count < lineLength) {
                sendByte(true, ' ');
            } else {
                state = &LCD::run;
                count = 255;
                setCurserAddress(address);
            }

            count++;
        }

        void stepBack(void) {
            sendByte(false, CURSER_LEFT);
            state = &LCD::run;
        }

        void sendByte(bool rs, uint8_t data) {
            uint8_t high = data >> 4;
            uint8_t low = data;
            sendNibble(rs, high);
            sendNibble(rs, low);
        }

        void sendNibble(bool rs, uint8_t data) {
            _d4 = Pin::Direction::Output;
            _d5 = Pin::Direction::Output;
            _d6 = Pin::Direction::Output;
            _d7 = Pin::Direction::Output;

            _d4 = (data & _BV(0)) ? Pin::Value::High : Pin::Value::Low;
            _d5 = (data & _BV(1)) ? Pin::Value::High : Pin::Value::Low;
            _d6 = (data & _BV(2)) ? Pin::Value::High : Pin::Value::Low;
            _d7 = (data & _BV(3)) ? Pin::Value::High : Pin::Value::Low;
            _rw = Pin::Value::Low;
            _rs = rs ? Pin::Value::High : Pin::Value::Low;

            _delay_us(1);
            _e = Pin::Value::High;
            _delay_us(1);
            _e = Pin::Value::Low;
        }

        // XXX May need to wait 43us when reading data.
        uint8_t getByte(bool rs) {
            uint8_t data = 0;

            _d4 = Pin::Direction::Input;
            _d5 = Pin::Direction::Input;
            _d6 = Pin::Direction::Input;
            _d7 = Pin::Direction::Input;

            _d4 = Pin::Value::Low;
            _d5 = Pin::Value::Low;
            _d6 = Pin::Value::Low;
            _d7 = Pin::Value::Low;
            _rw = Pin::Value::High;
            _rs = rs ? Pin::Value::High : Pin::Value::Low;

            _delay_us(1);

            _e = Pin::Value::High;
            _delay_us(1);

            data |= (_d7 == Pin::Value::High) ? (1 << 7) : 0;
            data |= (_d6 == Pin::Value::High) ? (1 << 6) : 0;
            data |= (_d5 == Pin::Value::High) ? (1 << 5) : 0;
            data |= (_d4 == Pin::Value::High) ? (1 << 4) : 0;

            _e = Pin::Value::Low;

            _delay_us(1);

            _e = Pin::Value::High;
            _delay_us(1);

            data |= (_d7 == Pin::Value::High) ? (1 << 3) : 0;
            data |= (_d6 == Pin::Value::High) ? (1 << 2) : 0;
            data |= (_d5 == Pin::Value::High) ? (1 << 1) : 0;
            data |= (_d4 == Pin::Value::High) ? (1 << 0) : 0;

            _e = Pin::Value::Low;

            return data;
        }

        void init0(void) {
            // Reset 1
            sendNibble(false, 0x3);
            state = &LCD::init1;
            delay(clock, MS_TO_TICKS(5));
        }

        void init1(void) {
            // Reset 2
            sendNibble(false, 0x3);
            state = &LCD::init2;
            delay(clock, MS_TO_TICKS(1));
        }

        void init2(void) {
            // Reset 3
            sendNibble(false, 0x3);
            state = &LCD::init3;
            delay(clock, MS_TO_TICKS(1));
        }

        void init3(void) {
            // initial 4 bit mode
            sendNibble(false, 0x2);
            state = &LCD::init4;
            delay(clock, MS_TO_TICKS(1));
        }

        void init4(void) {
            sendByte(false, FUNCTION_FOUR_BITS_TWO_LINES);
            state = &LCD::init5;
            delay(clock, MS_TO_TICKS(1));
        }

        void init5(void) {
            sendByte(false, DISPLAY_ON);
            state = &LCD::init6;
            delay(clock, MS_TO_TICKS(1));
        }

        void init6(void) {
            sendByte(false, CLEAR_DISPLAY);
            state = &LCD::init7;
            delay(clock, MS_TO_TICKS(4));
        }

        void init7(void) {
            sendByte(false, ENTRY_MODE_RIGHT);
            state = &LCD::run;
            delay(clock, MS_TO_TICKS(1));
        }
};

#endif
