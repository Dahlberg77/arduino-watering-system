#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

#include <LiquidCrystal.h>
#include <LCD.h>
#include <Keypad.h>
#include <MenuController.h>


// This sample file shows a menu on the LCD display and let you play with the buttons

LCDKeypad lcd = LCDKeypad();
Keypad keypad = Keypad();
MenuController menu = MenuController();

byte button;

string INDEX_NAMES[5] = {"Water","Fan","Light","Moister","Color"};
	
void setup()
{
	lcd.cleanLine(0);
	lcd.write(INDEX_NAMES[0],1);
}

void loop()
{

  button = keypad.read_buttons();

   if( keypad.was_button_pressed())
   {
		refresh_status(button);
   }

  delay(50);
}

void refresh_status(byte button_pressed){

   switch( button_pressed )
   {
      case BUTTON_NONE:
      {
         break;
      }
      case BUTTON_RIGHT:
      {

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

	return;	
}