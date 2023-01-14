#include "Panel.h"

Panel::Panel()
{
    coloumns = PANEL_X;
    rows = PANEL_Y;
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
}

#ifndef PANEL_NO_BUFFER
void Panel::swapBuffer(const LED *newBuffer, uint8_t bufferLength)
{
    memcpy(buffer, newBuffer, bufferLength);
}
#endif
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
    HIGH_TO_FULL_COLOR(c, &red, &green, &blue); // gets first couple colors

    for (uint8_t i = 0; i < 16; i++)
    {
        for (uint8_t row = 0; row < rows / 2; row++)
        {
            // switch through all rows
            sendWholeRow(red > i, green > i, blue > i, red > i, green > i, blue > i);
            selectLine(row);
        }
    }
}

inline void Panel::sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl)
{ // sends two pixels, one in upper half, one in lower half to display | first upper half values, the lower half
    // set all pins at once
    SET_COLOR(ru | gu << 1 | bu << 2 | rl << 3 | gl << 4 | bl << 5);
    CLOCK;
}

void Panel::sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl)
{ // sends two rows of pixels to display | first upper half values, the lower half
    SET_COLOR(ru | gu << 1 | bu << 2 | rl << 3 | gl << 4 | bl << 5);

    for (uint8_t i = 0; i < coloumns; i++)
    {
        CLOCK;
    }
    LATCH_DATA;
}

#ifndef PANEL_NO_BUFFER
void Panel::fillBuffer(uint16_t color)
{
    // get colors
    HIGH_TO_FULL_COLOR(color, &red, &green, &blue);

    // fills the buffer
    for (uint8_t x = 0; x < PANEL_X; x++)
    {
        for (uint8_t y = 0; y < PANEL_X; y++)
        {
            setBuffer(x, y, red, green, blue);
        }
    }
}

void Panel::setBuffer(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue)
{
#ifndef PANEL_BIG
    if (y < (PANEL_Y / 2))
    {
        // we are in upper half of pixels
        uint8_t index = (y * coloumns + x) / 4;
        switch (x % 4)
        {
        case 0: /*first pixel*/
            buffer[index].redUpper1 = red;
            buffer[index].greenUpper1 = green;
            buffer[index].blueUpper1 = blue;
            break;
        case 1: /*second pixel*/
            buffer[index].redUpper2 = red;
            buffer[index].greenUpper2 = green;
            buffer[index].blueUpper2 = blue;
            break;
        case 2: /*third pixel*/
            buffer[index].redUpper3 = red;
            buffer[index].greenUpper3 = green;
            buffer[index].blueUpper3 = blue;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redUpper4 = red;
            buffer[index].greenUpper4 = green;
            buffer[index].blueUpper4 = blue;
            break;

        default:
            break;
        }
    }
    else
    {
        y -= (PANEL_Y / 2);
        // we are in lower half of pixels
        uint8_t index = (y * coloumns + x) / 4;
        switch (x % 4)
        {
        case 0: /*first pixel*/
            buffer[index].redLower1 = red;
            buffer[index].greenLower1 = green;
            buffer[index].blueLower1 = blue;
            break;
        case 1: /*second pixel*/
            buffer[index].redLower2 = red;
            buffer[index].greenLower2 = green;
            buffer[index].blueLower2 = blue;
            break;
        case 2: /*third pixel*/
            buffer[index].redLower3 = red;
            buffer[index].greenLower3 = green;
            buffer[index].blueLower3 = blue;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redLower4 = red;
            buffer[index].greenLower4 = green;
            buffer[index].blueLower4 = blue;
            break;

        default:
            break;
        }
    }

#else

    if (y < (PANEL_Y / 2))
    {
        // we are in upper half of pixels
        uint8_t index = (y * coloumns + x) / 4;
        switch (x % 4)
        {
        case 0: /*first pixel*/
            buffer[index].redUpperBit1Led1 = red;
            buffer[index].greenUpperBit1Led1 = green;
            buffer[index].blueUpperBit1Led1 = blue;
            buffer[index].redUpperBit2Led1 = red >> 1;
            buffer[index].greenUpperBit2Led1 = green >> 1;
            buffer[index].blueUpperBit2Led1 = blue >> 1;
            break;
        case 1: /*second pixel*/
            buffer[index].redUpperBit1Led2 = red;
            buffer[index].greenUpperBit1Led2 = green;
            buffer[index].blueUpperBit1Led2 = blue;
            buffer[index].redUpperBit2Led2 = red >> 1;
            buffer[index].greenUpperBit2Led2 = green >> 1;
            buffer[index].blueUpperBit2Led2 = blue >> 1;
            break;
        case 2: /*third pixel*/
            buffer[index].redUpperBit1Led3 = red;
            buffer[index].greenUpperBit1Led3 = green;
            buffer[index].blueUpperBit1Led3 = blue;
            buffer[index].redUpperBit2Led3 = red >> 1;
            buffer[index].greenUpperBit2Led3 = green >> 1;
            buffer[index].blueUpperBit2Led3 = blue >> 1;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redUpperBit1Led4 = red;
            buffer[index].greenUpperBit1Led4 = green;
            buffer[index].blueUpperBit1Led4 = blue;
            buffer[index].redUpperBit2Led4 = red >> 1;
            buffer[index].greenUpperBit2Led4 = green >> 1;
            buffer[index].blueUpperBit2Led4 = blue >> 1;
            break;

        default:
            break;
        }
    }
    else
    {
        y -= (PANEL_Y / 2);
        // we are in lower half of pixels
        uint8_t index = (y * coloumns + x) / 4;
        switch (x % 4)
        {
        case 0:
            buffer[index].redLowerBit1Led1 = red;
            buffer[index].greenLowerBit1Led1 = green;
            buffer[index].blueLowerBit1Led1 = blue;
            buffer[index].redLowerBit2Led1 = red >> 1;
            buffer[index].greenLowerBit2Led1 = green >> 1;
            buffer[index].blueLowerBit2Led1 = blue >> 1;
            break;
        case 1: /*second pixel*/
            buffer[index].redLowerBit1Led2 = red;
            buffer[index].greenLowerBit1Led2 = green;
            buffer[index].blueLowerBit1Led2 = blue;
            buffer[index].redLowerBit2Led2 = red >> 1;
            buffer[index].greenLowerBit2Led2 = green >> 1;
            buffer[index].blueLowerBit2Led2 = blue >> 1;
            break;
        case 2: /*third pixel*/
            buffer[index].redLowerBit1Led3 = red;
            buffer[index].greenLowerBit1Led3 = green;
            buffer[index].blueLowerBit1Led3 = blue;
            buffer[index].redLowerBit2Led3 = red >> 1;
            buffer[index].greenLowerBit2Led3 = green >> 1;
            buffer[index].blueLowerBit2Led3 = blue >> 1;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redLowerBit1Led4 = red;
            buffer[index].greenLowerBit1Led4 = green;
            buffer[index].blueLowerBit1Led4 = blue;
            buffer[index].redLowerBit2Led4 = red >> 1;
            buffer[index].greenLowerBit2Led4 = green >> 1;
            buffer[index].blueLowerBit2Led4 = blue >> 1;
            break;

        default:
            break;
        }
    }
#endif
}

void Panel::displayBuffer()
{ // puts the  buffer contents onto the panel
#ifndef PANEL_BIG
    for (uint16_t index = 0; index < PANEL_BUFFERSIZE; index++)
    {
        // one led struct contains bits in 3 bytes:
        // |23  22  21  20  19  18  17  16 |15  14  13  12  11  10  9   8  |7   6   5   4   3   2   1   0  |
        // |bl4:gl4:rl4:bu4:gu4:ru4:bl3:gl3|rl3:bu3:gu3:ru3:bl2:gl2:rl2:bu2|gu2:ru2:bl1:gl1:rl1:bu1:gu1:ru1|

        // first pixels
        SET_COLOR(*(uint8_t *)(&buffer[index]));
        CLOCK;

        // second pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(&buffer[index])) >> 6)));
        CLOCK;

        // 3rd pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(((uint8_t *)(&buffer[index]) + sizeof(uint8_t))))) >> 4));
        CLOCK;

        // 4th pixels
        SET_COLOR(((*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 2))) >> 2));
        CLOCK;

        if ((index + 1) % PANEL_CHUNKSIZE == 0) /*16 = 64 / 4 for 4 pixels per loop iteration*/
        {
            SET_ROW_PINS(index / PANEL_CHUNKSIZE);
            LATCH_DATA;
        }
    }
#else

    // one led struct contains bits in 6 bytes:

    // first 3
    // |23    22    21    20    19    18    17    16   |15    14    13    12    11    10    9     8    |7     6     5     4     3     2     1     0    |
    // |bl2b2:gl2b2:rl2b2:bu2b2:gu2b2:ru2b2:bl2b1:gl2b1|rl2b1:bu2b1:gu2b1:ru2b1:bl1b2:gl1b2:rl1b2:bu1b2|gu1b2:ru1b2:bl1b1:gl1b1:rl1b1:bu1b1:gu1b1:ru1b1|

    // second 3
    // |23    22    21    20    19    18    17    16   |15    14    13    12    11    10    9     8    |7     6     5     4     3     2     1     0    |
    // |bl4b2:gl4b2:rl4b2:bu4b2:gu4b2:ru4b2:bl4b1:gl4b1|rl4b1:bu4b1:gu4b1:ru4b1:bl3b2:gl3b2:rl3b2:bu3b2|gu3b2:ru3b2:bl3b1:gl3b1:rl3b1:bu3b1:gu3b1:ru3b1|

    // msb pass 1
    for (uint16_t index = 0; index < PANEL_BUFFERSIZE; index++)
    {
        // first pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(&buffer[index])) >> 6)));
        CLOCK;

        // second pixels
        SET_COLOR(((*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 2))) >> 2));
        CLOCK;

        // 3rd pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 3)))) >> 6));
        CLOCK;

        // 4th pixels
        SET_COLOR(((*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 5))) >> 2));
        CLOCK;

        if ((index + 1) % PANEL_CHUNKSIZE == 0)
        {
            SET_ROW_PINS(index / PANEL_CHUNKSIZE);
            LATCH_DATA;
        }
    }

    // lsb
    for (uint16_t index = 0; index < PANEL_BUFFERSIZE; index++)
    {
        // first pixels
        SET_COLOR(*((uint8_t *)(&buffer[index])));
        CLOCK;

        // second pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(((uint8_t *)(&buffer[index])) + sizeof(uint8_t)))) >> 4));
        CLOCK;

        // 3rd pixels
        SET_COLOR(*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 3)));
        CLOCK;

        // 4th pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 4)))) >> 4));
        CLOCK;

        if ((index + 1) % PANEL_CHUNKSIZE == 0)
        {
            SET_ROW_PINS(index / PANEL_CHUNKSIZE);
            LATCH_DATA;
        }
    }

    // msb pass 2
    for (uint16_t index = 0; index < PANEL_BUFFERSIZE; index++)
    {
        // first pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(&buffer[index])) >> 6)));
        CLOCK;

        // second pixels
        SET_COLOR(((*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 2))) >> 2));
        CLOCK;

        // 3rd pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 3)))) >> 6));
        CLOCK;

        // 4th pixels
        SET_COLOR(((*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 5))) >> 2));
        CLOCK;

        if ((index + 1) % PANEL_CHUNKSIZE == 0)
        {
            SET_ROW_PINS(index / PANEL_CHUNKSIZE);
            LATCH_DATA;
        }
    }

    // msb pass 3
    for (uint16_t index = 0; index < PANEL_BUFFERSIZE; index++)
    {
        // first pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(&buffer[index])) >> 6)));
        CLOCK;

        // second pixels
        SET_COLOR(((*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 2))) >> 2));
        CLOCK;

        // 3rd pixels
        SET_COLOR((uint8_t)((*((uint16_t *)(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 3)))) >> 6));
        CLOCK;

        // 4th pixels
        SET_COLOR(((*(((uint8_t *)(&buffer[index])) + (sizeof(uint8_t) * 5))) >> 2));
        CLOCK;

        if ((index + 1) % PANEL_CHUNKSIZE == 0)
        {
            SET_ROW_PINS(index / PANEL_CHUNKSIZE);
            LATCH_DATA;
        }
    }
#endif
}

void Panel::drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{ // draws a line with color between the coords given
    // get colors
    HIGH_TO_FULL_COLOR(color, &red, &green, &blue);

    // calculate both gradients
    int8_t dx = abs(x2 - x1);
    int8_t dy = -abs(y2 - y1);
    // create de-/increment values for walking the line
    int8_t sx = x1 < x2 ? 1 : -1;
    int8_t sy = y1 < y2 ? 1 : -1;
    // error corerction
    float err = dx + dy, e2;
    while (1)
    {
        setBuffer(x1, y1, red, green, blue);
        e2 = 2 * err;
        if (e2 >= dy)
        {
            if (x1 == x2)
                break;
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            if (y1 == y2)
                break;
            err += dx;
            y1 += sy;
        }
    }
}

void Panel::drawEllipse(uint8_t xm, uint8_t ym, uint8_t a, uint8_t b, uint16_t color, bool fill)
{
    // get colors
    HIGH_TO_FULL_COLOR(color, &red, &green, &blue);

    int8_t x = -a;
    int8_t y = 0; /* II. quadrant from bottom left to top right */
    int16_t a2 = a * a;
    int16_t b2 = b * b;
    int16_t e2 = b * b;
    int16_t err = x * (2 * e2 + x) + e2; /* error of 1.step */

    do
    {
        setBuffer(xm - x, ym + y, red, green, blue); /*   I. Quadrant */
        setBuffer(xm + x, ym + y, red, green, blue); /*  II. Quadrant */
        setBuffer(xm + x, ym - y, red, green, blue); /* III. Quadrant */
        setBuffer(xm - x, ym - y, red, green, blue); /*  IV. Quadrant */
        e2 = 2 * err;
        if (e2 >= (x * 2 + 1) * b2) /* e_xy+e_x > 0 */
            err += (++x * 2 + 1) * b2;
        if (e2 <= (y * 2 + 1) * a2) /* e_xy+e_y < 0 */
            err += (++y * 2 + 1) * a2;
    } while (x <= 0);

    while (y++ < b)
    {                                            /* to early stop of flat ellipses a=1, */
        setBuffer(xm, ym + y, red, green, blue); /* -> finish tip of ellipse */
        setBuffer(xm, ym - y, red, green, blue);
    }

    if (fill)
    {
        while (a > 0)
        {
            drawEllipse(xm, ym, --a, b, color, true);
        }
    }
}

void Panel::drawCircle(uint8_t xm, uint8_t ym, uint8_t radius, uint16_t color, bool fill)
{
    // draws a circle at the coords with radius and color
    // get colors
    HIGH_TO_FULL_COLOR(color, &red, &green, &blue);

    int8_t x = -radius;
    int8_t y = 0;
    int8_t new_radius = radius;
    int16_t err = 2 - 2 * radius; // bottom left to top right
    do
    {
        setBuffer(xm - x, ym + y, red, green, blue); //   I. Quadrant +x +y
        setBuffer(xm - y, ym - x, red, green, blue); //  II. Quadrant -x +y
        setBuffer(xm + x, ym - y, red, green, blue); // III. Quadrant -x -y
        setBuffer(xm + y, ym + x, red, green, blue); //  IV. Quadrant +x -y

        new_radius = err;
        if (new_radius <= y)
            err += ++y * 2 + 1;        // e_xy+e_y < 0
        if (new_radius > x || err > y) // e_xy+e_x > 0 or no 2nd y-step
            err += ++x * 2 + 1;        // -> x-step now
    } while (x < 0);

    if (fill) // fill works
    {
        // check if point in circle, then fill
        for (int8_t i = -radius; i < radius; i++)
        {
            for (int8_t j = -radius; j < radius; j++)
            {
                if (((int16_t)i * i + (int16_t)j * j) < ((radius - 0.5) * (radius - 0.5)))
                {
                    setBuffer(xm + i, ym + j, red, green, blue);
                }
            }
        }
    }
}

void Panel::drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color, bool fill)
{ // draws a rect filled ro not filled with the given color at coords (landscape, origin in upper left corner)
    // get colors
    HIGH_TO_FULL_COLOR(color, &red, &green, &blue);

    if (fill)
    {
        for (uint8_t i = x1; i <= x2; i++)
        {
            for (uint8_t j = y1; j <= y2; j++)
            {
                setBuffer(i, j, red, green, blue);
            }
        }
    }
    else
    {
        // left line
        for (uint8_t j = y1; j <= y2; j++)
        {
            setBuffer(x1, j, red, green, blue);
        }

        // right line
        for (uint8_t j = y1; j <= y2; j++)
        {
            setBuffer(x2, j, red, green, blue);
        }

        // top line
        for (uint8_t i = x1; i <= x2; i++)
        {
            setBuffer(i, y1, red, green, blue);
        }

        // bottom line
        for (uint8_t i = x1; i <= x2; i++)
        {
            setBuffer(i, y2, red, green, blue);
        }
    }
}

void Panel::drawSquare(uint8_t x, uint8_t y, uint8_t size, uint8_t color, bool fill)
{
    drawRect(x, y, x + size, y + size, color, fill);
}

void Panel::drawChar(uint8_t x, uint8_t y, char letter, uint16_t color)
{ // deprecated, but probably faster
    // color for the char

    HIGH_TO_FULL_COLOR(color, &red, &green, &blue);
    // iterate through the character line by line
    char out;
    for (uint8_t i = 0; i < 5; i++)
    {
        out = getFontLine(letter, i);
        // iterate through the character bit by bit
        for (uint8_t j = 4; j > 0; --j)
        {
            // shift by j and check for bit set
            if (out & (1 << j))
            {
                // set pixel at i and j
                setBuffer(x + 4 - j, y + i, red, green, blue);
            }
        }
    }
}

void Panel::drawBigChar(uint8_t x, uint8_t y, char letter, uint16_t color, uint8_t size_modifier)
{ // new with scaling, but may be slower
    // color for the char
    HIGH_TO_FULL_COLOR(color, &red, &green, &blue);

    // iterate through the character line by line
    char out;
    for (uint8_t i = 0; i < 5 * size_modifier; i++)
    {
        out = getFontLine(letter, i / size_modifier);
        // iterate through the character bit by bit
        for (uint8_t j = 4 * size_modifier; j > 0; --j)
        {
            // shift by j and check for bit set
            if (out & (1 << j / size_modifier))
            {
                // set pixel at i and j
                setBuffer(x + 4 * size_modifier - j, y + i, red, green, blue);
            }
        }
    }
}
#endif // PANEL_NO_BUFFER

// todo add drawing methods for
// - triangle with arbitrary points
// - triangle with right angle, rotation and side lengths
// - line with given width