#include "Title_Screen.h"


void TitleScreen_Logic()
{
	switch (title_mode)
	{
		case TS_ANIMATION:
		{
			for (int k=0;k<col+1;k++)
			{
				if (titlescreen[k][0] == -1)
				{
					/*
					* Fills the top piece
					*/
					titlescreen[k][0] =rand() % 6;
					for (int i=0;i<TITLE_SCREENSIZE_HEIGHT-1;i++)
					{
						/*find the next empty spot */
						if (titlescreen[k][i] == -1)
						{
							for (int j=i;j > 0; j--)
							{
								titlescreen[k][j] = titlescreen[k][j-1];
								titlescreen[k][j-1] = -1;
							}
							break;
						}
					}
				}
			} 
			if (titlescreen[col][1] != -1)
			{
				if (col == TITLE_SCREENSIZE_WIDTH-1) 
				{
								
				} else {
					col++;
				}
			} 

			if (titlescreen[TITLE_SCREENSIZE_WIDTH-3][TITLE_SCREENSIZE_HEIGHT-2] != -1)
			{
				title_mode = TS_IDLE;
			}
			break;
		}
		case TS_IDLE:
		{
			if (secert) 
			{
				scott->Idle_Animate(200,400);
			} else {

				if (engine->Keys->up.is_key_pressed == true)
				{
					if (keycodecount == 0 || keycodecount == 1)
					{
						keycode[keycodecount] = 1;
						keycodecount++;
					} else {
						resetcode();
					}
					engine->Keys->up.is_key_pressed = false;	
				}
				if (engine->Keys->down.is_key_pressed == true)
				{
					if (keycodecount == 2 || keycodecount == 3)
					{
						keycode[keycodecount] = 1;
						keycodecount++;
					} else {
						resetcode();
					}
					engine->Keys->down.is_key_pressed = false;	
				}
				if (engine->Keys->left.is_key_pressed == true)
				{
					if (keycodecount == 4 || keycodecount == 6)
					{
						keycode[keycodecount] = 1;
						keycodecount++;
					} else {
						resetcode();
					}

					engine->Keys->left.is_key_pressed = false;
				}

				if (engine->Keys->right.is_key_pressed == true)
				{
					if (keycodecount == 5 || keycodecount == 7)
					{
						keycode[keycodecount] = 1;
						if (keycodecount == 7)
						{
							secert = true;
							resetcode();
						}

						keycodecount++;
					} else {
						resetcode();
					}

					engine->Keys->right.is_key_pressed = false;
				}
				break;
			}
		}
	}
	if (engine->Keys->enter.is_key_pressed == true)
	{
		main_menu_mode = SELECT_MODE;
		engine->Keys->enter.is_key_pressed = false;
	}

}

extern void TitleScreen_Render()
{
	
	engine->paintbg(0x00,0x00,0x00);
	if (!secert)
	{	
		for (int i=0;i<TITLE_SCREENSIZE_WIDTH-2;i++)
		{
			for (int j=0;j<TITLE_SCREENSIZE_HEIGHT-2;j++)
			{
				switch(titlescreen[i][j])
				{
					case 0:
					{
						engine->Images->show(Blue_Breaker_Num,Blue_Breaker_Filename,10+i*32,30+j*32);
						break;
					}
					case 1:
					{
						engine->Images->show(Green_Breaker_Num,Green_Breaker_Filename,10+i*32,30+j*32);
						break;
					}
					case 2:
					{
						engine->Images->show(Yellow_Breaker_Num,Yellow_Breaker_Filename,10+i*32,30+j*32);
						break;
					}
					case 3:
					{
						engine->Images->show(Red_Breaker_Num,Red_Breaker_Filename,10+i*32,30+j*32);
						break;
					}
					case 4:
					{
						engine->Images->show(Yellow_Gem_Num,Yellow_Gem,10+i*32,30+j*32);
						break;
					}

					case 5:
					{
						engine->Images->show(Red_Gem_Num,Red_Gem,10+i*32,30+j*32);
						break;
					}

					case 6:
					{
						engine->Images->show(Blue_Gem_Num,Blue_Gem,10+i*32,30+j*32);
						break;
					}

					case 7:
					{
						engine->Images->show(Green_Gem_Num,Green_Gem,10+i*32,20+j*32);
						break;
					}


				}
			}
		}
	

	//	engine->Texts->show_text(Game_Title_ID,Game_Code_Title,Game_Title,Game_Title_X,Game_Title_Y,0,0,0);

	//	engine->Images->show(0,"puzzlebomber.png", Game_Title_X-120,Game_Title_Y-70);

		engine->Images->show(0,"puzzlebomber.png", Game_Title_X-260,Game_Title_Y-200);

			
		switch (title_mode)
		{
			case TS_IDLE:
			{
				engine->Texts->searchtable(Enter_Code,0)->set_text(Enter_Text,255,130,0);
				engine->Texts->searchtable(Enter_Code,0)->printf("",Enter_X,Enter_Y,0,0,0);
				break;
			}

		}
	} else {
		engine->Texts->searchtable(chaintext,0)->set_text("Congrats, You've Unlocked:");
		engine->Texts->searchtable(chaintext,0)->printf("",300,200,0xFF,0,0);
		scott->Idle_Animate_Render(400,300);	
	}

}

void resetcode()
{
	for (int i=0;i<5;i++)
	{
		keycode[i] = 0;
	}
	keycodecount=0;
}
