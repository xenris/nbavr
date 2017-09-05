#ifndef NBAVR_MACROS_HPP
#define NBAVR_MACROS_HPP

/// #### macro CONCAT(...)
/// Concatinates a list of identifiers together.<br>
/// e.g. CONCAT(Foo, Bar) -> FooBar
#define CONCAT(...) GET_CONCAT(__VA_ARGS__, CONCAT8, CONCAT7, CONCAT6, CONCAT5, CONCAT4, CONCAT3, CONCAT2, CONCAT1)(__VA_ARGS__)

#define CONCAT1(A) A
#define CONCAT2(A, B) A ## B
#define CONCAT3(A, B, C) A ## B ## C
#define CONCAT4(A, B, C, D) A ## B ## C ## D
#define CONCAT5(A, B, C, D, E) A ## B ## C ## D ## E
#define CONCAT6(A, B, C, D, E, F) A ## B ## C ## D ## E ## F
#define CONCAT7(A, B, C, D, E, F, G) A ## B ## C ## D ## E ## F ## G
#define CONCAT8(A, B, C, D, E, F, G, H) A ## B ## C ## D ## E ## F ## G ## H

#define GET_CONCAT(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME

#define UNDERLINE(...) GET_UNDERLINE(__VA_ARGS__, UNDERLINE8, UNDERLINE7, UNDERLINE6, UNDERLINE5, UNDERLINE4, UNDERLINE3, UNDERLINE2, UNDERLINE1)(__VA_ARGS__)

#define UNDERLINE1(A) _ ## A ## _
#define UNDERLINE2(A, B) _ ## A ## _ ## B ## _
#define UNDERLINE3(A, B, C) _ ## A ## _ ## B ## _ ## C ## _
#define UNDERLINE4(A, B, C, D) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _
#define UNDERLINE5(A, B, C, D, E) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _
#define UNDERLINE6(A, B, C, D, E, F) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _ ## F ## _
#define UNDERLINE7(A, B, C, D, E, F, G) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _ ## F ## _ ## G ## _
#define UNDERLINE8(A, B, C, D, E, F, G, H) _ ## A ## _ ## B ## _ ## C ## _ ## D ## _ ## E ## _ ## F ## _ ## G ## _ ## H  ## _

#define GET_UNDERLINE(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME

#define TO_LETTER(N) TO_LETTER_(N)
#define TO_LETTER_(N) TO_LETTER_ ## N
#define TO_LETTER_0 A
#define TO_LETTER_1 B
#define TO_LETTER_2 C
#define TO_LETTER_3 D
#define TO_LETTER_4 E
#define TO_LETTER_5 F
#define TO_LETTER_6 G
#define TO_LETTER_7 H
#define TO_LETTER_8 I
#define TO_LETTER_9 J
#define TO_LETTER_10 K
#define TO_LETTER_11 L
#define TO_LETTER_12 M
#define TO_LETTER_13 N
#define TO_LETTER_14 O
#define TO_LETTER_15 P
#define TO_LETTER_16 Q
#define TO_LETTER_17 R
#define TO_LETTER_18 S
#define TO_LETTER_19 T
#define TO_LETTER_20 U
#define TO_LETTER_21 V
#define TO_LETTER_22 W
#define TO_LETTER_23 X
#define TO_LETTER_24 Y
#define TO_LETTER_25 Z

#define INC(N) INC_(N)
#define INC_(N) INC_ ## N
#define INC_0 1
#define INC_1 2
#define INC_2 3
#define INC_3 4
#define INC_4 5
#define INC_5 6
#define INC_6 7
#define INC_7 8
#define INC_8 9
#define INC_9 10
#define INC_10 11
#define INC_11 12
#define INC_12 13
#define INC_13 14
#define INC_14 15
#define INC_15 16
#define INC_16 17
#define INC_17 18
#define INC_18 19
#define INC_19 20
#define INC_20 21
#define INC_21 22
#define INC_22 23
#define INC_23 24
#define INC_24 25
#define INC_25 26
#define INC_26 27
#define INC_27 28
#define INC_28 29
#define INC_29 30
#define INC_30 31
#define INC_31 32
#define INC_32 33
#define INC_33 34
#define INC_34 35
#define INC_35 36
#define INC_36 37
#define INC_37 38
#define INC_38 39
#define INC_39 40

#define DEC(N) DEC_(N)
#define DEC_(N) DEC_ ## N
#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
#define DEC_4 3
#define DEC_5 4
#define DEC_6 5
#define DEC_7 6
#define DEC_8 7
#define DEC_9 8
#define DEC_10 9
#define DEC_11 10
#define DEC_12 11
#define DEC_13 12
#define DEC_14 13
#define DEC_15 14
#define DEC_16 15
#define DEC_17 16
#define DEC_18 17
#define DEC_19 18
#define DEC_20 19
#define DEC_21 20
#define DEC_22 21
#define DEC_23 22
#define DEC_24 23
#define DEC_25 24
#define DEC_26 25
#define DEC_27 26
#define DEC_28 27
#define DEC_29 28
#define DEC_30 29
#define DEC_31 30
#define DEC_32 31
#define DEC_33 32
#define DEC_34 33
#define DEC_35 34
#define DEC_36 35
#define DEC_37 36
#define DEC_38 37
#define DEC_39 38
#define DEC_40 39

// Any number including 0 and "" (nothing) -> true
// Not defined -> false
#define DEFINED(A) DEFINED_(A)
#define DEFINED_(A) A ## 1

#endif
