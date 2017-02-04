#ifndef NBAVR_PORT_HPP
#define NBAVR_PORT_HPP

#ifdef CHIP_PORT_A_OUTPUT_REG
    #define PORT A
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_B_OUTPUT_REG
    #define PORT B
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_C_OUTPUT_REG
    #define PORT C
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_D_OUTPUT_REG
    #define PORT D
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_E_OUTPUT_REG
    #define PORT E
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_F_OUTPUT_REG
    #define PORT F
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_G_OUTPUT_REG
    #define PORT G
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_H_OUTPUT_REG
    #define PORT H
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_I_OUTPUT_REG
    #define PORT I
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_J_OUTPUT_REG
    #define PORT J
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_K_OUTPUT_REG
    #define PORT K
    #include "port.tpp"
    #undef PORT
#endif

#ifdef CHIP_PORT_L_OUTPUT_REG
    #define PORT L
    #include "port.tpp"
    #undef PORT
#endif

#endif
