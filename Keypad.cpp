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
  
  This program demonstrates button detection on the Freetronics LCD & Keypad Shield, connected to an Arduino board.
  
  Pins used by Keypad Shield:
  
    A0: Buttons, analog input from voltage ladder
  
  ADC voltages for the 5 buttons on analog input pin A0:
  
    RIGHT:  0.00V :   0 @ 8bit ;   0 @ 10 bit
    UP:     0.71V :  36 @ 8bit ; 133 @ 10 bit
    DOWN:   1.61V :  82 @ 8bit ; 308 @ 10 bit
    LEFT:   2.47V : 126 @ 8bit ; 481 @ 10 bit
    SELECT: 3.62V : 185 @ 8bit ; 722 @ 10 bit

**/


/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/
// include this library's description file
#include "Keypad.h"

/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/
// this should be private

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances


Keypad::Keypad(void)
{
	 buttonJustPressed  = false;
	 buttonJustReleased = false;
	 last_debounce_Time = 0;
	 buttonWas          = BUTTON_NONE;
	
  //button adc input
  pinMode( BUTTON_ADC_PIN, INPUT );         //ensure A0 is an input
  digitalWrite( BUTTON_ADC_PIN, LOW );      //ensure pullup is off on A0

	return;
}

/*--------------------------------------------------------------------------------------
  Return true if the button was pressed. false otherwise
--------------------------------------------------------------------------------------*/
boolean Keypad::was_button_pressed()
{
	boolean res = buttonJustPressed;
	buttonJustPressed |= false; //clear flag
	
	return res;
}

/*--------------------------------------------------------------------------------------
  Return true if the button was released. false otherwise
--------------------------------------------------------------------------------------*/
boolean Keypad::was_button_released()
{
	boolean res = buttonJustReleased;
  buttonJustReleased |= false; //clear flag
	
	return res;
}

/*--------------------------------------------------------------------------------------
  Compare the measure to the set_point checking if it is withing the hysteresis
--------------------------------------------------------------------------------------*/
boolean Keypad::is_in_Range(unsigned int measure, unsigned int set_point, unsigned int hysteresis)
{
  return  (measure >= ( set_point - hysteresis ) && measure <= ( set_point + hysteresis ));
}

/*--------------------------------------------------------------------------------------
  read_buttons()
  Detect the button pressed and return the value
  Uses global values buttonWas, buttonJustPressed, buttonJustReleased.
--------------------------------------------------------------------------------------*/
byte Keypad::read_buttons()
{
	byte button ;
	
	button = get_button_from_input_volts();

	 if (is_bouncing(button))
		{
			button = BUTTON_BOUNCING;
		}else
		{	  
				//handle button flags for just pressed and just released events
		   if( ( buttonWas == BUTTON_NONE ) && ( button != BUTTON_NONE ) )
		   {
		      // the button was just pressed, set buttonJustPressed, this can optionally 
					// be used to trigger a once-off action for a button press event
		      // it's the duty of the receiver to clear these flags if it wants to detect a new button change event
		      buttonJustPressed  = true;
		      buttonJustReleased = false;
		   }
		
		   if( ( buttonWas != BUTTON_NONE ) && ( button == BUTTON_NONE ) )
		   {
		      buttonJustPressed  = false;
		      buttonJustReleased = true;
		   }
   
	   		//save the latest button value, for change event detection next time round
	   		buttonWas = button;			
		}
   
   return( button );
}

/*--------------------------------------------------------------------------------------
  get_button_from_unput_volts()
  Detect the button pressed based on the Voltage of the Analog input 
	return the button pressed
--------------------------------------------------------------------------------------*/
byte Keypad::get_button_from_input_volts()
{
	unsigned int buttonVoltage;
	byte button = BUTTON_NONE;   // return no button pressed if the below checks don't write to btn
  
  //read the button ADC pin voltage
  buttonVoltage = analogRead( BUTTON_ADC_PIN );

  //sense if the voltage falls within valid voltage windows
  if( buttonVoltage < ( RIGHT_10BIT_ADC + BUTTONHYSTERESIS ) )
  {
     button = BUTTON_RIGHT;
  }
  else if( is_in_Range(buttonVoltage, UP_10BIT_ADC, BUTTONHYSTERESIS))
  {
     button = BUTTON_UP;
  }
  else if( is_in_Range(buttonVoltage, DOWN_10BIT_ADC, BUTTONHYSTERESIS) )
  {
     button = BUTTON_DOWN;
  }
  else if( is_in_Range(buttonVoltage, LEFT_10BIT_ADC, BUTTONHYSTERESIS) )
  {
     button = BUTTON_LEFT;
  }
  else if( is_in_Range(buttonVoltage, SELECT_10BIT_ADC, BUTTONHYSTERESIS) )
  {
     button = BUTTON_SELECT;
  }

	return button;
}

/*--------------------------------------------------------------------------------------
  is_Button_Bouncing()
  Detect if the button is being pressed by natural bouncing 
	return true if it's bouncing
--------------------------------------------------------------------------------------*/
boolean Keypad::is_bouncing(byte button)
{
	boolean isBouncing = false;
	
	if(button == buttonWas)
	{
		last_debounce_Time = millis();
	}
	
	if(millis() - last_debounce_Time < DEBOUNCING_DELAY)
	{
		isBouncing = true;
	}
	
	return isBouncing;
}