[Index](../../index.hpp.md#index)

# Eeprom

```c++
atomic {
    nblib::hw::Eeprom0::address(0x00);
    nblib::hw::Eeprom0::data(0x01);
    nblib::hw::Eeprom0::masterWriteEnable();
    nblib::hw::Eeprom0::writeEnable();
}

while(nblib::hw::Eeprom0::writeEnabled());

nblib::hw::Eeprom0::address(0x00);
nblib::hw::Eeprom0::readEnable();

uint8_t n = nblib::hw::Eeprom0::data();
```

## class EepromN

#### enum AdcN::Mode
* eraseWrite
* eraseOnly
* writeOnly

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void mode([AdcN::Mode](eeprom.hpp.md#enum-adcnmode) m)

#### static void address(uint16_t a)

#### static void data(uint8_t d)

#### static uint8_t data()

#### static void masterWriteEnable()
Enable the Eeprom write.

#### static void writeEnable()
Start an Eeprom write.

#### static bool writeEnabled()
Returns true if Eeprom is currently writing.

#### static void readEnable()
Start an Eeprom read.

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callCallback()

#### static void intEnable(bool e)
