#ifndef HUB75NANO_LED_H
#define HUB75NANO_LED_H

#pragma region led_struct_definition
#ifdef PANEL_BIG
#include "2bit_LED.h"
#define LED LED_long
#else
#include "1bit_LED.h"
#define LED LED_short
#endif

#pragma endregion // led_struct_definition

#endif // HUB75NANO_LED_H