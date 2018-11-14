[Index](../index.hpp.md#index)

# I2c

## class I2c

#### enum Mode
* read
* write

### class I2c::Action

#### using I2c::Action::Callback = void (\*)(void\* data, Bool success)
The callback type used when an action finishes.

#### I2c::Action(Mode mode, Word8 address, Word8\* buffer, Word8 length, Callback callback, void\* data)
Get the type of hardware that this class represents.

#### static void init(Queue\<Action, S\>* queue)
Initialise the I2c hardware.
