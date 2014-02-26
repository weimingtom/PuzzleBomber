#include "Select_Screen.h"

void Select_Screen_Logic()
{
	if (is_down_key_pressed())
	{
		if (smcursor !=  Max_downspace)
		{
			move_cursor_down();
		}
		reset_down_key();
	}

	if (is_up_key_pressed())
	{
		if (smcursor != Max_upspace)
		{
			move_cursor_up();
		}
		reset_up_key();
	}

	if (is_enter_key_pressed())
	{
		if (smcursor == Single_Player_Y)
		{
			is_Single_Player = true;
			main_menu_mode=GAME_SCREEN;
			game_mode=CHARACTER_SELECT;
			if (sound) engine->sound_system->play_music(0,"charsel.mp3",-1);

		//	cpu = new CPU();
		}

		if (smcursor == VS_Player_Y)
		{
			is_Single_Player = false;
			main_menu_mode=GAME_SCREEN;
			game_mode=CHARACTER_SELECT;
			if (music) engine->sound_system->play_music(0,"charsel.mp3",-1);
		}

		if (smcursor == Opt_Y)
		{
			main_menu_mode=OPITION_SCREEN;
		}
		reset_enter_key();
	}
	mainbgx-=2;

	if (mainbgx <= -800)
	{
		mainbgx=0;
	}
}

void Select_Screen_Render()
{
	engine->paintbg(0x00,0x00,0x00);
      	engine->Images->show(0,"titlebg.png",mainbgx,mainbgy);
	engine->Images->show(0,"titlebg.png", mainbgx + 800,mainbgy);

	engine->Texts->show_text(Sel_Mode_ID,Sel_Mode_Code,Sel_Mode_Text,Sel_Mode_X,Sel_Mode_Y,255,0,0);
	engine->Texts->show_text(Single_Player_ID,Single_Player_Code,Single_Player_Name,Single_Player_X,Single_Player_Y,255,255,255);
	engine->Texts->show_text(VS_Player_ID,VS_Player_Code,VS_Player_Name,VS_Player_X,VS_Player_Y,255,255,255);
	engine->Texts->show_text(Opt_ID,Opt_Code,Opt_Name,Opt_X,Opt_Y,255,255,255);
	engine->Texts->show_text(curs_ID,curs_name,curs_Text,curs_X,smcursor,0,255,0);

	engine->Texts->show_text(BT_ID,BT_Name,BT_Text,BT_X,BT_Y,0,255,0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool is_down_key_pressed()
{
	return engine->Keys->down.is_key_pressed;
}

void move_cursor_down()
{
	smcursor+=cursor_space;
}

void move_cursor_up()
{
	smcursor-=cursor_space;
}

void reset_down_key()
{
	engine->Keys->down.is_key_pressed = false;	
}

void reset_up_key()
{
	engine->Keys->up.is_key_pressed = false;
}

void reset_enter_key()
{
	engine->Keys->enter.is_key_pressed = false;
}

bool is_up_key_pressed()
{
	return engine->Keys->up.is_key_pressed;
}

bool is_enter_key_pressed()
{
	return engine->Keys->enter.is_key_pressed;
}
