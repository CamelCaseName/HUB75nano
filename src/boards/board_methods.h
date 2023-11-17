#ifndef HUB75NANO_BOARD_METHODS_h
#define HUB75NANO_BOARD_METHODS_H

#ifndef ARDUINO_AVR_NANO
#ifndef ARDUINO_AVR_UNO
#error "This library only supports the Arduino nano and Uno, so the atm368p with 2kb sram, 1kb eeprom and 32kb flash. For other chips/boards, please see the internet or try to adapt this library here, but no guarantees"
#else
#include "boards/uno_methods.h"
#endif
#else
#include "boards/nano/nano_methods.h"
#endif

#endif // HUB75NANO_BOARD_METHODS