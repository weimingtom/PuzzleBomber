#include "Credits.h"

void Credits_Logic()
{
	ctimer++;
	if (ctimer == 100)
	{
		ctimer=0;
		switch(creditstate)
		{
			case PROG:
			{
				creditstate=SPRTART;
				break;
			}
			case SPRTART:
			{
				creditstate=BKGRD;
				break;
			}
			case BKGRD:
			{
				creditstate=SPTHX;
				break;
			}
			case SPTHX:
			{
				creditstate=DTHX;
				break;
			}
			case DTHX:
			{
				game_mode = CHARACTER_SELECT;
				main_menu_mode = SELECT_MODE;
				Credits_Reset();
				break;
			}
			
		}
		
	}


	switch(creditstate)
	{
		case PROG:
		{
			
			break;
		}
		case SPRTART:
		{
			break;
		}
		case BKGRD:
		{
			break;
		}
		case SPTHX:
		{
			break;
		}
		case DTHX:
		{
			break;
		}
			
	}

}

void Credits_Render()
{
	switch(creditstate)
	{
		case PROG:
		{
		
			engine->Texts->searchtable("credittext",0)->set_text("Programmer",0xFF,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,200,0,0,0);
			engine->Texts->searchtable("credittext",0)->set_text("Nattee Setobol",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,240,0,0,0);

			break;
		}
		case SPRTART:
		{
			engine->Texts->searchtable("credittext",0)->set_text("Sprite Artist/Rippers",0xFF,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,200,0,0,0);
			engine->Texts->searchtable("credittext",0)->set_text("Bart/Simpsons Arcade ripped by Random Talking Bush",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,240,0,0,0);


			engine->Texts->searchtable("credittext",0)->set_text("Kitteh / MappleStory ripped by rasudoken",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,280,0,0,0);
			
			engine->Texts->searchtable("credittext",0)->set_text("Prinny ripped by Random Talking Bush",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,320,0,0,0);


			break;
		}
		case BKGRD:
		{
			engine->Texts->searchtable("credittext",0)->set_text("Background Art",0xFF,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,200,0,0,0);

			engine->Texts->searchtable("credittext",0)->set_text("Backalley by Robert D Brown ",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,240,0,0,0);

			engine->Texts->searchtable("credittext",0)->set_text("Simpsons by Matt Groening ",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,280,0,0,0);
			
			engine->Texts->searchtable("credittext",0)->set_text("Prinny / Disagea Playstation network",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,320,0,0,0);

			break;
		}
		case SPTHX:
		{
			engine->Texts->searchtable("credittext",0)->set_text("Special Thanks to.... ",0xFF,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,200,0,0,0);
			engine->Texts->searchtable("credittext",0)->set_text("Josh M, Francis C for contributing ",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,240,0,0,0);
			engine->Texts->searchtable("credittext",0)->set_text("And all my friends!! ",0,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,280,0,0,0);


			break;
		}
		case DTHX:
		{
			engine->Texts->searchtable("credittext",0)->set_text("Thanks for Playing the Demo!!! ",0xFF,0,0);
			engine->Texts->searchtable("credittext",0)->printf("",300,200,0,0,0);
			kitteh->Win1_Animate(300,240);
			bart->Win1_Animate(350,240);
			prinny->Win1_Animate(400,240);
			break;
		}
	}
}

void Credits_Reset()
{
	creditstate = PROG;
	ctimer=0;
}
