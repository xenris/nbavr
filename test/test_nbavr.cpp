#define __AVR_ATmega328P__

#define RECORD_ID "nbavr"

#include "test.hpp"

// TEST(Adc, getHardwareType) {
//     ASSERT_EQ(Adc::getHardwareType(), HardwareType::ADC);
// }

TEST(Clock, millisToTicks) {
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::millisToTicks(1)), 16);
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::millisToTicks(1000)), 15625);
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::millisToTicks(1001)), 15641);
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::millisToTicks(16000000)), 250000000);
    EXPECT_EQ((Clock<TimerCounter1, 16000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Clock<TimerCounter1, 16000000>::millisToTicks(1)), 250);
    EXPECT_EQ((Clock<TimerCounter1, 16000000>::millisToTicks(1000)), 250000);
    EXPECT_EQ((Clock<TimerCounter1, 16000000>::millisToTicks(16000000)), 4000000000);
    EXPECT_EQ((Clock<TimerCounter1, 20000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Clock<TimerCounter1, 20000000>::millisToTicks(1)), 313);
    EXPECT_EQ((Clock<TimerCounter1, 20000000>::millisToTicks(1000)), 312500);
}

TEST(Clock, ticksToMillis) {
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::ticksToMillis(15)), 1);
    EXPECT_EQ((Clock<TimerCounter1, 1000000>::ticksToMillis(250)), 16);
    EXPECT_EQ((Clock<TimerCounter1, 16000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Clock<TimerCounter1, 16000000>::ticksToMillis(200)), 1);
    EXPECT_EQ((Clock<TimerCounter1, 16000000>::ticksToMillis(4000000000)), 16000000);
    EXPECT_EQ((Clock<TimerCounter1, 20000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Clock<TimerCounter1, 20000000>::ticksToMillis(316)), 1);
    EXPECT_EQ((Clock<TimerCounter1, 20000000>::ticksToMillis(312500)), 1000);
    EXPECT_EQ((Clock<TimerCounter1, 20000000>::ticksToMillis(312500)), 1000);
}

TEST(Util, reverse) {
    char str[8];

    strcpy(str, "");
    EXPECT_STREQ(reverse(str, 0), "");

    strcpy(str, "a");
    EXPECT_STREQ(reverse(str, 1), "a");

    strcpy(str, "ab");
    EXPECT_STREQ(reverse(str, 2), "ba");

    strcpy(str, "abc");
    EXPECT_STREQ(reverse(str, 3), "cba");

    strcpy(str, "abc");
    EXPECT_STREQ(reverse(str, 2), "bac");
}

TEST(Print, itoa) {
    char str[64];

    itoa(str, int8_t(0), 10);
    EXPECT_STREQ(str, "0");

    itoa(str, uint8_t(147), 10);
    EXPECT_STREQ(str, "147");

    itoa(str, int16_t(1476), 10);
    EXPECT_STREQ(str, "1476");

    itoa(str, int16_t(-1476), 10);
    EXPECT_STREQ(str, "-1476");

    itoa(str, int16_t(764), 2);
    EXPECT_STREQ(str, "1011111100");

    itoa(str, int16_t(764), 1);
    EXPECT_STREQ(str, "1011111100");

    itoa(str, int16_t(847), 16);
    EXPECT_STREQ(str, "34f");

    itoa(str, int16_t(-847), 16);
    EXPECT_STREQ(str, "-34f");

    itoa(str, int32_t(36), 36);
    EXPECT_STREQ(str, "10");

    itoa(str, int32_t(36), 37);
    EXPECT_STREQ(str, "10");
}
