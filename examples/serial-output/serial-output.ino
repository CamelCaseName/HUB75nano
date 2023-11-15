
#define PANEL_BIG
#include "HUB75nano.h"
// this sketch should ouptut serial input to the panel

Panel panel = {};
char out[81];
uint8_t length = 0;
uint8_t oldlength;
Color fcolor = Colors::RED;
Color bgcolor = Colors::DARKERBLUE;
char t;

void setup()
{
    Serial.begin(115200);
    panel.fillBuffer(bgcolor);
}

// example text to send in two parts, because murphys law:
//
// Lorem ipsum dolor sit amet, consectetur adipisici elit,
//  sed eiusmod tempor inci
//
void loop()
{
    if (Serial.available())
    {
        if (strlen(out) < 80)
        {
            t = (char)Serial.read();
            // Serial.print(t);
            if (t == 12)
            {
                for (uint8_t i = 0; i < 81; i++)
                {
                    out[i] = '\0';
                }
                oldlength = 0;
                length = 0;
                // Serial.println("clearing");
                panel.fillBuffer(bgcolor);
            }
            else if (t < 32)
            {
                if (t < 10)
                {
                    fcolor = {.color_444 = (uint16_t)t}; // r>= 0, < 8
                }
                else if (t >= 20)
                {
                    bgcolor = {.color_444 = (uint16_t)(t - 20)};
                }
            }
            else
            {
                out[strlen(out)] = t;
            }
        }
        oldlength = length;
        length = strlen(out);

        if (length >= 80 && Serial.available())
        {
            t = (char)Serial.read();
            if (t < 32)
            {
                if (t == 12)
                {
                    for (uint8_t i = 0; i < 81; i++)
                    {
                        out[i] = '\0';
                    }
                    oldlength = 0;
                    length = 0;
                    // Serial.println("clearing");
                    panel.fillBuffer(bgcolor);
                }
                else
                {
                    // get rid of all non text chars
                    while (t > 10 && t < 20)
                    {
                        t = (char)Serial.read();
                    }
                    // save first text char
                    out[0] = t;
                }
            }
            else
            {
                for (uint8_t i = 0; i < 81; i++)
                {
                    out[i] = '\0';
                }
                oldlength = 0;
                length = 0;
                // Serial.println("clearing");
                panel.fillBuffer(bgcolor);
            }
        }

        for (uint8_t i = oldlength; i < length; i++)
        {
            panel.drawChar((i % 16) * 4, (i / 16) * 6 + 1, out[i], fcolor);
        }
    }
    panel.displayBuffer();
}
