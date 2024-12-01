#ifndef HUB75NANO_NANO_METHODS_H
#define HUB75NANO_NANO_METHODS_H

#include "nano.h"
#include "../method_helper.h"
#include "../../Settings.h"

// bulk pin access color, only good if pins are in right order
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_set_color(uint8_t value)
{
#if RF == 14 and GF == 15 and BF == 16 and RS == 17 and GS == 18 and BS == 19
    // set 6 color pins and keep the rx tx pins as are
    PORTC = value;
#else
    __asm__ __volatile__("sbrc	%0, 0" ::"r"(value));
    high_pin(PORT_RF, PORT_PIN_RF);
    __asm__ __volatile__("sbrs	%0, 0" ::"r"(value));
    clear_pin(PORT_RF, PORT_PIN_RF);
    __asm__ __volatile__("sbrc	%0, 1" ::"r"(value));
    high_pin(PORT_GF, PORT_PIN_GF);
    __asm__ __volatile__("sbrs	%0, 1" ::"r"(value));
    clear_pin(PORT_GF, PORT_PIN_GF);
    __asm__ __volatile__("sbrc	%0, 2" ::"r"(value));
    high_pin(PORT_BF, PORT_PIN_BF);
    __asm__ __volatile__("sbrs	%0, 2" ::"r"(value));
    clear_pin(PORT_BF, PORT_PIN_BF);
    __asm__ __volatile__("sbrc	%0, 3" ::"r"(value));
    high_pin(PORT_RS, PORT_PIN_RS);
    __asm__ __volatile__("sbrs	%0, 3" ::"r"(value));
    clear_pin(PORT_RS, PORT_PIN_RS);
    __asm__ __volatile__("sbrc	%0, 4" ::"r"(value));
    high_pin(PORT_GS, PORT_PIN_GS);
    __asm__ __volatile__("sbrs	%0, 4" ::"r"(value));
    clear_pin(PORT_GS, PORT_PIN_GS);
    __asm__ __volatile__("sbrc	%0, 5" ::"r"(value));
    high_pin(PORT_BS, PORT_PIN_BS);
    __asm__ __volatile__("sbrs	%0, 5" ::"r"(value));
    clear_pin(PORT_BS, PORT_PIN_BS);
#endif
}

#ifndef PANEL_ROW_VAR
uint8_t _row = 0;
#define PANEL_ROW_VAR _row
#endif

// we can only set the _row fast when the pins are in order
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_stepRow()
{
#ifdef PANEL_3_PIN_ROWS

    if (PANEL_ROW_VAR == 0)
    {
        high_pin(PORT_RC, PORT_PIN_RC);
        high_pin(PORT_RA, PORT_PIN_RA);
        clear_pin(PORT_RA, PORT_PIN_RA);
        clear_pin(PORT_RC, PORT_PIN_RC);
    }
    else
    {
        high_pin(PORT_RA, PORT_PIN_RA);
        clear_pin(PORT_RA, PORT_PIN_RA);
    }
#else
// row pin check
#if PANEL_Y > 32
#if RA == 2 and RB == 3 and RC == 4 and RD == 5 and RE == 6
    PORTD = (PANEL_ROW_VAR << 2) | PORTD & (uint8_t)0b11000001;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 16
#if RA == 2 and RB == 3 and RC == 4 and RD == 5
    PORTD = (PANEL_ROW_VAR << 2) | PORTD & (uint8_t)0b11000011;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 8
#if RA == 2 and RB == 3 and RC == 4
    PORTD = (PANEL_ROW_VAR << 2) | PORTD & (uint8_t)0b11000111;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 4
#if RA == 2 and RB == 3
    PORTD = (PANEL_ROW_VAR << 2) | PORTD & (uint8_t)0b11001111;
#else
#define PANEL_ROW_PINS_OOO
#endif
#endif
#endif
#endif
#endif
#ifdef PANEL_ROW_PINS_OOO
    __asm__ __volatile__("sbrc	%0, 0" ::"r"(PANEL_ROW_VAR));
    high_pin(PORT_RA, PORT_PIN_RA);
    __asm__ __volatile__("sbrs	%0, 0" ::"r"(PANEL_ROW_VAR));
    clear_pin(PORT_RA, PORT_PIN_RA);
    __asm__ __volatile__("sbrc	%0, 1" ::"r"(PANEL_ROW_VAR));
    high_pin(PORT_RB, PORT_PIN_RB);
    __asm__ __volatile__("sbrs	%0, 1" ::"r"(PANEL_ROW_VAR));
    clear_pin(PORT_RB, PORT_PIN_RB);
#if PANEL_Y > 8
    __asm__ __volatile__("sbrc	%0, 2" ::"r"(PANEL_ROW_VAR));
    high_pin(PORT_RC, PORT_PIN_RC);
    __asm__ __volatile__("sbrs	%0, 2" ::"r"(PANEL_ROW_VAR));
    clear_pin(PORT_RC, PORT_PIN_RC);
#endif
#if PANEL_Y > 16
    __asm__ __volatile__("sbrc	%0, 3" ::"r"(PANEL_ROW_VAR));
    high_pin(PORT_RD, PORT_PIN_RD);
    __asm__ __volatile__("sbrs	%0, 3" ::"r"(PANEL_ROW_VAR));
    clear_pin(PORT_RD, PORT_PIN_RD);
#endif
#if PANEL_Y > 32
    __asm__ __volatile__("sbrc	%0, 4" ::"r"(PANEL_ROW_VAR));
    high_pin(PORT_RE, PORT_PIN_RE);
    __asm__ __volatile__("sbrs	%0, 4" ::"r"(PANEL_ROW_VAR));
    clear_pin(PORT_RE, PORT_PIN_RE);
#endif
#endif
#endif
    PANEL_ADVANCE_ROW;
}

#endif // HUB75NANO_NANO_METHODS_H
