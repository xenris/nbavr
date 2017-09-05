#ifndef NBAVR_SERIAL_HPP
#define NBAVR_SERIAL_HPP

template <class Usart, class cout_t, class cin_t = Queue<char, 0>>
struct Serial {
    static inline void init(uint32_t CpuFreq, uint32_t baud, cout_t* out, cin_t* in = nullptr) {
        static_assert(Usart::getHardwareType() == HardwareType::Usart, "Serial requires a Usart");

        if(out == nullptr) {
            return;
        }

        const uint16_t ubrr = CpuFreq / (16 * float(baud)) - 1 + 0.5;

        out->setNotify(outNotify, nullptr);

        atomic {
            Usart::transmitterEnable(true);
            Usart::baud(ubrr);
            Usart::use2X(false);

            if(in != nullptr) {
                Usart::receiverEnable(true);
                Usart::rxCompleteIntEnable(true);
                Usart::rxCompleteCallback(usartRxComplete, in);
            }

            Usart::dataRegisterEmptyCallback(usartDataRegisterEmpty, out);
        }
    }

private:
    static void usartRxComplete(void* data) {
        cin_t* in = reinterpret_cast<cin_t*>(data);

        char c = Usart::pop();

        in->push_(c);

        if(c == '\n') {
            in->notify();
        }
    }

    static void usartDataRegisterEmpty(void* data) {
        cout_t* out = reinterpret_cast<cout_t*>(data);

        char d;

        if(out->pop_(&d)) {
            Usart::push(d);
        } else {
            Usart::dataRegisterEmptyIntEnable(false);
        }
    }

    static void outNotify(void* data) {
        Usart::dataRegisterEmptyIntEnable(true);
    }
};

#endif
