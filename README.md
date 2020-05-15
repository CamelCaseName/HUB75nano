# HUB75nano
This Arduino library adds the basic functionality needed to drive a HUB 75 protocol LED Panel up to 64x32 Pixels RGB.
it can display colors up to 1/2 refresh rate pwm colors, or a 1 bit rgb buffer. It works with The UNO and even the NANO.

# Getting set up
Clone or download the archive and put it inside your Arduino IDE custom library folder. 
Then just put 
	#import <Panel.h>
and everything should work.
For the Pixels, do the same with
	#import <Pixel.h>


There is also the Buffer example, which is an implementation of these librarys

# Examples
This library also contains some examples on how to use it. The examples all end with *.ino. The Color example focuses on how to fill the screen with a color, and also with special colors. 
The buffer examples demonstrates how to interact with the 1bit rgb buffer for the display, in order to show more precise images. It also uses the bundled pixel class to display a smiley face.
