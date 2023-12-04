#ifndef HUB75NANO_UNO_R4_METHODS_H
#define HUB75NANO_UNO_R4_METHODS_H

#include "uno_r4.h"
#include "uno_r4_pin_helpers.h"
#include "../method_helper.h"
#include "../../Settings.h"

// bulk pin access color, only good if pins are in right order
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_set_color(uint8_t value)
{
#if RF == A5 and GF == A4 and BF == 5 and RS == 4 and GS == 3 and BS == 2
    // set 6 color pins and keep the rx tx pins as are
    // we need to shift two as the reads are optimized for nano and expect the 0 and 1 to be rx/tx
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RF))].PCNTR3.POSR = value >> 2;
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RF))].PCNTR3.PORR = (~(value >> 2)) & 63;
#else
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RF))].PCNTR3.POSR = (value & 1) << bit_from_pin(arduino_pin_to_avr_pin(RF));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RF))].PCNTR3.PORR = ((~value) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RF));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(GF))].PCNTR3.POSR = ((value >> 1) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GF));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(GF))].PCNTR3.PORR = ((~(value >> 1)) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GF));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(BF))].PCNTR3.POSR = ((value >> 2) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BF));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(BF))].PCNTR3.PORR = ((~(value >> 2)) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BF));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RS))].PCNTR3.POSR = ((value >> 3) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RS));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RS))].PCNTR3.PORR = ((~(value >> 3)) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RS));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(GS))].PCNTR3.POSR = ((value >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GS));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(GS))].PCNTR3.PORR = ((~(value >> 4)) & 1) << bit_from_pin(arduino_pin_to_avr_pin(GS));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(BS))].PCNTR3.POSR = ((value >> 5) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BS));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(BS))].PCNTR3.PORR = ((~(value >> 5)) & 1) << bit_from_pin(arduino_pin_to_avr_pin(BS));
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
#if RA == 11 and RB == 12 and RC == 13 and RD == 10 and RE == 8
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.POSR = (PANEL_ROW_VAR & 15) << bit_from_pin(arduino_pin_to_avr_pin(RA));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.PORR = ((~PANEL_ROW_VAR) & 15) << bit_from_pin(arduino_pin_to_avr_pin(RA));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RE))].PCNTR3.POSR = ((PANEL_ROW_VAR >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RE));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RE))].PCNTR3.PORR = (((~PANEL_ROW_VAR) >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RE));
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 16
#if RA == 11 and RB == 12 and RC == 13 and RD == 10
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.POSR = PANEL_ROW_VAR << bit_from_pin(arduino_pin_to_avr_pin(RA));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.PORR = ((~PANEL_ROW_VAR) & 15) << bit_from_pin(arduino_pin_to_avr_pin(RA));
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 8
#if RA == 11 and RB == 12 and RC == 13
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.POSR = PANEL_ROW_VAR << bit_from_pin(arduino_pin_to_avr_pin(RA));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.PORR = ((~PANEL_ROW_VAR) & 7) << bit_from_pin(arduino_pin_to_avr_pin(RA));
#else
#define PANEL_ROW_PINS_OOO
#endif
#else
#if PANEL_Y > 4
#if RA == 11 and RB == 12
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.POSR = PANEL_ROW_VAR << bit_from_pin(arduino_pin_to_avr_pin(RA));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.PORR = ((~PANEL_ROW_VAR) & 3) << bit_from_pin(arduino_pin_to_avr_pin(RA));
#else
#define PANEL_ROW_PINS_OOO
#endif
#endif
#endif
#endif
#endif
#ifdef PANEL_ROW_PINS_OOO
    uint8_t invertedRow = (~PANEL_ROW_VAR) & ((PANEL_Y / 2) - 1);
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.POSR = (PANEL_ROW_VAR & 1) << bit_from_pin(arduino_pin_to_avr_pin(RA));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RA))].PCNTR3.PORR = (invertedRow & 1) << bit_from_pin(arduino_pin_to_avr_pin(RA));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RB))].PCNTR3.POSR = ((PANEL_ROW_VAR >> 1) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RB));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RB))].PCNTR3.PORR = ((invertedRow >> 1) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RB));
#if PANEL_Y > 8
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RC))].PCNTR3.POSR = ((PANEL_ROW_VAR >> 2) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RC));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RC))].PCNTR3.PORR = ((invertedRow >> 2) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RC));
#endif
#if PANEL_Y > 16
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RD))].PCNTR3.POSR = ((PANEL_ROW_VAR >> 3) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RD));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RD))].PCNTR3.PORR = ((invertedRow >> 3) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RD));
#endif
#if PANEL_Y > 32
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RE))].PCNTR3.POSR = ((PANEL_ROW_VAR >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RE));
    ((PORTS *)IO_PORT_START)->port[port_from_pin(arduino_pin_to_avr_pin(RE))].PCNTR3.PORR = ((invertedRow >> 4) & 1) << bit_from_pin(arduino_pin_to_avr_pin(RE));
#endif
#endif
    PANEL_ADVANCE_ROW;
}

#endif // HUB75NANO_UNO_R4_METHODS_H
