#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

//for some reason it needs these 2 libraries for loading Relay4.h
#include <LiquidCrystal.h>
#include <LCD.h>

#include <Relay4.h>

// This sample file shows the interaction with the relay output
// what it does is for each relay turns it on and check its status, if it is on it turns it off.

#define OFF 0
#define ON 1

Relay4 relay = Relay4();

void setup(){}

void loop()
{
	for(size_t i = 0; i < 4; ++i)
	{
		if(set_status(i, ON))
		{
			delay(1000);
			set_status(i, OFF);
		}
	}
	
	relay.reset();

	return;
}

int set_status(int index, int status)
{	
	relay.set(index, ON);
	
	return relay.get_status(index);
}
