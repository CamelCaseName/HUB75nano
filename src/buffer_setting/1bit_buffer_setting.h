#ifndef HUB75NANO_1BIT_BUFFER_SETTING_H
#define HUB75NANO_1BIT_BUFFER_SETTING_H

#ifndef PANEL_FLASH
#ifndef PANEL_BIG

#include "buffer_common.h"

void _setSmallBuffer(uint8_t x, uint8_t y, Color color)
{
    // dont bother if outside of the panel
    if (x >= PANEL_X || y >= PANEL_Y)
    {
        return;
    }
    // flipping
#ifdef PANEL_FLIP_VERTICAL
    y = PANEL_Y - y;
#endif
#ifdef PANEL_FLIP_HORIZONTAL
    x = PANEL_X - x;
#endif
    if (y < (PANEL_Y / 2))
    {
        // we are in upper half of pixels
        uint16_t index = ((y * PANEL_X) + x) / 4;
        switch (x & 3)
        {
        case 0: /*first pixel*/
            buffer[index].redUpperBit1Led1 = color.red;
            buffer[index].greenUpperBit1Led1 = color.green;
            buffer[index].blueUpperBit1Led1 = color.blue;
            break;
        case 1: /*second pixel*/
            buffer[index].redUpperBit1Led2 = color.red;
            buffer[index].greenUpperBit1Led2 = color.green;
            buffer[index].blueUpperBit1Led2 = color.blue;
            break;
        case 2: /*third pixel*/
            buffer[index].redUpperBit1Led3 = color.red;
            buffer[index].greenUpperBit1Led3 = color.green;
            buffer[index].blueUpperBit1Led3 = color.blue;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redUpperBit1Led4 = color.red;
            buffer[index].greenUpperBit1Led4 = color.green;
            buffer[index].blueUpperBit1Led4 = color.blue;
            break;
        default:
            break;
        }
    }
    else
    {
        y -= (PANEL_Y / 2);
        // we are in lower half of pixels
        uint16_t index = (y * PANEL_X + x) / 4;
        switch (x & 3)
        {
        case 0: /*first pixel*/
            buffer[index].redLowerBit1Led1 = color.red;
            buffer[index].greenLowerBit1Led1 = color.green;
            buffer[index].blueLowerBit1Led1 = color.blue;
            break;
        case 1: /*second pixel*/
            buffer[index].redLowerBit1Led2 = color.red;
            buffer[index].greenLowerBit1Led2 = color.green;
            buffer[index].blueLowerBit1Led2 = color.blue;
            break;
        case 2: /*third pixel*/
            buffer[index].redLowerBit1Led3 = color.red;
            buffer[index].greenLowerBit1Led3 = color.green;
            buffer[index].blueLowerBit1Led3 = color.blue;
            break;
        case 3: /*fourth pixel*/
            buffer[index].redLowerBit1Led4 = color.red;
            buffer[index].greenLowerBit1Led4 = color.green;
            buffer[index].blueLowerBit1Led4 = color.blue;
            break;
        default:
            break;
        }
    }
}

void _setSmallBuffer4x(uint8_t x, uint8_t y, uint8_t block_count, Color color)
{
#ifdef PANEL_FLIP_VERTICAL
    y = PANEL_Y - y;
#endif
#ifdef PANEL_FLIP_HORIZONTAL
    x = PANEL_X - x;
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

        // temp buffers to store the cleaned values
        uint8_t lower, mid, higher;
        uint8_t *start = (uint8_t *)&buffer[index];

        // clean and cache the bits needed for thsi half
        lower = ((*start) & LED_SHORT_MASK_UPPER_1);
        start++;
        mid = ((*start) & LED_SHORT_MASK_UPPER_2);
        start++;
        higher = ((*start) & LED_SHORT_MASK_UPPER_3);
        start++;

        for (uint8_t i = 1; i < block_count; i++)
        {
            // apply the masks so we only copy the one half of the pixels we are "allowed" to
            *start &= LED_SHORT_MASK_LOWER_1;
            *start |= lower;
            start++;
            *start &= LED_SHORT_MASK_LOWER_2;
            *start |= mid;
            start++;
            *start &= LED_SHORT_MASK_LOWER_3;
            *start |= higher;
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

        // temp buffers to store the cleaned values
        uint8_t lower, mid, higher;
        uint8_t *start = (uint8_t *)&buffer[index];

        // clean and cache the bits needed for thsi half
        lower = ((*start) & LED_SHORT_MASK_LOWER_1);
        start++;
        mid = ((*start) & LED_SHORT_MASK_LOWER_2);
        start++;
        higher = ((*start) & LED_SHORT_MASK_LOWER_3);
        start++;

        for (uint8_t i = 1; i < block_count; i++)
        {
            // apply the masks so we only copy the one half of the pixels we are "allowed" to
            *start &= LED_SHORT_MASK_UPPER_1;
            *start |= lower;
            start++;
            *start &= LED_SHORT_MASK_UPPER_2;
            *start |= mid;
            start++;
            *start &= LED_SHORT_MASK_UPPER_3;
            *start |= higher;
            start++;
        }
    }
}

#endif
#endif
#endif // HUB75NANO_1BIT_BUFFER_SETTING_H