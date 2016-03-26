# nbavr reference

This reference is a work in progress, but should contain enough to get started, along with the examples.

## Task Manager

```c
// Run a group of tasks.
// "tasks" is a NULL terminated array.
// This function never returns.
// No more tasks can be started after this is called.
void nbavr(Task** tasks)
```

### Example

```c
static Task* tasks[] = {&task1, &task2, &task3, NULL};
nbavr(tasks)
```

## Tasks

```c
// Task declaration.
// All elements are optional.
Task task = {
    .setup = ..., // Function called once at task start and after crash.
    .loop = ..., // Function called repetedly after setup is called.
    .crash = ..., // Function called when the task manager detects that the task has halted.
    .priority = ..., // PRIORITY_LOW/MEDIUM/HIGH/DRIVER.
};

// The type of the .setup, .loop, and .crash functions.
typedef void (*TaskFunction)(void);

// Return immediately from the current task.
void yield(void);
```

### Example

```c
static void setup(void);
static void loop(void);
static void crash(void);

Task task = {
    .setup = setup,
    .loop = loop,
    .crash = crash,
    .priority = PRIORITY_LOW,
};

static void setup(void) {
    // Called once at the start.
    // Setup environment.
}

static void loop(void) {
    // Called repetedly.
    // Run main operation.
}

static void crash(void) {
    // Called if something goes wrong and the task halts.
    // Do what you need to before the task is reset and setup() is called again.
}
```

## Streams

```c
// Used to construct streams.
// These create static streams only, which means the arguments passed in must be constants and the stream it produces must be declared static. (See example.)
// The callback version will call the supplied function immediately before data is pushed to the stream. Useful for waking up a task when there is data to be processed. (See the serial module for an example.)
streamInit(uint16_t size);
streamInitCallback(uint16_t size, void (*callback)(void));

// A selection of functions for using streams.
bool streamPush(Stream* stream, uint8_t n);
bool streamPop(Stream* stream, uint8_t* n);
bool streamPeek(Stream* stream, uint8_t* n);

bool streamPush16(Stream* stream, uint16_t n);
bool streamPop16(Stream* stream, uint16_t* n);
bool streamPeek16(Stream* stream, uint16_t* n);

bool streamPushBuffer(Stream* stream, uint16_t count, uint8_t* buffer);
bool streamPopBuffer(Stream* stream, uint16_t count, uint8_t* buffer);

int16_t streamUsed(Stream* stream);
int16_t streamUnused(Stream* stream);

void streamClear(Stream* stream);

bool streamHasOverflowed(Stream* stream);

bool streamEmpty(Stream* stream);
bool streamHasData(Stream* stream);

// There are also non-atomic variants available for speed critical code (e.g. inside interrupts).
// Just append _ to the end of the stream function name.
bool streamPush_(Stream* stream, uint8_t n);
// etc...
```

### Example

```c
static Stream stream = streamInit(20);

if(!streamPush16(&stream, 100)) {
    // Failed to push int.
}

int n = 0;

if(!streamPop16(&stream, &n) {
    // Failed to pop int.
}
```

## Serial

To use serial the task "serialTask" needs to be added to the task list. e.g.
```c
static Task* tasks[] = {&task1, &task2, &task3, &serialTask, NULL};
```

```c
// Two streams are provided for serial communication.
// They can be written to using the print() function.
Stream* stdin;
Stream* stdout;

// The TWI task can be configured from config.h.
#define BAUD 9600
```

## Print

```c
// Functions for printing values to streams.
// Simplified version of printf
bool print(Stream* stream, const char* format, ...);
bool printstr(Stream* stream, const char* str);
bool printchar(Stream* stream, char c);
bool printvalue(Stream* stream, int c);
bool printint(Stream* stream, bool signed, uint16_t value, uint8_t base);
```

print() has the following formatting sequences:
* %i - A signed integer in decimal.
* %u - An unsigned integer in decimal.
* %x - An unsigned integer in hexadecimal.
* %o - An unsigned integer in octal.
* %b - An unsigned integer in binary.
* %s - A NULL terminated string.
* %c - A single character.
* %v - The exact byte value.
* %% - The '%' character.

### Example

```c
int a = 12;
print(stdout, "%i in binary is %b\n", a, a);
```

## Digital IO

```c
// Set a single pin as an output or input.
void pinDirection(Pin pin, Direction direction);

// Get the input value of a pin.
Value pinValue(Pin pin);

// Set the output value of a pin.
void pinSet(Pin pin, Value value);

// Enable or disable the pullup resistor on a pin.
void pinPullup(Pin pin, bool b);

// Toggle a pin high/low.
void pinToggle(Pin pin);


// Set multiple pins on port as outputs or inputs.
void portDirection(Port port, uint8_t directions);

// Get the inputs of a port.
uint8_t portValue(Port port);


// Set the outputs of a port.
void portSet(Port port, uint8_t values);

// Enable or disable multiple pullup resistors on a port.
void portPullup(Port port, uint8_t pins);

// Toggle multiple pins on a port high/low.
void portToggle(Port port, uint8_t pins);

typedef enum {
    PortB,
    PortC,
    PortD,
} Port;

typedef enum {
    PinB0,
    PinB1,
    PinB2,
    PinB3,
    PinB4,
    PinB5,
    PinB6,
    PinB7,
    PinC0,
    PinC1,
    PinC2,
    PinC3,
    PinC4,
    PinC5,
    PinC6,
    PinD0,
    PinD1,
    PinD2,
    PinD3,
    PinD4,
    PinD5,
    PinD6,
    PinD7,
} Pin;

typedef enum {
    Input,
    Output,
} Direction;

typedef enum {
    Low,
    High,
} Value;
```

### Example

```c
pinDirection(PinD5, Output);
pinSet(PinD5, High);
pinToggle(PinD5);

pinDirection(PinB4, Input);
pinPullup(PinB4, true);

portDirection(PortB, 0x0F);
portSet(PortB, 0x0F);
```

## Analog to Digital

```c
// Starts the ADC using the configuration provided.
void adcStart(ADCConfig config);

// Disables the ADC.
void adcDisable();

// Gets the most recently acquired analog to digital conversion
uint16_t adcGetValue();

typedef struct {
    ADCReference reference;
    ADCChannel channel;
    ADCPrescaler prescaler;
    ADCAdjust adjust;
    ADCAutoTrigger autoTrigger;
} ADCConfig;

typedef enum {
    ADC_REFERENCE_AREF,
    ADC_REFERENCE_AVCC,
    ADC_REFERENCE_INTERNAL,
} ADCReference;

typedef enum {
    ADC_0,
    ADC_1,
    ADC_2,
    ADC_3,
    ADC_4,
    ADC_5,
    ADC_6,
    ADC_7,
    ADC_8,
    ADC_VBG,
    ADC_GND,
} ADCChannel;

typedef enum {
    ADC_PRESCALER_2,
    ADC_PRESCALER_4,
    ADC_PRESCALER_8,
    ADC_PRESCALER_16,
    ADC_PRESCALER_32,
    ADC_PRESCALER_64,
    ADC_PRESCALER_128,
} ADCPrescaler;

typedef enum {
    ADC_RIGHT_ADJUST,
    ADC_LEFT_ADJUST,
} ADCAdjust;

typedef enum {
    ADC_SINGLE_CONVERSION,
    ADC_FREE_RUNNING,
    ADC_ANALOG_COMPARATOR,
    ADC_EXTERNAL_INT_0,
    ADC_TIMER0_COMPARE_MATCH_A,
    ADC_TIMER0_OVERFLOW,
    ADC_TIMER1_COMPARE_MATCH_B,
    ADC_TIMER1_OVERFLOW,
    ADC_TIMER1_CAPTURE_EVENT,
} ADCAutoTrigger;
```

### Example

```c
// Configure the ADC to do a single conversion on pin ADC1/PC1, using AVcc pin as reference, with a prescaler of 64.
ADCConfig config = {
    reference = ADC_REFERENCE_AVCC,
    channel = ADC_1,
    prescaler = ADC_PRESCALER_64,
}

// Start the convertion
adcStart(config);

static volatile value;

// This interrupt will be called when the convertion is complete.
ISR(ADC_vect) {
    value = adcGetValue();
}
```

## Servos

To run servos the task "servoTask" needs to be added to the task list. e.g.
```c
static Task* tasks[] = {&task1, &task2, &task3, &servoTask, NULL};
```

```c
// Servos can be added to any IO pin.
int8_t servoAdd(Pin pin);

// The position of the servo is defined by a signed 8 bit integer, which gives the range -128 to 127, end to end.
void servoSet(int8_t servo, int8_t position);

// Gets the position the servo is set to.
int8_t servoGet(int8_t servo);
```

### Example

```c
int8_t servo = servoAdd(PinD7);
// ...
servoSet(servo, -30);
// ...
servoSet(servo, servoGet(servo) + 1);
```

## Timer/Counters

Timer/Counter1 is used by nbavr and shouldn't be changed. (To use timer/counter2 change instances of "timer0" with "timer2".)

```c
// Start a timer/counter with the provided configuration.
void timer0(Timer0Config config);

// Get the current value of the timer/counter.
uint8_t timer0GetTimerRegister();

// Set the output compare registers.
void timer0SetOutputCompareA(uint8_t v);
void timer0SetOutputCompareB(uint8_t v);

// Enable various interrupts.
void timer0OverflowIntEnable(bool b);
void timer0OutputCompareMatchAIntEnable(bool b);
void timer0OutputCompareMatchBIntEnable(bool b)

typedef struct {
    Timer0OutputCompareMode outputCompareA;
    Timer0OutputCompareMode outputCompareB;
    Timer0WaveformGenerationMode waveformGenerationMode;
    Timer0ClockSelect clockSelect;
    uint8_t timerRegister;
    uint8_t outputCompareRegisterA;
    uint8_t outputCompareRegisterB;
    bool outputCompareMatchAIntEnable;
    bool outputCompareMatchBIntEnable;
    bool overflowIntEnable;
} Timer0Config;

typedef enum {
    TIMER0_OUTPUT_COMPARE_DISCONNECTED = 0,
    TIMER0_OUTPUT_COMPARE_TOGGLE = 1,
    TIMER0_OUTPUT_COMPARE_CLEAR_ON_COMPARE = 2,
    TIMER0_OUTPUT_COMPARE_SET_ON_COMPARE = 3,
} Timer0OutputCompareMode;

typedef enum {
    TIMER0_NORMAL = 0,
    TIMER0_PWM_PHASE_CORRECT = _BV(WGM00),
    TIMER0_CLEAR_TIMER_ON_COMPARE = _BV(WGM01),
    TIMER0_FAST_PWM = _BV(WGM01) | _BV(WGM00),
    TIMER0_PWM_PHASE_CORRECT_OCRA = _BV(WGM02) | _BV(WGM00),
    TIMER0_FAST_PWM_OCRA = _BV(WGM02) | _BV(WGM01) | _BV(WGM00),
} Timer0WaveformGenerationMode;

typedef enum {
    TIMER0_SOURCE_NONE = 0,
    TIMER0_SOURCE_1 = 1,
    TIMER0_SOURCE_8 = 2,
    TIMER0_SOURCE_64 = 3,
    TIMER0_SOURCE_256 = 4,
    TIMER0_SOURCE_1024 = 5,
    TIMER0_SOURCE_EXTERNAL_FALLING = 6,
    TIMER0_SOURCE_EXTERNAL_RISING = 7,
} Timer0ClockSelect;
```

### Example

```c
// Setup timer/counter0 to call an interrupt every 1024 * 256 clock cycles.

Timer0Config config {
    .clockSelect = TIMER0_SOURCE_1024,
    .overflowIntEnable = true,
}

timer0(config);

ISR(TIMER0_OVF_vect) {
    // ...
}

// ...

// Setup timer/counter2 to produce a PWM signal on pin OC2A/PB3.

pinDirection(PinB3, Output);

Timer2Config config {
    .clockSelect = TIMER2_SOURCE_8,
    .waveformGenerationMode = TIMER2_FAST_PWM,
    .outputCompareA = TIMER2_OUTPUT_COMPARE_SET_ON_COMPARE,
}

timer2(config);

// Set the phase of the PWM.
timer2SetOutputCompareA(50);

```

## Clock

```c
// Get the number of milliseconds passed since turning on. Wraps after 49.7 days.
uint32_t getMillis();
```

## Delay

```c
// Call the supplied function as an interrupt with the code as an argument after the specified number of microseconds.
bool addInterrupt(void (*function)(int), int code, uint16_t us);

// Delay the next call to this task by at least ms milliseconds.
void delayMillis(uint16_t ms);

// Delay the next call to this task by at least s seconds.
void delaySeconds(uint16_t s);
```

### Example

```c
// Toggle pin PB5 every 500ms.
// Note that delayMillis returns immediately. The delay happens outside the task.
void loop(void) {
    pinToggle(PinB5);
    delayMillis(500);
}
```

## LCD (Hitachi HD44780 compatible)

(The LCD task has only been tested with a 16x2 display.)

To use an LCD the task "lcdTask" needs to be added to the task list. e.g.
```c
static Task* tasks[] = {&task1, &task2, &task3, &lcdTask, NULL};
```

```c
// A stream is provided for writing to an LCD.
Stream* lcdout;

// The LCD task can be configured from config.h.
// Change these to match your configuration.
#define LCD_STREAM_SIZE 30
#define LCD_PIN_D4 PinC4
#define LCD_PIN_D5 PinC5
#define LCD_PIN_D6 PinD6
#define LCD_PIN_D7 PinD7
#define LCD_PIN_RW PinD5
#define LCD_PIN_RS PinD4
#define LCD_PIN_E PinB1
```

Write to lcdout using the print function. The following escape characters are defined:
* \r - Clear display and put curser at start (position (1, 1))
* \n - Go to start of next line.
* \v - Go to position defined by the next two literal bytes. (See example.)
* \a - Clear current line, preserving curser position.

### Example

```c
print(lcdout, "\rHello\n%i", 5);
//...
print(lcdout, "\r\v\5\2Position (5,2)"); // Values are in octal.
//...
print(lcdout, "\r\v%v%vPosition (%i,%i)", 3, 1);
```

## TWI

To use the TWI the task "twiTask" needs to be added to the task list. e.g.
```c
static Task* tasks[] = {&task1, &task2, &task3, &twiTask, NULL};
```

```c
// Queue the supplied TWI action.
bool twiDo(TWIAction* action);

typedef struct {
    TWIDirection rw;
    uint8_t addr;
    uint8_t count;
    uint8_t* data;
    TWIResult* result;
    bool repeatStart;
} TWIAction;

typedef enum {
    TWI_READ = TW_READ,
    TWI_WRITE = TW_WRITE,
} TWIDirection;

typedef enum {
    TWI_NONE,
    TWI_QUEUED,
    TWI_BUSY,
    TWI_SUCCESS,
    TWI_FAIL,
} TWIResult;

// The TWI task can be configured from config.h.
#define TWI_BAUD 400
```

### Example

```c
static TWIResult result;
static uint8_t buffer[] = {0x01};
//...
// Send a single byte from "buffer" to address 0x23 and track the TWI status with "result".
TWIAction action = {TWI_WRITE, 0x23, 1, buffer, &result, false};
twiDo(&action);
```

## External Interrupts

```c
// Enable external interrupt triggered by the defined event.
void int0(IntEvent event);
void int1(IntEvent event);

// Enable pin change external interrupts on the defined pins.
void pcint0(uint8_t active); // Pins PCINT0 to PCINT7
void pcint1(uint8_t active); // Pins PCINT8 to PCINT14 (No PCINT15)
void pcint2(uint8_t active); // Pins PCINT16 to PCINT23

typedef enum {
    IntLow = 0,
    IntChange = 1,
    IntFalling = 2,
    IntRising = 3,
    IntDisable = 4,
} IntEvent;
```

### Example

```c
// Enable an external interrupt, triggered when pin INT0/PD2 goes low.
int0(IntFalling);

// Enable a pin change external interrupt, triggered when either pin PCINT8/PC0 or PCINT9/PC1 changes.
pcint1(0x03);

ISR(INT0_vect) {
    //...
}

ISR(PCINT1_vect) {
    //...
}
```

## Arduino UNO Pin Mapping

To simplify working out which pin is which on the Arduino UNO the following mapping is provided.

```c
#define UNOD0 PinD0
#define UNOD1 PinD1
#define UNOD2 PinD2
#define UNOD3 PinD3
#define UNOD4 PinD4
#define UNOD5 PinD5
#define UNOD6 PinD6
#define UNOD7 PinD7
#define UNOD8 PinB8
#define UNOD9 PinB1
#define UNOD10 PinB2
#define UNOD11 PinB3
#define UNOD12 PinB4
#define UNOD13 PinB5
#define UNOA0 PinC0
#define UNOA1 PinC1
#define UNOA2 PinC2
#define UNOA3 PinC3
#define UNOA4 PinC4
#define UNOA5 PinC5
```
