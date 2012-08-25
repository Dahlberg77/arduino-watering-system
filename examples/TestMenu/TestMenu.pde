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
	lcd.cleanLine(0);
}

void loop()
{
  lcd.testMenu();
  delay(50);
}