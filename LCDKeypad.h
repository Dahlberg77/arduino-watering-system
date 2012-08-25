/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once

#ifndef LCDKeypad_h
#define LCDKeypad_h

// include types & constants of Wiring core API
#if defined(ARDUINO) && ARDUINO >= 100
	#ifndef Arduino_h
		#include "Arduino.h"
	#endif
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

// this is a forward class declaration, 
//I say what I'm going to need to have compiled before starting
class LiquidCrystal;
class Menu;

// library interface description
class LCDKeypad
{
  // user-accessible "public" interface
  public:
    LCDKeypad();
		boolean wasButtonPressed();
		boolean wasButtonReleased();
		void write(char* text, int line, int at);
		void write(int text, int line, int at);
		void cleanLine(int line);
		byte readButtons();
		void test();
		void testMenu();		

  // library-accessible "private" interface
  private:
			// Pins in use
		#define BUTTON_ADC_PIN           A0  // A0 is the button ADC input
		#define LCD_BACKLIGHT_PIN         3  // D3 controls LCD backlight
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
		//some example macros with friendly labels for LCD backlight/pin control, tested and can be swapped into the example code as you like
		#define LCD_BACKLIGHT_OFF()     digitalWrite( LCD_BACKLIGHT_PIN, LOW )
		#define LCD_BACKLIGHT_ON()      digitalWrite( LCD_BACKLIGHT_PIN, HIGH )
		#define LCD_BACKLIGHT(state)    { if( state ){digitalWrite( LCD_BACKLIGHT_PIN, HIGH );}else{digitalWrite( LCD_BACKLIGHT_PIN, LOW );} }
		//values for menu option status
		#define ON												1
		#define OFF												0
				
		byte buttonJustPressed;         	// this will be true after a ReadButtons() call if triggered	
		byte buttonJustReleased;         	// this will be true after a ReadButtons() call if triggered
		long last_debounce_Time;					// last time a button was pressed
		byte buttonWas;   								// used for remebering the latest button pressed

		boolean isInRange(unsigned int measure, unsigned int set_point, unsigned int hysteresis);
		byte getButtonFromInputVolts();
		boolean isButtonBouncing(byte button);
		void updateScreen();

};

#endif

