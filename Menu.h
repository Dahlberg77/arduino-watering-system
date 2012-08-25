/*
  Menu.h - Library for managing a menu in a LCD display
  2012 Snake Sanders
*/

// ensure this library description is only included once
#ifndef Menu_h
#define Menu_h

#ifndef Arduino_h
	#include "Arduino.h"
#endif

// include types & constants of Wiring core API
//#include "WConstants.h"
/**
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "WConstants.h"
#endif
*/



// library interface description
class Menu
{
  // user-accessible "public" interface
  public: 
    Menu();
		int next();
		int previous();
		char * getTitle();
		boolean getStatus();
		void setStatus(boolean new_status);
		int getIndex();
		// variables

  	// library-accessible "private" interface
  private:
		void resetStatus();
		boolean validateMenu(int index);

		// number of options listed by the menu
		#define MAX_OPTIONS 	4
				
		// variables
		int current_index;							// index of the current menu selected
		char *titles[MAX_OPTIONS];			// text for menu
		boolean statuses[MAX_OPTIONS]; 	// status of menu on/off
		
};

#endif

