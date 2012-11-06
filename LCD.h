/*
  Test.h - Test library for Wiring - description
  2012 Snake Sanders
*/

// ensure this library description is only included once

#ifndef LCD_h
#define LCD_h

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
// I say what I'm going to need to have compiled before starting
class LiquidCrystal;

// library interface description
class LCD
{
  // user-accessible "public" interface
  public:
    LCD();
		void write(char* text, int line, int at);
		void write(int text, int line, int at);
		void clean(int line);
		void clean_all();

  // library-accessible "private" interface
  private:
			// Pins in use
		#define LCD_BACKLIGHT_PIN         3  // D3 controls LCD backlight

		//some example macros with friendly labels for LCD backlight/pin control, tested and can be swapped into the example code as you like
		#define LCD_BACKLIGHT_OFF()     digitalWrite( LCD_BACKLIGHT_PIN, LOW )
		#define LCD_BACKLIGHT_ON()      digitalWrite( LCD_BACKLIGHT_PIN, HIGH )
		#define LCD_BACKLIGHT(state)    { if( state ){digitalWrite( LCD_BACKLIGHT_PIN, HIGH );}else{digitalWrite( LCD_BACKLIGHT_PIN, LOW );} }
		
		//values for menu option status
		#define ON												1
		#define OFF												0
};

#endif

