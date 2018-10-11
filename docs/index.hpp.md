# nbos Documentation

## Index

* [Task](src/task.hpp.md#task)
* [TaskManager](src/taskmanager.hpp.md#taskmanager)
* Hardware
    * [Analog to Digital Converters](src/hardware/adc.hpp.md#analog-to-digital-converters)
    * [Eeprom](src/hardware/eeprom.hpp.md#eeprom)
    * [External Interrupts](src/hardware/exint.hpp.md#external-interrupts)
    * [Pin Change Interrupts](src/hardware/pcint.hpp.md#pin-change-interrupts)
    * [Digital IO Pins](src/hardware/pin.hpp.md#digital-io-pins)
    * [Digital IO Ports](src/hardware/port.hpp.md#digital-io-ports)
    * [Serial Peripheral Interfaces](src/hardware/spi.hpp.md#serial-peripheral-interfaces)
    * [Timers](src/hardware/timer.hpp.md#timers)
    * [Two Wire Serial Interfaces](src/hardware/twi.hpp.md#two-wire-serial-interfaces)
    * [Universal Synchronous Asynchronous Receiver Transmitters](src/hardware/usart.hpp.md#universal-synchronous-asynchronous-receiver-transmitters)
    * [Universal Serial Interfaces](src/hardware/usi.hpp.md#universal-serial-interfaces)
* Examples
    * [nbos-project-template](https://github.com/xenris/nbos-project-template)
    * [8x8 LED Matrix Display](https://github.com/xenris/led-matrix-display)
    * [Optima Hitec Receiver PWM/PPM](https://github.com/xenris/hitec-receiver)
* [Adding Chips](src/hardware/chip.hpp.md#adding-chips)

## Editing documentation

All documents in the docs/ directory are generated with the gendocs.sh
script. To modify documents find their equivalent .hpp file and modify
that.

Documents use [GitHub flavoured markdown](https://guides.github.com/features/mastering-markdown/)
but with the added twist that only lines beginning with /// are included into the document.
This allows the gendocs.sh script to search through .hpp files, extract the documentation,
and produce equivalent .md files.

To generate paragraphs add a line with just /// between paragraphs.<br>
To generate new lines within the same paragraph use \<br\> at the end
of the line. ([Example](../index.hpp))
