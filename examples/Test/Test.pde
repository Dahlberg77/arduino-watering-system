#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

#include <LiquidCrystal.h>
#include <Menu.h>
#include <LCDKeypad.h>


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