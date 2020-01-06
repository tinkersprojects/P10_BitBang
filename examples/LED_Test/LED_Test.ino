#include <P10_BitBang.h>

#define enPin 16
#define aPin 14
#define bPin 12
#define DataPin 5
#define clkPin 13
#define sclkPin 3

#define width 32
#define height 16

P10_BitBang LEDdisplay(width, height,clkPin, sclkPin, DataPin, enPin, aPin, bPin);
  

void setup() 
{
  //ESP.wdtDisable();
  LEDdisplay.begin();
  LEDdisplay.clear();
  LEDdisplay.drawChar(2,  5, 'H', 1, 0, 1);
  LEDdisplay.drawChar(8,  5, 'E', 1, 0, 1);
  LEDdisplay.drawChar(14, 5, 'L', 1, 0, 1);
  LEDdisplay.drawChar(20, 5, 'L', 1, 0, 1);
  LEDdisplay.drawChar(26, 5, 'O', 1, 0, 1);
  LEDdisplay.drawRect(1, 13, 30 , 2, 1); 
}

void loop() 
{
    LEDdisplay.print();
}
