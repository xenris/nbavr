/// [[Index]]

/// # {{Tuple}}

#ifndef NBOS_TUPLE_HPP
#define NBOS_TUPLE_HPP

/// struct Tuple<class A, class B\>
template <class A, class B>
struct Tuple {
    A a;
    B b;

    /// #### Tuple(A a, B b)
    Tuple(A a, B b) : a(a), b(b) {}
};

/// struct Tuple3<class A, class B, class C\>
template <class A, class B, class C>
struct Tuple3 {
    A a;
    B b;
    C c;

    /// #### Tuple3(A a, B b, C c)
    Tuple3(A a, B b, C c) : a(a), b(b), c(c) {}
};

/// struct Tuple4<class A, class B, class C, class D\>
template <class A, class B, class C, class D>
struct Tuple4 {
    A a;
    B b;
    C c;
    D d;

    /// #### Tuple4(A a, B b, C c, D d)
    Tuple4(A a, B b, C c, D d) : a(a), b(b), c(c), d(d) {}
};

/// struct Tuple5<class A, class B, class C, class D, class E\>
template <class A, class B, class C, class D, class E>
struct Tuple5 {
    A a;
    B b;
    C c;
    D d;
    E e;

    /// #### Tuple5(A a, B b, C c, D d, E e)
    Tuple5(A a, B b, C c, D d, E e) : a(a), b(b), c(c), d(d), e(e) {}
};

/// struct Tuple6<class A, class B, class C, class D, class E, class F\>
template <class A, class B, class C, class D, class E, class F>
struct Tuple6 {
    A a;
    B b;
    C c;
    D d;
    E e;
    F f;

    /// #### Tuple6(A a, B b, C c, D d, E e, F f)
    Tuple6(A a, B b, C c, D d, E e, F f) : a(a), b(b), c(c), d(d), e(e), f(f) {}
};

#endif
