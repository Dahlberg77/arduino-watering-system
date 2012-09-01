/*
  LEDRGB.cpp - Controls and LED RGB offering a set of nice function for playing with colors

	Note: if you are using LEDs with common (-) catode you must change the constant 
	COMMON_ANODE to false.
	
  2012 Snake Sanders
*/

// include this library's description file
#include "LEDRGB.h"


// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

/*--------------------------------------------------------------------------------------
  LEDRGB
  Constructor for this class. Requires 3 integers as the output pins for each color.
--------------------------------------------------------------------------------------*/
LEDRGB::LEDRGB(int red_pin, int green_pin, int blue_pin)
{
	RED 	= red_pin;
	GREEN = green_pin;
	BLUE	= blue_pin;
	
  // initialize this instance's variables
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

/*--------------------------------------------------------------------------------------
  get_Pin_RED
  Return the pin associated to this color
--------------------------------------------------------------------------------------*/
int LEDRGB::get_Pin_RED()
{
	return RED;
}

/*--------------------------------------------------------------------------------------
  get_Pin_GREEN
  Return the pin associated to this color
--------------------------------------------------------------------------------------*/
int LEDRGB::get_Pin_GREEN()
{
	return GREEN;
}

/*--------------------------------------------------------------------------------------
  get_Pin_BLUE
  Return the pin associated to this color
--------------------------------------------------------------------------------------*/
int LEDRGB::get_Pin_BLUE()
{
	return BLUE;
}

/*--------------------------------------------------------------------------------------
  setColor
  Set the brightness for a specific color assigend to the pinOut, with a value.
	for 0 the color is OFF, for 255 the color is ON, with the others possible values 
	within.
--------------------------------------------------------------------------------------*/
void LEDRGB::setColor(int pinOut,int value)
{	
	
	if (validate_output(value))
	{
		if( COMMON_ANODE )
		{
			analogWrite(pinOut, MAX_VOLTAGE - value);
		} 
		else
		{
			rise_voltage(pinOut, value);
		}
	}
	
	return;
}

/*--------------------------------------------------------------------------------------
  fade_color_in
  Rise the brightness of the specific color connected to pinOut from 0 to 255 using a 
	delay of delay_time
--------------------------------------------------------------------------------------*/
void LEDRGB::fade_color_in(int pinOut, int delay_time)
{

	if( COMMON_ANODE )
	{
		low_voltage(pinOut, delay_time);
	} 
	else{
		rise_voltage(pinOut, delay_time);
	}
	
	return;
} 

/*--------------------------------------------------------------------------------------
  fade_color_out
  Low the brightness of the specific color connected to pinOut from 255 to 0 using a 
	delay of delay_time
--------------------------------------------------------------------------------------*/
void LEDRGB::fade_color_out(int pinOut, int delay_time)
{

	if( COMMON_ANODE )
	{
		rise_voltage(pinOut, delay_time);
	} 
	else{
		low_voltage(pinOut, delay_time);
	}
	
	return;
}

/*--------------------------------------------------------------------------------------
  test_colors
	Shows all the colors changing through them smoothly
--------------------------------------------------------------------------------------*/
void LEDRGB::test_colors()
{
  // fade from blue to violet
  fade_color_in(RED,FADE_SPEED);

  // fade from violet to red
  fade_color_out(BLUE,FADE_SPEED);

  // fade from red to yellow
  fade_color_in(GREEN,FADE_SPEED); 

  // fade from yellow to green
  fade_color_out(RED,FADE_SPEED);  

  // fade from green to teal
  fade_color_in(BLUE,FADE_SPEED);

  // fade from teal to blue
  fade_color_out(GREEN,FADE_SPEED);  

	return;
}

/*--------------------------------------------------------------------------------------
  test_cold_colors
	Shows COLD the colors changing through them smoothly
--------------------------------------------------------------------------------------*/
void LEDRGB::test_cold_colors()
{
  int delay_intercolor = 5000;
 
	setColor(RED,MIN_VOLTAGE);
  setColor(BLUE,MAX_VOLTAGE);
  setColor(GREEN, MIN_VOLTAGE);  
  
  fade_color_in(BLUE,FADE_SPEED);
  delay(delay_intercolor);
  
  fade_color_in(GREEN,FADE_SPEED);
  delay(delay_intercolor);
  
  fade_color_out(GREEN,FADE_SPEED);  
  delay(delay_intercolor);

  fade_color_out(BLUE,FADE_SPEED);
  
  fade_color_in(GREEN,FADE_SPEED);
  delay(delay_intercolor);

  fade_color_out(GREEN,FADE_SPEED);  

	return;
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

/*--------------------------------------------------------------------------------------
  rise_voltage
  Rise the voltage of pinOut from 0 to 255 using a delay of delay_time
--------------------------------------------------------------------------------------*/
void LEDRGB::rise_voltage(int pinOut, int delay_time)
{
	int i;
  
  for (i = 0; i < 256; i++)
  { 
    analogWrite(pinOut, i);
    delay(delay_time);
  }

	return;
}

/*--------------------------------------------------------------------------------------
  low_voltage
  Low the voltage of pinOut from 255 to 0 using a delay of delay_time
--------------------------------------------------------------------------------------*/
void LEDRGB::low_voltage(int pinOut, int delay_time)
{
  int i;
  
  for (i = 255; i > 0; i--)
  { 
    analogWrite(pinOut, i);
    delay(delay_time);
  }

	return;
}

/*--------------------------------------------------------------------------------------
  validate_Output
  Controls that the voltage to be assigned to the output pin is between min and max
	MIN_VOLTAGE <= voltage <= MAX_VOLTAGE
--------------------------------------------------------------------------------------*/
boolean LEDRGB::validate_output(int voltage)
{
	return	(MIN_VOLTAGE <= voltage) && (voltage <= MAX_VOLTAGE);
}

