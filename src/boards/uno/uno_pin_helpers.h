#ifndef HUB75NANO_UNO_PIN_HELPERS_H
#define HUB75NANO_UNO_PIN_HELPERS_H

// arduino pin number to port number and the respective pin number conversion
#pragma region pin_to_port_number_conversion
// todo make script to generate these macros/do two preprocessor passes with makefile
// first _row pin
#if RA < 8
#define PORT_RA PORTD
#define PORT_PIN_RA RA
#else
#if RA < 14
#define PORT_RA PORTB
#define PORT_PIN_RA RA - 8
#else
#define PORT_RA PORTC
#define PORT_PIN_RA RA - 14
#endif
#endif

// second _row pin
#if RB < 8
#define PORT_RB PORTD
#define PORT_PIN_RB RB
#else
#if RB < 14
#define PORT_RB PORTB
#define PORT_PIN_RB RB - 8
#else
#define PORT_RB PORTC
#define PORT_PIN_RB RB - 14
#endif
#endif

// third _row pin
#if RC < 8
#define PORT_RC PORTD
#define PORT_PIN_RC RC
#else
#if RC < 14
#define PORT_RC PORTB
#define PORT_PIN_RC RC - 8
#else
#define PORT_RC PORTC
#define PORT_PIN_RC RC - 14
#endif
#endif

// fourth _row pin
#if RD < 8
#define PORT_RD PORTD
#define PORT_PIN_RD RC
#else
#if RD < 14
#define PORT_RD PORTB
#define PORT_PIN_RD RD - 8
#else
#define PORT_RD PORTC
#define PORT_PIN_RD RD - 14
#endif
#endif

// fifth _row pin
#if RE < 8
#define PORT_RE PORTD
#define PORT_PIN_RE RE
#else
#if RE < 14
#define PORT_RE PORTB
#define PORT_PIN_RE RE - 8
#else
#define PORT_RE PORTC
#define PORT_PIN_RE RE - 14
#endif
#endif

// upper red
#if RF < 8
#define PORT_RF PORTD
#define PORT_PIN_RF RF
#else
#if RF < 14
#define PORT_RF PORTB
#define PORT_PIN_RF RF - 8
#else
#define PORT_RF PORTC
#define PORT_PIN_RF RF - 14
#endif
#endif

// upper green
#if GF < 8
#define PORT_GF PORTD
#define PORT_PIN_GF GF
#else
#if GF < 14
#define PORT_GF PORTB
#define PORT_PIN_GF GF - 8
#else
#define PORT_GF PORTC
#define PORT_PIN_GF GF - 14
#endif
#endif

// upper blue
#if BF < 8
#define PORT_BF PORTD
#define PORT_PIN_BF BF
#else
#if BF < 14
#define PORT_BF PORTB
#define PORT_PIN_BF BF - 8
#else
#define PORT_BF PORTC
#define PORT_PIN_BF BF - 14
#endif
#endif

// lower red
#if RS < 8
#define PORT_RS PORTD
#define PORT_PIN_RS RS
#else
#if RS < 14
#define PORT_RS PORTB
#define PORT_PIN_RS RS - 8
#else
#define PORT_RS PORTC
#define PORT_PIN_RS RS - 14
#endif
#endif

// lower green
#if GS < 8
#define PORT_GS PORTD
#define PORT_PIN_GS GS
#else
#if GS < 14
#define PORT_GS PORTB
#define PORT_PIN_GS GS - 8
#else
#define PORT_GS PORTC
#define PORT_PIN_GS GS - 14
#endif
#endif

// lower blue
#if BS < 8
#define PORT_BS PORTD
#define PORT_PIN_BS BS
#else
#if BS < 14
#define PORT_BS PORTB
#define PORT_PIN_BS BS - 8
#else
#define PORT_BS PORTC
#define PORT_PIN_BS BS - 14
#endif
#endif

// clock
#if CLK < 8
#define PORT_CLK PORTD
#define PORT_PIN_CLK CLK
#else
#if CLK < 14
#define PORT_CLK PORTB
#define PORT_PIN_CLK CLK - 8
#else
#define PORT_CLK PORTC
#define PORT_PIN_CLK CLK - 14
#endif
#endif

// latch
#if LAT < 8
#define PORT_LAT PORTD
#define PORT_PIN_LAT LAT
#else
#if LAT < 14
#define PORT_LAT PORTB
#define PORT_PIN_LAT LAT - 8
#else
#define PORT_LAT PORTC
#define PORT_PIN_LAT LAT - 14
#endif
#endif

// output enable
#if OE < 8
#define PORT_OE PORTD
#define PORT_PIN_OE OE
#else
#if OE < 14
#define PORT_OE PORTB
#define PORT_PIN_OE OE - 8
#else
#define PORT_OE PORTC
#define PORT_PIN_OE OE - 14
#endif
#endif
#pragma endregion // pin_to_port_number_conversion

#endif // HUB75NANO_UNO_PIN_HELPERS_H