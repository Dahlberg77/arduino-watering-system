/*
  Relay4.cpp - Controls the channels relays board
  2012 Snake Sanders
*/

// include core Wiring API
#include "Relay4.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

Relay4::Relay4()
{
  pinMode(RELAY_0, OUTPUT);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);

	digitalWrite(RELAY_0, LOW );
	digitalWrite(RELAY_1, LOW );
	digitalWrite(RELAY_2, LOW );
	digitalWrite(RELAY_3, LOW );
	
	reset();	
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries
void Relay4::set(int relay, int status)
{
	switch(relay)
	{
		case 0:
		{
			digitalWrite(RELAY_0, status);
			statuses[0] = status;
			break;
		}
		case 1:
		{
			digitalWrite(RELAY_1, status);
			statuses[1] = status;
			break;
		}
		case 2:
		{
			digitalWrite(RELAY_2, status);
			statuses[2] = status;			
			break;
		}
		case 3:
		{
			digitalWrite(RELAY_3, status);
			statuses[3] = status;			
			break;
		}
	}
	return;
}

/*--------------------------------------------------------------------------------------
  get_status()
  Returns the status of the Relays indexed by realy_index.
--------------------------------------------------------------------------------------*/
int Relay4::get_status(int realy_index)
{
	return statuses[realy_index];
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

/*--------------------------------------------------------------------------------------
  reset()
  Reset to OFF the statuses of the Relays.
--------------------------------------------------------------------------------------*/
void Relay4::reset()
{
	int i;
	
	for (i = 0; i < NUM_RELAYS; i++)
	{
		statuses[i] = 0;
		set(i, 0);
	}
	
	return;
}
