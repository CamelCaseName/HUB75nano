#ifndef HUB75NANO_EVERY_PIN_HELPER_H
#define HUB75NANO_EVERY_PIN_HELPER_H

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

#define PF0 40
#define PF1 41
#define PF2 42
#define PF3 43
#define PF4 44
#define PF5 45
#define PF6 46

#define PORTA_OFFSET 0
#define PORTB_OFFSET 1
#define PORTC_OFFSET 2
#define PORTD_OFFSET 3
#define PORTE_OFFSET 4
#define PORTF_OFFSET 5

constexpr uint8_t port_from_pin(uint8_t pin)
{
    return (uint8_t)(pin < 8    ? PORTA_OFFSET
                     : pin < 16 ? PORTB_OFFSET
                     : pin < 24 ? PORTC_OFFSET
                     : pin < 32 ? PORTD_OFFSET
                     : pin < 40 ? PORTE_OFFSET
                     : pin < 48 ? PORTF_OFFSET
                                : NOT_A_PORT);
}

constexpr uint8_t bit_from_pin(uint8_t pin)
{
    return (uint8_t)(pin < 8    ? pin
                     : pin < 16 ? pin - 8
                     : pin < 24 ? pin - 16
                     : pin < 32 ? pin - 24
                     : pin < 40 ? pin - 32
                     : pin < 48 ? pin - 40
                                : NOT_A_PORT);
}

constexpr uint8_t arduino_pin_to_avr_pin(uint8_t pin)
{
    return (uint8_t)(pin == 0    ? PC4
                     : pin == 1  ? PC5
                     : pin == 2  ? PA0
                     : pin == 3  ? PF5
                     : pin == 4  ? PC6
                     : pin == 5  ? PB2
                     : pin == 6  ? PF4
                     : pin == 7  ? PA1
                     : pin == 8  ? PE3
                     : pin == 9  ? PB0
                     : pin == 10 ? PB1
                     : pin == 11 ? PE0
                     : pin == 12 ? PE1
                     : pin == 13 ? PE2
                     : pin == 14 ? PD3
                     : pin == 15 ? PD2
                     : pin == 16 ? PD1
                     : pin == 17 ? PD0
                     : pin == 18 ? PA2
                     : pin == 19 ? PA3
                     : pin == 20 ? PD4
                     : pin == 21 ? PD5
                                 : NOT_A_PIN);
}

#endif // HUB75NANO_EVERY_PIN_HELPER_H