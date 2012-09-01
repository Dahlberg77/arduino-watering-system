#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

#include <LiquidCrystal.h>
#include <Menu.h>
#include <ChannelsRelay.h>
#include <LCDKeypad.h>

// This sample file shows a menu on the LCD display and let you play with the buttons

ChannelsRelay relaysChanner = ChannelsRelay();

void setup()
{

}

void loop()
{
  //lcd.testrelaysChanner();

	relaysChanner.set(0, 1);
  delay(2000);
	relaysChanner.set(0, 0);
  delay(1000);

	relaysChanner.set(1, 1);
  delay(2000);
	relaysChanner.set(1, 0);
  delay(1000);

	relaysChanner.set(2, 1);
  delay(2000);
	relaysChanner.set(2, 0);
  delay(1000);

	relaysChanner.set(3, true);
  delay(2000);
	relaysChanner.set(3, false);
  delay(1000);

}