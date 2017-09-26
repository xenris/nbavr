# EEPROM

#### macro INCLUDE_EEPROM_CALLBACK()
Include this to use Eeprom callbacks.

## class Eeprom

#### enum Mode
* EraseWrite
* EraseOnly
* WriteOnly

#### static constexpr HardwareType getHardwareType()
Get the type of hardware that this class represents.

#### static void mode(Mode m)
Set the programming mode.

#### static void address(uint16_t a)
Set the eeprom memory address to access.

#### static void data(uint8_t d)
Set the data to write.

#### static uint8_t data()
Returns the data read or written.

#### static void masterWriteEnable()
Enable the Eeprom write.

#### static void writeEnable()
Start an Eeprom write.

#### static bool writeEnabled()
Returns true if Eeprom is currently writing.

#### static void readEnable()
Start an Eeprom read.

#### static void callback(callback_t callback, void\* data)
Set the callback and data for when the Eeprom is ready.

#### static void intEnable(bool e)
Enable/disable the Eeprom ready interrupt.
