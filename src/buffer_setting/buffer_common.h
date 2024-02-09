#ifndef HUB75NANO_BUFFER_COMMON_H
#define HUB75NANO_BUFFER_COMMON_H

#include "../structs/LED.h"
#include "../structs/Color.h"
#include "../boards/board.h"
#include "../boards/board_methods.h"

#pragma region buffer_definition
#ifndef PANEL_NO_BUFFER
#ifdef PANEL_HUB75E
// int8_t update_needed = 1;
#endif
#ifdef PANEL_BIG
LED buffer[PANEL_BUFFERSIZE]; // uses 768 bytes on max size display with 1 bit, 1536 bytes with 2 bits of depth
#else
#ifdef PANEL_FLASH
PGM_VOID_P buffer = 0;
#else
LED buffer[PANEL_BUFFERSIZE];
#endif
#endif
#else
LED buffer[0];
#endif
#pragma endregion // buffer_definition

#endif // HUB75NANO_BUFFER_COMMON_H