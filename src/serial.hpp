/// [[Index]]

/// # {{Serial}}

/// ```c++
/// const uint64_t cpuFreq = 16000000;
/// const uint32_t baud = 115200;
///
/// nblib::Queue<char, 40> coutQueue;
/// nblib::Atomic<nblib::Queue<char>> cout(coutQueue);
///
/// nblib::Serial<nblib::hw::Usart0>::init(cpuFreq, baud, &cout.nonatomic());
///
/// cout << "5 * 3 = " << (5 * 3) << '\n';
/// ```

#ifndef NBLIB_SERIAL_HPP
#define NBLIB_SERIAL_HPP

#include "queue.hpp"
#include "hardware/system.hpp"
#include "string.hpp"
#include "hardware/hardwaretype.hpp"

namespace nblib {

/// ## class Serial<class Usart>
template <class Usart>
struct Serial {
    /// #### static void init(uint64_t cpuFreq, uint32_t baud, Queue<char>* out, Queue<char>* in);
    static inline void init(uint64_t cpuFreq, uint32_t baud, Queue<char>* out, Queue<char>* in = nullptr) {
        static_assert(Usart::getHardwareType() == hw::HardwareType::usart, "Serial requires a Usart");

        const uint16_t ubrr1x = uint16_t(float(cpuFreq) / (float(baud) * 16) - 1 + 0.5);
        const uint16_t ubrr2x = uint16_t(float(cpuFreq) / (float(baud) * 8) - 1 + 0.5);

        const uint64_t baudTrue1x = cpuFreq / ((ubrr1x + 1) * 16);
        const uint64_t baudTrue2x = cpuFreq / ((ubrr1x + 1) * 8);

        const float ubrr1xError = (float(baudTrue1x) / float(baud)) - 1;
        const float ubrr2xError = (float(baudTrue2x) / float(baud)) - 1;

        const bool use2x = ubrr2xError < ubrr1xError;

        atomic() {
            out->setCallback(outNotify, (void*)nullptr);

            Usart::baud(use2x ? ubrr2x : ubrr1x);
            Usart::use2X(use2x);

            Usart::transmitterEnable(out != nullptr);
            Usart::txCompleteIntEnable(false);
            Usart::dataRegisterEmptyIntEnable(false);
            Usart::setDeCallback(usartDataRegisterEmpty, out);

            Usart::receiverEnable(in != nullptr);
            Usart::rxCompleteIntEnable(in != nullptr);
            Usart::setRxCallback(usartRxComplete, in);
        }
    }

private:
    static void usartRxComplete(Queue<char>* in) {
        char c = char(Usart::pop());

        if(in != nullptr) {
            in->push(c);

            if(c == '\n') {
                in->callCallback();
            }
        }
    }

    static void usartDataRegisterEmpty(Queue<char>* out) {
        Optional<char> d;

        if((out != nullptr) && (d = out->pop())) {
            Usart::push(uint8_t(*d));
        } else {
            Usart::dataRegisterEmptyIntEnable(false);
        }
    }

    static void outNotify(void* data) {
        Usart::dataRegisterEmptyIntEnable(true);
    }
};

} // nblib

#endif
