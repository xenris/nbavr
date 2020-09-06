# Hierarchy of components

FIXME Outdated.

Levels can include lower levels (smaller number), but *not* higher or equal levels.

## Level 1 - Primitive types and functions

### Level 1.1

* basic.hpp - Basic helper templates
* libc.hpp - Temporary interface to some libc functions
* macros.hpp - Basic macros for identifier manipulation

### Level 1.2

* primitive.hpp - Primitive types

### Level 1.3

* math.hpp - Basic maths functions

## Level 2 - Complex types and functions

### Level 2.1

* callback.hpp - Class providing a callback with data
* initializer_list.hpp - C++ initializer_list definition
* iterator.hpp - Functions required for container iteration
* optional.hpp - Container which can contain either something or nothing
* tuple.hpp - Basic container for multiple types

### Level 2.2

* algorithm.hpp - Common algorithms
* array.hpp - Array-like container
* priorityqueue.hpp - Container which returns values in ascending or descending order
* queue.hpp - First in first out container
* random.hpp - Type which produces pseudo random values
* stack.hpp - First in last out container
* string.hpp - Character array container
* vector.hpp - Re-sizable array-like container

## Level 3 - Chip register description

* atmega2560.hpp
* atmega328.hpp
* atmega328p.hpp
* atmega48.hpp
* atmega8.hpp
* attiny85.hpp
* stm32f103c8.hpp

## Level 4 - Hardware implementations

### Level 4.1

* hardwaretype.hpp
* system.hpp

### Level 4.2

* adc.hpp
* exint.hpp
* sleep.hpp
* spi.hpp
* timer.hpp
* usart.hpp
* watchdog.hpp
* chip.hpp
* eeprom.hpp
* isr.hpp
* pcint.hpp
* port.hpp
* twi.hpp
* usi.hpp

## Level 5 - High level

* atomic.hpp - Container which allows atomic access to stored value
* clock.hpp - Time management utility
* i2c.hpp
* print.hpp - Provides functions for printing values to character queues
* serial.hpp - Basic implementation of serial using usart hardware
* memory.hpp - Memory access utilities, such atomic, block, and bit set and get
* task.hpp
* taskmanager.hpp

## Level 6 - Top level

* nblib.hpp
