#include "Panel.h"
// this sketch should ouptut serial input to the panel

//          IMPORTANT!!
//
// in order to run this sketch, you must go into panel.h and remove "#define BIG", or comment it. (line 41)
// The library will very likely be in your arduino libary folder
// C:\Users\*username*\Documents\Arduino\libraries\HUB75nano
// go in there, and do as said above. please.
//

#ifndef BIG

Panel panel(32, 64);
char out[81];
uint8_t length = 0;
uint8_t oldlength;
uint8_t fcolor = 3;
uint8_t bgcolor = 2;
char t;

void setup()
{
    Serial.begin(115200);
    panel.createBufferBG(bgcolor);
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
                panel.displayBuffer();
            }
            else if (t < 32)
            {
                if (t < 10)
                {
                    fcolor = t; // r>= 0, < 8
                }
                else if (t >= 20)
                {
                    bgcolor = t - 20;
                }
                else
                {
                }
            }
            else
            {
                out[strlen(out)] = t;
            }
            panel.displayBuffer();
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
                    panel.displayBuffer();
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
                panel.displayBuffer();
            }
        }

        for (uint8_t i = oldlength; i < length; i++)
        {
            /*if (out[i] == '\n') {
                out[i] == ' ';
                for (uint8_t j = i + 1; j < length; j++) {
                    out[i % 16 + ((i / 16) * 16) + length - j] = out[j];
                    out[j] == ' ';
                }
            }*/
            panel.drawChar((i % 16) * 4, (i / 16) * 6 + 1, out[i], fcolor);
            panel.displayBuffer();
        }
        panel.displayBuffer();
    }
    panel.displayBuffer();
}

//"error handleing"
#else
void setup()
{
    Serial.begin(115200);
}
void loop()
{
    Serial.println("It will not work!!!!!!");
    Serial.println("you will see ram blinking around, and you will write  wrong adresses");
    Serial.println("in order to run this sketch, you must go into panel.h and remove \"#define BIG\", or comment it. (line 41)");
}
#endif // BIG
