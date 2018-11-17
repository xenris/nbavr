[Index](../../index.hpp.md#index)

# Eeprom

```c++
atomic([]() {
    nbos::hw::Eeprom0::address(0x00);
    nbos::hw::Eeprom0::data(0x01);
    nbos::hw::Eeprom0::masterWriteEnable();
    nbos::hw::Eeprom0::writeEnable();
});

while(nbos::hw::Eeprom0::writeEnabled());

nbos::hw::Eeprom0::address(0x00);
nbos::hw::Eeprom0::readEnable();

Word8 n = nbos::hw::Eeprom0::data();
```

## class EepromN

#### enum AdcN::Mode
* eraseWrite
* eraseOnly
* writeOnly

#### static [HardwareType](hardwaretype.hpp.md#enum-hardwaretype) getHardwareType()

#### static void mode([AdcN::Mode](eeprom.hpp.md#enum-adcnmode) m)

#### static void address(Word16 a)

#### static void data(Word8 d)

#### static Word8 data()

#### static void masterWriteEnable()
Enable the Eeprom write.

#### static void writeEnable()
Start an Eeprom write.

#### static Bool writeEnabled()
Returns true if Eeprom is currently writing.

#### static void readEnable()
Start an Eeprom read.

#### static void setCallback([Callback](../callback.hpp.md#callbackt--void-t)<T\> function, T\* data)

#### static void callCallback()

#### static void intEnable(Bool e)