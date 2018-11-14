/// [[Index]]

/// # {{Serial}}

/// ```c++
/// const uint64_t cpuFreq = 16000000;
/// const Word32 baud = 115200;
///
/// nbos::Queue<Char, 40> coutQueue;
/// nbos::Atomic<nbos::Queue<Char>> cout(coutQueue);
///
/// nbos::Serial<nbos::hw::Usart0>::init(cpuFreq, baud, &cout.nonatomic());
///
/// cout << "5 * 3 = " << (5 * 3) << '\n';
/// ```

#ifndef NBOS_SERIAL_HPP
#define NBOS_SERIAL_HPP

#include "queue.hpp"
#include "atomic.hpp"
#include "string.hpp"
#include "hardware/hardwaretype.hpp"

namespace nbos {

/// ## class Serial<class Usart>
template <class Usart>
struct Serial {
    /// #### static void init(Integer cpuFreq, Word32 baud, Queue<Char>* out, Queue<Char>* in);
    static inline void init(Integer cpuFreq, Word32 baud, Queue<Char>* out, Queue<Char>* in = nullptr) {
        static_assert(Usart::getHardwareType() == hw::HardwareType::usart, "Serial requires a Usart");

        const Word16 ubrr1x = Word16(Float(cpuFreq) / (Float(baud) * 16) - 1 + 0.5);
        const Word16 ubrr2x = Word16(Float(cpuFreq) / (Float(baud) * 8) - 1 + 0.5);

        const Word32 baudTrue1x = cpuFreq / Integer((ubrr1x + 1) * 16);
        const Word32 baudTrue2x = cpuFreq / Integer((ubrr1x + 1) * 8);

        const Float ubrr1xError = (Float(baudTrue1x) / Float(baud)) - 1;
        const Float ubrr2xError = (Float(baudTrue2x) / Float(baud)) - 1;

        const Bool use2x = ubrr2xError < ubrr1xError;

        atomic {
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
    static void usartRxComplete(Queue<Char>* in) {
        Char c = Char(Usart::pop());

        if(in != nullptr) {
            in->push(c);

            if(c == '\n') {
                in->callCallback();
            }
        }
    }

    static void usartDataRegisterEmpty(Queue<Char>* out) {
        Optional<Char> d;

        if((out != nullptr) && (d = out->pop())) {
            Usart::push(Word8(*d));
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
