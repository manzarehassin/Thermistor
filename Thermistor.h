/*====================================================================================
                              THERMISTOR LIBRARY
======================================================================================

Rearranged by: Manzar-E-Hassin <mnz247@hotmail.com>
Published on Saturday, July 4, 2020

Original Creator: Limor Fried, Adafruit Industries https://learn.adafruit.com/thermistor/overview 

MIT License

Copyright (c) 2020 Manzar-E-Hassin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Thermistor library available at: https://github.com/kittyboy2005/Thermistor

*/


#define NUMSAMPLES 10
#define DEFAULT_INPUT A0                // Default input pin set to A0 (Analog 0)

#ifndef thermistor_h
#define thermistor_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Thermistor
{
  public:
    // Constructor 
   Thermistor(byte analogPin = DEFAULT_INPUT);

    // Methods
    float getC();   //Temperature in Celsius
    float getF();   //Temperature in Fahrenheit
    
  private:
    byte _analogPin;
    const PROGMEM unsigned long THERMISTORNOMINAL= 10000;    // resistance at 25 degrees C  
    const PROGMEM long BCOEFFICIENT =3950;                     // The beta coefficient of the thermistor (usually 3000-4000) 
    const PROGMEM long SERIESRESISTOR =10000;                // the value of the 'other' resistor (10k)
    const PROGMEM byte TEMPERATURENOMINAL =25;                 // temp. for nominal resistance (almost always 25 C)
    unsigned int samples[NUMSAMPLES];
    
    float getTemp();
};
#endif
