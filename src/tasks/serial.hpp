#ifndef NBAVR_SERIAL_HPP
#define NBAVR_SERIAL_HPP

#include <nbavr.hpp>

template <class Usart>
struct Serial {
    static inline void init(uint32_t CpuFreq, uint32_t baud, Stream<char>* stdout, Stream<char>* stdin = nullptr) {
        static_assert(Usart::getHardwareType() == HardwareType::Usart, "Serial requires a Usart");

        if(stdout == nullptr) {
            return;
        }

        const uint16_t ubrr = CpuFreq / (16 * float(baud)) - 1 + 0.5;

        stdout->setFlush(flushCallback, nullptr);

        atomic {
            Usart::transmitterEnable(true);
            Usart::baud(ubrr);
            Usart::use2X(false);

            if(stdin != nullptr) {
                Usart::receiverEnable(true);
                Usart::rxCompleteIntEnable(true);
                Usart::rxCompleteCallback(usartRxComplete, stdin);
            }

            Usart::dataRegisterEmptyCallback(usartDataRegisterEmpty, stdout);
        }
    }

private:
    static void usartRxComplete(void* data) {
        Stream<char>* stdin = reinterpret_cast<Stream<char>*>(data);

        stdin->push(Usart::pop());
    }

    static void usartDataRegisterEmpty(void* data) {
        Stream<char>* stdout = reinterpret_cast<Stream<char>*>(data);

        char d;

        if(stdout->pop_(&d)) {
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
