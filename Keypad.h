/*
  Test.h - Test library for Wiring - description
  2012 Snake Sanders
*/

// ensure this library description is only included once
#ifndef Keypad_h
#define Keypad_h

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
class Keypad
{
  // user-accessible "public" interface
  public:
    Keypad();
		boolean was_button_pressed();
		boolean was_button_released();
		byte read_buttons();

  // library-accessible "private" interface
  private:
			// Pins in use
		#define BUTTON_ADC_PIN           A0  // A0 is the button ADC input
		// ADC readings expected for the 5 buttons on the ADC input
		#define RIGHT_10BIT_ADC           0  // right
		#define UP_10BIT_ADC            133  // up
		#define DOWN_10BIT_ADC          308  // down
		#define LEFT_10BIT_ADC          481  // left
		#define SELECT_10BIT_ADC        722  // right
		#define BUTTONHYSTERESIS         10  // hysteresis in mVolts for valid button sensing window
		#define DEBOUNCING_DELAY				 50	 // time for skipping the bouncing button 

		//return values for ReadButtons()
		#define BUTTON_BOUNCING					 -1  // it is a invalid value caused by button bouncing
		#define BUTTON_NONE               0  // 
		#define BUTTON_RIGHT              1  // 
		#define BUTTON_UP                 2  // 
		#define BUTTON_DOWN               3  // 
		#define BUTTON_LEFT               4  // 
		#define BUTTON_SELECT             5  // 

		//values for menu option status
		#define ON												1
		#define OFF												0
				
		byte buttonJustPressed;         	// this will be true after a ReadButtons() call if triggered	
		byte buttonJustReleased;         	// this will be true after a ReadButtons() call if triggered
		long last_debounce_Time;					// last time a button was pressed
		byte buttonWas;   								// used for remebering the latest button pressed

		boolean is_in_Range(unsigned int measure, unsigned int set_point, unsigned int hysteresis);
		byte get_button_from_input_volts();
		boolean is_bouncing(byte button);

};

#endif

