# HUB75nano
This Arduino library adds the basic functionality needed to drive a HUB 75 protocol LED Panel up to 64x32 Pixels RGB (only tested with 64x32).

It can display colors up to 4 bit colors for a full screen, or a 1 or 2 bit rgb image buffer. It was written for the Arduino nano with the ATMega328(p) with 2k RAM, but should therefor also work with the UNO(same CPU, but 16k RAM).

# Setup
Clone or download the archive and put it inside your Arduino IDE custom library folder. 

Then just put `#import <Panel.h>` and everything should work.
	
Definitions you can use to change how the library works
```
/////////////////////
// #define PANEL_BIG // use 2 bit rgb image buffer
// #define PANEL_FLASH // 4 bit flash buffer
// #define PANEL_NO_BUFFER // no buffer, immediate mode only
// #define PANEL_NO_FONT // disables everything font related, saves some flash
// #define PANEL_MAX_SPEED // trades more size for more speed
/////////////////////
```

A writeup on very early stages of development is [here](https://create.arduino.cc/projecthub/CamelCaseName/running-a-32x64-rgb-led-panel-with-only-an-arduino-nano-c19385).

# Pinout/Connection reference
<img src="https://hackster.imgix.net/uploads/image/file/146124/DisplayPinout.jpg?auto=compress%2Cformat&w=740&h=555" alt="HUB75 Pinout" width="200"/>

This is a pin description for the HUB75 connector on the panels. The file in the "additional documentation" folder also contains a mapping for directly soldering to a 16pin flat cable
The corresponding pins on the arduino are as follows:

Pin mapping:

| Connector | nano | function                                                     |
| --------- | ---- | ------------------------------------------------------------ |
| A         | A0   | First/Least significant row bit                              |
| B         | A1   | Second row bit                                               |
| C         | A2   | Third row bit                                                |
| D         | A3   | Fourth/Most significant row bit                              |
| R1        | 2    | Set red LED on upper half                                    |
| G1        | 3    | Set green LED on upper half                                  |
| B1        | 4    | Set blue LED on upper half                                   |
| R2        | 5    | Set red LED on lower half                                    |
| G2        | 6    | Set green LED on lower half                                  |
| B2        | 7    | Set blue LED on lower half                                   |
| CLK       | 9    | Shifts the data on rising edge                               |
| LAT       | 10   | Latches the data from the shift registers to the LED drivers |
| OE        | 11   | Enables the output of the LED drivers                        |
| GND       | GND  | Ground reference                                             |

Right side is the panel, left the Arduino.

You can deviate from this mapping but it comes at a speed cost.

# Examples
This library also contains some examples on how to use it. The examples all are functioning arduino sketches ending with *.ino. 

# Limitations:
### voltage issues
- when running more than 800 LEDs on full white, the color starts to deterioate quickly. this happens because the blue LEDs need more voltage to run than the others, therefore it turns into an orange color. You can get more white LEDs when running them in coloumns (max about 25\*31) than rows (63\*23). With full white rows it starts to turn orange at about 4 to 5 rows. this can be helped by overvolting the panel supply voltage to above 5V, but it is not recommended. Tests have shown 6 full rows of white at 5.7V and no rows at 4.6V. 

### No Panel Chaining / other sizes really supported yet, is planned

### Flipping vertically/horizontally is planned
