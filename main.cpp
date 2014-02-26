#include <time.h>
#include "./SGE/Engine.h"
#include "Character.h"
#include "Player.h"
#include "main.h"
#include "setup.h"
#include "Texture.h"
#include "Load_Game.h"
#include "Loading_Screen.h"
#include "Title_Screen.h"
#include "Select_Screen.h"
#include "Character_Select.h"
#include "vs_screen.h"
#include "cpu_select.h"
#include "Gameplay.h"
#include "Options.h"
#include "Credits.h"


 int main(int argc, char *argv[])
{

	init_engine();
 
	
	while (quit == false)
	{
		engine->start_timer();
		engine->clear_buffer();

		if (engine->KeysHandler() == true) quit = true;

		/*
			Game Logic
		*/ 
		switch(main_menu_mode)
		{
			
			case LOADING_SCREEN:
			{
				Loading_Logic();
				break;
			}
			case TITLE_SCREEN:
			{
				TitleScreen_Logic(); 
				break;
			}
			case SELECT_MODE:
			{
				Select_Screen_Logic();
				break;
			}
			case OPITION_SCREEN:
			{
				Options_Logic();
				break;
			}
			case GAME_SCREEN:
			{
				switch(game_mode)
				{
					case CHARACTER_SELECT:
					{
						Character_Select_Logic();
						break;
					}
					case VS_SCREEN:
					{
						VS_Screen_Logic();
						break;
					}
					case GAME_PLAY:
					{
						Gameplay_Logic();
						break;
					}
					case CREDITS:
					{
						Credits_Logic();
						break;
					}

				}
				break;
			}
		}

		
		/*
		Render here
		*/

		switch(main_menu_mode)
		{
			case LOADING_SCREEN:
			{
				Loading_Render();	
				break;
			}
			case TITLE_SCREEN:
			{
				TitleScreen_Render();
				break;
			}

			case SELECT_MODE:
			{
				Select_Screen_Render();
				break;
			}
			case OPITION_SCREEN:
			{
				Options_Render();				
				break;
			}
			case GAME_SCREEN:
			{
				switch(game_mode)
				{
					case CHARACTER_SELECT:
					{
						Character_Select_Render();
						break;
					}
					case VS_SCREEN:
					{
						VS_Screen_Render();
						break;
					}
					case GAME_PLAY: 
					{
						Gameplay_Render();
						break;
					}
					case CREDITS:
					{
						Credits_Render();
						break;
					}
				}

				break;
			}

		}
		engine->doublebuffer();
		engine->frame_rate_start();
	}
	clean_up();
	return 0;
}





