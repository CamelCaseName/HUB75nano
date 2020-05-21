#include <Panel.h>

Panel panel(32, 64, true);
void setup() {
	panel.createBufferBG(panel.PURPLE);
	panel.drawRect(0, 0, 5, 10, panel.YELLOW, true);
	panel.drawRect(25, 12, 29, 16, panel.GREEN, false);
}

void loop() {
	panel.displayBuffer();
}