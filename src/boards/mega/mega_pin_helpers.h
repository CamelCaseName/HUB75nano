#ifndef HUB75NANO_MEGA_PIN_HELPERS_H
#define HUB75NANO_MEGA_PIN_HELPERS_H

#include <Arduino.h>

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 8
#define PB1 9
#define PB2 10
#define PB3 11
#define PB4 12
#define PB5 13
#define PB6 14
#define PB7 15

#define PC0 16
#define PC1 17
#define PC2 18
#define PC3 19
#define PC4 20
#define PC5 21
#define PC6 22
#define PC7 23

#define PD0 24
#define PD1 25
#define PD2 26
#define PD3 27
#define PD4 28
#define PD5 29
#define PD6 30
#define PD7 31

#define PE0 32
#define PE1 33
#define PE2 34
#define PE3 35
#define PE4 36
#define PE5 37
#define PE6 38
#define PE7 39

#define PF0 40
#define PF1 41
#define PF2 42
#define PF3 43
#define PF4 44
#define PF5 45
#define PF6 46
#define PF7 47

#define PG0 48
#define PG1 49
#define PG2 50
#define PG3 51
#define PG4 51
#define PG5 53

#define PH0 56
#define PH1 57
#define PH2 58
#define PH3 59
#define PH4 60
#define PH5 61
#define PH6 62
#define PH7 63

#define PJ0 64
#define PJ1 65
#define PJ2 66
#define PJ3 67
#define PJ4 68
#define PJ5 69
#define PJ6 70
#define PJ7 71

#define PK0 72
#define PK1 73
#define PK2 74
#define PK3 75
#define PK4 76
#define PK5 77
#define PK6 78
#define PK7 79

#define PL0 80
#define PL1 81
#define PL2 82
#define PL3 83
#define PL4 84
#define PL5 85
#define PL6 86
#define PL7 87

#define PORTA_OFFSET 0
#define PORTB_OFFSET 1
#define PORTC_OFFSET 2
#define PORTD_OFFSET 3
#define PORTE_OFFSET 4
#define PORTF_OFFSET 5
#define PORTG_OFFSET 6
#define PORTH_OFFSET 7
#define PORTJ_OFFSET 8
#define PORTK_OFFSET 9
#define PORTL_OFFSET 10

constexpr volatile uint8_t *port_from_pin(uint8_t pin)
{
    return (pin < 8    ? &PORTA
            : pin < 16 ? &PORTB
            : pin < 24 ? &PORTC
            : pin < 32 ? &PORTD
            : pin < 40 ? &PORTE
            : pin < 48 ? &PORTF
            : pin < 56 ? &PORTG
            : pin < 64 ? &PORTH
            : pin < 72 ? &PORTJ
            : pin < 80 ? &PORTK
            : pin < 88 ? &PORTL
                       : (volatile uint8_t *)NOT_A_PORT);
}

constexpr uint8_t bit_from_pin(uint8_t pin)
{
    return (uint8_t)(pin < 8    ? pin
                     : pin < 16 ? pin - 8
                     : pin < 24 ? pin - 16
                     : pin < 32 ? pin - 24
                     : pin < 40 ? pin - 32
                     : pin < 48 ? pin - 40
                     : pin < 56 ? pin - 48
                     : pin < 64 ? pin - 56
                     : pin < 72 ? pin - 64
                     : pin < 80 ? pin - 72
                     : pin < 88 ? pin - 80
                                : NOT_A_PORT);
}

constexpr uint8_t arduino_pin_to_avr_pin(uint8_t pin)
{
    return (uint8_t)(pin == 0    ? PE0
                     : pin == 1  ? PE1
                     : pin == 2  ? PE4
                     : pin == 3  ? PE5
                     : pin == 4  ? PG5
                     : pin == 5  ? PE3
                     : pin == 6  ? PH3
                     : pin == 7  ? PH4
                     : pin == 8  ? PH5
                     : pin == 9  ? PH6
                     : pin == 10 ? PB4
                     : pin == 11 ? PB5
                     : pin == 12 ? PB6
                     : pin == 13 ? PB7
                     : pin == 14 ? PJ1
                     : pin == 15 ? PJ0
                     : pin == 16 ? PH1
                     : pin == 17 ? PH0
                     : pin == 18 ? PD3
                     : pin == 19 ? PD2
                     : pin == 20 ? PD1
                     : pin == 21 ? PD0
                     : pin == 22 ? PA0
                     : pin == 23 ? PA1
                     : pin == 24 ? PA2
                     : pin == 25 ? PA3
                     : pin == 26 ? PA4
                     : pin == 27 ? PA5
                     : pin == 28 ? PA6
                     : pin == 29 ? PA7
                     : pin == 30 ? PC7
                     : pin == 31 ? PC6
                     : pin == 32 ? PC5
                     : pin == 33 ? PC4
                     : pin == 34 ? PC3
                     : pin == 35 ? PC2
                     : pin == 36 ? PC1
                     : pin == 37 ? PC0
                     : pin == 38 ? PD7
                     : pin == 39 ? PG2
                     : pin == 40 ? PG1
                     : pin == 41 ? PG0
                     : pin == 42 ? PL7
                     : pin == 43 ? PL6
                     : pin == 44 ? PL5
                     : pin == 45 ? PL4
                     : pin == 46 ? PL3
                     : pin == 47 ? PL2
                     : pin == 48 ? PL1
                     : pin == 49 ? PL0
                     : pin == 50 ? PB3
                     : pin == 51 ? PB2
                     : pin == 52 ? PB1
                     : pin == 53 ? PB0
                     : pin == 54 ? PF0
                     : pin == 55 ? PF1
                     : pin == 56 ? PF2
                     : pin == 57 ? PF3
                     : pin == 58 ? PF4
                     : pin == 59 ? PF5
                     : pin == 60 ? PF6
                     : pin == 61 ? PF7
                     : pin == 62 ? PK0
                     : pin == 63 ? PK1
                     : pin == 64 ? PK2
                     : pin == 65 ? PK3
                     : pin == 66 ? PK4
                     : pin == 67 ? PK5
                     : pin == 68 ? PK6
                     : pin == 69 ? PK7
                                 : NOT_A_PIN);
}

#endif // HUB75NANO_MEGA_PIN_HELPERS_H