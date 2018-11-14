#ifndef NBOS_CALLBACK_HPP
#define NBOS_CALLBACK_HPP

/// #### {{Callback}}<T\> = void (\*)(T\*)
/// General purpose callback function type.
template <class T>
using Callback = void (*)(T*);

#endif
