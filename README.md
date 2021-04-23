# Thermistor
Thermistor (ntc) based temperature monitoring library for Arduino environment

* Thermistor temperature range -55°C to 125°C
* Work at any voltage (digital sensors require 3 or 5V logic).
* Accuracy: 10K 1% thermistor is good for measuring with ±0.25°C accuracy.


## Initialize: 
### Thermistor obj (Input Pin);

**obj:** object of Thermistor class.

**Input Pin:** NTC connected analog pin. _you can use DEFAULT_INPUT as input pin, which represents A0_.

**Returns** nothing.


# _Temperature Reading_

### getC();

**Description:** Reading temperature in Celsius.

**Returns** 4 byte of float data.


### getF();

**Description:** Reading temperature in Fahrenheit.

**Returns** 4 byte of float data.

You will get cercuit diagram from this link: https://github.com/kittyboy2005/Thermistor/blob/master/Thermistor_Circuit_Diagram.png
