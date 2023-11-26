# HUB75nano
This Arduino library adds the basic functionality needed to drive a HUB 75 protocol LED Panel up to 64x32 Pixels RGB (only tested with 64x32).

It can display colors up to 8 bit colors for a full screen, a 1 or 2 bit rgb image buffer (dynamic) or 4 bit rgb buffers (static). It was originally written for the Arduino Nano (It should also work with the Arduino Uno), but is now being ported to a number of other chips in the nano formfactor (or with similar architecture). Refer to the [list below](README.md/#supported-boards) for the current state of support.

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
// #define PANEL_MAX_SPEED // uses more space but is faster, usually not needed
// #define PANEL_FLIP_VERTICAL // flips the panel vertically
// #define PANEL_FLIP_HORIZONTAL // flips the panel horizontally
/////////////////////
```

# Pinout/Connection reference
<img src="https://hackster.imgix.net/uploads/image/file/146124/DisplayPinout.jpg?auto=compress%2Cformat&w=740&h=555" alt="HUB75 Pinout" width="200"/>

This is a pin description for the HUB75 connector on the panels. The file in the "additional documentation" folder also contains a mapping for directly soldering to a 16pin flat cable
The corresponding pins on the arduino are as follows:

### Pin mapping

| Connector | Nano | Every | Mega2560 | def. name | function                                                     |
| --------- | ---- | ----- | -------- | --------- | ------------------------------------------------------------ |
| A         | A0   | 11    | 22       | RA        | First/Least significant row bit                              |
| B         | A1   | 12    | 23       | RB        | Second row bit                                               |
| C         | A2   | 13    | 24       | RC        | Third row bit                                                |
| D         | A3   | 8     | 25       | RD        | Fourth/Most significant row bit                              |
| R1        | 2    | A3    | 47       | RF        | Set red LED on upper half                                    |
| G1        | 3    | A2    | 46       | GF        | Set green LED on upper half                                  |
| B1        | 4    | A1    | 45       | BF        | Set blue LED on upper half                                   |
| R2        | 5    | A0    | 44       | RS        | Set red LED on lower half                                    |
| G2        | 6    | A6    | 43       | GS        | Set green LED on lower half                                  |
| B2        | 7    | A7    | 42       | BS        | Set blue LED on lower half                                   |
| CLK       | 9    | 9     | 37       | CLK       | Shifts the data on rising edge                               |
| LAT       | 10   | 10    | 36       | LAT       | Latches the data from the shift registers to the LED drivers |
| OE        | 11   | 5     | 35       | OE        | Enables the output of the LED drivers                        |
| GND       | GND  | GND   | GND      | -         | Ground reference                                             |

Connector refers to the HUB75 input connector on the panel. The pin names for the Arduino are the ones printed on the pcb.

You can deviate from this mapping but it comes at a speed cost. To use your own pins, refer to the table above (def. name coloumn) and just define the pin to one you like. 

Example: `#define RA 12` This puts the first row bit on D12 instead of A0.

# Supported Arduino boards
    ✅: Fully supported and tested  
    ❌: Not yet supported, some maybe never will be supported
    🅿️ : Support in progress 
    Ⓜ️ : Maybe works, should in theory (probably needs a custom pin assignment)

### 5V boards, work just like that
| board                      | chip          | operating voltage | supported |
| -------------------------- | ------------- | ----------------- | --------- |
| Arduino Nano               | ATmega328(p)  | 5V                | ✅         |
| Arduino Uno R3             | Atmega328p    | 5V                | Ⓜ️         |
| Arduino Uno WiFi Rev2      | ATmega4809    | 5V                | Ⓜ️         |
| Arduino Uno R4 Minima/WiFi | Renesas RA4M1 | 5V                | ❌         |
| Arduino Nano Every         | ATMega4809    | 5V                | ✅         |
| Arduino Mega               | ATmega2560    | 5V                | ✅         |


### 3.3V boards, usually need level shifters
You can use a dedicated shield like [this](https://github.com/CamelCaseName/Nano33IOTShield) or build one out of jumper wires and the [adafruit](https://www.adafruit.com/product/1787)(or similar) shifters for example.
| board                                  | chip                          | operating voltage | supported | shield                                                              |
| -------------------------------------- | ----------------------------- | ----------------- | --------- |---------------------------------------------------------------------|
| Arduino Nano 33 IOT                    | Arm® Cortex®-M0 32-bit SAMD21 | 3.3V              | 🅿️         |[nano33IOTShield](https://github.com/CamelCaseName/Nano33IOTShield) |
| Arduino Nano 33 BLE (Sense/Sense Rev2) | nRF52840                      | 3.3V              | ❌         | -                                                                  |
| Arduino Nano Esp32                     | u-blox® NORA-W106             | 3.3V              | ❌         | -                                                                  |
| Arduino Nano RP2040 Connect            | Raspberry Pi RP2040           | 3.3V              | 🅿️         | -                                                                  |

# Examples
This library also contains some examples on how to use it. The examples all are functioning arduino sketches ending with *.ino. 

# How the library works internally
A writeup on very very early stages of development is [here](https://create.arduino.cc/projecthub/CamelCaseName/running-a-32x64-rgb-led-panel-with-only-an-arduino-nano-c19385).

# Limitations:
### voltage issues
- when running more than 800 LEDs on full white, the color starts to deterioate quickly. this happens because the blue LEDs need more voltage to run than the others, therefore it turns into an orange color. You can get more white LEDs when running them in coloumns (max about 25\*31) than rows (63\*23). With full white rows it starts to turn orange at about 4 to 5 rows. this can be helped by overvolting the panel supply voltage to above 5V, but it is not recommended. Tests have shown 6 full rows of white at 5.7V and no rows at 4.6V. 

### No Panel Chaining / other sizes really supported yet, is planned
