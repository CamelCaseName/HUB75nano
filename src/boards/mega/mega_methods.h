#ifndef HUB75NANO_MEGA_METHODS_H
#define HUB75NANO_MEGA_METHODS_H

#include "mega.h"
#include "mega_pin_helpers.h"
#include "../method_helper.h"
#include "../../Settings.h"

// bulk pin access color, only good if pins are in right order
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_set_color(uint8_t value)
{
#if RF == 47 and GF == 46 and BF == 45 and RS == 44 and GS == 43 and BS == 42
    // pins are chosen carefully to allow for this
    PORTL = value;
#else
    __asm__ __volatile__("sbrc	%0, 2" ::"r"(value));
    high_pin(RF);
    __asm__ __volatile__("sbrs	%0, 2" ::"r"(value));
    clear_pin(RF);
    __asm__ __volatile__("sbrc	%0, 3" ::"r"(value));
    high_pin(GF);
    __asm__ __volatile__("sbrs	%0, 3" ::"r"(value));
    clear_pin(GF);
    __asm__ __volatile__("sbrc	%0, 4" ::"r"(value));
    high_pin(BF);
    __asm__ __volatile__("sbrs	%0, 4" ::"r"(value));
    clear_pin(BF);
    __asm__ __volatile__("sbrc	%0, 5" ::"r"(value));
    high_pin(RS);
    __asm__ __volatile__("sbrs	%0, 5" ::"r"(value));
    clear_pin(RS);
    __asm__ __volatile__("sbrc	%0, 6" ::"r"(value));
    high_pin(GS);
    __asm__ __volatile__("sbrs	%0, 6" ::"r"(value));
    clear_pin(GS);
    __asm__ __volatile__("sbrc	%0, 7" ::"r"(value));
    high_pin(BS);
    __asm__ __volatile__("sbrs	%0, 7" ::"r"(value));
    clear_pin(BS);
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
// row pin check
#if PANEL_Y > 32
#if RA == 22 and RB == 23 and RC == 24 and RD == 25 and RE == 26
    PORTA = PANEL_ROW_VAR | PORTC & (uint8_t)224;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 16
#if RA == 22 and RB == 23 and RC == 24 and RD == 25
    PORTA = PANEL_ROW_VAR | PORTC & (uint8_t)240;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 8
#if RA == 22 and RB == 23 and RC == 24
    PORTA = PANEL_ROW_VAR | PORTC & (uint8_t)248;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 4
#if RA == 22 and RB == 23
    PORTA = PANEL_ROW_VAR | PORTC & (uint8_t)252;
#else
#define PANEL_ROW_PINS_OOO
#endif
#endif
#endif
#endif
#endif
#ifdef PANEL_ROW_PINS_OOO
    __asm__ __volatile__("sbrc	%0, 0" ::"r"(PANEL_ROW_VAR));
    high_pin(RA);
    __asm__ __volatile__("sbrs	%0, 0" ::"r"(PANEL_ROW_VAR));
    clear_pin(RA);
    __asm__ __volatile__("sbrc	%0, 1" ::"r"(PANEL_ROW_VAR));
    high_pin(RB);
    __asm__ __volatile__("sbrs	%0, 1" ::"r"(PANEL_ROW_VAR));
    clear_pin(RB);
#if PANEL_Y > 8
    __asm__ __volatile__("sbrc	%0, 2" ::"r"(PANEL_ROW_VAR));
    high_pin(RC);
    __asm__ __volatile__("sbrs	%0, 2" ::"r"(PANEL_ROW_VAR));
    clear_pin(RC);
#endif
#if PANEL_Y > 16
    __asm__ __volatile__("sbrc	%0, 3" ::"r"(PANEL_ROW_VAR));
    high_pin(RD);
    __asm__ __volatile__("sbrs	%0, 3" ::"r"(PANEL_ROW_VAR));
    clear_pin(RD);
#endif
#if PANEL_Y > 32
    __asm__ __volatile__("sbrc	%0, 4" ::"r"(PANEL_ROW_VAR));
    high_pin(RE);
    __asm__ __volatile__("sbrs	%0, 4" ::"r"(PANEL_ROW_VAR));
    clear_pin(RE);
#endif
#endif
    PANEL_ADVANCE_ROW;
}

#endif // HUB75NANO_MEGA_METHODS_H
