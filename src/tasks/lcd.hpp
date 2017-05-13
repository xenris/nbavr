#ifndef NBAVR_LCD_HPP
#define NBAVR_LCD_HPP

#include <nbavr.hpp>
// FIXME Shouldn't really be using these blocking calls...?
#include <util/delay.h>

// #define _delay_us(n)
// #define _delay_ms(n)

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

template <class D4, class D5, class D6, class D7, class RW, class RS, class E>
class LCD : public Task {
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

    typedef void (LCD::*StateFunction)(Clock& clock);

    bool firstRun = true;
    StateFunction state;
    bool outOfBounds = false;
    Stream<char>& lcdout;

public:
    LCD(Stream<char>& lcdout) : lcdout(lcdout) {
        static_assert(D4::getHardwareType() == HardwareType::Pin, "LCD requires 7 Pins");
        static_assert(D5::getHardwareType() == HardwareType::Pin, "LCD requires 7 Pins");
        static_assert(D6::getHardwareType() == HardwareType::Pin, "LCD requires 7 Pins");
        static_assert(D7::getHardwareType() == HardwareType::Pin, "LCD requires 7 Pins");
        static_assert(RW::getHardwareType() == HardwareType::Pin, "LCD requires 7 Pins");
        static_assert(RS::getHardwareType() == HardwareType::Pin, "LCD requires 7 Pins");
        static_assert(E::getHardwareType() == HardwareType::Pin, "LCD requires 7 Pins");

        RW::direction(Direction::Output);
        RS::direction(Direction::Output);
        E::direction(Direction::Output);

        RW::output(Value::Low);
        RS::output(Value::Low);
        E::output(Value::Low);

        state = &LCD::init0;
    }

private:
    void loop(Clock& clock) override {
        if(firstRun) {
            firstRun = false;

            delay(clock, MS_TO_TICKS(50));
        } else {
            if(busy()) {
                return;
            }

            (this->*state)(clock);
        }
    }

    void run(Clock& clock) {
        char byte = 0;
        char x = 0;
        char y = 0;

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

        return data & bv(7);
    }

    uint8_t getCurserAddress(void) {
        uint8_t data = getByte(false);

        return data & ~bv(7);
    }

    uint8_t coordToAddress(uint8_t x, uint8_t y) {
        y = clip(y, uint8_t(0), uint8_t(lineCount - 1));
        x = clip(x, uint8_t(0), uint8_t(lineLength - 1));

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

    void clearCurrentLine(Clock& clock) {
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

    void stepBack(Clock& clock) {
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
        D4::direction(Direction::Output);
        D5::direction(Direction::Output);
        D6::direction(Direction::Output);
        D7::direction(Direction::Output);

        D4::output((data & bv(0)) ? Value::High : Value::Low);
        D5::output((data & bv(1)) ? Value::High : Value::Low);
        D6::output((data & bv(2)) ? Value::High : Value::Low);
        D7::output((data & bv(3)) ? Value::High : Value::Low);
        RW::output(Value::Low);
        RS::output(rs ? Value::High : Value::Low);

        _delay_us(1);
        E::output(Value::High);
        _delay_us(1);
        E::output(Value::Low);
    }

    // XXX May need to wait 43us when reading data.
    uint8_t getByte(bool rs) {
        uint8_t data = 0;

        D4::direction(Direction::Input);
        D5::direction(Direction::Input);
        D6::direction(Direction::Input);
        D7::direction(Direction::Input);

        D4::output(Value::Low);
        D5::output(Value::Low);
        D6::output(Value::Low);
        D7::output(Value::Low);
        RW::output(Value::High);
        RS::output(rs ? Value::High : Value::Low);

        _delay_us(1);

        E::output(Value::High);
        _delay_us(1);

        data |= (D7::input() == Value::High) ? (1 << 7) : 0;
        data |= (D6::input() == Value::High) ? (1 << 6) : 0;
        data |= (D5::input() == Value::High) ? (1 << 5) : 0;
        data |= (D4::input() == Value::High) ? (1 << 4) : 0;

        E::output(Value::Low);

        _delay_us(1);

        E::output(Value::High);
        _delay_us(1);

        data |= (D7::input() == Value::High) ? (1 << 3) : 0;
        data |= (D6::input() == Value::High) ? (1 << 2) : 0;
        data |= (D5::input() == Value::High) ? (1 << 1) : 0;
        data |= (D4::input() == Value::High) ? (1 << 0) : 0;

        E::output(Value::Low);

        return data;
    }

    void init0(Clock& clock) {
        // Reset 1
        sendNibble(false, 0x3);
        state = &LCD::init1;
        delay(clock, MS_TO_TICKS(5));
    }

    void init1(Clock& clock) {
        // Reset 2
        sendNibble(false, 0x3);
        state = &LCD::init2;
        delay(clock, MS_TO_TICKS(1));
    }

    void init2(Clock& clock) {
        // Reset 3
        sendNibble(false, 0x3);
        state = &LCD::init3;
        delay(clock, MS_TO_TICKS(1));
    }

    void init3(Clock& clock) {
        // initial 4 bit mode
        sendNibble(false, 0x2);
        state = &LCD::init4;
        delay(clock, MS_TO_TICKS(1));
    }

    void init4(Clock& clock) {
        sendByte(false, FUNCTION_FOUR_BITS_TWO_LINES);
        state = &LCD::init5;
        delay(clock, MS_TO_TICKS(1));
    }

    void init5(Clock& clock) {
        sendByte(false, DISPLAY_ON);
        state = &LCD::init6;
        delay(clock, MS_TO_TICKS(1));
    }

    void init6(Clock& clock) {
        sendByte(false, CLEAR_DISPLAY);
        state = &LCD::init7;
        delay(clock, MS_TO_TICKS(4));
    }

    void init7(Clock& clock) {
        sendByte(false, ENTRY_MODE_RIGHT);
        state = &LCD::run;
        delay(clock, MS_TO_TICKS(1));
    }
};

#endif
