/// [[Index]]

/// # {{Serial}}

/// ```c++
/// const uint64_t cpuFreq = 16000000;
/// const uint32_t baud = 115200;
///
/// nbos::Queue<char, 40> coutQueue;
/// nbos::Atomic<nbos::Queue<char>> cout(coutQueue);
///
/// nbos::Serial<nbos::hw::Usart0>::init(cpuFreq, baud, &cout.nonatomic());
///
/// cout << "5 * 3 = " << (5 * 3) << '\n';
/// ```

#ifndef NBOS_SERIAL_HPP
#define NBOS_SERIAL_HPP

#include "type.hpp"
#include "queue.hpp"
#include "atomic.hpp"
#include "hardware/hardwaretype.hpp"

namespace nbos {

/// ## class Serial<class Usart>
template <class Usart>
struct Serial {
    /// #### static void init(uint64_t cpuFreq, uint32_t baud, Queue<char>* out, Queue<char>* in);
    static inline void init(uint64_t cpuFreq, uint32_t baud, Queue<char>* out, Queue<char>* in = nullptr) {
        static_assert(Usart::getHardwareType() == hw::HardwareType::usart, "Serial requires a Usart");

        const uint16_t ubrr1x = cpuFreq / (16 * float(baud)) - 1 + 0.5;
        const uint16_t ubrr2x = cpuFreq / (8 * float(baud)) - 1 + 0.5;

        const uint32_t baudTrue1x = cpuFreq / (16 * (ubrr1x + 1));
        const uint32_t baudTrue2x = cpuFreq / (8 * (ubrr1x + 1));

        const float ubrr1xError = (float(baudTrue1x) / baud) - 1;
        const float ubrr2xError = (float(baudTrue2x) / baud) - 1;

        const bool use2x = ubrr2xError < ubrr1xError;

        atomic([&]() {
            out->notify(outNotify, nullptr);

            Usart::baud(use2x ? ubrr2x : ubrr1x);
            Usart::use2X(use2x);

            Usart::transmitterEnable(out != nullptr);
            Usart::txCompleteIntEnable(false);
            Usart::dataRegisterEmptyIntEnable(false);
            Usart::dataRegisterEmptyCallback((callback_t)usartDataRegisterEmpty, out);

            Usart::receiverEnable(in != nullptr);
            Usart::rxCompleteIntEnable(in != nullptr);
            Usart::rxCompleteCallback((callback_t)usartRxComplete, in);
        });
    }

private:
    static void usartRxComplete(Queue<char>* in) {
        char c = Usart::pop();

        if(in != nullptr) {
            in->push(c);

            if(c == '\n') {
                in->notify();
            }
        }
    }

    static void usartDataRegisterEmpty(Queue<char>* out) {
        Optional<char> d;

        if((out != nullptr) && (d = out->pop())) {
            Usart::push(*d);
        } else {
            Usart::dataRegisterEmptyIntEnable(false);
        }
    }

    static void outNotify(void* data) {
        Usart::dataRegisterEmptyIntEnable(true);
    }
};

} // nbos

#endif
