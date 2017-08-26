#ifndef NBAVR_SERIAL_HPP
#define NBAVR_SERIAL_HPP

#include <nbavr.hpp>

template <class Usart>
struct Serial {
    static inline void init(uint32_t CpuFreq, uint32_t baud, Stream<char>* cout, Stream<char>* cin = nullptr) {
        static_assert(Usart::getHardwareType() == HardwareType::Usart, "Serial requires a Usart");

        if(cout == nullptr) {
            return;
        }

        const uint16_t ubrr = CpuFreq / (16 * float(baud)) - 1 + 0.5;

        cout->setFlush(flushCallback, nullptr);

        atomic {
            Usart::transmitterEnable(true);
            Usart::baud(ubrr);
            Usart::use2X(false);

            if(cin != nullptr) {
                Usart::receiverEnable(true);
                Usart::rxCompleteIntEnable(true);
                Usart::rxCompleteCallback(usartRxComplete, cin);
            }

            Usart::dataRegisterEmptyCallback(usartDataRegisterEmpty, cout);
        }
    }

private:
    static void usartRxComplete(void* data) {
        Stream<char>* cin = reinterpret_cast<Stream<char>*>(data);

        char c = Usart::pop();

        cin->push(c);

        if(c == '\n') {
            cin->flush();
        }
    }

    static void usartDataRegisterEmpty(void* data) {
        Stream<char>* cout = reinterpret_cast<Stream<char>*>(data);

        char d;

        if(cout->pop_(&d)) {
            Usart::push(d);
        } else {
            Usart::dataRegisterEmptyIntEnable(false);
        }
    }

    static void flushCallback(void* data) {
        Usart::dataRegisterEmptyIntEnable(true);
    }
};

#endif
