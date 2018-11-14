#define __atmega328p__

#define RECORD_ID "nbos"

#include "test.hpp"

TEST(Clock, millisToTicks) {
    EXPECT_EQ((Clock<Timer1, 1000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Clock<Timer1, 1000000>::millisToTicks(1)), 16);
    EXPECT_EQ((Clock<Timer1, 1000000>::millisToTicks(1000)), 15625);
    EXPECT_EQ((Clock<Timer1, 1000000>::millisToTicks(1001)), 15641);
    EXPECT_EQ((Clock<Timer1, 1000000>::millisToTicks(16000000)), 250000000);
    EXPECT_EQ((Clock<Timer1, 16000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Clock<Timer1, 16000000>::millisToTicks(1)), 250);
    EXPECT_EQ((Clock<Timer1, 16000000>::millisToTicks(1000)), 250000);
    EXPECT_EQ((Clock<Timer1, 16000000>::millisToTicks(16000000)), 4000000000);
    EXPECT_EQ((Clock<Timer1, 20000000>::millisToTicks(0)), 0);
    EXPECT_EQ((Clock<Timer1, 20000000>::millisToTicks(1)), 313);
    EXPECT_EQ((Clock<Timer1, 20000000>::millisToTicks(1000)), 312500);
}

TEST(Clock, ticksToMillis) {
    EXPECT_EQ((Clock<Timer1, 1000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Clock<Timer1, 1000000>::ticksToMillis(15)), 1);
    EXPECT_EQ((Clock<Timer1, 1000000>::ticksToMillis(250)), 16);
    EXPECT_EQ((Clock<Timer1, 16000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Clock<Timer1, 16000000>::ticksToMillis(200)), 1);
    EXPECT_EQ((Clock<Timer1, 16000000>::ticksToMillis(4000000000)), 16000000);
    EXPECT_EQ((Clock<Timer1, 20000000>::ticksToMillis(0)), 0);
    EXPECT_EQ((Clock<Timer1, 20000000>::ticksToMillis(316)), 1);
    EXPECT_EQ((Clock<Timer1, 20000000>::ticksToMillis(312500)), 1000);
    EXPECT_EQ((Clock<Timer1, 20000000>::ticksToMillis(312500)), 1000);
}

TEST(Clock, delayedCall) {
    typedef Clock<Timer1, 16000000> Clock;

    Clock::delayedCall((Callback<void>)nullptr, (void*)nullptr, Clock::millisToTicks(3000));

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
    Char str[8];

    strcpy((Char::T*)str, "");
    reverse(str, 0);
    EXPECT_STREQ((Char::T*)str, "");

    strcpy((Char::T*)str, "a");
    reverse(str, 1);
    EXPECT_STREQ((Char::T*)str, "a");

    strcpy((Char::T*)str, "ab");
    reverse(str, 2);
    EXPECT_STREQ((Char::T*)str, "ba");

    strcpy((Char::T*)str, "abc");
    reverse(str, 3);
    EXPECT_STREQ((Char::T*)str, "cba");

    strcpy((Char::T*)str, "abc");
    reverse(str, 2);
    EXPECT_STREQ((Char::T*)str, "bac");
}

TEST(Print, itoa) {
    Char str[64];

    itoa(str, Int8(0));
    EXPECT_STREQ((Char::T*)str, "0");

    itoa(str, Word8(147));
    EXPECT_STREQ((Char::T*)str, "147");

    itoa(str, Int16(1476));
    EXPECT_STREQ((Char::T*)str, "1476");

    itoa(str, Int16(-1476));
    EXPECT_STREQ((Char::T*)str, "-1476");

    itoa<Int16, 2>(str, Int16(764));
    EXPECT_STREQ((Char::T*)str, "1011111100");

    itoa<Int16, 16>(str, Int16(847));
    EXPECT_STREQ((Char::T*)str, "34F");

    itoa<Int16, 16>(str, Int16(-847));
    EXPECT_STREQ((Char::T*)str, "-34F");

    itoa<Int32, 36>(str, Int32(36));
    EXPECT_STREQ((Char::T*)str, "10");

    itoa(str, Int32(65535));
    EXPECT_STREQ((Char::T*)str, "65535");

    itoa(str, Word32(65535));
    EXPECT_STREQ((Char::T*)str, "65535");

    itoa(str, Int32(32768));
    EXPECT_STREQ((Char::T*)str, "32768");
}

TEST(Container, Queue) {
    Queue<Int16, 3> queue;

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

    Optional<Int16> n;
    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(*n, 2);

    EXPECT_EQ(queue.full(), false);

    EXPECT_EQ(queue.push(5), true);
    EXPECT_EQ(queue.size(), 2);

    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(*n, 3);

    EXPECT_EQ(n = queue.pop(), true);
    EXPECT_EQ(queue.size(), 0);
    EXPECT_EQ(*n, 5);

    EXPECT_EQ(queue.empty(), true);

    EXPECT_EQ(n = queue.pop(), false);
    EXPECT_EQ(queue.size(), 0);

    EXPECT_EQ(queue.push(6), true);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.empty(), false);
    queue.clear();
    EXPECT_EQ(queue.empty(), true);

    // Make sure notify callbacks don't interfere.

    Queue<Int16, 3> queueF;
    Queue<Int16, 3> queueG;

    Callback<Char> f = [](Char* c) {
        *c = 'f';
    };

    Callback<Char> g = [](Char* c) {
        *c = 'g';
    };

    Char c = 'a';

    queueF.setCallback(f, &c);
    queueG.setCallback(g, &c);

    EXPECT_EQ(c, 'a');

    queueF.callCallback();

    EXPECT_EQ(c, 'f');

    queueG.callCallback();

    EXPECT_EQ(c, 'g');
}

TEST(Container, Stack) {
    Stack<Int16, 3> stack;

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

    Optional<Int16> n;
    EXPECT_EQ(n = stack.pop(), true);
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(*n, 3);
    EXPECT_EQ(n = stack.pop(), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(*n, 2);

    EXPECT_EQ(stack.full(), false);

    EXPECT_EQ(stack.push(5), true);
    EXPECT_EQ(stack.size(), 2);

    EXPECT_EQ(n = stack.pop(), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(*n, 5);

    EXPECT_EQ(n = stack.pop(), true);
    EXPECT_EQ(stack.size(), 0);
    EXPECT_EQ(*n, 1);

    EXPECT_EQ(stack.empty(), true);

    EXPECT_EQ(n = stack.pop(), false);
    EXPECT_EQ(stack.size(), 0);

    EXPECT_EQ(stack.push(6), true);
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.empty(), false);
    stack.clear();
    EXPECT_EQ(stack.empty(), true);
}

TEST(Container, Array) {
    Array<Int16, 3> array;

    EXPECT_EQ(array.size(), 3);

    array[0] = 6;
    array[1] = 7;
    array[2] = 8;

    EXPECT_EQ(array[0], 6);
    EXPECT_EQ(array[1], 7);
    EXPECT_EQ(array[2], 8);

    for(auto& n : array) {
        n = 0;
    }

    EXPECT_EQ(array[0], 0);
    EXPECT_EQ(array[1], 0);
    EXPECT_EQ(array[2], 0);

    array.fill(3);

    EXPECT_EQ(array[0], 3);
    EXPECT_EQ(array[1], 3);
    EXPECT_EQ(array[2], 3);

    Array<Int16, 3> array2 = array;

    EXPECT_EQ(array2[0], 3);
    EXPECT_EQ(array2[1], 3);
    EXPECT_EQ(array2[2], 3);
}

TEST(Container, PriorityQueue) {
    PriorityQueue<Int8, 5> pq;

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

    Optional<Int8> n;

    EXPECT_TRUE(n = pq.pop());
    EXPECT_EQ(*n, 1);

    EXPECT_TRUE(n = pq.pop());
    EXPECT_EQ(*n, 2);

    EXPECT_FALSE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 3);

    EXPECT_TRUE(n = pq.pop());
    EXPECT_EQ(*n, 3);

    EXPECT_TRUE(n = pq.pop());
    EXPECT_EQ(*n, 4);

    EXPECT_TRUE(n = pq.pop());
    EXPECT_EQ(*n, 6);

    EXPECT_TRUE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 0);

    pq.push(4);

    EXPECT_FALSE(pq.empty());
    EXPECT_FALSE(pq.full());
    EXPECT_EQ(pq.size(), 1);
}

TEST(Container, PriorityQueueMemoryUse) {
    Int a[5] = {};

    PriorityQueue<Int> pq(&a[1], 3);

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    EXPECT_EQ(pq.size(), 3);
    EXPECT_EQ(pq.capacity(), 3);

    EXPECT_EQ(a[0], 0);
    EXPECT_EQ(a[4], 0);
}

TEST(Algorithm, quicksort) {
    Int array1[6];

    array1[0] = 6;
    array1[1] = 8;
    array1[2] = 4;
    array1[3] = 5;
    array1[4] = 1;
    array1[5] = 2;

    quicksort(array1, 6);

    EXPECT_EQ(array1[0], 1);
    EXPECT_EQ(array1[1], 2);
    EXPECT_EQ(array1[2], 4);
    EXPECT_EQ(array1[3], 5);
    EXPECT_EQ(array1[4], 6);
    EXPECT_EQ(array1[5], 8);
}

TEST(Random, Limits) {
    Random r;

    EXPECT_TRUE(r.next<Float>() != r.next<Float>());

    for(Int i = 0; i < 1000; i++) {
        const Float n = r.next<Float>();

        EXPECT_LE(n, 1);
        EXPECT_GE(n, 0);
    }
}

TEST(Type, SafeTypes) {
    Int8 a;
    Int8 b = 5;

    EXPECT_EQ(a + b, 5);

    Int16 c = Int16(b) + 4;

    EXPECT_EQ(c, 9);

    Int16 d = 5;

    d = 1;

    false && (d++ == 0);

    EXPECT_EQ(d, 1);

    Word8 e = 0x30;
    Word16 f = 0x0010;

    Word16 g = Word16(e) | f;

    EXPECT_EQ(g, 0x0030);

    EXPECT_FALSE(IsFloating<decltype(g)>::value);
    EXPECT_TRUE(IsFloating<Float>::value);

    EXPECT_TRUE((IsSame<Float, Float>::value));
    EXPECT_TRUE((IsSame<Int, Int>::value));
    EXPECT_TRUE((IsSame<decltype(g), decltype(f)>::value));
    EXPECT_TRUE((IsSame<decltype(a), decltype(b)>::value));

    EXPECT_FALSE((IsSame<decltype(a), decltype(d)>::value));

    log(Float(5));

    Int h = IsSigned<Int8>::value;

    (void)h;
}

TEST(Type, Optional) {
    Optional<Int> a;

    EXPECT_FALSE(a);

    a = 5;

    EXPECT_TRUE(a);
    EXPECT_EQ(*a, 5);

    a = {};

    EXPECT_FALSE(a);
}

template <typename Clock, typename cout_t, typename cin_t>
struct Taskk : Task<Clock> {
    cout_t& cout;
    cin_t& cin;

    Taskk(cout_t& cout, cin_t& cin) : cout(cout), cin(cin) {
    }
};

TEST(A, A) {
    typedef Queue<Char, 10> cout_t;
    typedef Queue<Char, 10> cin_t;
    cout_t cout;
    cin_t cin;

    typedef Clock<Timer1, 16000000> Clock;

    Taskk<Clock, cout_t, cin_t> t(cout, cin);
}
