/*
  Menu.h - Library for managing a menu in a LCD display
  2012 Snake Sanders
*/

// ensure this library description is only included once
#ifndef MenuController_h
#define MenuController_h

#ifndef Arduino_h
	#include "Arduino.h"
#endif

// library interface description
class MenuController
{
  // user-accessible "public" interface
  public: 
    MenuController();
		int get_index();
		void set_index(int new_index);
		int next();
		int previous();
		
		int get_option();
		int get_option(int index);
		void set_option(int new_option);
		int next_opt();
		int previous_opt();		

		// variables

  	// library-accessible "private" interface
  private:
		void 		reset_status();
		int 		get_option_size(int index, int option);
		
		boolean validate_index(int index);
		boolean validate_option(int option);
		boolean validate_option(int index, int option);		
		boolean	validate_option_size(int index, int option);
				
		// variables
		int current_index;											// current item selected
		#define INDEX_SIZE  	5									// Maximum items of the menu
		#define OPTION_SIZE  	5								// Maximum subitems of the menu		
		int options[OPTION_SIZE];								// Number of subitmes of a Index
		int list_options_size[INDEX_SIZE];				// List of Maximum subitems for each item
		
};

#endif

