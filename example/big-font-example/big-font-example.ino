#include "Panel.h"

//create an instance of the panel
Panel panel(32, 64);
char out[81];
uint8_t length = 0;
uint8_t oldlength;
uint8_t fcolor = 3;
uint8_t bgcolor = 2;
char t;
//String test = "23.576%";

// I M P O R T A N T

//in panel.h, you should comment out line Nr. 41 for this to work better/more reliable


void setup() {
	panel.createBufferBG(bgcolor);
	/*
	panel.createBufferBG(panel.BLACK);//background black
	//panel.createBufferBG(26);//background red
	
	panel.drawBigChar(0,0,'A',panel.RED,1);
	panel.drawBigChar(4,0,'a',panel.GREEN,1);
	panel.drawBigChar(8,0,'B',panel.BLUE,1);
	panel.drawBigChar(12,0,'b',panel.WHITE,1);
	panel.drawBigChar(16,0,'C',panel.PURPLE,1);
	panel.drawBigChar(20,0,'c',panel.YELLOW,1);
	panel.drawBigChar(24,0,'D',panel.CYAN,1);
	panel.drawBigChar(28,0,'d',8,1);
	panel.drawBigChar(32,0,'E',9,1);
	panel.drawBigChar(36,0,'e',10,1);
	panel.drawBigChar(40,0,'F',11,1);
	panel.drawBigChar(44,0,'f',12,1);
	panel.drawBigChar(48,0,'G',13,1);
	panel.drawBigChar(52,0,'g',14,1);
	panel.drawBigChar(56,0,'H',15,1);
	panel.drawBigChar(60,0,'h',16,1);
	panel.drawBigChar(0,6,'I',17,2);
	panel.drawBigChar(8,6,'i',18,2);
	panel.drawBigChar(16,6,'J',19,2);
	panel.drawBigChar(24,6,'j',20,2);
	panel.drawBigChar(32,6,'K',21,2);
	panel.drawBigChar(40,6,'k',22,2);
	panel.drawBigChar(48,6,'L',23,2);
	panel.drawBigChar(56,6,'l',24,2);
	panel.drawBigChar(0,17,'M',25,3);
	panel.drawBigChar(16,17,'m',0,3);
	panel.drawBigChar(32,17,'N',1,3);
	panel.drawBigChar(48,17,'n',2,3);

	/*
	panel.drawBigChar(0,7,'2',0,3);
	panel.drawBigChar(10,7,'3',0,3);
	panel.drawBigChar(17,7,'.',0,3);
	panel.drawBigChar(24,7,'5',0,3);
	panel.drawBigChar(34,7,'7',2,3);
	panel.drawBigChar(44,7,'6',2,3);
	panel.drawBigChar(54,7,'%',2,3);

	
	panel.drawBigChar(0,7,test[0],0,3);
	panel.drawBigChar(10,7,test[1],0,3);
	panel.drawBigChar(17,7,test[2],0,3);
	panel.drawBigChar(24,7,test[3],0,3);
	panel.drawBigChar(34,7,test[4],2,3);
	panel.drawBigChar(44,7,test[5],2,3);
	panel.drawBigChar(54,7,test[6],2,3);
	*/
	String test = "23.576%";
}


void loop() {
	panel.drawBigChar(5,10,'2',0,3);
	panel.displayBuffer(); //makes the buffer visible and the leds all blinky blinky
}