

void Loading_Logic()
{
	switch (loading_mode)
	{			
		case LSCR_LOAD:
		{
			if (loading_thread == NULL) loading_thread  = engine->CreateThread( load_game, engine );
			break;
		}
		case LSCR_FADEOUT:
		{
			if (Is_Fadedout(Bomb_Index,Bomb_Filename)) main_menu_mode = TITLE_SCREEN;
		       FadeOutText(Loading_Index,Loading_Name);
			break;
		}
		break;
	}

}

void Loading_Render()
{
	switch (loading_mode)
	{
					
		case LSCR_LOAD:
		{
			break;
		}
		case LSCR_FADEOUT:
		{
			break;
		}
		break;
	}
	engine->Images->get_image(Bomb_Index,Bomb_Filename)->sprites->get_sprite(Bomb_Index,Bomb_Name)->animate(engine->frame,Bomb_Sprite_Number,Bomb_X,Bomb_Y);
	engine->Texts->show_text(Loading_Index,Loading_Name,Loading_Text,Loading_X,Loading_Y,0,0,0);
}

bool Is_Fadedout(int spritenum, char* imagename)
{
	if (engine->Images->get_image(spritenum,imagename)->decrease_alpha() < SDL_ALPHA_TRANSPARENT) return true;
	return false;
	
}

void FadeOutText(int spritenum, char* textname)
{
	engine->Texts->decrease_alpha(spritenum,textname);
}
