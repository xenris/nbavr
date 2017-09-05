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

INCLUDE_TIMERCOUNTER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMERCOUNTER_OVERFLOW_CALLBACK(1);

TEST(Clock, delayedCall) {
    typedef Clock<TimerCounter1, 16000000> Clock;

    Clock::delayedCall(nullptr, nullptr, Clock::millisToTicks(3000));

    DelayedCall a(nullptr, nullptr, 1000);
    DelayedCall b(nullptr, nullptr, 1500);
    DelayedCall c(nullptr, nullptr, 1001);
    DelayedCall d(nullptr, nullptr, 999);
    DelayedCall e(nullptr, nullptr, 1000);
    DelayedCall f(nullptr, nullptr, 4294967296 / 2 - 1);
    DelayedCall g(nullptr, nullptr, 4294967296 / 2 - 2);

    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(d < a);
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(a < f);
    EXPECT_TRUE(g < f);
    EXPECT_FALSE(b < a);
    EXPECT_FALSE(c < a);
    EXPECT_FALSE(a < e);
    EXPECT_FALSE(e < a);
    EXPECT_FALSE(f < a);
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

    itoa(str, int32_t(65535), 10);
    EXPECT_STREQ(str, "65535");

    itoa(str, uint32_t(65535), 10);
    EXPECT_STREQ(str, "65535");

    itoa(str, int32_t(32768), 10);
    EXPECT_STREQ(str, "32768");
}

TEST(Container, Queue) {
    Queue<int16_t, 3> queue;

    ::testing::StaticAssertTypeEq<Queue<int16_t, 3>::size_t, int8_t>();
    ::testing::StaticAssertTypeEq<Queue<int16_t, 127>::size_t, int8_t>();
    ::testing::StaticAssertTypeEq<Queue<int16_t, 128>::size_t, int16_t>();

    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(queue.capacity(), 3);

    EXPECT_EQ(queue.full(), false);

    EXPECT_EQ(queue.push(1), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.push(2), true);
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(queue.push(3), true);
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.full(), true);
    EXPECT_EQ(queue.push(4), false);
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.capacity(), 3);

    int16_t n;
    EXPECT_EQ(queue.pop(&n), true);
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(n, 1);
    EXPECT_EQ(queue.pop(&n), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(n, 2);

    EXPECT_EQ(queue.full(), false);

    EXPECT_EQ(queue.push(5), true);
    EXPECT_EQ(queue.size(), 2);

    EXPECT_EQ(queue.pop(&n), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(n, 3);

    EXPECT_EQ(queue.pop(&n), true);
    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(n, 5);

    EXPECT_EQ(queue.empty(), true);

    EXPECT_EQ(queue.pop(&n), false);
    EXPECT_EQ(queue.size(), 0);

    EXPECT_EQ(queue.push(6), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.empty(), false);
    queue.clear();
    EXPECT_EQ(queue.empty(), true);
}

TEST(Container, Stack) {
    Stack<int16_t, 3> stack;

    ::testing::StaticAssertTypeEq<Stack<int16_t, 3>::size_t, int8_t>();
    ::testing::StaticAssertTypeEq<Stack<int16_t, 127>::size_t, int8_t>();
    ::testing::StaticAssertTypeEq<Stack<int16_t, 128>::size_t, int16_t>();

    EXPECT_EQ(stack.size(), 0);
    EXPECT_EQ(stack.capacity(), 3);

    EXPECT_EQ(stack.full(), false);

    EXPECT_EQ(stack.push(1), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.push(2), true);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.push(3), true);
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.full(), true);
    EXPECT_EQ(stack.push(4), false);
    EXPECT_EQ(stack.size(), 3);
    EXPECT_EQ(stack.capacity(), 3);

    int16_t n;
    EXPECT_EQ(stack.pop(&n), true);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(n, 3);
    EXPECT_EQ(stack.pop(&n), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(n, 2);

    EXPECT_EQ(stack.full(), false);

    EXPECT_EQ(stack.push(5), true);
    EXPECT_EQ(stack.size(), 2);

    EXPECT_EQ(stack.pop(&n), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(n, 5);

    EXPECT_EQ(stack.pop(&n), true);
    EXPECT_EQ(stack.size(), 0);
    EXPECT_EQ(n, 1);

    EXPECT_EQ(stack.empty(), true);

    EXPECT_EQ(stack.pop(&n), false);
    EXPECT_EQ(stack.size(), 0);

    EXPECT_EQ(stack.push(6), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.empty(), false);
    stack.clear();
    EXPECT_EQ(stack.empty(), true);
}

TEST(Container, Array) {
    Array<int16_t, 3> array;

    ::testing::StaticAssertTypeEq<Array<int16_t, 3>::size_t, int8_t>();
    ::testing::StaticAssertTypeEq<Array<int16_t, 127>::size_t, int8_t>();
    ::testing::StaticAssertTypeEq<Array<int16_t, 128>::size_t, int16_t>();

    EXPECT_EQ(array.size(), 3);

    array[0] = 6;
    array[1] = 7;
    array[2] = 8;

    EXPECT_EQ(array[0], 6);
    EXPECT_EQ(array[1], 7);
    EXPECT_EQ(array[2], 8);
    EXPECT_EQ(array[3], 8);
    EXPECT_EQ(array[-1], 6);

    for(Array<int16_t, 3>::type& n : array) {
        n = 0;
    }

    EXPECT_EQ(array[0], 0);
    EXPECT_EQ(array[1], 0);
    EXPECT_EQ(array[2], 0);
}

TEST(Container, PriorityQueue) {
    PriorityQueue<int8_t, 5> pq;

    EXPECT_TRUE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 0);

    pq.push(4);
    pq.push(1);
    pq.push(2);

    EXPECT_FALSE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 3);

    pq.push(6);
    pq.push(3);

    EXPECT_FALSE(pq.empty());
    EXPECT_TRUE(pq.full());
    EXPECT_EQ(pq.size(), 5);

    int8_t n;

    EXPECT_TRUE(pq.pop(&n));
    EXPECT_EQ(n, 1);

    EXPECT_TRUE(pq.pop(&n));
    EXPECT_EQ(n, 2);

    EXPECT_FALSE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 3);

    EXPECT_TRUE(pq.pop(&n));
    EXPECT_EQ(n, 3);

    EXPECT_TRUE(pq.pop(&n));
    EXPECT_EQ(n, 4);

    EXPECT_TRUE(pq.pop(&n));
    EXPECT_EQ(n, 6);

    EXPECT_TRUE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 0);

    pq.push(4);

    EXPECT_FALSE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 1);
}

template <typename Clock, typename cout_t, typename cin_t>
struct Taskk : Task<Clock> {
    cout_t& cout;
    cin_t& cin;

    Taskk(cout_t& cout, cin_t& cin) : cout(cout), cin(cin) {
    }
};

TEST(A, A) {
    typedef Queue<char, 10> cout_t;
    typedef Queue<char, 10> cin_t;
    cout_t cout;
    cin_t cin;

    typedef Clock<TimerCounter1, 16000000> Clock;

    Taskk<Clock, cout_t, cin_t> t(cout, cin);
}
