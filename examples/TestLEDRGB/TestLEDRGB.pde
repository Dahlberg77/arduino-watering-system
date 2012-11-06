#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif


#include <LiquidCrystal.h>
#include <LCD.h>
#include <LEDRGB.h>

// This sample file shows a menu on the LCD display and let you play with the buttons
// check your pins and modify constructor of the LED

LEDRGB led1 = LEDRGB(44,45,46); //PWM output
LEDRGB led2 = LEDRGB(30,31,32); //Normal output

void setup()
{
	led2.setColor(32,1);
}

void loop()
{

	//led1.test_colors();
	//led1.test_cold_colors();
	led2.setColor(21,ON);
  delay(2000);
}
