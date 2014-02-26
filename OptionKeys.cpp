  #include "Options.h"


void PrintKeysPlayer(int x)
{
    engine->Texts->searchtable("option_keys",0)->set_text("Quick Drop"); 
    engine->Texts->searchtable("option_keys",0)->printf("",x,170,255,255,255);
 
    engine->Texts->searchtable("option_keys",0)->set_text("Speed up Drop");
    engine->Texts->searchtable("option_keys",0)->printf("",x,220,255,255,255);
    
    engine->Texts->searchtable("option_keys",0)->set_text("Move Left");
    engine->Texts->searchtable("option_keys",0)->printf("",x,270,255,255,255);
    
    engine->Texts->searchtable("option_keys",0)->set_text("Move Right");
    engine->Texts->searchtable("option_keys",0)->printf("",x,320,255,255,255);
    
    engine->Texts->searchtable("option_keys",0)->set_text("Rotate Left");
    engine->Texts->searchtable("option_keys",0)->printf("",x,370,255,255,255);
    
    engine->Texts->searchtable("option_keys",0)->set_text("Rotate Right");
    engine->Texts->searchtable("option_keys",0)->printf("",x,420,255,255,255);
 
    engine->Texts->searchtable("option_keys",0)->set_text("Special");
    engine->Texts->searchtable("option_keys",0)->printf("",x,470,255,255,255);
}

void PrintKeys()
{


    engine->Texts->searchtable("option_keys",0)->set_text("O");
    engine->Texts->searchtable("option_keys",0)->printf("",optionkeycursor_x,optionkeycursor_y,255,255,255);

    PrintKeysPlayer(100);
    PrintKeysPlayer(400);

    engine->Texts->searchtable("option_keys",0)->set_text("Exit");
    engine->Texts->searchtable("option_keys",0)->printf("",100,520,255,255,255);

    startadd = (unsigned long*) &engine->Keys->a;
    unsigned long* endadd = (unsigned long*) &engine->Keys->ralt;
    status* mystatus;
    int count = 0;

    __asm("mov $0x03, %eax");
    __asm("sub %eax, startadd");

       
    do {

	__asm("mov $0x03, %eax");
        __asm("add %eax, startadd");

	
        
        char keyname[20];
        
        mystatus = (status*) startadd; 
        if (&(*mystatus).key_pressed_down ==  Player1->is_up_key_pressed)
        {
                getkeys(count,270,170);
              
        }
  
         if (&(*mystatus).key_pressed_down ==  Player1->is_down_key_pressed)
        {
                getkeys(count,270,210);
              
        }    
        
    
        if (&(*mystatus).key_pressed_down ==  Player1->is_left_key_down )
        {
                getkeys(count,270,260);
  
              
        }    
        if (&(*mystatus).key_pressed_down ==  Player1->is_right_key_down)
        {
                getkeys(count,270,310);
  
              
        } 
        if (&(*mystatus).key_pressed_down ==  Player1->is_Rotate_L_pressed)
        {
                getkeys(count,270,370);
  
              
        }
        if (&(*mystatus).key_pressed_down ==  Player1->is_Rotate_R_pressed)
        {
                getkeys(count,270,420);
  
              
        }
        if (&(*mystatus).key_pressed_down ==  Player1->is_Special_pressed)
        {
                getkeys(count,270,470);
  
              
        }
 
        /*player 2*/
 
        if (&(*mystatus).key_pressed_down ==  Player2->is_up_key_pressed)
        {
                getkeys(count,570,170);
              
        }
          if (&(*mystatus).key_pressed_down ==  Player2->is_down_key_pressed)
        {
                getkeys(count,570,210);
              
        }    
        
    
        if (&(*mystatus).key_pressed_down ==  Player2->is_left_key_down)
        {
                getkeys(count,570,260);
  
              
        }    
        if (&(*mystatus).key_pressed_down ==  Player2->is_right_key_down)
        {
                getkeys(count,570,310);
  
              
        } 
        if (&(*mystatus).key_pressed_down ==  Player2->is_Rotate_L_pressed)
        {
                getkeys(count,570,370);
  
              
        }
        if (&(*mystatus).key_pressed_down ==  Player2->is_Rotate_R_pressed)
        {
                getkeys(count,570,420);
  
              
        }
        if (&(*mystatus).key_pressed_down ==  Player2->is_Special_pressed)
        {
                getkeys(count,570,470);
  
              
        }

        count++;
             
    } while (startadd < endadd);
    
    
 
}

void Option_Keys_Render()
{
    engine->paintbg(0x00,0x00,0x00);
    engine->Texts->searchtable("option_keys",0)->set_text("Key Options");
    engine->Texts->searchtable("option_keys",0)->printf("",340,10,255,255,255);
    
    engine->Texts->searchtable("option_keys",0)->set_text("Player 1");
    engine->Texts->searchtable("option_keys",0)->printf("",100,100,255,255,255);
    
    engine->Texts->searchtable("option_keys",0)->set_text("Player 2");
    engine->Texts->searchtable("option_keys",0)->printf("",400,100,255,255,255);
    
    
    PrintKeys();
    if (inputmode == false)
    {
	    if (is_down_key_pressed())
	    {
	        if ((optionkeycursor_y != 520))//470)
	        {
                	optionkeycursor_y += 50;
            	}	
		reset_down_key();
	    }

	    if (is_up_key_pressed())
	    {
	        if (optionkeycursor_y != 170)
	        {
                	optionkeycursor_y -= 50;
		   
		 }
		    reset_up_key();
        }
     
        if (engine->Keys->right.key_pressed_down)
        {
            if (optionkeycursor_x != 345)
            {
		if ((optionkeycursor_y != 520))
		{
                	optionkeycursor_x=345;
		}
            }
            engine->Keys->right.key_pressed_down = false;
        }
        
        if (engine->Keys->left.key_pressed_down)
        {
            if (optionkeycursor_x != 45)
            {
                optionkeycursor_x=45;
            }
            engine->Keys->left.key_pressed_down = false;
        }
    
        if (is_enter_key_pressed())
        {
	    if (optionkeycursor_y == 520)
	    {
		option_mode = GAME_OPTIONS;
	    } else {
            	inputmode = true;
            }

	    reset_enter_key();
	    engine->Keys->key_down = false;

        }
    } else {




        engine->Texts->searchtable("option_keys",0)->set_text("Press a Key");
        engine->Texts->searchtable("option_keys",0)->printf("",400,500,255,255,255);
	if (engine->Keys->key_down)
	{
		getstartadd = (unsigned long*) &engine->Keys->a;
    		unsigned long* getendadd = (unsigned long*) &engine->Keys->ralt;
    		status* getmystatus;
    		
		do {
               		 getmystatus = (status*) getstartadd; 
			 if ((*getmystatus).key_pressed_down)
			 {
				break;
			 }
			__asm("mov $0x03, %eax");
        		__asm("add %eax, getstartadd");
 
		} while (getstartadd != getendadd);

		/*UP  Quick drop */
		if (optionkeycursor_x == 45 && optionkeycursor_y == 170)
		{
			Player1->is_up_key_pressed = &(*getmystatus).key_pressed_down;			
		}

		if (optionkeycursor_x == 45 && optionkeycursor_y == 220)
		{
			Player1->is_down_key_pressed = &(*getmystatus).key_pressed_down;			
			
		}
		if (optionkeycursor_x == 45 && optionkeycursor_y == 270)
                {
			Player1->is_left_key_pressed = &(*getmystatus).is_key_pressed;
			Player1->is_left_key_down =  &(*getmystatus).key_pressed_down;
		}

		if (optionkeycursor_x == 45 && optionkeycursor_y == 320)
                {
			Player1->is_right_key_pressed = &(*getmystatus).is_key_pressed;
			Player1->is_right_key_down =  &(*getmystatus).key_pressed_down;
		}
		if (optionkeycursor_x == 45 && optionkeycursor_y == 370)
                {
			Player1->is_Rotate_L_pressed =  &(*getmystatus).key_pressed_down;
			
		}
		if (optionkeycursor_x == 45 && optionkeycursor_y == 420)
                {
    			Player1->is_Rotate_R_pressed =  &(*getmystatus).key_pressed_down;
			
		}
		if (optionkeycursor_x == 45 && optionkeycursor_y == 470)
                {
			Player1->is_Special_pressed =   &(*getmystatus).key_pressed_down;
			
		}

		/* Set Keys for Player 2*/
		if (optionkeycursor_x == 345 && optionkeycursor_y == 170)
		{
			Player2->is_up_key_pressed = &(*getmystatus).key_pressed_down;	
					
		}

		if (optionkeycursor_x == 345 && optionkeycursor_y == 220)
		{
			Player2->is_down_key_pressed = &(*getmystatus).key_pressed_down;			
			
		}
		if (optionkeycursor_x == 345 && optionkeycursor_y == 270)
                {
			Player2->is_left_key_pressed = &(*getmystatus).is_key_pressed;
			Player2->is_left_key_down =  &(*getmystatus).key_pressed_down;
		}

		if (optionkeycursor_x == 345 && optionkeycursor_y == 320)
                {
			Player2->is_right_key_pressed = &(*getmystatus).is_key_pressed;
			Player2->is_right_key_down =  &(*getmystatus).key_pressed_down;
		}
		if (optionkeycursor_x == 345 && optionkeycursor_y == 370)
                {
			Player2->is_Rotate_L_pressed =  &(*getmystatus).key_pressed_down;
			
		}
		if (optionkeycursor_x == 345 && optionkeycursor_y == 420)
                {
    			Player2->is_Rotate_R_pressed =  &(*getmystatus).key_pressed_down;
			
		}
		if (optionkeycursor_x == 345 && optionkeycursor_y == 470)
                {
			Player2->is_Special_pressed =   &(*getmystatus).key_pressed_down;
			
		}


		(*getmystatus).key_pressed_down = false;

		inputmode = false;
		
		printf("x: %i  y: %i\n",optionkeycursor_x, optionkeycursor_y);
		
	}
        
    }
}
//270 170

char* getkeys(int count2,int x, int y)
{
    char keyname[10];
     
    if (count2 > -1 && count2 < 25)
     {

	 if (count2 == 0)
	 {
		keyname[0] = (char) 65;
	 } else {
         	keyname[0] = (char) (65 + (count2));
	 }
                
          keyname[1] = 0x00;
          engine->Texts->searchtable("option_keys",0)->set_text(keyname);
          engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                
      } else {
        switch(count2-1)
        {
           case 25:
           {
               engine->Texts->searchtable("option_keys",0)->set_text("UP");
               engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
               break;
            }
            case 26:
            {
                engine->Texts->searchtable("option_keys",0)->set_text("Down");
                engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                break;
             }
             case 27:
             {
                 engine->Texts->searchtable("option_keys",0)->set_text("Left");
                 engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                 break;
             }
             case 28:
             {
                  engine->Texts->searchtable("option_keys",0)->set_text("Right");
                  engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                  break;
              }
              case 29:
              {
                   engine->Texts->searchtable("option_keys",0)->set_text("Enter");
                   engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                   break;
              }
              case 30:
              {
                   engine->Texts->searchtable("option_keys",0)->set_text("Escape");
                   engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                   break;
               }
               case 31:
               {
                    engine->Texts->searchtable("option_keys",0)->set_text("Backsapce");
                    engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                    break;
                }
                case 32:
                {
                     engine->Texts->searchtable("option_keys",0)->set_text("Tab");
                     engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                     break;
                }
                case 33:
                {
                      engine->Texts->searchtable("option_keys",0)->set_text("Delete");
                      engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                      break;
                 }
                 case 34:
                 {
                       engine->Texts->searchtable("option_keys",0)->set_text("Clear");
                       engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                       break;
                 }
                 case 35:
                 {
                       engine->Texts->searchtable("option_keys",0)->set_text("Space");
                       engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                       break;
                 }
                 case 36:
                 {
                    engine->Texts->searchtable("option_keys",0)->set_text("One");
                    engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                    break;
                  }
                  case 37:
                  {
                      engine->Texts->searchtable("option_keys",0)->set_text("Two");
                      engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                      break;
                  }
                  case 38:
                  {
                      engine->Texts->searchtable("option_keys",0)->set_text("Three");
                      engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                      break;
                  }
                  case 39:
                  {
                      engine->Texts->searchtable("option_keys",0)->set_text("Four");
                      engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                      break;
                  }
                  case 40:
                  {
                       engine->Texts->searchtable("option_keys",0)->set_text("Five");
                       engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                       break;
                   }
                   case 41:
                   {
                       engine->Texts->searchtable("option_keys",0)->set_text("Six");
                       engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                        break;
                    }
                    case 42:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Seven");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                        break;
                    }
                    case 43:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Eight");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                        break;
                    }
                    case 44:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Nine");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                        break;
                    }
                    case 45:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Zero");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                       
                        break;
                    }
                    case 46:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Right Shift");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                        break;
                    }
                    case 47:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Left Shift");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
           
                        break;
                    }
                    case 48:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Right Control");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                    
                        break;
                    }
                    case 49:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Left Control");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                       
                        break;
                    }
                    case 50:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Right Alt");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                        
                        break;
                    }
                    case 51:
                    {
                        engine->Texts->searchtable("option_keys",0)->set_text("Left Alt");
                        engine->Texts->searchtable("option_keys",0)->printf("",x,y,255,255,255);
                        break;
                    }
          }
     }

}
