/// [[Index]]

/// # {{I2c}}

#ifndef NBOS_I2C_HPP
#define NBOS_I2C_HPP

#include <queue.hpp>

namespace nbos {

/// ## class I2c
template <class Twi, uint32_t CpuFreq, uint32_t Baud>
struct I2c {
    /// #### enum Mode
    /// * read
    /// * write
    enum class Mode : int8_t {
        read = 1,
        write = 0,
    };

    /// ### class I2c::Action
    struct Action {
        /// #### using I2c::Action::Callback = void (\*)(void\* data, bool success)
        /// The callback type used when an action finishes.
        using Callback = void (*)(void* data, bool success);

        Mode mode;
        uint8_t address;
		Callback callback;
		void* data;
		uint8_t* buffer;
		uint8_t length;

		Action() {}

        /// #### I2c::Action(Mode mode, uint8_t address, uint8_t\* buffer, uint8_t length, Callback callback, void\* data)
        /// Get the type of hardware that this class represents.
        Action(Mode mode, uint8_t address, uint8_t* buffer, uint8_t length, Callback callback = nullptr, void* data = nullptr)
		: mode(mode), address(address), callback(callback), data(data), buffer(buffer), length(length) {
		}
    };

    /// #### static void init(Queue\<Action, S\>* queue)
    /// Initialise the I2c hardware.
	template <int S>
	static void init(Queue<Action, S>* queue) {
		const uint32_t scaleFactor = 1;
        const uint8_t bitRate = ((CpuFreq / Baud) - 16) / (2 * scaleFactor);

		queue->setNotify(i2cQueueNotify<S>, queue);

        Twi::callback(twiCallback<S>, queue);
        Twi::bitRate(bitRate);
	}

	template <int S>
	static void i2cQueueNotify(void* data) {
        atomic([&]() {
            auto queue = (Queue<Action, S>*)data;

            if(!Twi::active() && !queue->empty_()) {
                Twi::sendStart();
            }
        });
	}

    // TODO Add slave code.
	template <int S>
	static void twiCallback(void* data) {
		auto queue = (Queue<Action, S>*)data;

		static int i;

		Action action;

		if(queue->peek(&action)) {
			switch(Twi::status()) {
			case Twi::Status::startTransmitted:
			case Twi::Status::repeatedStartTransmitted:
				i = 0;

				Twi::push((action.address << 1) | int8_t(action.mode));

				Twi::sendNack();

				break;
			case Twi::Status::slawTransmittedAck:
			case Twi::Status::dataTransmittedAck:
				if(i < action.length) {
					Twi::push(action.buffer[i++]);

					Twi::sendNack();
				} else {
					queue->pop();

                    if(action.callback != nullptr) {
                        action.callback(action.data, true);
                    }

                    if(queue->empty()) {
                        Twi::sendStop();
                    } else {
                        Twi::sendStart();
                    }
				}

				break;
			case Twi::Status::slawTransmittedNack:
			case Twi::Status::dataTransmittedNack:
                Twi::sendStop();

                while(queue->pop(&action)) {
                    if(action.callback != nullptr) {
                        action.callback(action.data, false);
                    }
                }

				break;
			case Twi::Status::arbitrationLost:
                Twi::sendStop();

                while(queue->pop(&action)) {
                    if(action.callback != nullptr) {
                        action.callback(action.data, false);
                    }
                }

				break;
			case Twi::Status::slarTransmittedAck:
				Twi::sendAck();

				break;
			case Twi::Status::slarTransmittedNack:
                Twi::sendStop();

                while(queue->pop(&action)) {
                    if(action.callback != nullptr) {
                        action.callback(action.data, false);
                    }
                }

				break;
			case Twi::Status::dataReceivedAck:
				if(i < action.length) {
					action.buffer[i++] = Twi::pop();
				}

				if(i < action.length) {
					Twi::sendAck();
				} else {
					Twi::sendNack();
				}

				break;
			case Twi::Status::dataReceivedNack:
				queue->pop();

                if(action.callback != nullptr) {
                    action.callback(action.data, true);
                }

                if(queue->empty()) {
                    Twi::sendStop();
                } else {
                    Twi::sendStart();
                }

				break;
			case Twi::Status::ownSlawReceivedAck:
				Twi::sendNack();

				break;
			case Twi::Status::arbitrationLostOwnSlawAck:
				Twi::sendNack();

				break;
			case Twi::Status::generalCallAddressReceivedAck:
				Twi::sendNack();

				break;
			case Twi::Status::arbitrationLostGeneralCallAddressReceivedAck:
				Twi::sendNack();

				break;
			case Twi::Status::prevAddressedOwnSlawDataReceivedAck:
				Twi::sendNack();

				break;
			case Twi::Status::prevAddressedOwnSlawDataReceivedNack:
				Twi::sendNack();

				break;
			case Twi::Status::prevAddressedGeneralCallDataReceivedAck:
				Twi::sendNack();

				break;
			case Twi::Status::prevAddressedGeneralCallDataReceivedNack:
				Twi::sendNack();

				break;
			case Twi::Status::stopOrRepeatedStartWhileAddressedAsSlave:
				Twi::sendNack();

				break;
			case Twi::Status::ownSlarReceivedAck:
				Twi::sendNack();

				break;
			case Twi::Status::arbitrationLostOwnSLARAck:
				Twi::sendNack();

				break;
			case Twi::Status::dataInTwdrTransmittedAck:
				Twi::sendNack();

				break;
			case Twi::Status::dataInTwdrTransmittedNack:
				Twi::sendNack();

				break;
			case Twi::Status::lastDataTransmittedAck:
				Twi::sendNack();

				break;
			case Twi::Status::noState:
				break;
			case Twi::Status::busError:
                Twi::sendStop();
				break;
			}
		} else {
			if(Twi::active()) {
                Twi::sendStop();
            }
		}
    }
};

} // nbos

#endif
