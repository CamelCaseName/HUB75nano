#include "Panel.h"
//this sketch should ouptut serial input to the panel

Panel panel(32, 64, true);
char out[81];
uint8_t length = 0;
uint8_t oldlength;

void setup(){
	panel.createBufferBG(panel.BLUE);
	/*
	panel.drawChar(0 * 4, 0 * 6, 'A', panel.WHITE);
	panel.drawChar(1 * 4, 0 * 6, 'B', panel.WHITE);
	panel.drawChar(2 * 4, 0 * 6, 'C', panel.WHITE);
	panel.drawChar(3 * 4, 0 * 6, 'D', panel.WHITE);
	panel.drawChar(4 * 4, 0 * 6, 'E', panel.WHITE);
	panel.drawChar(5 * 4, 0 * 6, 'F', panel.WHITE);
	panel.drawChar(6 * 4, 0 * 6, 'G', panel.WHITE);
	panel.drawChar(7 * 4, 0 * 6, 'H', panel.WHITE);
	panel.drawChar(8 * 4, 0 * 6, 'I', panel.WHITE);
	panel.drawChar(9 * 4, 0 * 6, 'J', panel.WHITE);
	panel.drawChar(10 * 4, 0 * 6, 'K', panel.WHITE);
	panel.drawChar(11 * 4, 0 * 6, 'L', panel.WHITE);
	panel.drawChar(12 * 4, 0 * 6, 'M', panel.WHITE);
	panel.drawChar(13 * 4, 0 * 6, 'N', panel.WHITE);
	panel.drawChar(14 * 4, 0 * 6, 'O', panel.WHITE);
	panel.drawChar(15 * 4, 0 * 6, 'P', panel.WHITE);
	panel.drawChar(0 * 4, 1 * 6, '_', panel.WHITE);
	panel.drawChar(1 * 4, 1 * 6, 'x', panel.WHITE);
	panel.drawChar(2 * 4, 1 * 6, 'X', panel.WHITE);
	*/
}

//example text to send in two parts, because murphys law:
//
//Lorem ipsum dolor sit amet, consectetur adipisici elit,
// sed eiusmod tempor inci
void loop() {
	if (Serial.available()) {
		while (Serial.available() && strlen(out) < 80) {
			out[strlen(out)] = (char)Serial.read();
			panel.displayBuffer();
		}
		oldlength = length;
		length = strlen(out);

		if (length >= 80 && Serial.available()) {
			for (uint8_t i = 0; i < 81; i++) {
				out[i] = '\0';
			}
			oldlength = 0;
			length = 0;
			//Serial.println("clearing");
			panel.clearBuffer(panel.BLUE);
			panel.displayBuffer();
		}

		for (uint8_t i = oldlength; i < length;i++) {
			/*if (out[i] == '\n') {
				out[i] == ' ';
				for (uint8_t j = i + 1; j < length; j++) {
					out[i % 16 + ((i / 16) * 16) + length - j] = out[j];
					out[j] == ' ';
				}
			}*/
			panel.drawChar((i % 16) * 4, (i / 16) * 6 + 1, out[i], panel.WHITE);
			panel.displayBuffer();
		}
		panel.displayBuffer();
	}
	panel.displayBuffer();
}