#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

#include <LiquidCrystal.h>
#include <Menu.h>
#include <LCDKeypad.h>

// This sample test shows the differnts values in mV at the Analog input when differents buttons are pressed
// It is intended to be used for calibratng you keypad, based on the values shown on the screen.

LCDKeypad lcd = LCDKeypad();

void setup()
{
	lcd.write("Test a button",0,0);
}

void loop()
{
  lcd.test();
  delay(150);
}