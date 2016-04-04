#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "util.h"

#define timerN(A) CONCAT(timer,TIMER_ID,A)
#define TimerN(A) CONCAT(Timer,TIMER_ID,A)
#define TIMER_N(A) CONCAT(CHIP_TIMER_,TIMER_ID,A)

typedef void (*TimerCallback)(void);

#if TIMER_N(_OUTPUT_MODE)
typedef enum {
    TimerN(OutputModeDisconnected) = TIMER_N(_OUTPUT_MODE_DISCONNECTED_ID),
    TimerN(OutputModeToggle) = TIMER_N(_OUTPUT_MODE_TOGGLE_ID),
    TimerN(OutputModeClear) = TIMER_N(_OUTPUT_MODE_CLEAR_ID),
    TimerN(OutputModeSet) = TIMER_N(_OUTPUT_MODE_SET_ID),
} TimerN(OutputMode);
#endif

#if TIMER_N(_WAVEFORM)
typedef enum {
    TimerN(WaveformNormal) = TIMER_N(_WAVEFORM_NORMAL_ID),
    TimerN(WaveformPWM) = TIMER_N(_WAVEFORM_PWM_PHASE_CORRECT_ID),
    TimerN(WaveformCTCOCRA) = TIMER_N(_WAVEFORM_CTC_OCRA_ID),
    TimerN(WaveformFastPWM) = TIMER_N(_WAVEFORM_FAST_PWM_ID),
    #if TIMER_N(_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID)
    TimerN(WaveformPWMOCRA) = TIMER_N(_WAVEFORM_PWM_PHASE_CORRECT_OCRA_ID),
    #endif
    #if TIMER_N(_WAVEFORM_FAST_PWM_OCRA_ID)
    TimerN(WaveformFastPWMOCRA) = TIMER_N(_WAVEFORM_FAST_PWM_OCRA_ID),
    #endif
} TimerN(Waveform);
#endif

typedef enum {
    TimerN(ClockNone) = TIMER_N(_CLOCK_NONE_ID),
    TimerN(Clock1) = TIMER_N(_CLOCK_1_ID),
    TimerN(Clock8) = TIMER_N(_CLOCK_8_ID),
    #if TIMER_N(_CLOCK_32_ID)
    TimerN(Clock32) = TIMER_N(_CLOCK_32_ID),
    #endif
    TimerN(Clock64) = TIMER_N(_CLOCK_64_ID),
    #if TIMER_N(_CLOCK_128_ID)
    TimerN(Clock128) = TIMER_N(_CLOCK_128_ID),
    #endif
    TimerN(Clock256) = TIMER_N(_CLOCK_256_ID),
    TimerN(Clock1024) = TIMER_N(_CLOCK_1024_ID),
    #if TIMER_N(_CLOCK_EXT_FALLING_ID)
    TimerN(ClockExtFalling) = TIMER_N(_CLOCK_EXT_FALLING_ID),
    #endif
    #if TIMER_N(_CLOCK_EXT_RISING_ID)
    TimerN(ClockExtRising) = TIMER_N(_CLOCK_EXT_RISING_ID),
    #endif
} TimerN(Clock);

typedef struct {
    #if TIMER_N(_WAVEFORM)
    TimerN(Waveform) waveform;
    #endif
    TimerN(Clock) clock;
    TIMER_N(_TYPE) timerRegister;
    #if TIMER_N(_OUTPUT_A)
    TIMER_N(_TYPE) outputARegister;
    bool outputAIntEnable;
    TimerN(OutputMode) outputAMode;
    TimerCallback outputAIntCallback;
    #endif
    #if TIMER_N(_OUTPUT_B)
    TIMER_N(_TYPE) outputBRegister;
    bool outputBIntEnable;
    TimerN(OutputMode) outputBMode;
    TimerCallback outputBIntCallback;
    #endif
    bool overflowIntEnable;
    TimerCallback overflowIntCallback;
} TimerN(Config);

void timerN()(TimerN(Config) config) __attribute__((always_inline));

void timerN(SetTimerRegister)(TIMER_N(_TYPE) v) __attribute__((always_inline));
TIMER_N(_TYPE) timerN(GetTimerRegister)() __attribute__((always_inline));

#if TIMER_N(_OUTPUT_A)
void timerN(SetOutputCompareA)(TIMER_N(_TYPE) v) __attribute__((always_inline));
TIMER_N(_TYPE) timerN(GetOutputCompareA)() __attribute__((always_inline));
void timerN(OutputCompareMatchAIntEnable)(bool b) __attribute__((always_inline));
bool timerN(OutputCompareMatchAFlag)() __attribute__((always_inline));
void timerN(ClearOutputCompareMatchAFlag)() __attribute__((always_inline));
#endif

#if TIMER_N(_OUTPUT_B)
void timerN(SetOutputCompareB)(TIMER_N(_TYPE) v) __attribute__((always_inline));
TIMER_N(_TYPE) timerN(GetOutputCompareB)() __attribute__((always_inline));
void timerN(OutputCompareMatchBIntEnable)(bool b) __attribute__((always_inline));
bool timerN(OutputCompareMatchBFlag)() __attribute__((always_inline));
void timerN(ClearOutputCompareMatchBFlag)() __attribute__((always_inline));
#endif

void timerN(OverflowIntEnable)(bool b) __attribute__((always_inline));
bool timerN(OverflowFlag)() __attribute__((always_inline));
void timerN(ClearOverflowFlag)() __attribute__((always_inline));
