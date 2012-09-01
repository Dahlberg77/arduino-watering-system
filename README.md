arduino-watering-system
=======================

This is a project based on Arduino Mega for a watering system.

The intention of this project is controlling a greenhouse. I would like to 
see this code running on a real greenhouse someday.
The three basic parameter to control are: 

-light 
-moisture 
-temperature

The system has a LCD display with keypad for monitoring the inputs and
configuring the output.
Arduino should be able to control four devices connected to the output:

-Light
-Fan
-Water pump
-Humidifier

The structure of the source code at this time is as follow:

	Class name							Description
	==========================================================================================================

	LCDkyepad  						: Manage the user inputs interfacing the buttons and shows a menu on the LCD display
		|__ Menu 						: Displays the menu's options and the status of the output
		|__ ChannelsRelay 	: It's the interface between the LCDKeypad and the output. Turns on and off the output. 
	
	LEDRGB								: It's a class to manage a LED RGB for changing its colors

The first files will be for testing the devices, such as LCD display and water pump.

For more info check my blog:

http://handsonarduinomega.blogspot.cz/


Conditions:
===========

You can redistribute this code and/or modify it under the terms of the GPL.
This code is code is intended for experimentation and I can not warranty the correct functionality of this software, there fore I am not responsible of any damage on your hardware/software. The source is open, take a look at it if you have any doubts.
