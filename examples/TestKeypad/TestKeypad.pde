#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

#include <LiquidCrystal.h>
#include <LCD.h>
#include <Keypad.h>

/*--------------------------------------------------------------------------------------
  This Test function shows the voltage generated at the Analog input for each button
--------------------------------------------------------------------------------------*/

LCD lcd = LCD();
Keypad keypad = Keypad();


void setup()
{
	lcd.clean_all();
	lcd.write("Testing keypad",0,0);
}

void loop()
{
   byte button;
   
   //get the latest button pressed, also the buttonJustPressed, buttonJustReleased flags
   button = keypad.read_buttons();

   //blank the demo text line if a new button is pressed or released, ready for a new label to be written
   if( keypad.was_button_pressed() || keypad.was_button_released() )
   {
			lcd.clean(1);
			print_voltage();
   }

	print_press_release();

   //show text label for the button pressed
   switch( button )
   {
      case BUTTON_NONE:
      {
         break;
      }
      case BUTTON_RIGHT:
      {
				lcd.write("RIGHT",1 ,0);
        break;
      }
      case BUTTON_UP:
      {
				lcd.write("UP",1 ,0);
				break;
      }
      case BUTTON_DOWN:
      {
         lcd.write("DOWN",1 ,0);
         break;
      }
      case BUTTON_LEFT:
      {
				lcd.write("LEFT",1 ,0);
        break;
     }
     case BUTTON_SELECT:
     {
				lcd.write("SELECT",1 ,0);
				play_backLight();
        break;
      }
      default:
     {
        break;
     }
   }
  
  delay(100);

}

//debug/test display of the adc reading for the button input voltage pin.
void print_voltage()
{
	int volts = 0;
	//quick hack to blank over default left-justification from display.print()
	volts = analogRead( BUTTON_ADC_PIN );
	lcd.write("    mV",1 ,10);
	lcd.write(volts, 1,10);
	
	return;	
}

// prints a P when a button is pressed
// prints a R when a button is released
void print_press_release()
{
	if(keypad.was_button_pressed())
	{
		lcd.write("P",0,15);
	}
	if(keypad.was_button_released())
	{
		lcd.write("R",0,15);
	}
	
	return;	
}

// it pulses the LCD backlight off and on for demo
void play_backLight()
{
	digitalWrite( LCD_BACKLIGHT_PIN, LOW );
	delay( 150 );
	digitalWrite( LCD_BACKLIGHT_PIN, HIGH );   //leave the backlight on at exit
	delay( 150 );
	
	return;
}