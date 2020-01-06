#ifndef P10_BitBang_h
#define P10_BitBang_h

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
  #include <wiring.h>
#endif

#include <Adafruit_GFX.h>



class P10_BitBang : public Adafruit_GFX 
{
  public:
    P10_BitBang(uint16_t _w, uint16_t _h,int8_t _clk, int8_t _sclk, int8_t _data, int8_t _en, int8_t _a, int8_t _b);
    void clear();
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void startWrite();
    void endWrite();
    void printData();
    void begin();

    int8_t _enPin;
    int8_t _aPin;
    int8_t _bPin;
    int8_t _cPin;
    int8_t _dPin;
    int8_t _gPin;
    int8_t _rPin;
    int8_t _clkPin;
    int8_t _width;
    int8_t _height;
    
    int8_t _sclkPin;
    int8_t _dataPin;

    int8_t displaydata[4][16];

};


#endif
