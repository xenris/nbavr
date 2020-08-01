# nblib

Non-Blocking Library.

Created by Henry Shepperd (hshepperd@gmail.com)

## About

nblib is a high level, zero overhead, type safe C++ library for AVR and ARM microcontrollers.

## Goals

* Reliable.
* Efficient.
* Simple.
* Type safety.
* Maximise compile time errors, minimise run time errors.
* No blocking functions.
* Mitigate software lockups.
* Easily extendable to other microcontrollers.
* High level hardware abstraction with zero overhead.

## Simple Example

Blinking LED

```
constexpr uint64_t cpuFreq = 16000000;

using LedPin = nblib::hw::PortB::Pin5;

void main() {
    LedPin::direction(LedPin::Direction::output);

    while(true) {
        LedPin::toggle();

        for(int i = 0; i < 500; ++i) {
            nblib::delay<cpuFreq, 1000000>(); // 1000000 nanosecond delay.
        }
    }
}
```

## Type safety

While nblib is often more verbose than Arduino, it has the advantage of catching more errors at compile time (as opposed
to run time when it is much harder to work out what went wrong).

For example: With Arduino it is possible to compile and run the line "digitalWrite(OUTPUT, INPUT)". The compiler has no clue
about what a valid pin or output value is, so cannot know that this code makes no sense.

With nblib every type, function, and value has been designed such that nonsensical expressions are much more likely to be
caught by the compiler.

## High level hardware access with zero overhead

```
// Analog to digital converter hardware.
using Adc = nblib::hw::Adc0;

uint16_t adcValue = 0;

void main() {
    // The compiler will automatically combine and optimise the following lines into the minimum number of assembly code instructions.

    Adc::channel(Adc::Channel::adc0);
    Adc::prescaler(Adc::Prescaler::div128);
    Adc::reference(Adc::Reference::avcc);
    Adc::intEnable(true);
    Adc::trigger(Adc::Trigger::freeRunning);
    Adc::enable(true);

    // To prevent optimization, and ensure sequential order, the macro "block" can be used.

    block() {}

    Adc::start();

    nblib::interruptsEnable(true);

    while(true) {
        // The "atomic" macro prevents interrupts from modifying the value while it is being used, and ensures sequential order (much like "block").
        const uint16_t value = atomic(adcValue);
    }
}

// Adc result ready interrupt vector.
vectorAdc0 {
    adcValue = Adc::value();
}
```

## Status

Beta

The code is mostly stable, some things may not work, things will change, and more things will be added.

## Using this library

See [nblib-script](https://github.com/xenris/nblib-script)

## Documentation

[Documentation](docs/index.hpp.md) is limited, but there should be enough to get started.

## Compatible Devices

* atmega2560
* atmega328
* atmega328p
* atmega328pb
* atmega48
* atmega8
* attiny402
* attiny85
* stm32f103c8_md

## License

MIT. See [license](license).
