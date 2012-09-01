/*
  LEDRGB.h - Controls and LED RGB offering a set of nice function for playing with colors
  2012 Snake Sanders
*/

// ensure this library description is only included once
#ifndef LEDRGB_h
#define LEDRGB_h

// include types & constants of Wiring core API
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif


// library interface description
class LEDRGB
{
  // user-accessible "public" interface
  public:
    LEDRGB(int red_pin, int green_pin, int blue_pin);
		int 	get_Pin_RED();
		int 	get_Pin_GREEN();
		int 	get_Pin_BLUE();
		void 	setColor(int pinOut,int value);
		void 	fade_color_in(int pinOut, int delay_time);
		void 	fade_color_out(int pinOut, int delay_time);
		//tests:
		void 	test_colors();
		void 	test_cold_colors();

  // library-accessible "private" interface
  private:
		// defines the type of LED connection, common (+). This means that for turn it ON you put 0 at the output
		// for common (-) you put 1 to turn it ON
		#define COMMON_ANODE 			true	

		#define MIN_VOLTAGE 			0		
		#define MAX_VOLTAGE 			255
		#define FADE_SPEED 				25  // make this higher to slow down
		
		int RED ;	
		int GREEN; 
		int BLUE;
		
		void rise_voltage(int pinOut, int delay_time);
		void low_voltage(int pinOut, int delay_time);
		boolean validate_output(int voltage);

};

#endif

