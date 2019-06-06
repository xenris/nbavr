[Index](../index.hpp.md#index)

# I2c

## class I2c

#### enum Mode
* read
* write

### class I2c::Action

#### using I2c::Action::Callback = void (\*)(void\* data, bool success)
The callback type used when an action finishes.

#### I2c::Action(Mode mode, uint8_t address, uint8_t\* buffer, uint8_t length, Callback callback, void\* data)
Get the type of hardware that this class represents.

#### static void init(Queue\<Action\>* queue)
Initialise the I2c hardware.
