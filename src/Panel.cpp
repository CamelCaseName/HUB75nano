#include "Panel.h"

Panel::Panel(uint8_t height, uint8_t width)
{
    rows = height;
    coloumns = width;
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
    buffer = (LED *)malloc(sizeof(LED) * (bsize));
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
    case Panel::LIGHTRED:
        *rt = 2;
        *gt = 0;
        *bt = 0;
        break;
    case Panel::LIGHTGREEN:
        *rt = 0;
        *gt = 2;
        *bt = 0;
        break;
    case Panel::LIGHTBLUE:
        *rt = 0;
        *gt = 0;
        *bt = 2;
        break;
    case Panel::LIGHTWHITE:
        *rt = 2;
        *gt = 2;
        *bt = 2;
        break;
    case Panel::LIGHTCYAN:
        *rt = 0;
        *gt = 2;
        *bt = 2;
        break;
    case Panel::DARKYELLOW:
        *rt = 1;
        *gt = 2;
        *bt = 0;
        break;
    case Panel::LIGHTPURPLE:
        *rt = 2;
        *gt = 0;
        *bt = 2;
        break;
    case Panel::LIGHTYELLOW:
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
    case Panel::DEEPPURPLE:
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

    default:
        HIGH_TO_FULL_COLOR(c, rt, gt, bt);
        break;
    }
}

void Panel::createBufferBG(uint16_t c)
{ // creates a buffer used to display stuff
    // get colors
    cnvColor(c, &r, &g, &b);

    // initiates buffer accordingly
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

void Panel::selectLine(uint8_t i)
{ // selects one of the 16 lines, 0 based
    SET_ROW_PINS(i);
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

    for (uint8_t i = 0; i < 20; i++)
    {
        for (uint8_t row = 0; row < rows / 2; row++)
        {
            // switch through all rows
            sendWholeRow(r > i, g > i, b > i, r > i, g > i, b > i);
            selectLine(row);
        }
    }
}

void Panel::sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl)
{ // sends two pixels, one in upper half, one in lower half to display | first upper half values, the lower half
    // first red pin
    SET_RF(ru);
    // first green pin
    SET_GF(gu);
    // first blue pin
    SET_BF(bu);
    // second red pin
    SET_RS(rl);
    // second green pin
    SET_GS(gl);
    // second blue pin
    SET_BS(bl);
    CLOCK;
}

void Panel::sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl)
{ // sends two rows of pixels to display | first upper half values, the lower half
    // first red pin
    SET_RF(ru);
    // first green pin
    SET_GF(gu);
    // first blue pin
    SET_BF(bu);
    // second red pin
    SET_RS(rl);
    // second green pin
    SET_GS(gl);
    // second blue pin
    SET_BS(bl);

    for (uint8_t i = 0; i < coloumns; i++)
    {
        CLOCK;
    }
    LATCH_DATA;
}

void Panel::displayBuffer()
{ // puts the  buffer contents onto the
    for (uint8_t i = 0; i < (bsize / 2); i++)
    {
        l = i + (bsize / 2);
        k = i / 8;
        // first pixels
        // and checks wether pixel set in buffer, therefor deciding the pin level
        SETCOLOR((*(uint8_t *)(void *)(&buffer[i]) & 0b111) | ((*(uint8_t *)(void *)(&buffer[l]) & 0b111) << 3));
        CLOCK;
        // second pixels
        SETCOLOR(((*(uint8_t *)(void *)(&buffer[i]) & 0b111000) >> 3) | (*(uint8_t *)(void *)(&buffer[l]) & 0b111000));
        CLOCK;

        // 3rd pixels
        SETCOLOR(buffer[i].rc3 | buffer[i].gc3 << 1 | buffer[i].bc3 << 2 | buffer[l].rc3 << 3 | buffer[l].gc3 << 4 | buffer[l].bc3 << 5);

        // TODO
        // SETCOLOR(((*(uint8_t *)(void *)(&buffer[i]) & 56) >> 3) | (*(uint8_t *)(void *)(&buffer[l]) & 56));
        CLOCK;

        // 4th pixels
        SETCOLOR(buffer[i].rc4 | buffer[i].gc4 << 1 | buffer[i].bc4 << 2 | buffer[l].rc4 << 3 | buffer[l].gc4 << 4 | buffer[l].bc4 << 5);
        CLOCK;

        // 5th pixels
        SETCOLOR(buffer[i].rc5 | buffer[i].gc5 << 1 | buffer[i].bc5 << 2 | buffer[l].rc5 << 3 | buffer[l].gc5 << 4 | buffer[l].bc5 << 5);
        CLOCK;

        // 6th pixels
        SETCOLOR(buffer[i].rc6 | buffer[i].gc6 << 1 | buffer[i].bc6 << 2 | buffer[l].rc6 << 3 | buffer[l].gc6 << 4 | buffer[l].bc6 << 5);
        CLOCK;

        // 7th pixels
        SETCOLOR(buffer[i].rc7 | buffer[i].gc7 << 1 | buffer[i].bc7 << 2 | buffer[l].rc7 << 3 | buffer[l].gc7 << 4 | buffer[l].bc7 << 5);
        CLOCK;

        // 8th pixels
        SETCOLOR(buffer[i].rc8 | buffer[i].gc8 << 1 | buffer[i].bc8 << 2 | buffer[l].rc8 << 3 | buffer[l].gc8 << 4 | buffer[l].bc8 << 5);
        CLOCK;

        if ((i + 1) % 8 == 0)
        {
            SET_ROW_PINS(k);
            LATCH_DATA;
        }
    }

#ifdef PANEL_BIG // only use when big buffer is wanted
    // to sort out half colors
    for (uint8_t i = 0; i < (bsize) / 2; i++)
    {
        l = i + (bsize / 2);
        k = i / 8;
        // first pixels
        // and checks wether pixel set in buffer, therefor deciding the pin level
        SET_RF(buffer[i].rc1 == 1);
        SET_GF(buffer[i].gc1 == 1);
        SET_BF(buffer[i].bc1 == 1);
        SET_RS(buffer[l].rc1 == 1);
        SET_GS(buffer[l].gc1 == 1);
        SET_BS(buffer[l].bc1 == 1);
        CLOCK;
        // second pixels
        SET_RF(buffer[i].rc2 == 1);
        SET_GF(buffer[i].gc2 == 1);
        SET_BF(buffer[i].bc2 == 1);
        SET_RS(buffer[l].rc2 == 1);
        SET_GS(buffer[l].gc2 == 1);
        SET_BS(buffer[l].bc2 == 1);
        CLOCK;

        // 3rd pixels
        SET_RF(buffer[i].rc3 == 1);
        SET_GF(buffer[i].gc3 == 1);
        SET_BF(buffer[i].bc3 == 1);
        SET_RS(buffer[l].rc3 == 1);
        SET_GS(buffer[l].gc3 == 1);
        SET_BS(buffer[l].bc3 == 1);
        CLOCK;

        // 4th pixels
        SET_RF(buffer[i].rc4 == 1);
        SET_GF(buffer[i].gc4 == 1);
        SET_BF(buffer[i].bc4 == 1);
        SET_RS(buffer[l].rc4 == 1);
        SET_GS(buffer[l].gc4 == 1);
        SET_BS(buffer[l].bc4 == 1);
        CLOCK;

        // 5th pixels
        SET_RF(buffer[i].rc5 == 1);
        SET_GF(buffer[i].gc5 == 1);
        SET_BF(buffer[i].bc5 == 1);
        SET_RS(buffer[l].rc5 == 1);
        SET_GS(buffer[l].gc5 == 1);
        SET_BS(buffer[l].bc5 == 1);
        CLOCK;

        // 6th pixels
        SET_RF(buffer[i].rc6 == 1);
        SET_GF(buffer[i].gc6 == 1);
        SET_BF(buffer[i].bc6 == 1);
        SET_RS(buffer[l].rc6 == 1);
        SET_GS(buffer[l].gc6 == 1);
        SET_BS(buffer[l].bc6 == 1);
        CLOCK;

        // 7th pixels
        SET_RF(buffer[i].rc7 == 1);
        SET_GF(buffer[i].gc7 == 1);
        SET_BF(buffer[i].bc7 == 1);
        SET_RS(buffer[l].rc7 == 1);
        SET_GS(buffer[l].gc7 == 1);
        SET_BS(buffer[l].bc7 == 1);
        CLOCK;

        // 8th pixels
        SET_RF(buffer[i].rc8 == 1);
        SET_GF(buffer[i].gc8 == 1);
        SET_BF(buffer[i].bc8 == 1);
        SET_RS(buffer[l].rc8 == 1);
        SET_GS(buffer[l].gc8 == 1);
        SET_BS(buffer[l].bc8 == 1);
        CLOCK;

        if ((i + 1) % 8 == 0)
        {
            SET_ROW_PINS(k);
            LATCH_DATA;
        }
    }
#endif // BIG
}

void Panel::clearBuffer(uint16_t c)
{
    // get colors
    cnvColor(c, &r, &g, &b);

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
    fillScreenColor(OCEANBLUE);
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

void Panel::drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t c, bool fill)
{ // draws a rect filled ro not filled with the given color at coords (landscape, origin in upper left corner)
    // get colors
    cnvColor(c, &r, &g, &b);

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

void Panel::drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t c)
{ // draws a line with color at coords given, must be left to right
    // get colors

    cnvColor(c, &r, &g, &b);

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

void Panel::drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t c, bool fill)
{ // draws a circle at the coords with radius and color
    // get colors

    cnvColor(c, &r, &g, &b);
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

void Panel::drawChar(uint8_t x, uint8_t y, char ch, uint16_t c)
{ // deprecated, but probably faster
    // color for the char

    cnvColor(c, &r, &g, &b);
    // iterate through the character line by line
    uint8_t temp = 0;
    char out;
    for (uint8_t i = 0; i < 5; i++)
    {
        out = getFontLine(ch, i);
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

void Panel::drawBigChar(uint8_t x, uint8_t y, char ch, uint16_t c, uint8_t size_modifier)
{ // new with scaling, but may be slower
    // color for the char
    cnvColor(c, &r, &g, &b);

    //  Serial.println("drawing char");

    // x = (x>64)*(x-64)+(x<64)*(x);

    // iterate through the character line by line
    uint8_t temp = 0;
    char out;
    for (uint8_t i = 0; i < 5 * size_modifier; i++)
    {
        out = getFontLine(ch, i / size_modifier);
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
