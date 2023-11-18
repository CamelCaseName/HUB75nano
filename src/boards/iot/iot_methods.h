#ifndef HUB75NANO_IOT_METHODS_H
#define HUB75NANO_IOT_METHODS_H

#include "iot.h"
#include <port.h>

// bulk pin access color, only good if pins are in right order
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_set_color(uint8_t value)
{
#if RF == PA16 and GF == PA17 and BF == PA18 and RS == PA19 and GS == PA20 and BS == PA21
    // set 6 color pins and keep the rx tx pins as are
    // todo
    PORT->Group[port_from_pin(RF)].OUTSET.reg = value << bit_from_pin(RF);
#else
    PORT->Group[port_from_pin(RF)].OUTSET.reg = (value & 1) << bit_from_pin(RF);
    PORT->Group[port_from_pin(GF)].OUTSET.reg = ((value >> 1) & 1) << bit_from_pin(GF);
    PORT->Group[port_from_pin(BF)].OUTSET.reg = ((value >> 2) & 1) << bit_from_pin(BF);
    PORT->Group[port_from_pin(RS)].OUTSET.reg = ((value >> 3) & 1) << bit_from_pin(RS);
    PORT->Group[port_from_pin(GS)].OUTSET.reg = ((value >> 4) & 1) << bit_from_pin(GS);
    PORT->Group[port_from_pin(BS)].OUTSET.reg = ((value >> 5) & 1) << bit_from_pin(BS);
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

#if RA == PA03 and RB == PA04 and RC == PA05 and RD == PA06
    // set the 4 _row pins at once
    // todo
    PORT->Group[port_from_pin(RA)].OUTSET.reg = PANEL_ROW_VAR << bit_from_pin(RA);
#else
    PORT->Group[port_from_pin(RA)].OUTSET.reg = (PANEL_ROW_VAR & 1) << bit_from_pin(RA);
    PORT->Group[port_from_pin(RB)].OUTSET.reg = ((PANEL_ROW_VAR >> 1) & 1) << bit_from_pin(RB);
    PORT->Group[port_from_pin(RC)].OUTSET.reg = ((PANEL_ROW_VAR >> 2) & 1) << bit_from_pin(RC);
    PORT->Group[port_from_pin(RD)].OUTSET.reg = ((PANEL_ROW_VAR >> 3) & 1) << bit_from_pin(RD);
#endif
    PANEL_ROW_VAR = (PANEL_ROW_VAR + 1) & (uint8_t)31;
}

#endif // HUB75NANO_IOT_METHODS_H