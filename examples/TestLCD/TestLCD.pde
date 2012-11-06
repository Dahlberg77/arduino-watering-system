#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif

#include <LiquidCrystal.h>
#include <LCD.h>

/*--------------------------------------------------------------------------------------
  This Test function Shows the functionalities of the LCD class
--------------------------------------------------------------------------------------*/

LCD lcd = LCD();

void setup()
{
	lcd.clean_all();
}

void loop()
{
	delay(1000);
  lcd.write("Testing the LCD",0,0);
  delay(1000);
	lcd.clean(0);
	
  lcd.write("Write line 1",0,0);
  delay(1000);
  lcd.write("Write line 2",1,0);
  delay(1000);
  lcd.write("Cleaning line 1",1,0);
  delay(1000);
	lcd.clean(0);

  delay(1000);
  lcd.write("Cleaning line 2",0,0);
  delay(1000);
	lcd.clean(1);
  delay(1000);
	
	for(int line = 0; line < 2; ++line)
	{
		lcd.clean(line);
		print_number(line);
	}
	
	delay(1000);
	lcd.clean_all();

}

void print_number(int line)
{
	int x;
	
	for(int i = 0; i < 16; ++i)
	{
		delay(500);
		
		if( i > 9) x = i - 10;	
		else x = i;
  	
		lcd.write(x,line,i);
	}
	
	return;
}