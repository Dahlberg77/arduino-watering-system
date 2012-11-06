/*--------------------------------------------------------------------------------------
  This Test function uses the menu class to manage the option on the screen
--------------------------------------------------------------------------------------
void LCD::testMenu()
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


--------------------------------------------------------------------------------------
  This Test function uses the ChannelsRelay class to manage outputs
--------------------------------------------------------------------------------------
void LCD::testRelays()
{
	if(refreshMenu())
	{
				// debug:
				write("    ",1 ,0);
				write(menu.getIndex(),1 ,0);				   
				write(menu.getStatus(),1 ,2);				   
				
		relays.set(menu.getIndex(),menu.getStatus());
	}
	
	return;
}

--------------------------------------------------------------------------------------
  Updates the screen depending on what button is pressed
	Return true if one of the menu has change its status
--------------------------------------------------------------------------------------
boolean LCD::refreshMenu()
{
	byte button;
	boolean hasChangedStatus = false;
  
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
				hasChangedStatus = true;
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
				hasChangedStatus = true;
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

	return hasChangedStatus;
}


*/


