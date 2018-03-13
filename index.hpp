/// # nbos Documentation

/// ## Index

/// * [Task](src/task.md)
/// * [TaskManager](src/taskmanager.md)
/// * Hardware
///     * [Adc](src/hardware/adc.md)
///     * [Eeprom](src/hardware/eeprom.md)
///     * [ExInt](src/hardware/exint.md)
///     * [PcInt](src/hardware/pcint.md)
///     * [Pin](src/hardware/pin.md)
///     * [Port](src/hardware/port.md)
///     * [Spi](src/hardware/spi.md)
///     * [Timer](src/hardware/timer.md)
///     * [Twi](src/hardware/twi.md)
///     * [Usart](src/hardware/usart.md)
///     * [Usi](src/hardware/usi.md)
///     * [Util](src/hardware/util.md)
/// * Examples
///     * [nbos-project-template](https://github.com/xenris/nbos-project-template)
///     * [8x8 LED Matrix Display](https://github.com/xenris/led-matrix-display)
///     * [Optima Hitec Receiver PWM/PPM](https://github.com/xenris/hitec-receiver)
/// * [Adding Chips/Tests](src/hardware/chip.md)

/// ## Editing documentation

/// All documents in the docs/ directory are generated with the gendocs.sh
/// script. To modify documents find their equivalent .hpp file and modify
/// that.

/// Documents use [GitHub flavoured markdown](https://guides.github.com/features/mastering-markdown/)
/// but with the added twist that only lines beginning with /// are included into the document.
/// This allows the gendocs.sh script to search through .hpp files, extract the documentation,
/// and produce equivalent .md files.

/// To generate paragraphs add a line with just /// between paragraphs.<br>
/// To generate new lines within the same paragraph use \<br\> at the end
/// of the line. ([Example](../index.hpp))
