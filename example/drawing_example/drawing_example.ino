#include <Panel.h>

Panel panel(32, 64, true);
int i = 0;
void setup() {

}

void loop() {
	if (i / 1000 < 16) {
		panel.selectLine(i / 1000);
		panel.sendWholeRow(1, 1, 1, 1, 1, 1);
		if (i % 1000 == 0) {
			Serial.println(i / 1000);
		}
	}
	i++;
	if (i > 16000) {
		i = 0;
	}
}
