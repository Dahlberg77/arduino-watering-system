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

LCDKeypad _lcd = LCDKeypad();
//Menu _menu = Menu();
ChannelsRelay _relays = ChannelsRelay();

	
void setup()
{
	lcd.cleanLine(0);

}

void loop()
{
	// manual set
	if(lcd.refreshMenu())
	{
				// debug:
				/*
		lcd.write("    ",1 ,0);
		lcd.write(menu.getIndex(),1 ,0);				   
		lcd.write(menu.getStatus(),1 ,2);				   
		relays.set(menu.getIndex(),menu.getStatus());
		*/
	}
	
	// automatic set
	check_schedule_tasks();
  delay(50);
}

void check_schedule_tasks()
{

	unsigned long watering_time_current;
	
	watering_time_current = millis() % HOUR;

	if( watering_time_current != watering_time_previous)
	{
		watering_time_previous = watering_time_current;
		watering_alarm();
	}
	
	return;
}
	
// functions to be called when an alarm triggers:
void watering_alarm()
{
  //lcd.write("Alarm: Watering");
	int water_pump = 1;
	_relays.set(water_pump,1);
	delay(5 * SEC);
	_relays.set(water_pump,0);
	return;
}

