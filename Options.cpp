#include "Options.h"
#include "OptionKeys.h"

void Options_Render()
{
    switch(option_mode)
    {
        case GAME_OPTIONS:
        {
	        char setround[255];

	        engine->paintbg(0x00,0x00,0x00);
	        engine->Texts->show_text(0,optiontitle_code,optiontitle_text,300,50,255,0,0);

	        sprintf(setround, "%i",max_round);

	        engine->Texts->searchtable(optionround_code,0)->set_text("Total Rounds:");
	        engine->Texts->searchtable(optionround_code,0)->printf("",340,150,255,255,255);
	
	        engine->Texts->searchtable(optionround_code,0)->set_text(setround,180,180,180);
	        engine->Texts->searchtable(optionround_code,0)->printf("",470,150,255,255,255);

	        engine->Texts->searchtable(optionexit_code,0)->set_text("Key Options",255,255,255);
	        engine->Texts->searchtable(optionexit_code,0)->printf("",340,190,0,0,0);

	        engine->Texts->searchtable(optionexit_code,0)->set_text("Sound:",255,255,255);
	        engine->Texts->searchtable(optionexit_code,0)->printf("",340,230,0,0,0);
		
		if (sound)
		{
			engine->Texts->searchtable(optionround_code,0)->set_text("on",180,180,180);
		} else {
			engine->Texts->searchtable(optionround_code,0)->set_text("off",180,180,180);
			
		}
	        engine->Texts->searchtable(optionround_code,0)->printf("",470,230,255,255,255);



	        engine->Texts->searchtable(optionexit_code,0)->set_text("Music:",255,255,255);
	        engine->Texts->searchtable(optionexit_code,0)->printf("",340,270,0,0,0);

		if (music)
		{
			engine->Texts->searchtable(optionround_code,0)->set_text("on",180,180,180);
		} else {
			engine->Texts->searchtable(optionround_code,0)->set_text("off",180,180,180);
			
		}
	        engine->Texts->searchtable(optionround_code,0)->printf("",470,270,255,255,255);



            //	engine->Texts->show_text(0,optionexit_code,optionext,340,190);

	        engine->Texts->searchtable(optionexit_code,0)->set_text("Exit",0,255,255);
	        engine->Texts->searchtable(optionexit_code,0)->printf("",340,310,0,0,0);
	
	        engine->Texts->searchtable(ocurz_code,0)->set_text("O",0,255,0);
	        engine->Texts->searchtable(ocurz_code,0)->printf("",315,OP_CUR);
	        break;
	     }
	     case KEYOPTIONS:
	     {
	        Option_Keys_Render();
	        break;
	     }
	  
    }
   
}

void Options_Logic()
{
    switch(option_mode)
    {
        case GAME_OPTIONS:
        {
	        if (is_down_key_pressed())
	        {
		        if (OP_CUR !=  MAX_OP_Y)
		        {
			        OP_CUR+=40;
		        }
		        reset_down_key();
	        }

	        if (is_up_key_pressed())
	        {
		        if (OP_CUR != MIN_OP_Y)
		        {
			        OP_CUR-=40;
		        }
		        reset_up_key();
	        }

	        if (is_enter_key_pressed())
	        {
		        switch(OP_CUR)
		        {
			        case 150:
			        {
				        switch(max_round)
				        {
					        case 1:
					        {
						        //Two rounds
						        max_round = 3;
						        rounds2win=2;
						        break;
					        }
					        case 3:
					        {
						        //Five rounds
						        max_round = 5;
						        rounds2win=3;
						        break;
					
					        }
					        case 5:
					        {
					        	//One round
					        	max_round = 1;
					        	rounds2win=1;
					    	    break;
					        }
				        }
				         break;
			     }
			    case 190:
			    {
                    option_mode = KEYOPTIONS;
				    break;
			    }
			    case 230:
			    {
				//sound
				if (sound)
				{
					sound = false;
				} else {
					sound = true;
				}
				break;
			    }
			    case 270:
			    {
				//music
				if (music)
				{
					music = false;
				} else {
					music = true;
				}
				break;
			    }

			    case 310:
			    {
				    main_menu_mode = SELECT_MODE;
				    OP_CUR=150;
				    break;
			    }
		    }
		    reset_enter_key();
	    }	
	  }
	  case KEYOPTIONS:
	  {
	     break;
	  }
   }
}
