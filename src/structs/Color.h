#ifndef HUB75NANO_COLOR_H
#define HUB75NANO_COLOR_H

#include <inttypes.h>

#pragma region color_helpers

#ifndef MAX_COLORDEPTH
#define MAX_COLORDEPTH 1
#endif

#define MAX_COLOR (MAX_COLORDEPTH * MAX_COLORDEPTH) - 1
#if MAX_COLOR == 0
#define MAX_COLOR 1
#endif
#define COLOR_CLAMP (255.0 / (MAX_COLOR))

#pragma pack(push, 1)
#ifdef PANEL_NO_BUFFER
typedef union Color
{
    struct
    {
        uint8_t red : 8;
        uint8_t green : 8;
        uint8_t blue : 8;
        uint8_t invalid_bits : 8;
    };
    uint32_t color_444;
} Color;
#else
typedef union Color
{
    struct
    {
        uint8_t red : 4;
        uint8_t green : 4;
        uint8_t blue : 4;
        uint8_t invalid_bits : 4;
    };
    uint16_t color_444;
} Color;
#endif
#pragma pack(pop)

constexpr Color COLOR_888_to_444(uint8_t r, uint8_t g, uint8_t b)
{
    return {(r & (uint8_t)15), (g & (uint8_t)15), (b & (uint8_t)15)};
}
constexpr Color COLOR_888_to_444_FULL(uint8_t r, uint8_t g, uint8_t b)
{
    return {(int)(((double)r / 8) - 0.5), (int)(((double)g / 4) - 0.5), (int)(((double)b / 8) - 0.5)};
}
constexpr Color COLOR_888_to_444_CLAMPED(uint8_t r, uint8_t g, uint8_t b)
{
    return {(int)(((double)r / COLOR_CLAMP) + 0.5), (int)(((double)g / COLOR_CLAMP) + 0.5), (int)(((double)b / COLOR_CLAMP) + 0.5)};
}
constexpr Color COLOR_888_to_444_COLORF(float r, float g, float b)
{
    return {((int)(r * MAX_COLOR + 0.5f)), (int)((g * MAX_COLOR + 0.5f)), (int)((b * MAX_COLOR) + 0.5f)};
}

#pragma endregion

#endif // HUB75NANO_COLOR_H