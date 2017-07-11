#define __AVR_ATmega328P__

#define RECORD_ID "nbavr"

#include "test.hpp"

// TEST(Adc, getHardwareType) {
//     ASSERT_EQ(Adc::getHardwareType(), HardwareType::ADC);
// }

TEST(Nbavr, millisToTicks) {
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::millisToTicks(1)), 16);
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::millisToTicks(1000)), 15625);
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::millisToTicks(1001)), 15641);
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::millisToTicks(16000000)), 250000000);
    EXPECT_EQ((Nbavr<TimerCounter1, 16000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Nbavr<TimerCounter1, 16000000>::millisToTicks(1)), 250);
    EXPECT_EQ((Nbavr<TimerCounter1, 16000000>::millisToTicks(1000)), 250000);
    EXPECT_EQ((Nbavr<TimerCounter1, 16000000>::millisToTicks(16000000)), 4000000000);
    EXPECT_EQ((Nbavr<TimerCounter1, 20000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Nbavr<TimerCounter1, 20000000>::millisToTicks(1)), 313);
    EXPECT_EQ((Nbavr<TimerCounter1, 20000000>::millisToTicks(1000)), 312500);
}

TEST(Nbavr, ticksToMillis) {
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::ticksToMillis(15)), 1);
    EXPECT_EQ((Nbavr<TimerCounter1, 1000000>::ticksToMillis(250)), 16);
    EXPECT_EQ((Nbavr<TimerCounter1, 16000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Nbavr<TimerCounter1, 16000000>::ticksToMillis(200)), 1);
    EXPECT_EQ((Nbavr<TimerCounter1, 16000000>::ticksToMillis(4000000000)), 16000000);
    EXPECT_EQ((Nbavr<TimerCounter1, 20000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Nbavr<TimerCounter1, 20000000>::ticksToMillis(316)), 1);
    EXPECT_EQ((Nbavr<TimerCounter1, 20000000>::ticksToMillis(312500)), 1000);
    EXPECT_EQ((Nbavr<TimerCounter2, 20000000>::ticksToMillis(312500)), 1000);
}
