#ifndef HUB75NANO_2BIT_BUFFER_SETTING_H
#define HUB75NANO_2BIT_BUFFER_SETTING_H
#ifndef PANEL_FLASH
#ifdef PANEL_BIG

#include "buffer_common.h"

void _setBigBuffer(uint8_t x, uint8_t y, Color color)
{
    // dont bother if outside of the panel
    if (x >= PANEL_X || y >= PANEL_Y)
    {
        return;
    }
    // flipping
#ifdef PANEL_FLIP_VERTICAL
    y = PANEL_Y - y - 1;
#endif
#ifdef PANEL_FLIP_HORIZONTAL
    x = PANEL_X - x - 1;
#endif
    if (y < (PANEL_Y / 2))
    {
        // we are in upper half of pixels
        uint8_t index = (y * PANEL_X + x) / 4;
        switch (x & 3)
        {
        case 0: /*first pixel*/
            buffer[index].redUpperBit1Led1 = color.red;
            buffer[index].greenUpperBit1Led1 = color.green;
            buffer[index].blueUpperBit1Led1 = color.blue;
            buffer[index].redUpperBit2Led1 = color.red >> (uint8_t)1;
            buffer[index].greenUpperBit2Led1 = color.green >> (uint8_t)1;
            buffer[index].blueUpperBit2Led1 = color.blue >> (uint8_t)1;
            break;
        case 1: /*second pixel*/
            buffer[index].redUpperBit1Led2 = color.red;
            buffer[index].greenUpperBit1Led2 = color.green;
            buffer[index].blueUpperBit1Led2 = color.blue;
            buffer[index].redUpperBit2Led2 = color.red >> (uint8_t)1;
            buffer[index].greenUpperBit2Led2 = color.green >> (uint8_t)1;
            buffer[index].blueUpperBit2Led2 = color.blue >> (uint8_t)1;
            break;
        case 2: /*third pixel*/
            buffer[index].redUpperBit1Led3 = color.red;
            buffer[index].greenUpperBit1Led3 = color.green;
            buffer[index].blueUpperBit1Led3 = color.blue;
            buffer[index].redUpperBit2Led3 = color.red >> (uint8_t)1;
            buffer[index].greenUpperBit2Led3 = color.green >> (uint8_t)1;
            buffer[index].blueUpperBit2Led3 = color.blue >> (uint8_t)1;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redUpperBit1Led4 = color.red;
            buffer[index].greenUpperBit1Led4 = color.green;
            buffer[index].blueUpperBit1Led4 = color.blue;
            buffer[index].redUpperBit2Led4 = color.red >> (uint8_t)1;
            buffer[index].greenUpperBit2Led4 = color.green >> (uint8_t)1;
            buffer[index].blueUpperBit2Led4 = color.blue >> (uint8_t)1;
            break;
        default:
            break;
        }
    }
    else
    {
        y -= (PANEL_Y / 2);
        // we are in lower half of pixels
        uint8_t index = (y * PANEL_X + x) / 4;
        switch (x & 3)
        {
        case 0:
            buffer[index].redLowerBit1Led1 = color.red;
            buffer[index].greenLowerBit1Led1 = color.green;
            buffer[index].blueLowerBit1Led1 = color.blue;
            buffer[index].redLowerBit2Led1 = color.red >> (uint8_t)1;
            buffer[index].greenLowerBit2Led1 = color.green >> (uint8_t)1;
            buffer[index].blueLowerBit2Led1 = color.blue >> (uint8_t)1;
            break;
        case 1: /*second pixel*/
            buffer[index].redLowerBit1Led2 = color.red;
            buffer[index].greenLowerBit1Led2 = color.green;
            buffer[index].blueLowerBit1Led2 = color.blue;
            buffer[index].redLowerBit2Led2 = color.red >> (uint8_t)1;
            buffer[index].greenLowerBit2Led2 = color.green >> (uint8_t)1;
            buffer[index].blueLowerBit2Led2 = color.blue >> (uint8_t)1;
            break;
        case 2: /*third pixel*/
            buffer[index].redLowerBit1Led3 = color.red;
            buffer[index].greenLowerBit1Led3 = color.green;
            buffer[index].blueLowerBit1Led3 = color.blue;
            buffer[index].redLowerBit2Led3 = color.red >> (uint8_t)1;
            buffer[index].greenLowerBit2Led3 = color.green >> (uint8_t)1;
            buffer[index].blueLowerBit2Led3 = color.blue >> (uint8_t)1;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redLowerBit1Led4 = color.red;
            buffer[index].greenLowerBit1Led4 = color.green;
            buffer[index].blueLowerBit1Led4 = color.blue;
            buffer[index].redLowerBit2Led4 = color.red >> (uint8_t)1;
            buffer[index].greenLowerBit2Led4 = color.green >> (uint8_t)1;
            buffer[index].blueLowerBit2Led4 = color.blue >> (uint8_t)1;
            break;
        default:
            break;
        }
    }
}

void _setBigBuffer4x(uint8_t x, uint8_t y, uint8_t block_count, Color color)
{
#ifdef PANEL_FLIP_VERTICAL
    y = PANEL_Y - y - 1;
#endif
#ifdef PANEL_FLIP_HORIZONTAL
    x = PANEL_X - x - 1;
#endif
    if (y < (PANEL_Y / 2))
    {
        // we are in upper half of pixels
        uint16_t index = ((y * PANEL_X) + x) / 4;

        buffer[index].redUpperBit1Led1 = color.red;
        buffer[index].greenUpperBit1Led1 = color.green;
        buffer[index].blueUpperBit1Led1 = color.blue;
        buffer[index].redUpperBit1Led2 = color.red;
        buffer[index].greenUpperBit1Led2 = color.green;
        buffer[index].blueUpperBit1Led2 = color.blue;
        buffer[index].redUpperBit1Led3 = color.red;
        buffer[index].greenUpperBit1Led3 = color.green;
        buffer[index].blueUpperBit1Led3 = color.blue;
        buffer[index].redUpperBit1Led4 = color.red;
        buffer[index].greenUpperBit1Led4 = color.green;
        buffer[index].blueUpperBit1Led4 = color.blue;
        // second bit
        buffer[index].redUpperBit2Led1 = color.red >> (uint8_t)1;
        buffer[index].greenUpperBit2Led1 = color.green >> (uint8_t)1;
        buffer[index].blueUpperBit2Led1 = color.blue >> (uint8_t)1;
        buffer[index].redUpperBit2Led2 = color.red >> (uint8_t)1;
        buffer[index].greenUpperBit2Led2 = color.green >> (uint8_t)1;
        buffer[index].blueUpperBit2Led2 = color.blue >> (uint8_t)1;
        buffer[index].redUpperBit2Led3 = color.red >> (uint8_t)1;
        buffer[index].greenUpperBit2Led3 = color.green >> (uint8_t)1;
        buffer[index].blueUpperBit2Led3 = color.blue >> (uint8_t)1;
        buffer[index].redUpperBit2Led4 = color.red >> (uint8_t)1;
        buffer[index].greenUpperBit2Led4 = color.green >> (uint8_t)1;
        buffer[index].blueUpperBit2Led4 = color.blue >> (uint8_t)1;

        // temp buffers to store the cleaned values
        uint8_t lowest, lower, lowmid, mid, higher, highest;
        uint8_t *start = (uint8_t *)&buffer[index];

        // clean and cache the bits needed for thsi half
        lowest = ((*start) & LED_LONG_MASK_UPPER_1);
        start++;
        lower = ((*start) & LED_LONG_MASK_UPPER_2);
        start++;
        lowmid = ((*start) & LED_LONG_MASK_UPPER_3);
        start++;
        mid = ((*start) & LED_LONG_MASK_UPPER_4);
        start++;
        higher = ((*start) & LED_LONG_MASK_UPPER_5);
        start++;
        highest = ((*start) & LED_LONG_MASK_UPPER_6);
        start++;

#ifdef PANEL_FLIP_HORIZONTAL
        start -= block_count * 6;
#endif

        for (uint8_t i = 1; i < block_count; i++)
        {
            // apply the masks so we only copy the one half of the pixels we are "allowed" to
            *start &= LED_LONG_MASK_LOWER_1;
            *start |= lowest;
            start++;
            *start &= LED_LONG_MASK_LOWER_2;
            *start |= lower;
            start++;
            *start &= LED_LONG_MASK_LOWER_3;
            *start |= lowmid;
            start++;
            *start &= LED_LONG_MASK_LOWER_4;
            *start |= mid;
            start++;
            *start &= LED_LONG_MASK_LOWER_5;
            *start |= higher;
            start++;
            *start &= LED_LONG_MASK_LOWER_6;
            *start |= highest;
            start++;
        }
    }
    else
    {
        y -= (PANEL_Y / 2);
        // we are in lower half of pixels
        uint16_t index = ((y * PANEL_X) + x) / 4;

        buffer[index].redLowerBit1Led1 = color.red;
        buffer[index].greenLowerBit1Led1 = color.green;
        buffer[index].blueLowerBit1Led1 = color.blue;
        buffer[index].redLowerBit1Led2 = color.red;
        buffer[index].greenLowerBit1Led2 = color.green;
        buffer[index].blueLowerBit1Led2 = color.blue;
        buffer[index].redLowerBit1Led3 = color.red;
        buffer[index].greenLowerBit1Led3 = color.green;
        buffer[index].blueLowerBit1Led3 = color.blue;
        buffer[index].redLowerBit1Led4 = color.red;
        buffer[index].greenLowerBit1Led4 = color.green;
        buffer[index].blueLowerBit1Led4 = color.blue;
        // second bit
        buffer[index].redLowerBit2Led1 = color.red >> (uint8_t)1;
        buffer[index].greenLowerBit2Led1 = color.green >> (uint8_t)1;
        buffer[index].blueLowerBit2Led1 = color.blue >> (uint8_t)1;
        buffer[index].redLowerBit2Led2 = color.red >> (uint8_t)1;
        buffer[index].greenLowerBit2Led2 = color.green >> (uint8_t)1;
        buffer[index].blueLowerBit2Led2 = color.blue >> (uint8_t)1;
        buffer[index].redLowerBit2Led3 = color.red >> (uint8_t)1;
        buffer[index].greenLowerBit2Led3 = color.green >> (uint8_t)1;
        buffer[index].blueLowerBit2Led3 = color.blue >> (uint8_t)1;
        buffer[index].redLowerBit2Led4 = color.red >> (uint8_t)1;
        buffer[index].greenLowerBit2Led4 = color.green >> (uint8_t)1;
        buffer[index].blueLowerBit2Led4 = color.blue >> (uint8_t)1;

        // temp buffers to store the cleaned values
        uint8_t lowest, lower, lowmid, mid, higher, highest;
        uint8_t *start = (uint8_t *)&buffer[index];

        // clean and cache the bits needed for thsi half
        lowest = ((*start) & LED_LONG_MASK_LOWER_1);
        start++;
        lower = ((*start) & LED_LONG_MASK_LOWER_2);
        start++;
        lowmid = ((*start) & LED_LONG_MASK_LOWER_3);
        start++;
        mid = ((*start) & LED_LONG_MASK_LOWER_4);
        start++;
        higher = ((*start) & LED_LONG_MASK_LOWER_5);
        start++;
        highest = ((*start) & LED_LONG_MASK_LOWER_6);
        start++;

#ifdef PANEL_FLIP_HORIZONTAL
        start -= block_count * 6;
#endif

        for (uint8_t i = 1; i < block_count; i++)
        {
            // apply the masks so we only copy the one half of the pixels we are "allowed" to
            *start &= LED_LONG_MASK_UPPER_1;
            *start |= lowest;
            start++;
            *start &= LED_LONG_MASK_UPPER_2;
            *start |= lower;
            start++;
            *start &= LED_LONG_MASK_UPPER_3;
            *start |= lowmid;
            start++;
            *start &= LED_LONG_MASK_UPPER_4;
            *start |= mid;
            start++;
            *start &= LED_LONG_MASK_UPPER_5;
            *start |= higher;
            start++;
            *start &= LED_LONG_MASK_UPPER_6;
            *start |= highest;
            start++;
        }
    }
}

#endif
#endif
#endif // HUB75NANO_2BIT_BUFFER_SETTING_H