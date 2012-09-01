/*
  ChannelsRelay.h - Controls the channels relays board
  2012 Snake Sanders
*/

// ensure this library description is only included once
#ifndef ChannelsRelay_h
#define ChannelsRelay_h

// include types & constants of Wiring core API
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#endif

// library interface description
class ChannelsRelay
{
  // user-accessible "public" interface
  public:
    ChannelsRelay();
		void set(int relay, int status);

  // library-accessible "private" interface
  private:
		// connection relay to output pins
		#define RELAY_0 	22
		#define RELAY_1 	23	
		#define RELAY_2 	24
		#define RELAY_3 	25
};

#endif

