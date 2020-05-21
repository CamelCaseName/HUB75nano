#include <Panel.h>

//create an instance of the panel
Panel panel(32, 64, true);

void setup() {
	panel.createBufferBG(panel.RED);//background red
	panel.drawRect(0, 0, 5, 10, panel.YELLOW, true); //yellow filled rectangle top left
	panel.drawRect(25, 16, 29, 23, panel.GREEN, false); //green hollow rectangle somewhere in the middle
	panel.drawLine(6, 0, 63, 31, panel.WHITE); //white diagonal through nearly the whole frame
	panel.drawCircle(50, 10, 9, panel.BLUE, false); //hollow blue circle top right
	panel.drawCircle(11, 25, 5, panel.CYAN, true); //filled cyan circle bottom left
}

void loop() {
	panel.displayBuffer(); //makes the buffer visible and the leds all blinky blinky
}