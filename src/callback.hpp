#ifndef NBLIB_CALLBACK_HPP
#define NBLIB_CALLBACK_HPP

/// #### {{Callback}}<T\> = void (\*)(T\*)
/// General purpose callback function type.
template <class T>
using Callback = void (*)(T*);

#endif
