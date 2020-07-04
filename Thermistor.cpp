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


#include "Thermistor.h"

Thermistor::Thermistor(byte analogPin)
{
	_analogPin = analogPin;
  pinMode(_analogPin,INPUT);
}

float Thermistor::getTemp()
{
	uint8_t i;
	float average,steinhart;
	
	for (i=0; i< NUMSAMPLES; i++) 
	{
		samples[i] = analogRead(_analogPin);
	}
	
	average = 0;
	for (i=0; i< NUMSAMPLES; i++)
	{
		average += samples[i];
	}
	
	average /= NUMSAMPLES;
	average = 1023 / average - 1;
	average = SERIESRESISTOR / average;
	
	steinhart = average / THERMISTORNOMINAL;     			// (R/Ro)
	steinhart = log(steinhart);                  			// ln(R/Ro)
	steinhart /= BCOEFFICIENT;                   			// 1/B * ln(R/Ro)
	steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
	steinhart = 1.0 / steinhart;                 			// Invert
	steinhart -= 273.15;                         			// convert to C
	
	return steinhart;
}

float Thermistor::getC()
{
	return getTemp();                                 //Temperature in Celsius
}

float Thermistor::getF()
{
	return ((float(getTemp())*9.00)/5.00)+32.00;      //Temperature in Fahrenheit
}
