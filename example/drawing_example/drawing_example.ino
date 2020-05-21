#include <Panel.h>

Panel panel(32, 64, true);
void setup() {
	panel.createBufferBG(panel.RED);
	panel.drawRect(0, 0, 5, 10, panel.YELLOW, true);
	panel.drawRect(25, 16, 29, 20, panel.GREEN, false);
	panel.drawLine(6, 0, 63, 31, panel.WHITE);
}

void loop() {
	panel.displayBuffer();
}