#include "lcd.h"

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

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
#define clip(x,l,h) (max(min(x,h), l))

typedef struct {
    uint8_t min;
    uint8_t max;
} Range;

typedef struct {
    uint8_t x;
    uint8_t y;
} Coord;

// memoryMap[line].min/max

static const Range memoryMap[] = {
    {0x00, 0x0f},
    {0x40, 0x4f}};

static const uint8_t lineCount = 2;
static const uint8_t lineLength = 16;

static void (*state)(void);
static bool outOfBounds;

static void setup(void);
static void loop(void);
static void run(void);
static void writeCharacter(uint8_t character);
static void setCurser(uint8_t x, uint8_t y);
static void setCurserAddress(uint8_t address);
static void newLine(void);
static bool busy(void);
static uint8_t getCurserAddress(void);
static uint8_t coordToAddress(uint8_t x, uint8_t y);
static Coord addressToCoord(uint8_t address);
static void clearCurrentLine(void);
static void stepBack(void);
static void sendByte(bool rs, uint8_t data);
static void sendNibble(bool rs, uint8_t data);
static uint8_t getByte(bool rs);
static void init0(void);
static void init1(void);
static void init2(void);
static void init3(void);
static void init4(void);
static void init5(void);
static void init6(void);
static void init7(void);

Task lcdTask = {
    .setup = setup,
    .loop = loop,
};

static Stream _lcdout = streamInit(LCD_STREAM_SIZE);

Stream* lcdout = &_lcdout;

static void setup(void) {
    pinDirection(LCD_PIN_RW, Output);
    pinDirection(LCD_PIN_RS, Output);
    pinDirection(LCD_PIN_E, Output);
    pinSet(LCD_PIN_RW, Low);
    pinSet(LCD_PIN_RS, Low);
    pinSet(LCD_PIN_E, Low);

    state = init0;
    outOfBounds = false;

    delay(&lcdTask, MS_TO_TICKS(50));
}

static void loop(void) {
    if(busy()) {
        return;
    }

    state();
}

static void run(void) {
    uint8_t byte;
    uint8_t x;
    uint8_t y;

    if(streamPop(lcdout, &byte)) {
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
            if(streamPop(lcdout, &x) && streamPop(lcdout, &y)) {
                setCurser(x - 1, y - 1);
                outOfBounds = false;
            }
            break;
        case '\a':
            state = clearCurrentLine;
            outOfBounds = false;
            break;
        default:
            if(!outOfBounds) {
                writeCharacter(byte);
            }
        }
    } else {
        delay(&lcdTask, MS_TO_TICKS(20));
    }
}

static void writeCharacter(uint8_t character) {
    uint8_t address = getCurserAddress();
    Coord coord = addressToCoord(address);

    if(coord.x == lineLength - 1) {
        outOfBounds = true;
        state = stepBack;
    }

    sendByte(true, character);
}

static void setCurser(uint8_t x, uint8_t y) {
    setCurserAddress(coordToAddress(x, y));
}

static void setCurserAddress(uint8_t address) {
    sendByte(false, SET_DDRAM_ADDRESS | address);
}

static void newLine(void) {
    uint8_t address = getCurserAddress();
    Coord coord = addressToCoord(address);

    uint8_t y = (coord.y + 1) % lineCount;

    setCurserAddress(memoryMap[y].min);
}

static bool busy(void) {
    uint8_t data = getByte(false);

    return data & _BV(7);
}

static uint8_t getCurserAddress(void) {
    uint8_t data = getByte(false);

    return data & ~_BV(7);
}

static uint8_t coordToAddress(uint8_t x, uint8_t y) {
    y = clip(y, 0, lineCount - 1);
    x = clip(x, 0, lineLength - 1);

    return memoryMap[y].min + x;
}

static Coord addressToCoord(uint8_t address) {
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

static void clearCurrentLine(void) {
    static uint8_t count = 255;
    static uint8_t address;

    if(count == 255) {
        address = getCurserAddress();
        Coord coord = addressToCoord(address);
        address = memoryMap[coord.y].min;
        setCurserAddress(address);
    } else if(count < lineLength) {
        sendByte(true, ' ');
    } else {
        state = run;
        count = 255;
        setCurserAddress(address);
    }

    count++;
}

static void stepBack(void) {
    sendByte(false, CURSER_LEFT);
    state = run;
}

static void sendByte(bool rs, uint8_t data) {
    uint8_t high = data >> 4;
    uint8_t low = data;
    sendNibble(rs, high);
    sendNibble(rs, low);
}

static void sendNibble(bool rs, uint8_t data) {
    Value d4 = (data & _BV(0)) ? High : Low;
    Value d5 = (data & _BV(1)) ? High : Low;
    Value d6 = (data & _BV(2)) ? High : Low;
    Value d7 = (data & _BV(3)) ? High : Low;

    pinDirection(LCD_PIN_D4, Output);
    pinDirection(LCD_PIN_D5, Output);
    pinDirection(LCD_PIN_D6, Output);
    pinDirection(LCD_PIN_D7, Output);

    pinSet(LCD_PIN_D4, d4);
    pinSet(LCD_PIN_D5, d5);
    pinSet(LCD_PIN_D6, d6);
    pinSet(LCD_PIN_D7, d7);
    pinSet(LCD_PIN_RW, Low);
    pinSet(LCD_PIN_RS, rs ? High : Low);

    _delay_us(1);
    pinSet(LCD_PIN_E, High);
    _delay_us(1);
    pinSet(LCD_PIN_E, Low);
}

// XXX May need to wait 43us when reading data.
static uint8_t getByte(bool rs) {
    uint8_t data = 0;

    pinDirection(LCD_PIN_D4, Input);
    pinDirection(LCD_PIN_D5, Input);
    pinDirection(LCD_PIN_D6, Input);
    pinDirection(LCD_PIN_D7, Input);

    pinSet(LCD_PIN_D4, Low);
    pinSet(LCD_PIN_D5, Low);
    pinSet(LCD_PIN_D6, Low);
    pinSet(LCD_PIN_D7, Low);
    pinSet(LCD_PIN_RW, High);
    pinSet(LCD_PIN_RS, rs ? High : Low);

    _delay_us(1);

    pinSet(LCD_PIN_E, High);
    _delay_us(1);

    data |= (pinValue(LCD_PIN_D7) == High) ? (1 << 7) : 0;
    data |= (pinValue(LCD_PIN_D6) == High) ? (1 << 6) : 0;
    data |= (pinValue(LCD_PIN_D5) == High) ? (1 << 5) : 0;
    data |= (pinValue(LCD_PIN_D4) == High) ? (1 << 4) : 0;

    pinSet(LCD_PIN_E, Low);

    _delay_us(1);

    pinSet(LCD_PIN_E, High);
    _delay_us(1);

    data |= (pinValue(LCD_PIN_D7) == High) ? (1 << 3) : 0;
    data |= (pinValue(LCD_PIN_D6) == High) ? (1 << 2) : 0;
    data |= (pinValue(LCD_PIN_D5) == High) ? (1 << 1) : 0;
    data |= (pinValue(LCD_PIN_D4) == High) ? (1 << 0) : 0;

    pinSet(LCD_PIN_E, Low);

    return data;
}

static void init0(void) {
    // Reset 1
    sendNibble(false, 0x3);
    state = init1;
    delay(&lcdTask, MS_TO_TICKS(5));
}

static void init1(void) {
    // Reset 2
    sendNibble(false, 0x3);
    state = init2;
    delay(&lcdTask, MS_TO_TICKS(1));
}

static void init2(void) {
    // Reset 3
    sendNibble(false, 0x3);
    state = init3;
    delay(&lcdTask, MS_TO_TICKS(1));
}

static void init3(void) {
    // initial 4 bit mode
    sendNibble(false, 0x2);
    state = init4;
    delay(&lcdTask, MS_TO_TICKS(1));
}

static void init4(void) {
    sendByte(false, FUNCTION_FOUR_BITS_TWO_LINES);
    state = init5;
    delay(&lcdTask, MS_TO_TICKS(1));
}

static void init5(void) {
    sendByte(false, DISPLAY_ON);
    state = init6;
    delay(&lcdTask, MS_TO_TICKS(1));
}

static void init6(void) {
    sendByte(false, CLEAR_DISPLAY);
    state = init7;
    delay(&lcdTask, MS_TO_TICKS(4));
}

static void init7(void) {
    sendByte(false, ENTRY_MODE_RIGHT);
    state = run;
    delay(&lcdTask, MS_TO_TICKS(1));
}
