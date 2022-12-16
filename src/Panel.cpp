#include "Panel.h"

Panel::Panel()
{
    rows = PANEL_X;
    coloumns = PANEL_Y;
    pinMode(RA, OUTPUT);
    pinMode(RB, OUTPUT);
    pinMode(RC, OUTPUT);
    pinMode(RD, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(RF, OUTPUT);
    pinMode(RS, OUTPUT);
    pinMode(GF, OUTPUT);
    pinMode(GS, OUTPUT);
    pinMode(BF, OUTPUT);
    pinMode(BS, OUTPUT);
    pinMode(LAT, OUTPUT);
    pinMode(OE, OUTPUT);

    // primarily used for debugging
#ifdef DEBUG
    Serial.begin(38400);
    // Serial.println("pinmode set");
#endif // DEBUG

    // each LED struct contains 8 leds, rows * cols in total, so rows*cols/8 is needed
    bsize = rows * (coloumns / 8);
}

void cnvColor(uint16_t c, uint8_t *rt, uint8_t *gt, uint8_t *bt)
{ // input color, get converted color by reference
    switch (c)
    {
    case Panel::RED:
        *rt = 1;
        *gt = 0;
        *bt = 0;
        break;
    case Panel::GREEN:
        *rt = 0;
        *gt = 1;
        *bt = 0;
        break;
    case Panel::BLUE:
        *rt = 0;
        *gt = 0;
        *bt = 1;
        break;
    case Panel::WHITE:
        *rt = 1;
        *gt = 1;
        *bt = 1;
        break;
    case Panel::BLACK:
        *rt = 0;
        *gt = 0;
        *bt = 0;
        break;
    case Panel::PURPLE:
        *rt = 1;
        *gt = 0;
        *bt = 1;
        break;
    case Panel::YELLOW:
        *rt = 1;
        *gt = 1;
        *bt = 0;
        break;
    case Panel::CYAN:
        *rt = 0;
        *gt = 1;
        *bt = 1;
        break;
#ifdef PANEL_BIG
    case Panel::DEEPRED:
        *rt = 2;
        *gt = 0;
        *bt = 0;
        break;
    case Panel::DEEPGREEN:
        *rt = 0;
        *gt = 2;
        *bt = 0;
        break;
    case Panel::DEEPBLUE:
        *rt = 0;
        *gt = 0;
        *bt = 2;
        break;
    case Panel::DEEPWHITE:
        *rt = 2;
        *gt = 2;
        *bt = 2;
    case Panel::DEEPERWHITE:
        *rt = 3;
        *gt = 3;
        *bt = 3;
        break;
    case Panel::DEEPCYAN:
        *rt = 0;
        *gt = 2;
        *bt = 2;
        break;
    case Panel::DARKYELLOW:
        *rt = 1;
        *gt = 2;
        *bt = 0;
        break;
    case Panel::DEEPPURPLE:
        *rt = 2;
        *gt = 0;
        *bt = 2;
        break;
    case Panel::DEEPYELLOW:
        *rt = 2;
        *gt = 2;
        *bt = 0;
        break;
    case Panel::TURQUOISE:
        *rt = 0;
        *gt = 1;
        *bt = 2;
        break;
    case Panel::PINK:
        *rt = 1;
        *gt = 0;
        *bt = 2;
        break;
    case Panel::DARKPURPLE:
        *rt = 2;
        *gt = 0;
        *bt = 1;
        break;
    case Panel::BRIGHTGREEN:
        *rt = 2;
        *gt = 1;
        *bt = 0;
        break;
    case Panel::BRIGHTCYAN:
        *rt = 2;
        *gt = 1;
        *bt = 1;
        break;
    case Panel::MEDIUMGREEN:
        *rt = 2;
        *gt = 1;
        *bt = 2;
        break;
    case Panel::DEEPERPURPLE:
        *rt = 2;
        *gt = 2;
        *bt = 1;
        break;
    case Panel::OCEANBLUE:
        *rt = 0;
        *gt = 2;
        *bt = 1;
        break;
    case Panel::FLESH:
        *rt = 1;
        *gt = 2;
        *bt = 2;
        break;
    case Panel::LIGHTPINK:
        *rt = 1;
        *gt = 2;
        *bt = 1;
        break;
#endif
    default:
        HIGH_TO_FULL_COLOR(c, rt, gt, bt);
        break;
    }
}

inline void Panel::selectLine(uint8_t lineIndex)
{ // selects one of the 16 lines, 0 based
    SET_ROW_PINS(lineIndex);
    LATCH_DATA;
}

void Panel::fillScreenShift(uint8_t s, uint8_t f, uint8_t o)
{ // creates interesting patterns (shift, factor, offset) | I honestly dont know what it does, @hexchen made this
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    for (uint8_t r = 0; r < rows / 2; r++)
    {
        // switch through all rows
        selectLine(r);

        for (uint8_t c = 0; c < coloumns; c++)
        {
            // c = coloumn r = row s = shift for moving fist number is offset for color, second for overall
            r = ((c + 0 + r + s * 1 + o) % f) == 0;
            b = ((c + 1 + r + s * 2 + o) % f) == 0;
            g = ((c + 2 + r + s * 3 + o) % f) == 0;
            r ^= ((c + 3 - r + s * 1 + o) % f) == 0;
            g ^= ((c + 4 - r + s * 2 + o) % f) == 0;
            b ^= ((c + 5 - r + s * 3 + o) % f) == 0;
            sendTwoPixels(r, g, b, r, g, b);
        }
        LATCH_DATA; // general latch to get rid of ghosting, or so i thought
    }
}

void Panel::fillScreenColor(uint16_t c)
{ // fills the screeen with the set color
    // switches all the colors and sets the values depending on colors
    cnvColor(c, &r, &g, &b); // gets first couple colors

    for (uint8_t i = 0; i < 16; i++)
    {
        for (uint8_t row = 0; row < rows / 2; row++)
        {
            // switch through all rows
            sendWholeRow(r > i, g > i, b > i, r > i, g > i, b > i);
            selectLine(row);
        }
    }
}

inline void Panel::sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl)
{ // sends two pixels, one in upper half, one in lower half to display | first upper half values, the lower half
    // set all pins at once
    SET_COLOR(ru | gu << 1 | bu << 2 | rl << 3 | gl << 4 | b << 5);
    CLOCK;
}

void Panel::sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl)
{ // sends two rows of pixels to display | first upper half values, the lower half
    SET_COLOR(ru | gu << 1 | bu << 2 | rl << 3 | gl << 4 | b << 5);

    for (uint8_t i = 0; i < coloumns; i++)
    {
        CLOCK;
    }
    LATCH_DATA;
}

void Panel::displayBuffer()
{ // puts the  buffer contents onto the panel
#ifndef PANEL_BIG
    for (uint8_t upper = 0; upper < (bsize >> 1); upper++)
    {
        lower = upper + (bsize >> 1); // ^= / 2
        // first pixels
        // one led struct contains bits in 3 bytes:
        // |23 22 21 20 19 18 17 16|15 14 13 12 11 10 9  8 |7  6  5  4  3  2  1  0 |
        // |b8:g8:r8:b7:g7:r7:b6:g6|r6:b5:g5:r5:b4:g4:r4:b3|g3:r3:b2:g2:r2:b1:g1:r1|

        // checks wether pixel set in buffer, therefor deciding the pin level
        SET_COLOR((*(uint8_t *)(&buffer[upper]) & 0b00000111) | ((*(uint8_t *)(&buffer[lower]) << 3) & 0b00111000));
        // SET_COLOR(((reinterpret_cast<uint8_t>(buffer[upper])) & 0b00000111) | ((*(uint8_t *)(&buffer[lower]) << 3) & 0b00111000));
        CLOCK;
        // second pixels
        SET_COLOR(((*(uint8_t *)(&buffer[upper]) >> 3) & 0b00000111) | (*(uint8_t *)(&buffer[lower]) & 0b00111000));
        CLOCK;

        // 3rd pixels
        SET_COLOR(((uint8_t)((*((uint16_t *)(&buffer[upper])) >> 6) & 0b00000111)) | ((uint8_t)((*((uint16_t *)(&buffer[lower])) >> 3) & 0b00111000)));
        CLOCK;

        // 4th pixels
        SET_COLOR(((*((uint8_t *)(&buffer[upper]) + sizeof(uint8_t)) >> 1) & 0b00000111) | ((*((uint8_t *)(&buffer[lower]) + sizeof(uint8_t)) << 2) & 0b00111000));
        CLOCK;

        // 5th pixels
        SET_COLOR(((*((uint8_t *)(&buffer[upper]) + sizeof(uint8_t)) >> 4) & 0b00000111) | ((*((uint8_t *)(&buffer[lower]) + sizeof(uint8_t)) >> 1) & 0b00111000));
        CLOCK;

        // 6th pixels
        SET_COLOR(((uint8_t)((*((uint16_t *)((uint8_t *)(&buffer[upper]) + sizeof(uint8_t))) >> 7) & 0b00000111)) | ((uint8_t)((*((uint16_t *)((uint8_t *)(&buffer[lower]) + sizeof(uint8_t))) >> 4) & 0b00111000)));
        CLOCK;

        // 7th pixels
        SET_COLOR(((*((uint8_t *)(&buffer[upper]) + sizeof(uint8_t) * 2) >> 2) & 0b00000111) | ((*((uint8_t *)(&buffer[lower]) + sizeof(uint8_t) * 2) << 1) & 0b00111000));
        CLOCK;

        // 8th pixels
        SET_COLOR(((*((uint8_t *)(&buffer[upper]) + sizeof(uint8_t) * 2) >> 5) & 0b00000111) | ((*((uint8_t *)(&buffer[lower]) + sizeof(uint8_t) * 2) >> 2) & 0b00111000));
        CLOCK;

        if ((upper + 1) % 8 == 0)
        {
            SET_ROW_PINS(upper / 8);
            LATCH_DATA;
        }
    }

#else
  // only use when big buffer is wanted and we need the expanded color palette
    // for second bit
    for (uint8_t upper = 0; upper < (bsize >> 1); upper++)
    {
        lower = upper + (bsize >> 1); // ^= / 2
        // first pixels
        // one led struct contains bits in 3 bytes:
        // |23 22 21 20 19 18 17 16|15 14 13 12 11 10 9  8 |7  6  5  4  3  2  1  0 |
        // |b8:g8:r8:b7:g7:r7:b6:g6|r6:b5:g5:r5:b4:g4:r4:b3|g3:r3:b2:g2:r2:b1:g1:r1|

        // checks wether pixel set in buffer, therefor deciding the pin level
        SET_COLOR((buffer[upper].rc1 >> 1) | (buffer[upper].gc1 >> 1) << 1 | (buffer[upper].bc1 >> 1) << 2 | (buffer[lower].rc1 >> 1) << 3 | (buffer[lower].gc1 >> 1) << 4 | (buffer[lower].bc1 >> 1) << 5);
        CLOCK;

        // second pixels
        SET_COLOR((buffer[upper].rc2 >> 1) | (buffer[upper].gc2 >> 1) << 1 | (buffer[upper].bc2 >> 1) << 2 | (buffer[lower].rc2 >> 1) << 3 | (buffer[lower].gc2 >> 1) << 4 | (buffer[lower].bc2 >> 1) << 5);
        CLOCK;

        // 3rd pixels
        SET_COLOR((buffer[upper].rc3 >> 1) | (buffer[upper].gc3 >> 1) << 1 | (buffer[upper].bc3 >> 1) << 2 | (buffer[lower].rc3 >> 1) << 3 | (buffer[lower].gc3 >> 1) << 4 | (buffer[lower].bc3 >> 1) << 5);
        CLOCK;

        // 4th pixels
        SET_COLOR((buffer[upper].rc4 >> 1) | (buffer[upper].gc4 >> 1) << 1 | (buffer[upper].bc4 >> 1) << 2 | (buffer[lower].rc4 >> 1) << 3 | (buffer[lower].gc4 >> 1) << 4 | (buffer[lower].bc4 >> 1) << 5);
        CLOCK;

        // 5th pixels
        SET_COLOR((buffer[upper].rc5 >> 1) | (buffer[upper].gc5 >> 1) << 1 | (buffer[upper].bc5 >> 1) << 2 | (buffer[lower].rc5 >> 1) << 3 | (buffer[lower].gc5 >> 1) << 4 | (buffer[lower].bc5 >> 1) << 5);
        CLOCK;

        // 6th pixels
        SET_COLOR((buffer[upper].rc6 >> 1) | (buffer[upper].gc6 >> 1) << 1 | (buffer[upper].bc6 >> 1) << 2 | (buffer[lower].rc6 >> 1) << 3 | (buffer[lower].gc6 >> 1) << 4 | (buffer[lower].bc6 >> 1) << 5);
        CLOCK;

        // 7th pixels
        SET_COLOR((buffer[upper].rc7 >> 1) | (buffer[upper].gc7 >> 1) << 1 | (buffer[upper].bc7 >> 1) << 2 | (buffer[lower].rc7 >> 1) << 3 | (buffer[lower].gc7 >> 1) << 4 | (buffer[lower].bc7 >> 1) << 5);
        CLOCK;

        // 8th pixels
        SET_COLOR((buffer[upper].rc8 >> 1) | (buffer[upper].gc8 >> 1) << 1 | (buffer[upper].bc8 >> 1) << 2 | (buffer[lower].rc8 >> 1) << 3 | (buffer[lower].gc8 >> 1) << 4 | (buffer[lower].bc8 >> 1) << 5);
        CLOCK;

        if ((upper + 1) % 8 == 0)
        {
            SET_ROW_PINS(upper / 8);
            LATCH_DATA;
        }
    }

    // do first bit
    for (uint8_t upper = 0; upper < (bsize >> 1); upper++)
    {
        lower = upper + (bsize >> 1); // ^= / 2
        // first pixels
        // one led struct contains bits in 3 bytes:
        // |23 22 21 20 19 18 17 16|15 14 13 12 11 10 9  8 |7  6  5  4  3  2  1  0 |
        // |b8:g8:r8:b7:g7:r7:b6:g6|r6:b5:g5:r5:b4:g4:r4:b3|g3:r3:b2:g2:r2:b1:g1:r1|

        // checks wether pixel set in buffer, therefor deciding the pin level
        SET_COLOR((buffer[upper].rc1 & 1) | (buffer[upper].gc1 & 1) << 1 | (buffer[upper].bc1 & 1) << 2 | (buffer[lower].rc1 & 1) << 3 | (buffer[lower].gc1 & 1) << 4 | (buffer[lower].bc1 & 1) << 5);
        CLOCK;

        // second pixels
        SET_COLOR((buffer[upper].rc2 & 1) | (buffer[upper].gc2 & 1) << 1 | (buffer[upper].bc2 & 1) << 2 | (buffer[lower].rc2 & 1) << 3 | (buffer[lower].gc2 & 1) << 4 | (buffer[lower].bc2 & 1) << 5);
        CLOCK;

        // 3rd pixels
        SET_COLOR((buffer[upper].rc3 & 1) | (buffer[upper].gc3 & 1) << 1 | (buffer[upper].bc3 & 1) << 2 | (buffer[lower].rc3 & 1) << 3 | (buffer[lower].gc3 & 1) << 4 | (buffer[lower].bc3 & 1) << 5);
        CLOCK;

        // 4th pixels
        SET_COLOR((buffer[upper].rc4 & 1) | (buffer[upper].gc4 & 1) << 1 | (buffer[upper].bc4 & 1) << 2 | (buffer[lower].rc4 & 1) << 3 | (buffer[lower].gc4 & 1) << 4 | (buffer[lower].bc4 & 1) << 5);
        CLOCK;

        // 5th pixels
        SET_COLOR((buffer[upper].rc5 & 1) | (buffer[upper].gc5 & 1) << 1 | (buffer[upper].bc5 & 1) << 2 | (buffer[lower].rc5 & 1) << 3 | (buffer[lower].gc5 & 1) << 4 | (buffer[lower].bc5 & 1) << 5);
        CLOCK;

        // 6th pixels
        SET_COLOR((buffer[upper].rc6 & 1) | (buffer[upper].gc6 & 1) << 1 | (buffer[upper].bc6 & 1) << 2 | (buffer[lower].rc6 & 1) << 3 | (buffer[lower].gc6 & 1) << 4 | (buffer[lower].bc6 & 1) << 5);
        CLOCK;

        // 7th pixels
        SET_COLOR((buffer[upper].rc7 & 1) | (buffer[upper].gc7 & 1) << 1 | (buffer[upper].bc7 & 1) << 2 | (buffer[lower].rc7 & 1) << 3 | (buffer[lower].gc7 & 1) << 4 | (buffer[lower].bc7 & 1) << 5);
        CLOCK;

        // 8th pixels
        SET_COLOR((buffer[upper].rc8 & 1) | (buffer[upper].gc8 & 1) << 1 | (buffer[upper].bc8 & 1) << 2 | (buffer[lower].rc8 & 1) << 3 | (buffer[lower].gc8 & 1) << 4 | (buffer[lower].bc8 & 1) << 5);
        CLOCK;

        if ((upper + 1) % 8 == 0)
        {
            SET_ROW_PINS(upper / 8);
            LATCH_DATA;
        }
    }

    // for second bit second run
    for (uint8_t upper = 0; upper < (bsize >> 1); upper++)
    {
        lower = upper + (bsize >> 1); // ^= / 2
        // first pixels
        // one led struct contains bits in 3 bytes:
        // |23 22 21 20 19 18 17 16|15 14 13 12 11 10 9  8 |7  6  5  4  3  2  1  0 |
        // |b8:g8:r8:b7:g7:r7:b6:g6|r6:b5:g5:r5:b4:g4:r4:b3|g3:r3:b2:g2:r2:b1:g1:r1|

        // checks wether pixel set in buffer, therefor deciding the pin level
        SET_COLOR((buffer[upper].rc1 >> 1) | (buffer[upper].gc1 >> 1) << 1 | (buffer[upper].bc1 >> 1) << 2 | (buffer[lower].rc1 >> 1) << 3 | (buffer[lower].gc1 >> 1) << 4 | (buffer[lower].bc1 >> 1) << 5);
        CLOCK;

        // second pixels
        SET_COLOR((buffer[upper].rc2 >> 1) | (buffer[upper].gc2 >> 1) << 1 | (buffer[upper].bc2 >> 1) << 2 | (buffer[lower].rc2 >> 1) << 3 | (buffer[lower].gc2 >> 1) << 4 | (buffer[lower].bc2 >> 1) << 5);
        CLOCK;

        // 3rd pixels
        SET_COLOR((buffer[upper].rc3 >> 1) | (buffer[upper].gc3 >> 1) << 1 | (buffer[upper].bc3 >> 1) << 2 | (buffer[lower].rc3 >> 1) << 3 | (buffer[lower].gc3 >> 1) << 4 | (buffer[lower].bc3 >> 1) << 5);
        CLOCK;

        // 4th pixels
        SET_COLOR((buffer[upper].rc4 >> 1) | (buffer[upper].gc4 >> 1) << 1 | (buffer[upper].bc4 >> 1) << 2 | (buffer[lower].rc4 >> 1) << 3 | (buffer[lower].gc4 >> 1) << 4 | (buffer[lower].bc4 >> 1) << 5);
        CLOCK;

        // 5th pixels
        SET_COLOR((buffer[upper].rc5 >> 1) | (buffer[upper].gc5 >> 1) << 1 | (buffer[upper].bc5 >> 1) << 2 | (buffer[lower].rc5 >> 1) << 3 | (buffer[lower].gc5 >> 1) << 4 | (buffer[lower].bc5 >> 1) << 5);
        CLOCK;

        // 6th pixels
        SET_COLOR((buffer[upper].rc6 >> 1) | (buffer[upper].gc6 >> 1) << 1 | (buffer[upper].bc6 >> 1) << 2 | (buffer[lower].rc6 >> 1) << 3 | (buffer[lower].gc6 >> 1) << 4 | (buffer[lower].bc6 >> 1) << 5);
        CLOCK;

        // 7th pixels
        SET_COLOR((buffer[upper].rc7 >> 1) | (buffer[upper].gc7 >> 1) << 1 | (buffer[upper].bc7 >> 1) << 2 | (buffer[lower].rc7 >> 1) << 3 | (buffer[lower].gc7 >> 1) << 4 | (buffer[lower].bc7 >> 1) << 5);
        CLOCK;

        // 8th pixels
        SET_COLOR((buffer[upper].rc8 >> 1) | (buffer[upper].gc8 >> 1) << 1 | (buffer[upper].bc8 >> 1) << 2 | (buffer[lower].rc8 >> 1) << 3 | (buffer[lower].gc8 >> 1) << 4 | (buffer[lower].bc8 >> 1) << 5);
        CLOCK;

        if ((upper + 1) % 8 == 0)
        {
            SET_ROW_PINS(upper / 8);
            LATCH_DATA;
        }
    }
#endif // BIG
}

void Panel::fillBuffer(uint16_t color)
{
    // get colors
    cnvColor(color, &r, &g, &b);

    // fills the buffer
    for (uint16_t x = 0; x < bsize; x++)
    {
        buffer[x].rc1 = r;
        buffer[x].gc1 = g;
        buffer[x].bc1 = b;
        buffer[x].rc2 = r;
        buffer[x].gc2 = g;
        buffer[x].bc2 = b;
        buffer[x].rc3 = r;
        buffer[x].gc3 = g;
        buffer[x].bc3 = b;
        buffer[x].rc4 = r;
        buffer[x].gc4 = g;
        buffer[x].bc4 = b;
        buffer[x].rc5 = r;
        buffer[x].gc5 = g;
        buffer[x].bc5 = b;
        buffer[x].rc6 = r;
        buffer[x].gc6 = g;
        buffer[x].bc6 = b;
        buffer[x].rc7 = r;
        buffer[x].gc7 = g;
        buffer[x].bc7 = b;
        buffer[x].rc8 = r;
        buffer[x].gc8 = g;
        buffer[x].bc8 = b;
    }
}

void Panel::test()
{
    fillScreenColor(BLUE);
    // fillScreenColor(2047);
}

void Panel::setBuffer(uint8_t r, uint8_t g, uint8_t b, uint8_t sector, uint8_t i)
{
    switch (i % 8)
    {
    case 0:
        buffer[sector].rc1 = r;
        buffer[sector].gc1 = g;
        buffer[sector].bc1 = b;
        break;
    case 1:
        buffer[sector].rc2 = r;
        buffer[sector].gc2 = g;
        buffer[sector].bc2 = b;
        break;
    case 2:
        buffer[sector].rc3 = r;
        buffer[sector].gc3 = g;
        buffer[sector].bc3 = b;
        break;
    case 3:
        buffer[sector].rc4 = r;
        buffer[sector].gc4 = g;
        buffer[sector].bc4 = b;
        break;
    case 4:
        buffer[sector].rc5 = r;
        buffer[sector].gc5 = g;
        buffer[sector].bc5 = b;
        break;
    case 5:
        buffer[sector].rc6 = r;
        buffer[sector].gc6 = g;
        buffer[sector].bc6 = b;
        break;
    case 6:
        buffer[sector].rc7 = r;
        buffer[sector].gc7 = g;
        buffer[sector].bc7 = b;
        break;
    case 7:
        buffer[sector].rc8 = r;
        buffer[sector].gc8 = g;
        buffer[sector].bc8 = b;
        break;
    default:
        break;
    }
}

void Panel::drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color, bool fill)
{ // draws a rect filled ro not filled with the given color at coords (landscape, origin in upper left corner)
    // get colors
    cnvColor(color, &r, &g, &b);

    //  Serial.println("drawing rect");

    if (fill)
    {
        for (uint8_t i = x1; i <= x2; i++)
        {
            for (uint8_t j = y1; j <= y2; j++)
            {
                uint8_t temp = (j * coloumns / 8) + (i / 8);
                setBuffer(r, g, b, temp, i);
            }
        }
    }
    else
    {
        // left line
        for (uint8_t j = y1; j <= y2; j++)
        {
            uint8_t temp = (j * coloumns / 8) + (x1 / 8);
            setBuffer(r, g, b, temp, x1);
        }

        // right line
        for (uint8_t j = y1; j <= y2; j++)
        {
            uint8_t temp = (j * coloumns / 8) + (x2 / 8);
            setBuffer(r, g, b, temp, x2);
        }

        // top line
        for (uint8_t i = x1; i <= x2; i++)
        {
            uint8_t temp = (y1 * coloumns / 8) + (i / 8);
            setBuffer(r, g, b, temp, i);
        }

        // bottom line
        for (uint8_t i = x1; i <= x2; i++)
        {
            uint8_t temp = (y2 * coloumns / 8) + (i / 8);
            setBuffer(r, g, b, temp, i);
        }
    }
}

void Panel::drawSquare(uint8_t x, uint8_t y, uint8_t size, uint8_t color, bool fill)
{
    drawRect(x, y, x + size, y + size, color, fill);
}

void Panel::drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{ // draws a line with color at coords given, must be left to right
    // get colors

    cnvColor(color, &r, &g, &b);

    //  f(x) = m*x+t
    //  t = f(0) = y1
    //  m =(y2-y1)/(x2-x1)
    //  ->iterate for each x from x1 to x2
    //

    float dy = y2 + 1 - y1; // delta y
    float m = dy / (x2 + 1 - x1);
    uint8_t temp = 0;
    // Serial.println(m);
    for (uint8_t x = 0; x <= (x2 - x1); x++)
    {
        // Serial.print((m * x + y1) + 0.5f);
        // Serial.print(" ");
        // Serial.println(x + x1);
        uint8_t y = (uint8_t)(m * x + y1) + 0.5f;
        temp = (uint8_t)(y * coloumns / 8) + ((x + x1) / 8);
        setBuffer(r, g, b, temp, x + x1);
    }
}

void Panel::drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color, bool fill)
{ // draws a circle at the coords with radius and color
    // get colors

    cnvColor(color, &r, &g, &b);
    uint8_t temp = 0;
    int xC;
    int yC;

    if (fill)
    {
        // draw outline
        for (uint8_t i = 1; i < 180; i++)
        {
            xC = x + (radius - 0.1) * cos(i * 0.035) + 0.5;
            yC = y + (radius - 0.1) * sin(i * 0.035) + 0.5;
            temp = (uint8_t)(yC * coloumns / 8) + xC / 8;
            setBuffer(r, g, b, temp, xC);
        }
        // check if point in circle, then fill
        for (uint8_t i = x - radius; i < x + radius; i++)
        {
            for (uint8_t j = y - radius; j < y + radius; j++)
            {
                if ((x - i) * (x - i) + (y - j) * (y - j) < ((radius - 0.5) * (radius - 0.5)))
                {
                    temp = (j * coloumns / 8) + i / 8;
                    setBuffer(r, g, b, temp, i);
                }
            }
        }
        // todo learn for finals
    }
    else
    {
        // draw circle outline
        for (uint8_t i = 1; i < 180; i++)
        {
            // draws a circle using trigonomic formulas
            xC = x + radius * cos(i * 0.035) + 0.5;
            yC = y + radius * sin(i * 0.035) + 0.5;
            // create index
            temp = (uint8_t)(yC * coloumns / 8) + xC / 8;
            setBuffer(r, g, b, temp, xC);
        }
    }
}

void Panel::drawChar(uint8_t x, uint8_t y, char letter, uint16_t color)
{ // deprecated, but probably faster
    // color for the char

    cnvColor(color, &r, &g, &b);
    // iterate through the character line by line
    uint8_t temp = 0;
    char out;
    for (uint8_t i = 0; i < 5; i++)
    {
        out = getFontLine(letter, i);
        // iterate through the character bit by bit
        for (uint8_t j = 4; j > 0; --j)
        {
            temp = ((y + i) * (coloumns / 8) + (x + 4 - j) / 8);
            // shift by j and check for bit set
            if (out & (1 << j))
            {
                // set pixel at i and j
                setBuffer(r, g, b, temp, x + 4 - j);
            }
        }
    }
}

void Panel::drawBigChar(uint8_t x, uint8_t y, char letter, uint16_t color, uint8_t size_modifier)
{ // new with scaling, but may be slower
    // color for the char
    cnvColor(color, &r, &g, &b);

    //  Serial.println("drawing char");

    // x = (x>64)*(x-64)+(x<64)*(x);

    // iterate through the character line by line
    uint8_t temp = 0;
    char out;
    for (uint8_t i = 0; i < 5 * size_modifier; i++)
    {
        out = getFontLine(letter, i / size_modifier);
        Serial.println(out);
        // iterate through the character bit by bit
        for (uint8_t j = 4 * size_modifier; j > 0; --j)
        {
            temp = ((y + i) * (coloumns / 8) + (x + 4 * size_modifier - j) / 8);
            // shift by j and check for bit set
            if (out & (1 << j / size_modifier))
            {
                // set pixel at i and j
                setBuffer(r, g, b, temp, x + 4 * size_modifier - j);
            }
        }
    }
}
