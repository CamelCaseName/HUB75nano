#ifndef HUB75NANO_COLORS_H
#define HUB75NANO_COLORS_H

#include "Color.h"

#pragma region color_enum_definition
typedef class Colors
{
public:
    inline static const Color RED = COLOR_888_to_444(3, 0, 0);
    inline static const Color GREEN = COLOR_888_to_444(0, 3, 0);
    inline static const Color BLUE = COLOR_888_to_444(0, 0, 3);
    inline static const Color WHITE = COLOR_888_to_444(3, 3, 3);
    inline static const Color BLACK = COLOR_888_to_444(0, 0, 0);
    inline static const Color PURPLE = COLOR_888_to_444(3, 0, 3);
    inline static const Color YELLOW = COLOR_888_to_444(3, 3, 0);
    inline static const Color CYAN = COLOR_888_to_444(0, 3, 3);
#ifdef PANEL_BIG
    inline static const Color DARKRED = COLOR_888_to_444(2, 0, 0);
    inline static const Color DARKGREEN = COLOR_888_to_444(0, 2, 0);
    inline static const Color DARKBLUE = COLOR_888_to_444(0, 0, 2);
    inline static const Color DARKWHITE = COLOR_888_to_444(2, 2, 2);
    inline static const Color DARKPURPLE = COLOR_888_to_444(2, 0, 2);
    inline static const Color DARKYELLOW = COLOR_888_to_444(2, 2, 0);
    inline static const Color DARKCYAN = COLOR_888_to_444(0, 2, 2);
    inline static const Color DARKERRED = COLOR_888_to_444(1, 0, 0);
    inline static const Color DARKERGREEN = COLOR_888_to_444(0, 1, 0);
    inline static const Color DARKERBLUE = COLOR_888_to_444(0, 0, 1);
    inline static const Color DARKERWHITE = COLOR_888_to_444(1, 1, 1);
    inline static const Color DARKERPURPLE = COLOR_888_to_444(1, 0, 1);
    inline static const Color DARKERYELLOW = COLOR_888_to_444(1, 1, 0);
    inline static const Color DARKERCYAN = COLOR_888_to_444(0, 1, 1);
    inline static const Color ORANGE = COLOR_888_to_444(3, 1, 0);
#endif
    inline static const Color NO_COLOR = {0, 0, 0, 15};

} Colors;
#pragma endregion // color_enum_definition

#endif // HUB75NANO_COLORS_H