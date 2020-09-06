MEMORY {
    flash (rx) : org = 0x08000000, len = 64k
    sram (rwx) : org = 0x20000000, len = 20k
}

ENTRY(__main)

SECTIONS {
    .text : {
        KEEP(*(.vector_table))
        __text_start__ = .;
        *(.text*)
        . = ALIGN(4);
        __text_end__ = .;
        *(.rodata*)
        . = ALIGN(4);
    } >flash

    .data : {
        __data_start__ = .;
        *(.data*)
        . = ALIGN(4);
        __data_end__ = .;
    } >sram AT >flash

    .bss : {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
    } >sram
}

PROVIDE(__stack__ = ORIGIN(sram) + LENGTH(sram));
