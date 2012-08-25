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
  
  This program demonstrates button detection, LCD text/number printing,
  and LCD backlight control on the Freetronics LCD & Keypad Shield, connected to an Arduino board.
  
  After powerup, the screen looks like this:
  
       ------------------
       |Freetronics 16x2|
       |Btn:          0 | <- This time value counts up the number of seconds since reset (overflows at 99)
       ------------------
 
  When a button is pressed, a label appears for it:
  
       ------------------
       |Freetronics 16x2|
       |Btn:RIGHT     0 |
       ------------------
       Labels are LEFT, UP, DOWN, RIGHT and SELECT-FLASH.
       SELECT-FLASH makes the LCD backlight flash off and on when held down.  
  
  Pins used by LCD & Keypad Shield:
  
    A0: Buttons, analog input from voltage ladder
    D4: LCD bit 4
    D5: LCD bit 5
    D6: LCD bit 6
    D7: LCD bit 7
    D8: LCD RS
    D9: LCD E
    D3: LCD Backlight (high = on, also has pullup high so default is on)
  
  ADC voltages for the 5 buttons on analog input pin A0:
  
    RIGHT:  0.00V :   0 @ 8bit ;   0 @ 10 bit
    UP:     0.71V :  36 @ 8bit ; 133 @ 10 bit
    DOWN:   1.61V :  82 @ 8bit ; 308 @ 10 bit
    LEFT:   2.47V : 126 @ 8bit ; 481 @ 10 bit
    SELECT: 3.62V : 185 @ 8bit ; 722 @ 10 bit
**/

// include this library's description file
#include "LCDKeypad.h"
#include <LiquidCrystal.h>
#include <string.h>
#include "Menu.h"

/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/
// this should be private
//Pins for the freetronics 16x2 LCD shield. LCD: ( RS, E, LCD-D4, LCD-D5, LCD-D6, LCD-D7 )
LiquidCrystal display( 8, 9, 4, 5, 6, 7 ); 
Menu menu = Menu();  

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances
LCDKeypad::LCDKeypad (void)
{
	 buttonJustPressed  = false;
	 buttonJustReleased = false;
	 last_debounce_Time = 0;
	 buttonWas          = BUTTON_NONE;
	
   //button adc input
   pinMode( BUTTON_ADC_PIN, INPUT );         //ensure A0 is an input
   digitalWrite( BUTTON_ADC_PIN, LOW );      //ensure pullup is off on A0

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
void LCDKeypad::write(char* text, int line, int at)
{
	 display.setCursor(at, line);
	 display.print(text);
	return;
}

void LCDKeypad::write(int text, int line, int at)
{
	 display.setCursor(at, line);
	 display.print(text);
	return;
}

/*--------------------------------------------------------------------------------------
  Clean the whole line from the LCD especified by line
--------------------------------------------------------------------------------------*/
void LCDKeypad::cleanLine(int line)
{
				//1234567890123456
	write( "                ", line ,0);
	return;
}

/*--------------------------------------------------------------------------------------
  Return true if the button was pressed. false otherwise
--------------------------------------------------------------------------------------*/
boolean LCDKeypad::wasButtonPressed()
{
	return buttonJustPressed;
}

/*--------------------------------------------------------------------------------------
  Return true if the button was released. false otherwise
--------------------------------------------------------------------------------------*/
boolean LCDKeypad::wasButtonReleased()
{
	return buttonJustReleased;
}

/*--------------------------------------------------------------------------------------
  This Test function Shows the voltage generated at the Analog input for each button
--------------------------------------------------------------------------------------*/
void LCDKeypad::test()
{
   byte button;
   
   //get the latest button pressed, also the buttonJustPressed, buttonJustReleased flags
   button = readButtons();
   //blank the demo text line if a new button is pressed or released, ready for a new label to be written
   if( buttonJustPressed || buttonJustReleased )
   {
			write( "                ", 1 ,0);
   }
   //show text label for the button pressed
   switch( button )
   {
      case BUTTON_NONE:
      {
         break;
      }
      case BUTTON_RIGHT:
      {
				write("RIGHT",1 ,0);
        break;
      }
      case BUTTON_UP:
      {
				write("UP",1 ,0);
				break;
      }
      case BUTTON_DOWN:
      {
         write("DOWN",1 ,0);
         break;
      }
      case BUTTON_LEFT:
      {
				write("LEFT",1 ,0);
        break;
     }
     case BUTTON_SELECT:
     {
				write("SELECT",1 ,0);
        
        //SELECT is a special case, it pulses the LCD backlight off and on for demo
        digitalWrite( LCD_BACKLIGHT_PIN, LOW );
        delay( 150 );
        digitalWrite( LCD_BACKLIGHT_PIN, HIGH );   //leave the backlight on at exit
        delay( 150 );
                
        break;
      }
      default:
     {
        break;
     }
   }
  
   //debug/test display of the adc reading for the button input voltage pin.
	 write("    mV",1 ,10);
	//quick hack to blank over default left-justification from display.print()
   display.setCursor(10, 1);         //note the value will be flickering/faint on the LCD
   display.print( analogRead( BUTTON_ADC_PIN ) );
   delay(500);

   //clear the buttonJustPressed or buttonJustReleased flags, they've already done their job now.
   if( buttonJustPressed )
      buttonJustPressed = false;
   if( buttonJustReleased )
      buttonJustReleased = false;
}

/*--------------------------------------------------------------------------------------
  This Test function uses the menu class to manage the option on the screen
--------------------------------------------------------------------------------------*/
void LCDKeypad::testMenu()
{
   byte button;
   
   //get the latest button pressed, also the buttonJustPressed, buttonJustReleased flags
   button = readButtons();

   //blank the demo text line if a new button is pressed or released, ready for a new label to be written
   if( buttonJustPressed || buttonJustReleased )
   {
		//this should avoid de bouncing of the button.
		delay(50);
		cleanLine(0);
   }
   //show text label for the button pressed
   switch( button )
   {
      case BUTTON_NONE:
      {
         break;
      }
      case BUTTON_RIGHT:
      {
				menu.setStatus(ON);
        break;
      }
      case BUTTON_UP:
      {
				menu.previous();
				break;
      }
      case BUTTON_DOWN:
      {
				menu.next();
        break;
      }
      case BUTTON_LEFT:
      {
				menu.setStatus(OFF);
        break;
     }
     case BUTTON_SELECT:
     {
				write("SELECT",2 ,0);                
        break;
      }
      default:
     {
        break;
     }
   }

		//updates de info shown on the LCD scree with valid data
		updateScreen();
	
   //clear the buttonJustPressed or buttonJustReleased flags, they've already done their job now.
   if( buttonJustPressed )
      buttonJustPressed = false;
   if( buttonJustReleased )
      buttonJustReleased = false;
}

/*--------------------------------------------------------------------------------------
  Compare the measure to the set_point checking if it is withing the hysteresis
--------------------------------------------------------------------------------------*/
boolean LCDKeypad::isInRange(unsigned int measure, unsigned int set_point, unsigned int hysteresis)
{
  return  (measure >= ( set_point - hysteresis ) && measure <= ( set_point + hysteresis ));
}

/*--------------------------------------------------------------------------------------
  ReadButtons()
  Detect the button pressed and return the value
  Uses global values buttonWas, buttonJustPressed, buttonJustReleased.
--------------------------------------------------------------------------------------*/
byte LCDKeypad::readButtons()
{
	byte button ;
	
	button = getButtonFromInputVolts();

	 if (isButtonBouncing(button))
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
  getButtonFromInputVolts()
  Detect the button pressed based on the Voltage of the Analog input 
	return the button pressed
--------------------------------------------------------------------------------------*/
byte LCDKeypad::getButtonFromInputVolts()
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
  else if( isInRange(buttonVoltage, UP_10BIT_ADC, BUTTONHYSTERESIS))
  {
     button = BUTTON_UP;
  }
  else if( isInRange(buttonVoltage, DOWN_10BIT_ADC, BUTTONHYSTERESIS) )
  {
     button = BUTTON_DOWN;
  }
  else if( isInRange(buttonVoltage, LEFT_10BIT_ADC, BUTTONHYSTERESIS) )
  {
     button = BUTTON_LEFT;
  }
  else if( isInRange(buttonVoltage, SELECT_10BIT_ADC, BUTTONHYSTERESIS) )
  {
     button = BUTTON_SELECT;
  }

	return button;
}

/*--------------------------------------------------------------------------------------
  isButtonBouncing()
  Detect if the button is being pressed by natural bouncing 
	return true if it's bouncing
--------------------------------------------------------------------------------------*/
boolean LCDKeypad::isButtonBouncing(byte button)
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

/*--------------------------------------------------------------------------------------
  updateScreen()
  Updates the information shown on the screen of the LCD
--------------------------------------------------------------------------------------*/
void LCDKeypad::updateScreen()
{
		// format: index-Title	
		write(menu.getIndex() + 1, 0, 0);
		write("-", 0, 1);		
		write(menu.getTitle(), 0, 2);
		
		if(menu.getStatus())
		{
			write(" ON", 2, 13);
		}else{
			write("OFF", 2, 13);
		}
		
		return;
}

