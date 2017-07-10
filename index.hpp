/// # nbavr Documentation

/// ## Index

/// * [Tasks](src/task.md)
/// * [TaskManager](src/nbavr.md)
/// * Hardware
///     * [Analog to Digital](src/hardware/adc.md)
///     * [External Interrupts](src/hardware/exint.md)
///     * [Pin Change Interrupts](src/hardware/pcint.md)
///     * [Digital IO Pins](src/hardware/pin.md)
///     * [Digital IO Ports](src/hardware/port.md)
///     * [Timer/Counters](src/hardware/timercounter.md)
///     * [USARTs](src/hardware/usart.md)
///     * [Utils](src/hardware/util.md)
/// * [Examples](../tests)

/// ## Editing documentation

/// All documents in the docs/ directory are generated with the gendocs.sh
/// script. To modify documents find their equivalent .hpp file and modify
/// that.
///
/// Documents use [GitHub flavoured markdown](https://guides.github.com/features/mastering-markdown/)
/// but with the added twist that only lines beginning with /// are included into the document.
/// This allows the gendocs.sh script to search through .hpp files, extract the documentation,
/// and produce equivalent .md files.
///
/// To generate paragraphs add a line with just /// between paragraphs.<br>
/// To generate new lines within the same paragraph use \<br\> at the end
/// of the line. ([Example](../index.hpp))