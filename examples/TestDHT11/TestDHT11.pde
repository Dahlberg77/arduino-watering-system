#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

#include <LiquidCrystal.h>
#include <LCD.h>
#include <DHT11.h>



/*--------------------------------------------------------------------------------------
  This Test function Shows the temperature and humidity on a display LCD
--------------------------------------------------------------------------------------*/

DHT11 sensor = DHT11();
LCD lcd = LCD();

#define SENSOR_PIN 21

void setup()
{
	
	lcd.clean_all();
	lcd.write("Testing DHT11",0,0);
	lcd.clean(1);
	delay(2000);
	lcd.write("Temp:",0,0);
	lcd.write("Hum.:",1,0);

}

void loop()
{
	
	if(sensor.read(SENSOR_PIN))
	{
		lcd.write("* ",0,14);
	}else{
		lcd.write("OK",0,14);		
	}
	lcd.write(sensor.get_temp(),0,5);
	lcd.write(sensor.get_humi(),1,5);
	delay(1000);
}