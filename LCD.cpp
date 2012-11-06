/**

  This is an example I took from freetronic.com which I addapted it for my LCD keypad Shield,
  I found this code very helpful, specially for my LCD Shield which I don't know even which brand it is.
  The voltages for the A0 input were addapted for this particular LCD Shield.
  
  For more info here is my blog
  
    http://handsonarduinomega.blogspot.cz/

  Example code for the Freetronics LCD & Keypad Shield:
  
    http://www.freetronics.com/products/lcd-keypad-shield
  
  by Marc Alexander, 7 September 2011
  This example code is in the public domain.
  
  ---------------------------------------------------------------------
  
  This program demonstrates LCD text/number printing,
  and LCD backlight control on the Freetronics LCD & Keypad Shield, connected to an Arduino board.
    
  Pins used by LCD:
  
    A0: Buttons, analog input from voltage ladder
    D4: LCD bit 4
    D5: LCD bit 5
    D6: LCD bit 6
    D7: LCD bit 7
    D8: LCD RS
    D9: LCD E
    D3: LCD Backlight (high = on, also has pullup high so default is on)
  
**/

// include this library's description file
#include "LCD.h"
#include <LiquidCrystal.h>
#include <string.h>

/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/
// this should be private
//Pins for the freetronics 16x2 LCD shield. LCD: ( RS, E, LCD-D4, LCD-D5, LCD-D6, LCD-D7 )
LiquidCrystal display( 8, 9, 4, 5, 6, 7 ); 


// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances
LCD::LCD (void)
{

   //lcd backlight control
   digitalWrite( LCD_BACKLIGHT_PIN, HIGH );  //backlight control pin D3 is high (on)
   pinMode( LCD_BACKLIGHT_PIN, OUTPUT );     //D3 is an output
   //set up the LCD number of columns and rows: 
   display.begin( 16, 2 );
   //Print some initial text to the LCD.
   display.setCursor( 0, 0 );   //top left
   //              1234567890123456
   display.print( "Starting..." );
   //
   display.setCursor( 0, 1 );   //bottom left

}

/*--------------------------------------------------------------------------------------
  This Test function writes on the LCD the *text in the *line starting *at column
	Line starts at 0. Aslo at.
--------------------------------------------------------------------------------------*/
void LCD::write(char* text, int line, int at)
{
	 display.setCursor(at, line);
	 display.print(text);
	return;
}

void LCD::write(int text, int line, int at)
{
	 display.setCursor(at, line);
	 display.print(text);
	return;
}

/*--------------------------------------------------------------------------------------
  Clean the whole line from the LCD especified by line
--------------------------------------------------------------------------------------*/
void LCD::clean(int line)
{
				//1234567890123456
	write( "                ", line ,0);
	return;
}

/*--------------------------------------------------------------------------------------
  Clean the LCD
--------------------------------------------------------------------------------------*/
void LCD::clean_all()
{
				//1234567890123456
	write( "                ", 0 ,0);
	write( "                ", 1 ,0);	
	return;
}

