/*====================================================================================
                              THERMISTOR LIBRARY EXAMPLE
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


/*
   In this example we are going to build a 10k thermistor (NTC) based thermometer. 
   Circuit diagram available here: https://github.com/kittyboy2005/Thermistor/blob/master/Thermistor_Circuit_Diagram.png
 */

 
#include <Thermistor.h>

const byte SensorPin = DEFAULT_INPUT;   //Here DEFAULT_INPUT represents A0. 

Thermistor ntc(SensorPin);         	    //Initializing A0 pin as Thermistor input pin.
/*
 *    You can also define Sensor input pin as [Here we are declaring A1 as input pin]
 *    Thermistor thermistor(A1);
*/
 
void setup() 
{
  Serial.begin(9600);                  //Initializing serial interface with 9600 bps
}

void loop()
{
  //Printing the temperature in serial monitor.
  
  Serial.print(F("Temperature in Celsius: "));
  Serial.print(ntc.getC()); //Reading from thermistor
  Serial.println(F(" degree C"));

  Serial.print(F("Temperature in Fahrenheit: "));
  Serial.print(ntc.getF()); //Reading from thermistor
  Serial.println(F(" degree F"));

  Serial.println(F("----------------------------------------------"));
  delay(1000);
}