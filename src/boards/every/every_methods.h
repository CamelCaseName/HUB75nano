#ifndef HUB75NANO_EVERY_METHODS_H
#define HUB75NANO_EVERY_METHODS_H

#include "every.h"
#include "every_pin_helpers.h"
#include "../method_helper.h"
#include "../../Settings.h"

// bulk pin access color, only good if pins are in right order
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_set_color(uint8_t value)
{
#if RF == A3 and GF == A2 and BF == A1 and RS == A0 and GS == A6 and BS == A7
    // set 6 color pins and keep the rx tx pins as are
    // we need to shift two as the reads are optimized for nano and expect the 0 and 1 to be rx/tx
    ((PORT_t *)&PORTA + PORTD_OFFSET)->OUTSET = value >> 2;
    ((PORT_t *)&PORTA + PORTD_OFFSET)->OUTCLR = (~(value >> 2)) & 63;

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
#ifdef PANEL_3_PIN_ROWS

    if (PANEL_ROW_VAR == 0)
    {
        HIGH_RC;
        HIGH_RA;
        CLEAR_RA;
        CLEAR_RC;
    }
    else
    {
        HIGH_RA;
        CLEAR_RA;
    }
#else
// row pin check
#if PANEL_Y > 32
#if RA == 11 and RB == 12 and RC == 13 and RD == 8 and RE == 2
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTSET = PANEL_ROW_VAR;
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTCLR = (~PANEL_ROW_VAR) & 31;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 16
#if RA == 11 and RB == 12 and RC == 13 and RD == 8
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTSET = PANEL_ROW_VAR;
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTCLR = (~PANEL_ROW_VAR) & 15;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 8
#if RA == 11 and RB == 12 and RC == 13
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTSET = PANEL_ROW_VAR;
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTCLR = (~PANEL_ROW_VAR) & 7;
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 4
#if RA == 11 and RB == 12
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTSET = PANEL_ROW_VAR;
    ((PORT_t *)&PORTA + PORTE_OFFSET)->OUTCLR = (~PANEL_ROW_VAR) & 3;
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
#endif
    PANEL_ADVANCE_ROW;
}

#endif // HUB75NANO_EVERY_METHODS_H
