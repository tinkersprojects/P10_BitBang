# P10_BitBang Library
[https://tinkersprojects.com/p10_bitbang-library/](https://tinkersprojects.com/p10_bitbang-library/)

This is a library to allow any pins to be connected to a P10 LED display. 

## Functions
#### P10_BitBang(uint16_t _w, uint16_t _h,int8_t _clk, int8_t _sclk, int8_t _data, int8_t _en, int8_t _a, int8_t _b)
#### void begin()
#### void clear()
#### void print()

## Example

```c++
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
```
