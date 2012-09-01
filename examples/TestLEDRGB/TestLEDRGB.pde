#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif


#include <LiquidCrystal.h>
#include <Menu.h>
#include <LCDKeypad.h>
#include <LEDRGB.h>

// This sample file shows a menu on the LCD display and let you play with the buttons
// check your pins and modify constructor of the LED

LEDRGB led1 = LEDRGB(44,45,46); //PWM output

void setup()
{

}

void loop()
{

	//led1.test_colors();
	led1.test_cold_colors();
  delay(50);
}
