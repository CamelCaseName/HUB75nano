#ifndef HUB75NANO_IOT_METHODS_H
#define HUB75NANO_IOT_METHODS_H

#include "iot.h"
#include "../method_helper.h"
#include "../../Settings.h"

// bulk pin access color, only good if pins are in right order
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_set_color(uint8_t value)
{
    uint8_t invertedValue = (~value) & 63;
#if RF == 11 and GF == 13 and BF == 8 and RS == 12 and GS == 9 and BS == 10
    // set 6 color pins and keep the rx tx pins as are
    PORT->Group[0].OUTSET.reg = (value << 16);
    PORT->Group[0].OUTCLR.reg = invertedValue << 16;
#else
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RF))].OUTSET.reg = (value & 1) << bit_from_pin(arduino_pin_to_avr_pin(RF));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RF))].OUTCLR.reg = (invertedValue & 1) << bit_from_pin(arduino_pin_to_avr_pin(RF));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(GF))].OUTSET.reg = ((value >> 1) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GF));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(GF))].OUTCLR.reg = ((invertedValue >> 1) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GF));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(BF))].OUTSET.reg = ((value >> 2) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BF));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(BF))].OUTCLR.reg = ((invertedValue >> 2) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BF));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RS))].OUTSET.reg = ((value >> 3) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RS));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RS))].OUTCLR.reg = ((invertedValue >> 3) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RS));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(GS))].OUTSET.reg = ((value >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GS));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(GS))].OUTCLR.reg = ((invertedValue >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GS));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(BS))].OUTSET.reg = ((value >> 5) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BS));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(BS))].OUTCLR.reg = ((invertedValue >> 5) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BS));
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
#if RA == A0 and RB == 6 and RC == 5 and RD == 7 and RE == 4
    uint8_t adjustedRow = (PANEL_ROW_VAR & 1) | ((PANEL_ROW_VAR & 30) << 1);
    uint8_t invertedRow = (~adjustedRow) & 61;
    // set the 4 _row pins at once
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTSET.reg = adjustedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTCLR.reg = invertedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 16
#if RA == A0 and RB == 6 and RC == 5 and RD == 7
    uint8_t adjustedRow = (PANEL_ROW_VAR & 1) | ((PANEL_ROW_VAR & 14) << 1);
    uint8_t invertedRow = (~adjustedRow) & 29;
    // set the 4 _row pins at once
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTSET.reg = adjustedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTCLR.reg = invertedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 8
#if RA == A0 and RB == 6 and RC == 5
    uint8_t adjustedRow = (PANEL_ROW_VAR & 1) | ((PANEL_ROW_VAR & 6) << 1);
    uint8_t invertedRow = (~adjustedRow) & 9;
    // set the 4 _row pins at once
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTSET.reg = adjustedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTCLR.reg = invertedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 4
#if RA == A0 and RB == 6
    uint8_t adjustedRow = (PANEL_ROW_VAR & 1) | ((PANEL_ROW_VAR & 2) << 1);
    uint8_t invertedRow = (~adjustedRow) & 5;
    // set the 4 _row pins at once
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTSET.reg = adjustedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTCLR.reg = invertedRow << bit_from_pin(arduino_pin_to_avr_pin(RA));
#else
#define PANEL_ROW_PINS_OOO
#endif
#endif
#endif
#endif
#endif
#ifdef PANEL_ROW_PINS_OOO
    uint8_t invertedRow = (~PANEL_ROW_VAR) & ((PANEL_Y / 2) - 1);
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTSET.reg = (PANEL_ROW_VAR & 1) << bit_from_pin(arduino_pin_to_avr_pin(RA));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RA))].OUTCLR.reg = (invertedRow & 1) << bit_from_pin(arduino_pin_to_avr_pin(RA));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RB))].OUTSET.reg = ((PANEL_ROW_VAR >> 1) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RB));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RB))].OUTCLR.reg = ((invertedRow >> 1) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RB));
#if PANEL_Y > 8
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RC))].OUTSET.reg = ((PANEL_ROW_VAR >> 2) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RC));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RC))].OUTCLR.reg = ((invertedRow >> 2) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RC));
#endif
#if PANEL_Y > 16
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RD))].OUTSET.reg = ((PANEL_ROW_VAR >> 3) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RD));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RD))].OUTCLR.reg = ((invertedRow >> 3) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RD));
#endif
#if PANEL_Y > 32
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RE))].OUTSET.reg = ((PANEL_ROW_VAR >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RE));
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(RE))].OUTCLR.reg = ((invertedRow >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RE));
#endif
#endif
#endif
    PANEL_ADVANCE_ROW;
}

#endif // HUB75NANO_IOT_METHODS_H