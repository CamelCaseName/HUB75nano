# HUB75nano
This Arduino library adds the basic functionality needed to drive a HUB 75 protocol LED Panel up to 64x32 Pixels RGB.

it can display colors up to 1/2 refresh rate pwm colors, or a 1 or 2 bit rgb buffer. It works with The UNO and even the NANO.

# Getting set up
Clone or download the archive and put it inside your Arduino IDE custom library folder. 

Then just put 
	`#import <Panel.h>`
and everything should work.
	
There are also numerous examples, which are implementations of this library.

I made a write up [here](https://create.arduino.cc/projecthub/CamelCaseName/running-a-32x64-rgb-led-panel-with-only-an-arduino-nano-c19385).

# Which cable goes where
<img src="https://hackster.imgix.net/uploads/image/file/146124/DisplayPinout.jpg?auto=compress%2Cformat&w=740&h=555" alt="HUB75 Pinout" width="200"/>

This is a pin description for the HUB75 connector on the panels.
The corresponding pins on the arduino are as follows:

- A A0
- B A1
- C A2
- D A4
- R1 2
- R2 5
- B1 4
- B2 7
- G1 3
- G2 6
- LAT A3
- CLK 8
- OE 9
- GND GND

Right side is the panel, left the Arduino.

# Examples
This library also contains some examples on how to use it. The examples all end with *.ino. 

The Color example focuses on how to fill the screen with a color, and also with special colors. 

The buffer examples demonstrates how to interact with the 1bit rgb buffer for the display,
in order to show more precise images. 

The picture example shows how text generated with [this tool](https://www.github.com/CamelCaseName/pic2led) can be shown.
simply copy the generated text into your setup, it will take awhile though. These images will use around 6,5kb of ROM.

<img src="https://i.imgur.com/Zr81xNZ.jpg" alt="smiley face" width="200"/>

# current problems
There is some ghosting, excpecially on black pixels:

<img src="https://i.imgur.com/KeBjTea.jpg" alt="ghosting on smiley" width="200"/>

Unfortunately, it seems there is no way around this, because it is probably caused 
by badly insulated lanes on the pcb and stray currents. Your experience may differ.
