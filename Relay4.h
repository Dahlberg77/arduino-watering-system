/*
  Relay4.h - Controls the channels relays board
  2012 Snake Sanders
*/

// ensure this library description is only included once
#ifndef Relay4_h
#define Relay4_h

// include types & constants of Wiring core API
#if defined(ARDUINO) && ARDUINO >= 100
	#ifndef Arduino_h
		#include "Arduino.h"
	#endif
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

// library interface description
class Relay4
{
  // user-accessible "public" interface
  public:
	
    Relay4();
		void set(int relay, int status);
		int get_status(int realy);
		void reset();
		

  // library-accessible "private" interface
  private:
		// connection relay to output pins
		#define RELAY_0 	22
		#define RELAY_1 	23	
		#define RELAY_2 	24
		#define RELAY_3 	25
		
		#define NUM_RELAYS 4
		
		int statuses[NUM_RELAYS]; 	// save the status of the output on/off
		
};

#endif

