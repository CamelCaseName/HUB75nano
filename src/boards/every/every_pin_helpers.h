#ifndef HUB75NANO_IOT_PIN_HELPERS_H
#define HUB75NANO_IOT_PIN_HELPERS_H

#define PA00 0
#define PA01 1
#define PA02 2
#define PA03 3
#define PA04 4
#define PA05 5
#define PA06 6
#define PA07 7

#define PB00 8
#define PB01 9
#define PB02 10
#define PB03 11
#define PB04 12
#define PB05 13

#define PC00 16
#define PC01 17
#define PC02 18
#define PC03 19
#define PC04 20
#define PC05 21
#define PC06 22
#define PC07 23

#define PD00 24
#define PD01 25
#define PD02 26
#define PD03 27
#define PD04 28
#define PD05 29
#define PD06 30
#define PD07 31

#define PE00 32
#define PE01 33
#define PE02 34
#define PE03 35

#define PF00 40
#define PF01 41
#define PF02 42
#define PF03 43
#define PF04 44
#define PF05 45
#define PF06 46

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
    return (uint8_t)(pin == 0    ? PC04
                     : pin == 1  ? PC05
                     : pin == 2  ? PA00
                     : pin == 3  ? PF05
                     : pin == 4  ? PC06
                     : pin == 5  ? PB02
                     : pin == 6  ? PF04
                     : pin == 7  ? PA01
                     : pin == 8  ? PE03
                     : pin == 9  ? PB00
                     : pin == 10 ? PB01
                     : pin == 11 ? PE00
                     : pin == 12 ? PE01
                     : pin == 13 ? PE02
                     : pin == 14 ? PD03
                     : pin == 15 ? PD02
                     : pin == 16 ? PD01
                     : pin == 17 ? PD00
                     : pin == 18 ? PA02
                     : pin == 19 ? PA03
                     : pin == 20 ? PD04
                     : pin == 21 ? PD05
                                 : NOT_A_PIN);
}

#endif // HUB75NANO_IOT_PIN_HELPERS_H