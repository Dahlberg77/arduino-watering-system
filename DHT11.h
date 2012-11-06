// 
//    FILE: dht11.h
// VERSION: 0.3.2
// PURPOSE: DHT11 Temperature & Humidity Sensor library for Arduino
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
// DATASHEET: http://www.micro4you.com/files/sensor/DHT11.pdf
//
//     URL: http://arduino.cc/playground/Main/DHT11Lib
//
// HISTORY:
// George Hadjikyriacou - Original version
// see dht.cpp file
// 

#ifndef DHT11_h
#define DHT11_h


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

#define DHT11LIB_VERSION "0.3.2"

class DHT11
{
	public:
	    int read(int pin);
			int get_temp();
			int get_humi();

	private:
			int humidity;
			int temperature;
};
#endif
//
// END OF FILE
//