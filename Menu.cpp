/*
  Menu.cpp - Library for managing a menu in a LCD display
  2012 Snake Sanders
*/

// include this library's description file
#include "Menu.h"
#include <string.h>

/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/
	
// Constructor /////////////////////////////////////////////////////////////////

//Menu::Menu(char *titles, int max_options)
Menu::Menu()
{
	// Texts for the menu	
	// if you cange the num of menu remember to cange MAX_OPTIONS
	//titles = {"LIGHTS","WATER PUMP","FAN","MOISTER"};
	
	titles[0] = "LIGHTS";
	titles[1] = "WATER PUMP";
	titles[2] = "FAN";
	titles[3] = "HUMIDIFIER";

	
	resetStatus();
	current_index = 0;
}

/*--------------------------------------------------------------------------------------
  getTitle()
  Return the title of the current menu
--------------------------------------------------------------------------------------*/
char* Menu::getTitle()
{
	return titles[current_index];
}

/*--------------------------------------------------------------------------------------
  getStatus()
  Return the status of the current menu
--------------------------------------------------------------------------------------*/
boolean Menu::getStatus()
{
	return statuses[current_index];
}

/*--------------------------------------------------------------------------------------
  setStatus()
  set status of the current menu
--------------------------------------------------------------------------------------*/
void Menu::setStatus(boolean new_status)
{
	statuses[current_index] = new_status;
	return;
}

/*--------------------------------------------------------------------------------------
  getIndex()
  Return the index of the current menu selected
--------------------------------------------------------------------------------------*/
int Menu::getIndex()
{
	return current_index;
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

/*--------------------------------------------------------------------------------------
  next()
  Select next Menu
	return the current selected menu 
--------------------------------------------------------------------------------------*/
int Menu::next()
{
	int index = current_index + 1;
	
	if( validateMenu(index) )
	{
		current_index = index;
	}
	
	return current_index;
}

/*--------------------------------------------------------------------------------------
  previous()
  Select previous Menu
	return the current selected menu 
--------------------------------------------------------------------------------------*/
int Menu::previous()
{
	int index = current_index - 1;
		
	if( validateMenu(index) )
	{
		current_index = index;
	}
	
	return current_index;
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

/*--------------------------------------------------------------------------------------
  resetStatus()
  Reset to OFF the statuses of the Menus.
--------------------------------------------------------------------------------------*/
void Menu::resetStatus()
{
	int i;
	
	for (i = 0; i < MAX_OPTIONS; i++)
	{
		statuses[i] = false;
	}
	
	return;
}

/*--------------------------------------------------------------------------------------
  validateMenu()
  Controls the index is within the valid values for the Menu index.
--------------------------------------------------------------------------------------*/
boolean Menu::validateMenu(int index)
{
	return (index >=  0) && (index < MAX_OPTIONS);
}
