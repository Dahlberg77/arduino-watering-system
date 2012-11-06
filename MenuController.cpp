/*
  Menu.cpp - Library for managing a menu with set of options and sub options
	Index is the primary item selectable of the menu.
	Option is a selection within a Index.
	
	e.g.
	
	Index Title		Option1	Option2	Option3 ..	Size
	0			Water		Off			On			-						2
	1			Fan			Off			On			-						2	
	2			Humid.	Off			On			-						2
	3			Light		Off			On			-						2
	4			Color		RED			GREEN		BLUE		..	3
	
	Index is represented by an Integer [0 -9]
	The Title text is not store on this class
	Option is represented by an Integer [0 -9]
	Size represents how many options has the index
	
	
  2012 Snake Sanders

*/

// include this library's description file
#include "MenuController.h"
#include <string.h>

/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/
	
// Constructor /////////////////////////////////////////////////////////////////


//MenuController::Menu(int num_itmes)
MenuController::MenuController()
{	
	reset_status();
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

/*--------------------------------------------------------------------------------------
  get_index()
  Return the index of the current menu
--------------------------------------------------------------------------------------*/
int MenuController::get_index()
{
	return current_index;
}

/*--------------------------------------------------------------------------------------
  set_index()
  Set current item for the menu
--------------------------------------------------------------------------------------*/
void MenuController::set_index(int new_index)
{
 	current_index = new_index;
	return;
}

/*--------------------------------------------------------------------------------------
  next()
  Select next Menu
	return the current selected menu 
--------------------------------------------------------------------------------------*/
int MenuController::next()
{
	int new_index = current_index + 1;
	
	if( validate_index(new_index) )
	{
		current_index = new_index;
	}
	
	return current_index;
}

/*--------------------------------------------------------------------------------------
  previous()
  Select previous Menu
	return the current selected menu 
--------------------------------------------------------------------------------------*/
int MenuController::previous()
{
	int new_index = current_index - 1;
		
	if( validate_index(new_index) )
	{
		current_index = new_index;
	}
	
	return current_index;
}

/*--------------------------------------------------------------------------------------
  get_option()
  Return the index of the current option selected. Consider the current index
--------------------------------------------------------------------------------------*/
int MenuController::get_option()
{
	return get_option(current_index);
}

int MenuController::get_option(int index)
{
	return options[index];
}

/*--------------------------------------------------------------------------------------
  set_option()
  Set current subitem for the current itme selected menu
--------------------------------------------------------------------------------------*/
void MenuController::set_option(int new_option)
{
	if(validate_option(new_option))
	{
		options[current_index] = new_option;	
	}
 	
	return;
}

/*--------------------------------------------------------------------------------------
  next_opt()
  Select next option
	return the current selected suboption
--------------------------------------------------------------------------------------*/
int MenuController::next_opt()
{
	int new_option = options[current_index] + 1;
	
	if( validate_option(new_option) )
	{
		options[current_index] = new_option;
	}
	
	return options[current_index];
}

/*--------------------------------------------------------------------------------------
  previous_opt()
  Select previous Menu
	return the current selected suboption 
--------------------------------------------------------------------------------------*/
int MenuController::previous_opt()
{
	int new_option = options[current_index] - 1;
	
	if( validate_option(new_option) )
	{
		options[current_index] = new_option;
	}
	
	return options[current_index];
}


// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

/*--------------------------------------------------------------------------------------
  resetStatus()
  Reset to the menu to the first item, first option.
--------------------------------------------------------------------------------------*/
void MenuController::reset_status()
{
	current_index = 0;
	options[0] = 0;
	
	return;
}

/*--------------------------------------------------------------------------------------
  validate_index()
  Controls the index is within the valid values for the Menu index.
--------------------------------------------------------------------------------------*/
boolean MenuController::validate_index(int index)
{
	return (index >=  0) && (index < INDEX_SIZE);
}

/*--------------------------------------------------------------------------------------
  validate_option()
  Controls the option is within the valid values for the index. Also validates the index
--------------------------------------------------------------------------------------*/
boolean MenuController::validate_option(int option)
{	
	return validate_option(current_index, option);
}

boolean MenuController::validate_option(int index, int option)
{	
	return validate_index(index) && (option >=  0) && (option < options[index]);
}