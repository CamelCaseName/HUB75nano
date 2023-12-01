#ifndef HUB75NANO_UNO_R4_PIN_HELPER_H
#define HUB75NANO_UNO_R4_PIN_HELPER_H

#define P000 0
#define P001 1
#define P002 2
#define P003 3
#define P004 4
#define P005 5
#define P006 6
#define P007 7
#define P008 8
#define P010 10
#define P011 11
#define P012 12
#define P013 13
#define P014 14
#define P015 15

#define P100 100
#define P101 101
#define P102 102
#define P103 103
#define P104 104
#define P105 105
#define P106 106
#define P107 107
#define P108 108
#define P109 109
#define P110 110
#define P111 111
#define P112 112
#define P113 113
#define P114 114
#define P115 115

#define P201 201
#define P202 202
#define P203 203
#define P204 204
#define P205 205
#define P206 206
#define P212 212
#define P213 213

#define P300 300
#define P301 301
#define P302 302
#define P303 303
#define P304 304
#define P305 305
#define P306 306
#define P307 307

#define P400 400
#define P401 401
#define P402 402
#define P403 403
#define P404 404
#define P405 405
#define P406 406
#define P407 407
#define P408 408
#define P409 409
#define P410 410
#define P411 411
#define P412 412
#define P413 413
#define P414 414
#define P415 415

#define P500 500
#define P501 501
#define P502 502
#define P503 503
#define P504 504
#define P505 505

#define P600 600
#define P601 601
#define P602 602
#define P603 603
#define P608 608
#define P609 609
#define P610 610

#define P708 708

#define P808 808
#define P809 809

#define P914 914
#define P915 915

#define NOT_A_PORT 255
#define NOT_A_PIN 255

// todo fix
#define IO_PORT_START 0x40040000

#define PORT0_OFFSET 0
#define PORT1_OFFSET 1
#define PORT2_OFFSET 2
#define PORT3_OFFSET 3
#define PORT4_OFFSET 4
#define PORT5_OFFSET 5
#define PORT6_OFFSET 6
#define PORT7_OFFSET 7
#define PORT8_OFFSET 8
#define PORT9_OFFSET 9

constexpr uint8_t
port_from_pin(uint16_t pin)
{
    return (uint8_t)(pin < 100    ? PORT0_OFFSET
                     : pin < 200  ? PORT1_OFFSET
                     : pin < 300  ? PORT2_OFFSET
                     : pin < 400  ? PORT3_OFFSET
                     : pin < 500  ? PORT4_OFFSET
                     : pin < 600  ? PORT5_OFFSET
                     : pin < 700  ? PORT6_OFFSET
                     : pin < 800  ? PORT7_OFFSET
                     : pin < 900  ? PORT8_OFFSET
                     : pin < 1000 ? PORT9_OFFSET
                                  : NOT_A_PORT);
}

constexpr uint8_t bit_from_pin(uint8_t pin)
{
    return (uint8_t)(pin < 100    ? pin
                     : pin < 200  ? pin - 100
                     : pin < 300  ? pin - 200
                     : pin < 400  ? pin - 300
                     : pin < 500  ? pin - 400
                     : pin < 600  ? pin - 500
                     : pin < 700  ? pin - 600
                     : pin < 800  ? pin - 700
                     : pin < 900  ? pin - 800
                     : pin < 1000 ? pin - 900
                                  : NOT_A_PORT);
}

constexpr uint8_t arduino_pin_to_avr_pin(uint8_t pin)
{
    return (uint8_t)(pin == 0    ? P301
                     : pin == 1  ? P302
                     : pin == 2  ? P105
                     : pin == 3  ? P104
                     : pin == 4  ? P103
                     : pin == 5  ? P102
                     : pin == 6  ? P106
                     : pin == 7  ? P107
                     : pin == 8  ? P304
                     : pin == 9  ? P303
                     : pin == 10 ? P112
                     : pin == 11 ? P109
                     : pin == 12 ? P110
                     : pin == 13 ? P111
                     : pin == 14 ? P014
                     : pin == 15 ? P000
                     : pin == 16 ? P001
                     : pin == 17 ? P002
                     : pin == 18 ? P101
                     : pin == 19 ? P100
                                 : NOT_A_PIN);
}

#pragma pack(push, 1)
typedef struct IOPORT
{
    union PCNTR1
    {
        struct
        {
            // 1 is output high
            uint16_t PDR;
            // data direction, 1 is output
            uint16_t PODR;
        };
        uint32_t reg;
    } PCNTR1;
    union PCNTR2
    {
        struct
        {
            // pin state
            uint16_t PIDR;
            // event input data, 1 is high
            uint16_t EIDR;
        };
        uint32_t reg;
    } PCNTR2;
    union PCNTR3
    {
        struct
        {
            // pin output set, 1 is high
            uint16_t POSR;
            // pin output clear, 1 is low
            uint16_t PORR;
        };
        uint32_t reg;
    } PCNTR3;
    union PCNTR4
    {
        struct
        {
            // pin event ouput set
            uint16_t EOSR;
            // pin event output clear
            uint16_t EORR;
        };
        uint32_t reg;
    } PCNTR4;
    uint8_t padding[16];
} IOPORT;

typedef struct PORTS
{
    IOPORT port[10];
} PORTS;
#pragma pack(pop)

#endif // HUB75NANO_UNO_R4_PIN_HELPER_H