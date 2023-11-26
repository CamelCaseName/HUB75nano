#ifndef HUB75NANO_IOT_PIN_HELPERS_H
#define HUB75NANO_IOT_PIN_HELPERS_H

// this is the package pin number
#define AREF 33

#define PA00 0
#define PA01 1
#define PA02 2
#define PA03 3
#define PA04 4
#define PA05 5
#define PA06 6
#define PA07 7
#define PA08 8
#define PA09 9
#define PA10 10
#define PA11 11
#define PA12 12
#define PA13 13
#define PA14 14
#define PA15 15
#define PA16 16
#define PA17 17
#define PA18 18
#define PA19 19
#define PA20 20
#define PA21 21
#define PA22 22
#define PA23 23
#define PA24 24
#define PA25 25
#define PA26 26
#define PA27 27
#define PA28 28
#define PA29 29
#define PA30 30
#define PA31 31

#define PB00 (32 + 0)
#define PB01 (32 + 1)
#define PB02 (32 + 2)
#define PB03 (32 + 3)
#define PB04 (32 + 4)
#define PB05 (32 + 5)
#define PB06 (32 + 6)
#define PB07 (32 + 7)
#define PB08 (32 + 8)
#define PB09 (32 + 9)
#define PB10 (32 + 10)
#define PB11 (32 + 11)
#define PB12 (32 + 12)
#define PB13 (32 + 13)
#define PB14 (32 + 14)
#define PB15 (32 + 15)
#define PB16 (32 + 16)
#define PB17 (32 + 17)
#define PB18 (32 + 18)
#define PB19 (32 + 19)
#define PB20 (32 + 20)
#define PB21 (32 + 21)
#define PB22 (32 + 22)
#define PB23 (32 + 23)
#define PB24 (32 + 24)
#define PB25 (32 + 25)
#define PB26 (32 + 26)
#define PB27 (32 + 27)
#define PB28 (32 + 28)
#define PB29 (32 + 29)
#define PB30 (32 + 30)
#define PB31 (32 + 31)

constexpr uint8_t port_from_pin(uint8_t pin)
{
    return (uint8_t)(pin < 32   ? PORTA
                     : pin < 64 ? PORTB
                                : NOT_A_PORT);
}

constexpr uint8_t bit_from_pin(uint8_t pin)
{
    return (uint8_t)(pin < 32   ? pin
                     : pin < 64 ? (pin - 32)
                                : NOT_A_PORT);
}

constexpr uint8_t arduino_pin_to_avr_pin(uint8_t pin)
{
    return (uint8_t)(pin == 0    ? PB22
                     : pin == 1  ? PB23
                     : pin == 2  ? PB10
                     : pin == 3  ? PB11
                     : pin == 4  ? PA07
                     : pin == 5  ? PA05
                     : pin == 6  ? PA04
                     : pin == 7  ? PA06
                     : pin == 8  ? PA18
                     : pin == 9  ? PA20
                     : pin == 10 ? PA21
                     : pin == 11 ? PA16
                     : pin == 12 ? PA19
                     : pin == 13 ? PA17
                     : pin == 14 ? PA02
                     : pin == 15 ? PB02
                     : pin == 16 ? PA11
                     : pin == 17 ? PA10
                     : pin == 18 ? PB08
                     : pin == 19 ? PB09
                     : pin == 20 ? PA09
                     : pin == 21 ? PB03
                     : pin == 33 ? PA03
                                 : NOT_A_PORT);
}
#endif // HUB75NANO_IOT_PIN_HELPERS_H