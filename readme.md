# nblib

Non-Blocking Library.

Created by Henry Shepperd (hshepperd@gmail.com)

## About

nblib is a high level, zero overhead, type safe C++ library for AVR and ARM microcontrollers.

## Goals

* Reliable.
* Efficient.
* Simple.
* No blocking functions.
* Optional non-preemptive multitasking.
* Mitigate software lockups.
* Easily extendable to other microcontrollers.
* High level hardware abstraction with zero overhead.
* Only header files.

## Simple Example

Blinking LED

### nblib
```
void main() {
    constexpr uint64_t cpuFreq = 16000000;

    using LedPin = nblib::hw::PortB::Pin5;
    using Pin = nblib::hw::Pin;

    LedPin::mode(Pin::Mode::output);

    while(true) {
        LedPin::output(Pin::Value::high);

        for(int i = 0; i < 500; ++i) {
            nblib::delay<cpuFreq, 1000000>();
        }

        LedPin::output(Pin::Value::low);

        for(int i = 0; i < 500; ++i) {
            nblib::delay<cpuFreq, 1000000>();
        }
    }
}
```

### Equivalent Arduino code
```
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);

  delay(500);

  digitalWrite(LED_BUILTIN, LOW);

  delay(500);
}
```

## Type safety

While nblib is often more verbose than Arduino, it has the advantage of catching more errors at compile time (as opposed
to run time when it is much harder to work out what went wrong).

With Arduino it is possible to compile and run the line "digitalWrite(OUTPUT, INPUT)". The compiler has no clue
about what a valid pin or output value is, so cannot know that this code makes no sense.

With nblib every type, function, and value has been designed such that nonsensical expressions are much more likely to be
caught by the compiler.

## High level hardware access with zero overhead

```
// Analog to digital converter hardware.
using Adc = nblib::hw::Adc0;

uint16_t adcValue = 0;

Callback<uint16_t> adcCallback = [](uint16_t* value) {
    *value = Adc::value();
};

// The compiler will automatically combine and optimise the following lines into the minimum number of assembly code instructions.

Adc::channel(Adc::Channel::adc0);
Adc::prescaler(Adc::Prescaler::div128);
Adc::reference(Adc::Reference::avcc);
Adc::setCallback(adcCallback, &adcValue);
Adc::intEnable(true);
Adc::trigger(Adc::Trigger::freeRunning);
Adc::enable(true);

// To prevent optimization, and ensure sequential order, the macro "block" can be used.
// However this is only sometimes necessary.

block() {}

Adc::start();

nblib::interruptsEnable(true);

while(true) {
    // The "atomic" macro prevents interrupts from modifying the value while it is being used, and ensures sequential order (much like "block").
    const uint16_t value = atomic(adcValue);
}
```

## Status

Beta

The code is mostly stable, some things may not work, things will change, and more things will be added.

## Using this library

See [nblib-project-template](https://github.com/xenris/nblib-project-template).

## Documentation

[Documentation](docs/index.hpp.md) is limited, but there should be enough to get started.

## Compatible Devices

* atmega2560
* atmega328
* atmega328p
* atmega328pb
* atmega48
* atmega8
* attiny85
* stm32f103c8_md

## License

MIT. See [license](license).
