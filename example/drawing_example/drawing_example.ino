#define PANEL_BIG

#include "Panel.h"

// create an instance of the panel
Panel panel;

void setup()
{

	panel.fillBuffer(panel.BLACK); // background red
	// panel.createBufferBG(26);//background red

	panel.drawRect(0, 0, 5, 10, panel.YELLOW, true);	// yellow filled rectangle top left
	panel.drawRect(25, 16, 29, 23, panel.GREEN, false); // green hollow rectangle somewhere in the middle
	panel.drawLine(6, 0, 63, 31, panel.WHITE);			// white diagonal through nearly the whole frame
	panel.drawCircle(50, 10, 5, panel.BLUE, false);		// hollow blue circle top right
	panel.drawCircle(11, 25, 5, panel.OCEANBLUE, true); // filled cyan circle bottom left
	panel.drawEllipse(30, 6, 6, 3, panel.GREEN, false);
	panel.drawEllipse(60, 19, 3, 8, panel.DEEPERPURPLE, true);

	/*
	panel.drawRect(0, 0, 7, 7, panel.YELLOW, true); //yellow filled rectangle top left
	panel.drawRect(8, 0, 15, 7, panel.BLUE, true); //yellow filled rectangle top left
	panel.drawRect(16, 0, 23, 7, panel.CYAN, true); //yellow filled rectangle top left
	panel.drawRect(24, 0, 31, 7, panel.GREEN, true); //yellow filled rectangle top left
	panel.drawRect(32, 0, 39, 7, panel.PURPLE, true); //yellow filled rectangle top left
	panel.drawRect(40, 0, 47, 7, panel.WHITE, true); //yellow filled rectangle top left
	*/
}

void loop()
{
	panel.displayBuffer(); // makes the buffer visible and the leds all blinky blinky
}