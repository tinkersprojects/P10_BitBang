
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
  #include <wiring.h>
#endif

#include "P10_BitBang.h"

  #include "Arduino.h"


 P10_BitBang::P10_BitBang(uint16_t _w, uint16_t _h,int8_t _clk, int8_t _sclk, int8_t _data, int8_t _en, int8_t _a, int8_t _b):Adafruit_GFX(_w, _h)
{
    _enPin=_en;
    _aPin=_a;
    _bPin=_b;
    _clkPin=_clk;
    _sclkPin=_sclk;
    _dataPin=_data;

    _width = _w;
    _height = _h;
}


 void P10_BitBang::begin()
 {
    pinMode(_enPin,OUTPUT);
    pinMode(_aPin,OUTPUT);
    pinMode(_bPin,OUTPUT);
    pinMode(_clkPin,OUTPUT);
    pinMode(_sclkPin,OUTPUT);
    pinMode(_dataPin,OUTPUT);
    
    digitalWrite(_enPin,HIGH);
    digitalWrite(_dataPin,HIGH);
}
    
void  P10_BitBang::clear()
{
    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 16; j++)
      {
        displaydata[i][j] = 0;
      }
    }
      
    endWrite();
}

void  P10_BitBang::drawPixel(int16_t x, int16_t y, uint16_t color)
{
  if(_width <= x || _height <= y)
  return;
  y = _height - y;
  int LocAA = x%8; // find bit 
  int LocBB = y%4; // find in the 4 Y lines (AA, AB, BA, BB)
  int LocA = (x-LocAA)/8; //
  int LocB = (y-LocBB)/4;
  int Loc = (LocA*4)+LocB;

  if(color>0)
  bitSet(displaydata[LocBB][Loc], LocAA);
  else
  bitClear(displaydata[LocBB][Loc], LocAA);
  
}

void  P10_BitBang::startWrite(void)
{
}

void  P10_BitBang::endWrite(void)
{
    for(int i = 0; i < 4; i++)
    {
      //ESP.wdtFeed();
      switch(i)
      {
        case 1:
          digitalWrite(_aPin,HIGH);
          digitalWrite(_bPin,HIGH);
          break;
        case 2:
          digitalWrite(_aPin,LOW);
          digitalWrite(_bPin,HIGH);
          break;
        case 3:
          digitalWrite(_aPin,HIGH);
          digitalWrite(_bPin,LOW);
          break;
        default:
          digitalWrite(_aPin,LOW);
          digitalWrite(_bPin,LOW);
          break;
      }
      
      for(int j = 0; j <16; j++)
      {
        for(int h = 0; h <8; h++)
        {
         // ESP.wdtFeed();
            digitalWrite(_dataPin,!bitRead(displaydata[i][j],h));
            digitalWrite(_clkPin,HIGH);
            digitalWrite(_clkPin,LOW);
        }
      }
    digitalWrite(_sclkPin,HIGH);
    digitalWrite(_sclkPin,LOW);
    }
}

void  P10_BitBang::printData(void)
{
  //startWrite();
  //endWrite();
  this->endWrite();
}
