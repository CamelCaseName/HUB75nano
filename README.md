# HUB75nano
This Arduino library adds the basic functionality needed to drive a HUB 75 protocol LED Panel up to 64x32 Pixels RGB.
it can display colors up to 1/2 refresh rate pwm colors, or a 1 bit rgb buffer. It works with The UNO and even the NANO.

# Getting set up
Clone or download the archive and put it inside your Arduino IDE custom library folder. 
Then just put 
	`#import <Panel.h>`
and everything should work.
For the Pixels, do the same with
	`#import <Pixel.h>`
	
There is also the Buffer example, which is an implementation of these librarys

# Which cable goes where
![HUB75 Pinout](https://hackster.imgix.net/uploads/image/file/146124/DisplayPinout.jpg?auto=compress%2Cformat&w=740&h=555&fit=max) This is a pin description for the HUB75 connector on the panels.
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
This library also contains some examples on how to use it. The examples all end with *.ino. The Color example focuses on how to fill the screen with a color, and also with special colors. 
The buffer examples demonstrates how to interact with the 1bit rgb buffer for the display, in order to show more precise images. It also uses the bundled pixel class to display a smiley face.
![smiley face](https://i.imgur.com/Zr81xNZ.jpg)

# current problems
There is some ghosting, excpecially on black pixels: ![ghosting example](https://i.imgur.com/KeBjTea.jpg)
Unfortunately, it seems there is no way around this, because it is probably caused by badly insulated lanes on the pcb and stray currents. Your experience may differ.