#include "vs_screen.h"

int VS_Screen_Render()
{
	engine->Images->show(door_filename_ID,door_filename, door_L_x, door_L_y);
	engine->Images->show(door_filename_ID,door_filename, door_R_x, door_R_y);

	(*Player1->character)->Show_Big_Personal(230,200);
//	engine->Texts->show_text(player1_selected_ID,player1_selected_code,(*Player1->character)->name,230,350,0,0,0);

	(*Player1->character)->showname(230,350);
	

	if (is_Single_Player == false)
	{
		(*Player2->character)->Show_Big_Personal_Flip(430,200);
		(*Player2->character)->showname(530,350);
	//	engine->Texts->show_text(player2_selected_ID,player2_selected_code,(*Player2->character)->name,530,350,0,0,0);
		
	} else {
		(*cpu->character)->Show_Big_Personal_Flip(430,200);
		(*cpu->character)->showname(530,350);
	//	engine->Texts->show_text(player2_selected_ID,player2_selected_code,(*cpu->character)->name,530,350,0,0,0);
		
	}
	engine->Images->show(18,"VS.png",340,240);
	//engine->Images->get_image(18,"VS.png")->set_alpha(SDL_ALPHA_TRANSPARENT);		
	
	
	//engine->Texts->show_text(VS_ID,VS_Code,VS_Text,300,200,0,0,0);

}

int VS_Screen_Logic()
{
	if (engine->frame % 2)
	{
		VS_Screen_Pause++;
		if (VS_Screen_Pause == 50)
		{
			VS_Screen_Pause=0;
			game_mode = GAME_PLAY;
		}
	}

}
