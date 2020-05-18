#include <Panel.h>

Panel panel(32, 64, true);

void setup() {
    
}

void loop() {
    panel.selectLine(millis()/1000);
    panel.sendWholeRow(1, 1, 1, 1, 1, 1);
}
