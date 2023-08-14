
#define PANEL_FLASH // 4 bit flash buffer
#include "Panel.h"

// buffer which contains the image we want to display, important to use the PROGMEM so it is saved to flash!
// generated with https://github.com/CamelCaseName/BMP2HUB75
const unsigned char buffer[4096] PROGMEM = {

    0, 0, 0, 0, 192, 216, 216, 24, 216, 192, 32, 0, 24, 12, 24, 4, 4, 36, 36, 12, 12, 12, 12, 108, 4, 4, 12, 12, 12, 12, 12, 12, 12, 204, 204, 12, 4, 12, 204, 204, 204, 12, 204, 204, 204, 204, 204, 12, 204, 196, 4, 4, 4, 4, 204, 216, 192, 24, 0, 0, 192, 192, 192, 192,
    0, 0, 0, 192, 0, 0, 0, 192, 216, 24, 44, 24, 12, 4, 36, 4, 4, 36, 4, 36, 4, 4, 12, 204, 108, 12, 12, 4, 12, 12, 4, 28, 12, 196, 28, 4, 12, 4, 12, 12, 12, 28, 12, 204, 204, 196, 12, 12, 12, 204, 204, 12, 4, 4, 196, 204, 24, 12, 24, 0, 0, 192, 192, 192,
    0, 0, 0, 0, 0, 0, 24, 0, 0, 8, 56, 12, 24, 4, 4, 4, 4, 4, 4, 4, 4, 12, 4, 4, 204, 228, 12, 28, 4, 4, 28, 4, 4, 12, 4, 4, 4, 4, 4, 4, 12, 4, 28, 28, 204, 12, 4, 12, 12, 12, 12, 4, 12, 4, 4, 4, 4, 12, 12, 24, 24, 0, 192, 0,
    0, 0, 0, 0, 0, 24, 24, 24, 24, 24, 12, 4, 4, 4, 4, 4, 12, 12, 4, 36, 12, 4, 12, 12, 12, 192, 108, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 12, 4, 12, 28, 12, 12, 12, 12, 4, 4, 12, 12, 12, 12, 4, 4, 12, 0, 12, 0, 24, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 24, 4, 4, 4, 36, 36, 12, 12, 44, 36, 4, 12, 12, 12, 0, 12, 192, 100, 12, 12, 4, 12, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 4, 12, 4, 4, 12, 24, 24, 0, 0, 0,
    0, 0, 24, 0, 24, 24, 24, 24, 24, 24, 12, 24, 4, 4, 36, 100, 4, 12, 44, 100, 12, 4, 4, 12, 12, 12, 12, 204, 236, 12, 12, 12, 12, 4, 12, 4, 4, 4, 4, 4, 4, 4, 4, 28, 28, 12, 12, 4, 4, 4, 4, 12, 12, 12, 12, 12, 4, 4, 24, 12, 0, 0, 24, 0,
    0, 0, 0, 24, 24, 24, 24, 24, 12, 12, 12, 4, 4, 4, 36, 36, 12, 4, 12, 36, 4, 4, 4, 0, 12, 4, 12, 12, 192, 108, 0, 12, 12, 28, 12, 12, 12, 12, 4, 4, 4, 4, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 4, 12, 4, 12, 4, 4, 4, 4, 24, 24, 0, 0,
    0, 0, 0, 0, 0, 0, 24, 24, 24, 24, 12, 24, 4, 4, 4, 0, 4, 4, 4, 4, 4, 12, 0, 12, 0, 12, 12, 12, 12, 0, 12, 12, 28, 12, 12, 12, 28, 12, 12, 4, 4, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 4, 12, 4, 4, 4, 4, 4, 0, 12, 24, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 24, 12, 24, 0, 24, 4, 0, 0, 0, 0, 4, 0, 4, 4, 4, 4, 12, 12, 4, 12, 12, 12, 12, 12, 12, 4, 12, 12, 12, 4, 4, 4, 4, 4, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 4, 4, 4, 12, 12, 12, 4, 4, 4, 4, 12, 24,
    0, 0, 0, 0, 0, 0, 0, 0, 24, 24, 4, 4, 4, 0, 0, 0, 96, 100, 0, 32, 120, 100, 4, 4, 4, 0, 4, 0, 28, 12, 12, 12, 0, 12, 0, 12, 4, 12, 24, 24, 0, 24, 12, 4, 12, 12, 12, 4, 12, 12, 12, 4, 4, 12, 12, 12, 12, 4, 12, 4, 4, 24, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 196, 192, 0, 0, 0, 100, 4, 0, 0, 196, 100, 4, 4, 4, 0, 4, 4, 4, 12, 4, 4, 0, 4, 4, 12, 24, 0, 0, 24, 0, 24, 4, 4, 12, 12, 12, 12, 4, 12, 12, 4, 12, 12, 4, 12, 12, 4, 4, 4, 24, 24, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 24, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 196, 96, 4, 4, 4, 4, 4, 4, 4, 4, 12, 4, 12, 24, 24, 0, 0, 0, 24, 0, 12, 4, 12, 4, 12, 12, 12, 4, 4, 12, 4, 12, 12, 12, 4, 12, 4, 4, 12, 24, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 12, 0, 12, 0, 0, 24, 0, 0, 0, 24, 24, 0, 12, 4, 12, 4, 4, 4, 4, 12, 24, 12, 4, 12, 12, 12, 4, 4, 4, 4, 12, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 68, 12, 4, 12, 12, 0, 12, 0, 0, 24, 0, 24, 0, 0, 0, 24, 24, 0, 24, 24, 4, 4, 0, 12, 24, 24, 24, 24, 4, 4, 4, 4, 4, 4, 4, 12, 0,
    0, 0, 0, 0, 64, 96, 0, 64, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 12, 0, 24, 0, 0, 0, 24, 0, 24, 24, 0, 24, 0, 24, 24, 24, 0, 0, 24, 24, 24, 24, 24, 4, 24, 24, 24, 4, 4, 24, 4, 4,
    0, 0, 64, 0, 88, 24, 120, 0, 24, 24, 4, 0, 0, 0, 4, 0, 0, 4, 4, 0, 0, 0, 0, 12, 0, 0, 0, 96, 64, 0, 96, 0, 64, 120, 24, 0, 0, 0, 24, 24, 88, 0, 24, 24, 24, 24, 24, 0, 24, 24, 0, 0, 0, 0, 24, 24, 24, 0, 0, 0, 24, 24, 24, 24,

    208, 208, 208, 208, 24, 0, 0, 128, 36, 24, 24, 56, 0, 52, 36, 44, 12, 108, 12, 20, 20, 20, 52, 244, 204, 220, 220, 212, 212, 204, 204, 204, 140, 28, 60, 156, 204, 220, 28, 12, 12, 212, 20, 20, 12, 20, 20, 148, 20, 44, 204, 204, 204, 204, 20, 0, 24, 192, 216, 152, 16, 24, 24, 16,
    144, 216, 216, 16, 216, 216, 216, 24, 0, 192, 20, 32, 20, 44, 12, 44, 12, 12, 28, 12, 204, 204, 20, 20, 236, 204, 212, 204, 220, 220, 204, 140, 20, 12, 140, 28, 148, 220, 156, 220, 220, 204, 212, 20, 20, 28, 148, 140, 140, 44, 20, 212, 220, 220, 12, 20, 192, 212, 128, 152, 152, 48, 16, 48,
    144, 208, 208, 216, 208, 216, 192, 216, 216, 208, 4, 52, 4, 12, 12, 12, 12, 12, 204, 60, 204, 212, 204, 204, 28, 108, 220, 204, 204, 204, 140, 12, 204, 148, 12, 12, 140, 140, 28, 140, 212, 204, 204, 140, 28, 148, 140, 148, 148, 148, 212, 204, 212, 204, 204, 204, 204, 148, 212, 128, 128, 152, 56, 208,
    152, 152, 216, 216, 216, 192, 192, 192, 192, 196, 212, 44, 12, 12, 12, 12, 20, 156, 204, 108, 212, 204, 212, 212, 212, 0, 244, 204, 220, 140, 140, 12, 140, 140, 12, 140, 12, 128, 140, 12, 140, 212, 140, 220, 140, 204, 140, 148, 212, 140, 204, 204, 204, 212, 148, 220, 204, 212, 216, 212, 216, 192, 208, 208,
    144, 144, 216, 208, 216, 216, 216, 216, 212, 212, 196, 204, 60, 12, 12, 108, 148, 212, 28, 108, 220, 212, 212, 212, 192, 148, 0, 236, 148, 156, 12, 156, 140, 12, 12, 140, 0, 140, 128, 12, 128, 204, 212, 212, 212, 212, 148, 204, 140, 212, 212, 212, 212, 148, 204, 148, 140, 204, 212, 196, 192, 216, 152, 208,
    144, 152, 132, 152, 196, 132, 192, 192, 192, 196, 212, 196, 204, 204, 12, 172, 204, 212, 28, 172, 212, 140, 204, 140, 140, 140, 148, 20, 108, 140, 140, 12, 148, 12, 20, 140, 12, 12, 140, 128, 12, 128, 204, 204, 204, 156, 220, 140, 140, 156, 204, 148, 140, 140, 148, 148, 220, 140, 192, 148, 216, 152, 128, 152,
    24, 144, 152, 128, 128, 128, 132, 192, 148, 212, 220, 140, 204, 140, 12, 108, 148, 140, 60, 108, 140, 204, 140, 128, 148, 140, 12, 12, 0, 244, 0, 156, 220, 12, 20, 156, 156, 28, 12, 140, 0, 140, 148, 220, 148, 148, 140, 140, 140, 140, 140, 148, 140, 212, 140, 148, 140, 140, 140, 140, 132, 128, 152, 144,
    24, 152, 24, 152, 152, 152, 132, 132, 192, 132, 148, 196, 140, 140, 44, 36, 140, 128, 44, 44, 140, 148, 128, 148, 128, 148, 148, 20, 148, 0, 12, 20, 140, 20, 140, 12, 140, 156, 28, 140, 128, 20, 28, 140, 140, 140, 148, 148, 148, 148, 148, 148, 212, 140, 212, 140, 140, 140, 140, 140, 152, 148, 128, 144,
    0, 0, 128, 152, 152, 152, 152, 152, 132, 148, 132, 144, 132, 128, 56, 48, 128, 128, 32, 36, 140, 140, 140, 140, 20, 148, 140, 140, 148, 20, 28, 148, 148, 12, 20, 156, 28, 140, 12, 0, 140, 12, 156, 156, 156, 148, 212, 204, 204, 140, 148, 148, 140, 140, 204, 148, 140, 148, 140, 12, 140, 140, 148, 128,
    0, 0, 0, 128, 0, 128, 128, 128, 4, 132, 128, 128, 128, 152, 48, 32, 160, 172, 36, 16, 160, 188, 12, 12, 12, 0, 140, 128, 12, 20, 148, 140, 0, 12, 128, 28, 12, 148, 132, 4, 152, 132, 20, 140, 156, 220, 156, 156, 148, 212, 148, 140, 140, 148, 140, 140, 148, 140, 148, 140, 12, 128, 152, 152,
    0, 0, 0, 0, 0, 0, 128, 0, 128, 16, 144, 204, 32, 48, 0, 0, 32, 160, 28, 0, 56, 44, 172, 12, 12, 12, 0, 12, 12, 156, 28, 12, 140, 128, 12, 140, 148, 4, 152, 152, 4, 152, 4, 140, 12, 148, 148, 148, 148, 140, 148, 148, 28, 20, 148, 140, 156, 148, 140, 140, 76, 64, 0, 88,
    16, 16, 16, 16, 0, 0, 0, 0, 0, 0, 208, 0, 4, 216, 16, 0, 192, 196, 0, 0, 216, 196, 204, 44, 164, 12, 12, 28, 12, 12, 140, 12, 28, 20, 140, 20, 4, 128, 24, 152, 24, 128, 24, 20, 156, 148, 140, 20, 148, 148, 12, 12, 148, 12, 148, 20, 148, 76, 20, 76, 12, 20, 64, 24,
    24, 16, 16, 16, 16, 16, 0, 0, 0, 0, 192, 208, 192, 16, 0, 0, 0, 196, 0, 208, 4, 4, 4, 192, 204, 0, 12, 12, 12, 12, 12, 12, 20, 24, 20, 24, 24, 4, 152, 24, 24, 0, 0, 24, 20, 140, 20, 12, 12, 12, 12, 148, 0, 148, 12, 148, 84, 20, 76, 12, 28, 12, 20, 88,
    24, 24, 16, 16, 16, 16, 16, 80, 32, 192, 192, 4, 0, 4, 0, 4, 4, 0, 16, 0, 4, 0, 4, 0, 192, 12, 76, 60, 20, 12, 20, 20, 24, 20, 24, 24, 4, 24, 4, 24, 24, 24, 4, 0, 24, 0, 0, 12, 12, 24, 20, 0, 0, 0, 64, 12, 12, 12, 12, 12, 12, 12, 20, 24,
    24, 24, 24, 16, 48, 112, 80, 48, 16, 192, 0, 4, 0, 4, 0, 4, 4, 0, 0, 12, 0, 12, 4, 4, 24, 216, 216, 88, 88, 52, 88, 24, 20, 24, 0, 24, 24, 24, 4, 24, 0, 0, 24, 0, 24, 4, 0, 0, 24, 24, 0, 0, 0, 68, 0, 12, 0, 0, 0, 12, 12, 0, 12, 12,
    24, 24, 56, 88, 32, 68, 96, 16, 192, 0, 0, 4, 0, 4, 0, 4, 0, 12, 0, 0, 0, 0, 4, 28, 24, 24, 216, 120, 56, 88, 120, 88, 48, 96, 0, 16, 24, 24, 0, 0, 32, 24, 0, 4, 0, 4, 4, 16, 0, 0, 24, 24, 24, 24, 0, 0, 0, 24, 24, 16, 0, 4, 0, 0,

    232, 232, 232, 40, 60, 36, 36, 68, 0, 60, 92, 28, 36, 12, 100, 20, 148, 188, 220, 236, 236, 236, 12, 172, 252, 236, 52, 236, 44, 60, 252, 252, 92, 52, 20, 84, 252, 52, 60, 60, 60, 236, 44, 44, 60, 44, 44, 76, 44, 28, 220, 60, 252, 60, 44, 36, 60, 36, 252, 92, 40, 60, 60, 40,
    72, 248, 252, 40, 60, 252, 60, 60, 36, 36, 76, 4, 44, 28, 84, 20, 156, 212, 236, 220, 252, 252, 44, 44, 188, 252, 236, 60, 244, 60, 60, 68, 140, 52, 68, 140, 76, 236, 84, 244, 244, 36, 236, 44, 44, 44, 76, 92, 92, 28, 44, 236, 44, 236, 60, 44, 228, 236, 68, 92, 92, 8, 40, 8,
    72, 232, 232, 220, 232, 60, 228, 252, 252, 244, 68, 12, 36, 60, 148, 156, 148, 148, 244, 108, 252, 236, 252, 252, 52, 60, 244, 228, 244, 252, 68, 156, 52, 76, 148, 148, 84, 84, 140, 84, 236, 244, 228, 68, 52, 76, 92, 76, 76, 76, 236, 252, 236, 252, 252, 252, 244, 76, 236, 68, 68, 92, 24, 232,
    92, 92, 252, 252, 252, 228, 228, 228, 228, 228, 236, 20, 60, 52, 148, 148, 140, 84, 244, 244, 236, 252, 236, 236, 236, 48, 172, 252, 236, 84, 92, 148, 92, 84, 156, 92, 148, 88, 84, 156, 84, 236, 92, 244, 68, 252, 92, 76, 236, 92, 252, 252, 252, 236, 76, 236, 252, 236, 252, 236, 248, 228, 232, 232,
    72, 72, 248, 232, 252, 252, 252, 252, 236, 236, 228, 252, 12, 60, 84, 228, 76, 204, 84, 244, 236, 236, 236, 236, 240, 76, 48, 180, 76, 84, 148, 84, 84, 156, 148, 84, 152, 84, 88, 148, 88, 244, 236, 236, 236, 236, 76, 252, 92, 236, 236, 236, 204, 76, 252, 76, 92, 244, 236, 224, 228, 252, 92, 232,
    72, 92, 64, 92, 224, 64, 228, 228, 228, 228, 236, 228, 252, 244, 92, 100, 228, 236, 84, 116, 236, 92, 252, 92, 92, 92, 76, 44, 60, 92, 92, 156, 76, 148, 140, 92, 148, 156, 84, 88, 148, 88, 244, 196, 228, 84, 244, 92, 92, 76, 252, 76, 92, 92, 76, 76, 236, 92, 228, 76, 252, 92, 68, 92,
    220, 72, 92, 68, 68, 68, 64, 228, 76, 236, 228, 92, 244, 92, 84, 228, 76, 68, 100, 244, 84, 252, 92, 80, 76, 92, 156, 156, 48, 172, 144, 84, 244, 132, 140, 84, 84, 148, 156, 84, 152, 84, 76, 244, 76, 76, 92, 92, 92, 92, 92, 76, 92, 236, 92, 76, 92, 84, 84, 84, 64, 68, 92, 72,
    220, 92, 220, 92, 92, 92, 64, 64, 228, 68, 76, 228, 84, 84, 20, 0, 68, 68, 20, 20, 92, 76, 80, 76, 80, 76, 76, 140, 76, 144, 156, 140, 68, 140, 92, 156, 68, 84, 148, 84, 88, 140, 148, 92, 92, 92, 76, 76, 76, 76, 76, 76, 236, 92, 236, 92, 92, 92, 92, 92, 92, 76, 68, 72,
    216, 216, 88, 92, 92, 92, 92, 92, 68, 76, 68, 72, 64, 88, 28, 104, 80, 80, 8, 96, 92, 92, 92, 92, 204, 76, 92, 92, 76, 140, 132, 76, 76, 156, 140, 84, 148, 92, 148, 152, 84, 148, 84, 84, 84, 76, 236, 252, 252, 92, 76, 76, 92, 92, 252, 76, 92, 76, 92, 220, 84, 84, 76, 68,
    216, 208, 208, 80, 208, 80, 80, 80, 196, 68, 88, 88, 88, 92, 8, 112, 100, 124, 0, 72, 100, 108, 220, 212, 212, 208, 92, 80, 196, 204, 76, 92, 208, 156, 80, 148, 156, 76, 64, 132, 68, 68, 140, 92, 84, 244, 84, 76, 76, 236, 76, 92, 92, 76, 92, 92, 76, 92, 76, 92, 220, 68, 92, 92,
    208, 208, 208, 208, 208, 208, 80, 208, 80, 200, 72, 52, 24, 40, 48, 48, 4, 104, 44, 48, 28, 60, 124, 220, 220, 212, 208, 212, 220, 76, 212, 220, 84, 80, 156, 92, 76, 132, 92, 92, 132, 68, 196, 92, 220, 76, 76, 76, 76, 92, 76, 76, 204, 204, 76, 92, 68, 76, 92, 84, 20, 4, 196, 28,
    136, 200, 200, 200, 208, 144, 208, 144, 216, 152, 40, 248, 132, 184, 232, 240, 40, 32, 240, 240, 60, 32, 60, 60, 108, 220, 220, 204, 220, 212, 84, 212, 204, 204, 92, 204, 196, 68, 196, 92, 196, 68, 196, 204, 76, 76, 92, 204, 76, 76, 220, 220, 76, 220, 76, 204, 76, 28, 204, 92, 220, 204, 4, 220,
    156, 136, 200, 200, 136, 136, 144, 152, 152, 152, 56, 40, 56, 136, 240, 144, 232, 32, 144, 40, 224, 224, 236, 40, 60, 136, 156, 148, 148, 212, 220, 220, 204, 220, 204, 220, 196, 196, 88, 196, 220, 196, 196, 220, 204, 92, 204, 220, 220, 220, 220, 76, 196, 76, 220, 76, 76, 204, 92, 220, 204, 212, 204, 24,
    156, 156, 136, 136, 136, 136, 136, 8, 24, 56, 56, 236, 132, 128, 144, 236, 128, 240, 232, 144, 128, 228, 128, 232, 40, 252, 28, 12, 140, 156, 140, 204, 156, 140, 156, 196, 128, 196, 192, 220, 196, 220, 192, 196, 220, 196, 196, 220, 220, 220, 204, 196, 196, 196, 4, 220, 220, 220, 220, 148, 212, 148, 204, 220,
    156, 156, 132, 136, 8, 232, 8, 8, 232, 56, 232, 128, 228, 128, 240, 140, 128, 240, 144, 148, 152, 148, 128, 224, 228, 36, 60, 4, 92, 12, 28, 156, 140, 156, 132, 156, 196, 156, 128, 156, 132, 132, 156, 132, 220, 128, 132, 196, 220, 220, 132, 196, 196, 0, 196, 220, 196, 132, 196, 220, 156, 196, 148, 148,
    156, 156, 28, 4, 4, 0, 228, 232, 36, 228, 136, 224, 132, 128, 136, 128, 144, 148, 152, 252, 156, 156, 128, 148, 252, 252, 164, 252, 4, 68, 252, 28, 8, 228, 132, 136, 156, 132, 132, 132, 4, 156, 132, 128, 132, 128, 128, 136, 132, 132, 156, 196, 220, 196, 196, 196, 132, 196, 156, 136, 196, 128, 132, 196,

    12, 12, 12, 236, 96, 108, 108, 100, 72, 104, 128, 224, 204, 252, 160, 240, 208, 144, 48, 188, 188, 188, 252, 252, 84, 4, 248, 28, 252, 244, 16, 16, 48, 124, 92, 56, 16, 252, 116, 112, 112, 28, 124, 124, 96, 60, 124, 124, 124, 80, 48, 240, 16, 240, 124, 44, 96, 236, 64, 96, 108, 104, 96, 108,
    108, 4, 0, 108, 224, 0, 224, 96, 108, 236, 156, 236, 220, 244, 144, 240, 208, 48, 164, 48, 20, 16, 220, 124, 240, 16, 28, 240, 28, 244, 240, 44, 220, 116, 44, 192, 60, 4, 60, 28, 28, 236, 24, 124, 124, 96, 124, 112, 112, 80, 120, 28, 224, 64, 112, 124, 4, 28, 108, 96, 104, 76, 44, 76,
    108, 12, 12, 32, 76, 224, 12, 64, 0, 28, 144, 252, 192, 208, 208, 208, 212, 208, 80, 164, 80, 28, 16, 16, 60, 112, 28, 12, 16, 20, 44, 208, 240, 60, 208, 208, 48, 48, 196, 48, 28, 16, 76, 108, 60, 124, 112, 124, 124, 124, 28, 84, 28, 16, 16, 16, 16, 124, 28, 108, 100, 96, 68, 12,
    96, 96, 0, 0, 0, 12, 76, 12, 4, 16, 28, 240, 208, 208, 208, 208, 220, 124, 16, 176, 28, 20, 28, 92, 24, 120, 252, 16, 0, 112, 52, 208, 48, 48, 212, 52, 208, 36, 48, 208, 48, 28, 112, 28, 108, 0, 112, 124, 28, 112, 16, 20, 16, 28, 120, 0, 16, 28, 8, 28, 4, 12, 12, 76,
    108, 108, 4, 12, 0, 0, 0, 0, 28, 28, 0, 16, 224, 208, 144, 156, 124, 124, 156, 144, 0, 24, 28, 28, 24, 124, 120, 240, 60, 60, 208, 124, 112, 208, 208, 48, 196, 48, 36, 208, 36, 80, 28, 28, 28, 28, 124, 80, 96, 92, 28, 28, 60, 124, 16, 124, 116, 16, 92, 8, 12, 64, 104, 76,
    108, 96, 104, 96, 8, 104, 4, 76, 76, 8, 28, 16, 16, 80, 144, 252, 20, 28, 156, 240, 28, 112, 20, 96, 112, 116, 124, 60, 112, 112, 48, 208, 124, 212, 220, 112, 208, 212, 52, 36, 208, 36, 16, 44, 12, 124, 28, 112, 112, 100, 16, 124, 112, 96, 124, 124, 4, 112, 12, 124, 0, 104, 108, 96,
    0, 108, 96, 108, 108, 108, 104, 12, 124, 28, 20, 112, 20, 112, 148, 156, 124, 124, 176, 144, 112, 20, 112, 120, 124, 112, 208, 192, 56, 252, 216, 60, 28, 204, 220, 60, 60, 220, 208, 112, 196, 48, 124, 28, 124, 124, 112, 112, 112, 112, 112, 124, 112, 92, 116, 124, 112, 112, 112, 112, 104, 108, 96, 108,
    0, 96, 0, 96, 104, 96, 104, 104, 76, 96, 124, 80, 112, 112, 240, 252, 124, 112, 240, 240, 112, 124, 120, 124, 120, 124, 124, 220, 124, 216, 208, 220, 108, 220, 48, 212, 44, 124, 220, 48, 100, 220, 220, 112, 112, 116, 124, 124, 124, 124, 124, 124, 28, 112, 28, 112, 112, 112, 116, 116, 96, 124, 108, 108,
    0, 0, 96, 104, 96, 96, 96, 96, 112, 124, 112, 108, 104, 100, 224, 172, 120, 120, 240, 188, 112, 112, 112, 112, 28, 124, 112, 112, 124, 220, 212, 124, 124, 208, 220, 124, 220, 112, 208, 196, 112, 208, 124, 124, 124, 124, 28, 16, 16, 116, 124, 124, 116, 112, 20, 124, 112, 124, 112, 16, 112, 112, 124, 108,
    0, 24, 24, 120, 24, 120, 120, 120, 16, 112, 100, 100, 100, 96, 236, 184, 252, 244, 252, 140, 236, 224, 16, 16, 20, 24, 116, 120, 12, 28, 124, 112, 24, 208, 120, 220, 208, 124, 96, 208, 124, 104, 220, 112, 124, 28, 124, 96, 124, 28, 124, 112, 112, 124, 112, 96, 124, 112, 124, 112, 16, 100, 96, 96,
    24, 24, 24, 24, 24, 24, 120, 24, 120, 12, 108, 240, 36, 140, 216, 216, 248, 240, 192, 216, 232, 16, 240, 20, 16, 16, 24, 16, 16, 100, 28, 20, 112, 120, 208, 112, 124, 192, 96, 104, 208, 124, 16, 116, 16, 124, 124, 124, 124, 112, 124, 124, 0, 28, 124, 112, 116, 124, 112, 112, 208, 204, 12, 200,
    204, 12, 12, 12, 24, 216, 24, 216, 0, 192, 236, 196, 96, 100, 204, 216, 240, 252, 216, 216, 224, 252, 240, 16, 244, 16, 16, 4, 20, 16, 112, 20, 0, 28, 112, 28, 16, 108, 28, 96, 28, 100, 28, 28, 96, 124, 116, 28, 124, 124, 20, 16, 124, 16, 124, 28, 124, 208, 28, 148, 16, 28, 196, 0,
    192, 204, 12, 12, 204, 204, 216, 192, 192, 192, 224, 236, 224, 108, 216, 120, 208, 252, 120, 236, 220, 220, 212, 240, 240, 208, 208, 208, 208, 16, 16, 16, 28, 0, 28, 0, 28, 8, 100, 28, 0, 12, 12, 0, 28, 112, 28, 16, 20, 16, 16, 124, 12, 124, 16, 124, 156, 28, 148, 16, 4, 16, 28, 196,
    192, 192, 204, 204, 204, 204, 204, 204, 192, 224, 224, 212, 120, 124, 120, 212, 124, 216, 204, 120, 124, 216, 124, 208, 240, 208, 208, 192, 220, 208, 220, 28, 192, 220, 200, 28, 212, 28, 8, 0, 28, 0, 8, 12, 0, 12, 12, 20, 16, 8, 28, 4, 4, 12, 204, 16, 16, 16, 20, 208, 16, 212, 28, 0,
    200, 192, 220, 204, 204, 140, 204, 204, 204, 224, 208, 124, 216, 124, 216, 116, 124, 216, 120, 112, 100, 112, 124, 220, 220, 252, 224, 220, 128, 220, 192, 200, 220, 192, 204, 192, 28, 192, 200, 192, 204, 204, 192, 204, 0, 200, 204, 12, 0, 0, 204, 12, 12, 200, 12, 20, 12, 204, 12, 16, 208, 12, 208, 208,
    192, 192, 192, 220, 196, 200, 12, 204, 236, 204, 112, 220, 120, 124, 112, 124, 120, 112, 100, 212, 116, 116, 124, 124, 192, 192, 124, 0, 220, 156, 136, 192, 196, 12, 204, 196, 200, 220, 204, 204, 204, 200, 196, 200, 204, 200, 200, 204, 204, 204, 192, 28, 0, 28, 12, 12, 196, 28, 192, 204, 4, 200, 204, 12

};

// create the panel and link it to the buffer created above
Panel panel(buffer);
void setup()
{
}

void loop()
{
    panel.displayBuffer();
}