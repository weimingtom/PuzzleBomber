#include "Gameplay.h"


int Gameplay_Render()
{
	switch(game_play_mode)
	{
		case INIT_ROUND:
		{
			break;
		}

		case INTRO:
		{
			(*Player1->character)->Intro_Animate_Render();
			if (is_Single_Player)
			{
				(*cpu->character)->Intro_Animate_Flip_Render();
			} else {
				(*Player2->character)->Intro_Animate_Flip_Render();
			}
			
			break;
		}
		case ROUND_NUMBER:
		{
			(*Player1->character)->Idle_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
			if (is_Single_Player)
			{
				(*cpu->character)->Idle_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
			} else {
				(*Player2->character)->Idle_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
			}

			sprintf(round_text,"Round %i",current_round); 
			engine->Texts->show_text(round_ID,round_code,round_text,360,100,0,0,0);	
	
			break;
		}
		case READY:
		{
			(*Player1->character)->Idle_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
			if (is_Single_Player)
			{
				(*cpu->character)->Idle_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
			} else {
				(*Player2->character)->Idle_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);				
			}

			engine->Images->show(ready_ID,ready_Filename, 270, 170);
			break;
		}
		case PLAY_GAME:
		{

			switch(Player1->Mood)
			{
				case 0:
				{
					(*Player1->character)->Idle_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
					break;
				}
				case 1:
				{
					(*Player1->character)->Attack_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
					break;
				}
				case 2:
				{
					(*Player1->character)->Hurt_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);				
					break;
				}

			}

			if (is_Single_Player)
			{
				switch (cpu->Mood)
				{
					case 0:
					{
						(*cpu->character)->Idle_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);

						break;
					}
					case 1:
					{
						(*cpu->character)->Attack_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
						break;
					}
				}
			} else {
				switch (Player2->Mood)
				{
					case 0:
					{
						(*Player2->character)->Idle_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);

						break;
					}
					case 1:
					{
						(*Player2->character)->Attack_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
						break;
					}
					case 2:
					{
						(*Player2->character)->Hurt_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
						break;
					}

				}

			}

			/* show next block*/
			switch (getcurrentblock(Player1->nextblocknum)->top.color)
			{
				case 0:
				{
					engine->Images->show(0,Blue_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+15);
					break;
				}
				case 1:
				{

					engine->Images->show(0,Blue_Gem,p1_nbr_x+15,p1_nbr_y+15);
					break;
				}
				case 2:
				{
					engine->Images->show(0,Green_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+15);
					break;
				}
				case 3:
				{
					engine->Images->show(0,Green_Gem,p1_nbr_x+15,p1_nbr_y+15);
					break;
				}
				case 4:
				{
					engine->Images->show(0,Red_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+15);
					break;
				}
				case 5:
				{
					engine->Images->show(0,Red_Gem,p1_nbr_x+15,p1_nbr_y+15);

					break;
				}
				case 6:
				{
					engine->Images->show(0,Yellow_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+15);
					break;
				}
				case 7:
				{
					engine->Images->show(0,Yellow_Gem,p1_nbr_x+15,p1_nbr_y+15);
					break;
				}


			}

			switch (getcurrentblock(Player1->nextblocknum)->bottom.color)
			{
				case 0:
				{
					engine->Images->show(0,Blue_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+50);
					break;
				}
				case 1:
				{

					engine->Images->show(0,Blue_Gem,p1_nbr_x+15,p1_nbr_y+50);
					break;
				}
				case 2:
				{
					engine->Images->show(0,Green_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+50);
					break;
				}
				case 3:
				{
					engine->Images->show(0,Green_Gem,p1_nbr_x+15,p1_nbr_y+50);
					break;
				}
				case 4:
				{
					engine->Images->show(0,Red_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+50);

					break;
				}
				case 5:
				{
					engine->Images->show(0,Red_Gem,p1_nbr_x+15,p1_nbr_y+50);

					break;
				}
				case 6:
				{
					engine->Images->show(0,Yellow_Breaker_Filename,p1_nbr_x+15,p1_nbr_y+50);

					break;
				}
				case 7:
				{
					engine->Images->show(0,Yellow_Gem,p1_nbr_x+15,p1_nbr_y+50);

					break;
				}


			}


			switch (getcurrentblock(Player2->nextblocknum)->top.color)
			{
				case 0:
				{
					engine->Images->show(0,Blue_Breaker_Filename,p2_nbr_x+15,p1_nbr_y+15);
					break;
				}
				case 1:
				{

					engine->Images->show(0,Blue_Gem,p2_nbr_x+15,p2_nbr_y+15);
					break;
				}
				case 2:
				{
					engine->Images->show(0,Green_Breaker_Filename,p2_nbr_x+15,p2_nbr_y+15);
					break;
				}
				case 3:
				{
					engine->Images->show(0,Green_Gem,p2_nbr_x+15,p2_nbr_y+15);
					break;
				}
				case 4:
				{
					engine->Images->show(0,Red_Breaker_Filename,p2_nbr_x+15,p2_nbr_y+15);
					break;
				}
				case 5:
				{
					engine->Images->show(0,Red_Gem,p2_nbr_x+15,p2_nbr_y+15);

					break;
				}
				case 6:
				{
					engine->Images->show(0,Yellow_Breaker_Filename,p2_nbr_x+15,p2_nbr_y+15);
					break;
				}
				case 7:
				{
					engine->Images->show(0,Yellow_Gem,p2_nbr_x+15,p2_nbr_y+15);
					break;
				}


			}

			switch (getcurrentblock(Player2->nextblocknum)->bottom.color)
			{
				case 0:
				{
					engine->Images->show(0,Blue_Breaker_Filename,p2_nbr_x+15,p2_nbr_y+50);
					break;
				}
				case 1:
				{

					engine->Images->show(0,Blue_Gem,p2_nbr_x+15,p2_nbr_y+50);
					break;
				}
				case 2:
				{
					engine->Images->show(0,Green_Breaker_Filename,p2_nbr_x+15,p2_nbr_y+50);
					break;
				}
				case 3:
				{
					engine->Images->show(0,Green_Gem,p2_nbr_x+15,p2_nbr_y+50);
					break;
				}
				case 4:
				{
					engine->Images->show(0,Red_Breaker_Filename,p2_nbr_x+15,p2_nbr_y+50);

					break;
				}
				case 5:
				{
					engine->Images->show(0,Red_Gem,p2_nbr_x+15,p2_nbr_y+50);

					break;
				}
				case 6:
				{
					engine->Images->show(0,Yellow_Breaker_Filename,p2_nbr_x+15,p2_nbr_y+50);

					break;
				}
				case 7:
				{
					engine->Images->show(0,Yellow_Gem,p2_nbr_x+15,p2_nbr_y+50);

					break;
				}


			}

			break;
		}
		case GAMEOVER_QUOTE:
		{
		
			engine->Images->show(0,infobox,500,150);	
			engine->Images->show(0,"quotebox.png",0,0);
			if (Player1->is_winner)
			{
				engine->Texts->show_text(0,winquote,(*Player1->character)->win_quote,30,480,0,0,0);	
				(*Player1->character)->show_win_quote(10,100);
			} else {
				if (is_Single_Player)
				{
					engine->Texts->show_text(0,winquote,(*Player2->character)->win_quote,30,480,0,0,0);	
					(*Player2->character)->show_win_quote(10,100);

				} else {
					engine->Texts->show_text(0,winquote,(*cpu->character)->win_quote,30,480,0,0,0);	
					(*cpu->character)->show_win_quote(10,100);

				}
			}
			engine->Texts->show_text(0,charsel,"Character Select",540,190,0,0,0);	
			engine->Texts->show_text(0,exitgame,"Exit",540,220,0,0,0);
			engine->Texts->show_text(0,curz, "O",520,curs2pos,255,0,0);	
	

			break;
		}
		
	}

	if (game_play_mode != GAMEOVER_QUOTE)
	{

		engine->Texts->show_text(0,nextblockid,"NEXT:",300,50,0,0,0);
      		engine->Texts->show_text(0,nextblockid,"NEXT:",430,50,0,0,0);


		engine->Texts->show_text(0,scoreid,"SCORE:",300,450,0xff,0x00,0);
		engine->Texts->show_text(0,scoreid,"SCORE:",440,450,0xff,0x00,0);	

        	char p1score[255];

		sprintf(p1score,"%i",Player1->score);
        	engine->Texts->show_text(0,p1_score,p1score,300,475,0,0,0);

		sprintf(p1score,"%i",Player2->score);
		engine->Texts->show_text(0,p2_score,p1score,440,475,0,0,0);	
	
		engine->Images->show(0,nextblockracket,p1_nbr_x,p1_nbr_y);

		engine->Images->show(0,nextblockracket,p2_nbr_x,p2_nbr_y);
		engine->Images->show(Jar_ID,Jar_filename, Jar_Player1_X, Jar_Player1_Y);
		engine->Images->show(Jar_ID,Jar_filename, Jar_Player2_X, Jar_Player2_Y);

	}
}

int Gameplay_Logic()
{
	
	switch(game_play_mode)
	{
		case INIT_ROUND:
		{

			
			if (Player1->List == NULL) Player1->List = new xylist();
			if (Player2->List == NULL) Player2->List = new xylist();
			Player1->List->clear();
			Player2->List->clear();
			for (int g=0;g<6;g++)
			{
				for (int h=0;h<12;h++)
				{
					explodemap[g][h] = -1;
				}
			}
			Rounds[current_round].winner=0;
			addblock();
			addblock();
			switch_mode(INTRO);
			break;
		}

		case INTRO:
		{
			(*Player1->character)->Intro_Animate();
			if (is_Single_Player)
			{
				(*cpu->character)->Intro_Animate_Flip();
			} else {
				(*Player2->character)->Intro_Animate_Flip();
			}
			if ((*Player1->character)->Intro_Flip_X < (*Player1->character)->Intro_Flip_Stop_X_Spot && (*Player1->character)->Intro_Flip_Stop_At == X_SPOT)
			{

				if (is_Single_Player)
				{
					if ((*cpu->character)->Intro_Flip_X < (*cpu->character)->Intro_Flip_Stop_X_Spot && (*cpu->character)->Intro_Flip_Stop_At == X_SPOT)
					{
						switch_mode(ROUND_NUMBER);
					}
	
				} else {
					if ((*Player2->character)->Intro_Flip_X < (*Player2->character)->Intro_Flip_Stop_X_Spot && (*Player2->character)->Intro_Flip_Stop_At == X_SPOT)
					{
						switch_mode(ROUND_NUMBER);
					}

				}
			}

			break;
		}
		case ROUND_NUMBER:
		{
			(*Player1->character)->Idle_Animate((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
			if (is_Single_Player)
			{
				(*cpu->character)->Idle_Animate_Flip((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
			} else {
				(*Player2->character)->Idle_Animate_Flip((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
			}
		        if (engine->frame % 2)
			{
				round_timer++;
				if (round_timer == 15)
				{
					round_timer = 0;
					game_play_mode = READY;
					break;
				}
			}	
			break;
		}
		case READY:
		{
			(*Player1->character)->Idle_Animate((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
			if (is_Single_Player)
			{
				(*cpu->character)->Idle_Animate_Flip((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
			} else {
				(*Player2->character)->Idle_Animate_Flip((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
			}
			if (engine->frame % 2)
			{
				ready_timer++;
				if (ready_timer == 20)
				{
					/*resets the key incase it was pressed */
					(*Player1->is_right_key_pressed) = false;
					(*Player1->is_left_key_pressed) = false;
					(*Player1->is_Rotate_R_pressed) = false;
					(*Player1->is_Rotate_L_pressed) = false;
					if (is_Single_Player == false)
					{
						(*Player2->is_right_key_pressed) = false;
						(*Player2->is_left_key_pressed) = false;
						(*Player2->is_Rotate_R_pressed) = false;
						(*Player2->is_Rotate_L_pressed) = false;
					}
					game_play_mode = PLAY_GAME;
				}						
			}
				
			break;
		}
		case PLAY_GAME:
		{	
			
			/*Character Animation*/
			switch(Player1->Mood)
			{
				case 0:
				{
					(*Player1->character)->Idle_Animate( (*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
					break;
				}
				case 1:
				{
					if ((*Player1->character)->Attack_Animate( (*Player1->character)->Attack_X,(*Player1->character)->Attack_Y))
					{
						Player1->Mood = 0;
					}
					break;

				}
				case 2:
				{
					if ((*Player1->character)->Hurt_Animate( (*Player1->character)->Intro_X,(*Player1->character)->Intro_Y))
					{
						Player1->Mood = 0;
					}

					break;
				}
        		}

			if (is_Single_Player)
			{
				switch(cpu->Mood)
				{
					case 0:
					{
						(*cpu->character)->Idle_Animate_Flip((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
						break;
					}
					case 1:
					{
						if ((*cpu->character)->Attack_Animate_F( (*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y))
						{
							cpu->Mood = 0;
						}
		
						break;
					}
					case 2:
					{
						if ((*cpu->character)->Hurt_Animate( (*cpu->character)->Intro_X,(*cpu->character)->Intro_Y))
						{
							cpu->Mood = 0;
						}
						break;
					}
				}
			} else {
				switch(Player2->Mood)
				{
					case 0:
					{
						(*Player2->character)->Idle_Animate_Flip((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
						break;
					}
					case 1:
					{
						if ((*Player2->character)->Attack_Animate_F( (*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y))
						{
							Player2->Mood = 0;
						}
		
						break;
					}
					case 2:
					{
						if ((*Player2->character)->Hurt_Animate( (*Player2->character)->Intro_X,(*Player2->character)->Intro_Y))
						{
							Player2->Mood = 0;
						}

						break;
					}
				}

			}
			
			for (int i=0;i<6;i++)
			{
				for (int j=0;j<12;j++)
				{
					if (Player1->explodemap[i][j] != -1)
					{
						exp_animation(i,j, &Player1);
						if (Player1->explodemap[i][j] == 5)
						{
							Player1->explodemap[i][j] = -1;
						} else {
							Player1->explodemap[i][j]++;
						}
					}
					if (Player2->explodemap[i][j] != -1)
					{
						exp_animation(i,j, &Player2);
						if (Player2->explodemap[i][j] == 5)
						{
							Player2->explodemap[i][j] = -1;
						} else {
							Player2->explodemap[i][j]++;
						}
					}

				}
			}

		
			if (deleteblock() == true)
			{
				Player1->nextblocknum--;
				Player2->nextblocknum--;
			} 
			Player1_Gameplay(&Player1);
			Player1_Gameplay(&Player2);
		//	if (Player_Thread== NULL) Player_Thread = SDL_CreateThread( Player1_Gameplay, NULL);
			break;
		}
		case GAMEOVER_QUOTE:
		{
			if (isfinwait == true)
			{
				if (engine->Keys->up.is_key_pressed == true)
				{
					if (curs2pos != 190)
					{
						curs2pos -= 30;
					}
					engine->Keys->up.is_key_pressed = false;
				}

				if (engine->Keys->down.is_key_pressed == true)
				{
					if (curs2pos != 220)
					{
						curs2pos += 30;
					}
					engine->Keys->down.is_key_pressed = false;
				}
				if (engine->Keys->enter.is_key_pressed == true)
				{
					Has_Paused = false;
					Has_Selected = false;
					Player1_selected_big_ID=0;
					Player2_selected_big_ID=0;
					Player1_Has_Selected = false;
					Player2_Has_Selected = false;
					pause_time=0;
					VS_Screen_Pause=0;
					door_L_x=-400;
					door_L_y=0;
					door_R_x=800;
					door_R_y=0;
					waitpause=0;
					isfinwait = false;
					game_play_mode = INIT_ROUND;

					if (curs2pos == 190)
					{
						game_mode = CHARACTER_SELECT;
						
					} else
					if (curs2pos == 220)
					{
						smcursor = 200;
						curs2pos = 190;
						is_Single_Player = false;
						game_mode = CHARACTER_SELECT;
						main_menu_mode = SELECT_MODE;
					}
				}
				engine->Keys->enter.is_key_pressed = false;
			}

			if (isfinwait == false) waitpause++;

			if (waitpause > 10) 
			{
				if (isfinwait == false)
				{
					isfinwait = true;
				}
			}


			break;
		}	
	}
	


}

int switch_mode(int mode)
{
	game_play_mode = mode;
}


int Player1_Gameplay(Player** player)
{
	
//	while (1)
//	{
	//	engine->start_timer();
	//	engine->clear_buffer();

	/*====================== Player render ====================================*/

	if ((*player)->top_block != -1 && (*player)->bottom_block != -1)
	{
/*

		engine->Images->show((*player)->top_block_ID,(*player)->top_block_name,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*(*player)->top_block_x),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*(*player)->top_block_y));

		engine->Images->show((*player)->bottom_block_ID,(*player)->bottom_block_name,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*(*player)->bottom_block_x),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*(*player)->bottom_block_y));
*/

		
		engine->Images->show(0,(*player)->top_block_name,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*(*player)->top_block_x),(*player)->FIELD_POSITION_Y+(/*BLOCK_SIZE-*/(*player)->tph_y));

		engine->Images->show(0,(*player)->bottom_block_name,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*(*player)->bottom_block_x),(*player)->FIELD_POSITION_Y+(/*BLOCK_SIZE+*/(*player)->bph_y));

	}
	/*Draw Field*/
	for (int i=0;i<FIELD_WIDTH;i++)
	{
		for (int j=0;j<FIELD_HEIGHT;j++)
		{
			switch ((*player)->field[i][j].color)
			{
				case 0:
				{
					engine->Images->show(Blue_Breaker_Num,Blue_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 1:
				{
					engine->Images->show(Blue_Gem_Num,Blue_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 2:
				{
					engine->Images->show(Green_Breaker_Num,Green_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 3:
				{
					engine->Images->show(Green_Gem_Num,Green_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 4:
				{
					engine->Images->show(Red_Breaker_Num,Red_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 5:
				{
					engine->Images->show(Red_Gem_Num,Red_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 6:
				{
					engine->Images->show(Yellow_Breaker_Num,Yellow_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 7:
				{
					engine->Images->show(Yellow_Gem_Num,Yellow_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}


			}
		}
	}

	switch ((*player)->logic)
	{
		case SET_RND_BLOCK:
		{
			break;
		}
		case GEM_DROP:
		{
			break;
		}
		case GEM_HIT:
		{
			break;
		}
		case GEM_BREAK_CHK:
		{
			break;
		}
		case DROP_GEM:
		{
			break;
		}
		case GEM_PAUSE:
		{
			break;
		}
		case GEM_DROP_PAUSE:
		{
			break;
		}
		case GEM_SEND:
		{
			break;
		}
		case GAMEOVER_CHECK:
		{
			break;
		}
		case ROUND_END:
		{
			if (*player == Player1)
			{
				if (Rounds[current_round].winner == 1)
				{
					engine->Texts->show_text(0,youwin,"Win!",90,250,0,0,0);
				} else {
					engine->Texts->show_text(0,youlose,"Lose!",90,250,0,0,0);
				}
			} else {
				if (Rounds[current_round].winner == 2)
				{
					engine->Texts->show_text(0,youwin,"Win!",560,250,0,0,0);
				} else {
					engine->Texts->show_text(0,youlose,"Lose!",560,250,0,0,0);

				}

			}
		
			engine->Texts->show_text(0,kotext,"KO!",340,250,0,0,0);

			break;
		}
		case ROUND_CLEAR:
		{
			break;
		}
	}


	/*Player's Logic*/

	switch((*player)->logic)
	{
		case SET_RND_BLOCK:
		{
			(*player)->top_block= getcurrentblock((*player)->nextblocknum)->top.color;  //rand() % 7;
			(*player)->bottom_block=getcurrentblock((*player)->nextblocknum)->bottom.color;// rand() % 7;
		
			getcurrentblock((*player)->nextblocknum)->used++;
			
			(*player)->nextblocknum++;
			
			addblock();

			switch((*player)->top_block)
			{
				case 0:
				{
					(*player)->top_block_ID = Blue_Breaker_Num;
					strcpy((*player)->top_block_name,Blue_Breaker_Filename);
					break;
				}
				case 1:
				{
					(*player)->top_block_ID = Blue_Gem_Num;
					strcpy((*player)->top_block_name,Blue_Gem);

					break;
				}
				case 2:
				{
					(*player)->top_block_ID = Green_Breaker_Num;
					strcpy((*player)->top_block_name,Green_Breaker_Filename);

					break;
				}
				case 3:
				{
					(*player)->top_block_ID = Green_Gem_Num;
					strcpy((*player)->top_block_name,Green_Gem);

					break;
				}
				case 4:
				{
					(*player)->top_block_ID = Red_Breaker_Num;
					strcpy((*player)->top_block_name,Red_Breaker_Filename);


					break;
				}
				case 5:
				{
					(*player)->top_block_ID = Red_Gem_Num;
					strcpy((*player)->top_block_name,Red_Gem);

					break;
				}

				case 6:
				{
					(*player)->top_block_ID = Yellow_Breaker_Num;
					strcpy((*player)->top_block_name,Yellow_Breaker_Filename);


					break;
				}
				case 7:
				{
					(*player)->top_block_ID = Yellow_Gem_Num;
					strcpy((*player)->top_block_name,Yellow_Gem);

					break;
				}

			}



			switch((*player)->bottom_block)
			{
				case 0:
				{
					(*player)->bottom_block_ID = Blue_Breaker_Num;
					strcpy((*player)->bottom_block_name,Blue_Breaker_Filename);
					break;
				}
				case 1:
				{
					(*player)->bottom_block_ID = Blue_Gem_Num;
					strcpy((*player)->bottom_block_name,Blue_Gem);

					break;
				}
				case 2:
				{
					(*player)->bottom_block_ID = Green_Breaker_Num;
					strcpy((*player)->bottom_block_name,Green_Breaker_Filename);

					break;
				}
				case 3:
				{
					(*player)->bottom_block_ID = Green_Gem_Num;
					strcpy((*player)->bottom_block_name,Green_Gem);

					break;
				}
				case 4:
				{
					(*player)->bottom_block_ID = Red_Breaker_Num;
					strcpy((*player)->bottom_block_name,Red_Breaker_Filename);


					break;
				}
				case 5:
				{
					(*player)->bottom_block_ID = Red_Gem_Num;
					strcpy((*player)->bottom_block_name,Red_Gem);

					break;
				}

				case 6:
				{
					(*player)->bottom_block_ID = Yellow_Breaker_Num;
					strcpy((*player)->bottom_block_name,Yellow_Breaker_Filename);


					break;
				}
				case 7:
				{
					(*player)->bottom_block_ID = Yellow_Gem_Num;
					strcpy((*player)->bottom_block_name,Yellow_Gem);

					break;
				}
			}

			(*player)->rotate = NORMAL;
			(*player)->top_block_x=2;
			(*player)->top_block_y=-2;
			(*player)->bottom_block_x = (*player)->top_block_x;
			(*player)->bottom_block_y = (*player)->top_block_y+1;
			(*player)->logic = GEM_DROP;
			break;
		}

		case GEM_DROP:
		{
// if (*(*player)->is_esc_key_pressed)
		
	//		if (engine->Keys->one.is_key_pressed)
	//		{
	//			game_mode = CHARACTER_SELECT;
	//			engine->Keys->one.is_key_pressed = false;
	//		}
			if (*(*player)->is_down_key_pressed)
			{
				switch ((*player)->rotate)
				{
					case NORMAL:
					{
						if ((*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color == -1 && (*player)->bottom_block_y != 11)
						{
							(*player)->bottom_block_y++;				
						}	
						break;
					}
					case LEFTSIDE_DOWN:
					{
						if (
						(
						(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color == -1
						&&
						(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color == -1
						)
						&&
						(*player)->bottom_block_y != 11
						)
						{
							(*player)->bottom_block_y++;
						}
						break;
					}
					case UPSIDE_DOWN:
					{
						if ((*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color == -1 && (*player)->top_block_y != 11)
						{
							(*player)->bottom_block_y++;				
						}	
						break;
					}
					case RIGHTSIDE_UP:
					{
						if (
						(
						(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color == -1
						&&
						(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color == -1
						)
						&&
						(*player)->bottom_block_y != 11
						)
						{
							(*player)->bottom_block_y++;
						}

						break;
					}
				}
				(*(*player)->is_down_key_pressed) = false;
			}
			if (*(*player)->is_up_key_pressed)
			{


			
				switch((*player)->rotate)
				{
					case NORMAL:
					{
						if ((*player)->field[(*player)->bottom_block_x][11].color == -1)
						{		
							(*player)->bottom_block_y = 11;
							break;
						}

						for (int i=0;i<FIELD_HEIGHT;i++)
						{
							if ((*player)->field[(*player)->bottom_block_x][i+1].color != -1 && i !=11)
							{
								(*player)->bottom_block_y = i;
								break;
							}

						}
						break;
					}
					case LEFTSIDE_DOWN:
					{
						if ((*player)->field[(*player)->bottom_block_x][11].color == -1 && (*player)->field[(*player)->top_block_x][11].color == -1)
						{
							(*player)->bottom_block_y = 11;
							(*(*player)->is_up_key_pressed) = false;
							break;
						}
						
						for (int i=0;i<FIELD_HEIGHT;i++)
						{
							if ((*player)->field[(*player)->bottom_block_x][i+1].color != -1 )
							{
								(*player)->bottom_block_y = i;
								break;
	
							}
							if ((*player)->field[(*player)->top_block_x][i+1].color != -1 )
							{
								(*player)->bottom_block_y = i;
								break;
	
							}

						}
						(*(*player)->is_up_key_pressed) = false;
						break;
					}
					case UPSIDE_DOWN:
					{
						if ((*player)->field[(*player)->top_block_x][11].color == -1 && (*player)->field[(*player)->top_block_x][11].color == -1)
						{		
							(*player)->bottom_block_y = 10;
						
							break;
						}
						for (int i=0;i<FIELD_HEIGHT;i++)
						{
							if ((*player)->field[(*player)->top_block_x][i+1].color != -1)
							{
								(*player)->bottom_block_y = i-1;
							

								break;
							}

						}
						break;
					}
					case RIGHTSIDE_UP:
					{
						if ((*player)->field[(*player)->bottom_block_x][11].color == -1 && (*player)->field[(*player)->top_block_x][11].color == -1)
						{
							(*player)->bottom_block_y = 11;
							(*(*player)->is_up_key_pressed) = false;
							break;
						}
						for (int i=0;i<FIELD_HEIGHT;i++)
						{
							if ((*player)->field[(*player)->bottom_block_x][i+1].color != -1 )
							{
								(*player)->bottom_block_y = i;
								break;
	
							}
							if ((*player)->field[(*player)->top_block_x][i+1].color != -1 )
							{
								(*player)->bottom_block_y = i;
								break;
							}

						}

						break;
					}

				}
				(*(*player)->is_up_key_pressed) = false;
			}
			if (*(*player)->is_left_key_pressed)
			{
				

				(*player)->can_move_left = true;
				switch ((*player)->rotate)
				{
					case NORMAL:
					{
						
						if ( ((*player)->top_block_x == 2 || (*player)->top_block_x == 3) && ((*player)->top_block_y == -1 || (*player)->top_block_y == -2))
						{
							(*player)->can_move_left=false;
							break;
						}
						if (((*player)->bottom_block_x == 2 || (*player)->bottom_block_x == 3) && (*player)->bottom_block_y == -2)
						{
							(*player)->can_move_left=true;
							break;
						}
						if (
						(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y].color != -1
						||						
						(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y].color != -1
						)
						{
							(*player)->can_move_left = false;
							break;
						}
						if ((*player)->top_block_x == 0) (*player)->can_move_left=false;
						break;
					}
					case LEFTSIDE_DOWN:
					{
						if ((*player)->top_block_x == 2 && (*player)->top_block_y == -2)
						{
							(*player)->can_move_left = false;
							break;
						}
						if (
						(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y].color != -1
						)
						{
							(*player)->can_move_left = false;
							break;
						}
						if ((*player)->top_block_x == 0) (*player)->can_move_left=false;
						break;
					}
					case UPSIDE_DOWN:
					{
						if (
						(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y].color != -1
						||						
						(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y].color != -1
						)
						{
							(*player)->can_move_left = false;
							break;
						}

						if ((*player)->top_block_x == 0) (*player)->can_move_left=false;
						break;
					}
					case RIGHTSIDE_UP:
					{
						if (
						(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y].color != -1
						)
						{
							(*player)->can_move_left = false;
							break;
						}

						if ((*player)->bottom_block_x == 0) (*player)->can_move_left=false;

						break;
					}
				}

				if ((*player)->can_move_left == true) (*player)->bottom_block_x -=1;	
				
				(*(*player)->is_left_key_pressed) = false;
				
			}
			if ((*(*player)->is_right_key_pressed))
			{
				(*player)->can_move_right=true;	
				switch ((*player)->rotate)
				{
					case NORMAL:
					{
						if ((*player)->top_block_x == 3 && ((*player)->top_block_y == -2 || (*player)->top_block_y == -1))
						{
							(*player)->can_move_right=false;
							break;
						}
						if (
							(*player)->top_block_x == 2 && (*player)->top_block_y == -2
							||
							(*player)->top_block_x == 2 && (*player)->top_block_y == -1

						)
						{
							(*player)->can_move_right = false;
							break;
						}
						if (
						(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y].color != -1
						||						
						(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y].color != -1
						)
						{
							(*player)->can_move_right = false;
							break;
						}
						if ((*player)->top_block_x == 5) (*player)->can_move_right=false;
						break;
					}
					case LEFTSIDE_DOWN:
					{
						if (
						(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y].color != -1
						)
						{
							(*player)->can_move_right = false;
							break;
						}

						if ((*player)->bottom_block_x == 5) (*player)->can_move_right=false;

						break;
					}
					case UPSIDE_DOWN:
					{
						if (
						(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y].color != -1
						||						
						(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y].color != -1
						)
						{
							(*player)->can_move_right = false;
							break;
						}

						if ((*player)->top_block_x == 5) (*player)->can_move_right=false;

						break;
					}
					case RIGHTSIDE_UP:
					{
						if (
						(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y].color != -1
						)
						{
							(*player)->can_move_right = false;
							break;
						}

						if ((*player)->top_block_x == 5) (*player)->can_move_right=false;

						break;
					}
				}

				if ((*player)->can_move_right) (*player)->bottom_block_x +=1;
				
				(*(*player)->is_right_key_pressed) = false;
			}

			if ( (*(*player)->is_Rotate_R_pressed))
			{
				(*player)->can_rot_right = true;
				switch ((*player)->rotate)
				{
					case NORMAL:
					{	
						if (
						(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y].color != -1
						||
						(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y].color != -1
						)
						{
							(*player)->can_rot_right = false;
							break;
						}
						if ((*player)->bottom_block_x == 5)
						{
							(*player)->can_rot_right = false;
							break;
						}
					
						break;
					}
					case LEFTSIDE_DOWN:
					{

						if (
						(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color != -1
						&&
						(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color != -1
						)
						{
							(*player)->can_rot_right = false;
							break;
						}
						break;
					}
					case UPSIDE_DOWN:
					{
						if ((*player)->bottom_block_x == 0)
						{
							(*player)->can_rot_right = false;
							break;
						}
						if (
						(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y].color != -1
						||
						(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y].color != -1
						)
						{
							(*player)->can_rot_right = false;
							break;
						}
						break;
					}
					case RIGHTSIDE_UP:
					{
						if ((*player)->bottom_block_y == 11)
						{
							(*player)->can_rot_right = false;
							break;
						}

						if (
						(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color != -1
						||
						(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color != -1
						)
						{
							(*player)->can_rot_right = false;
							break;
						}
						break;
					}
				
				}

				if ((*player)->rotate == NORMAL) 	
				{
					if ((*player)->can_rot_right) (*player)->rotate = RIGHTSIDE_UP;
				} else {
					if ((*player)->can_rot_right) (*player)->rotate--;
				}

				((*(*player)->is_Rotate_R_pressed)) = false;
			}

			if (*(*player)->is_Rotate_L_pressed)
			{
				(*player)->can_rot_left=true;
				switch ((*player)->rotate)
				{
					case NORMAL:
					{
						if ((*player)->top_block_x == 2 && (*player)->top_block_y == -2)
						{
							(*player)->can_rot_left = false;
							break;
						}
						if ((*player)->top_block_x == 3 && (*player)->top_block_y == -2)
						{
							(*player)->can_rot_left =true;
							break;
						}
						if (
						(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y].color != -1
						
						||
						(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y].color != -1
						)
						{
							(*player)->can_rot_left = false;
							break;
						} 
						if ((*player)->top_block_x==0) (*player)->can_rot_left = false;
						break;
					}
					case LEFTSIDE_DOWN:
					{
						if (
						(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color != -1
						||
						(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color != -1

						)
						{
							(*player)->can_rot_left=false;
							break;
						}
						if ((*player)->bottom_block_y == 11) (*player)->can_rot_left = false;
						break;
					}
					case UPSIDE_DOWN:
					{
						if ((*player)->field[(*player)->top_block_x+1][(*player)->top_block_y].color != -1)
						{
							(*player)->can_rot_left=false;
							break;
						}


						if ((*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y].color != -1)
						{
							(*player)->can_rot_left=false;
							break;
						}

						if ((*player)->top_block_x == 5) (*player)->can_rot_left = false;
						break;
					}
					case RIGHTSIDE_UP:
					{
						if (
						(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y-1].color != -1
						||
						(*player)->field[(*player)->top_block_x][(*player)->top_block_y-1].color != -1
						
						)
						{
							(*player)->can_rot_left=false;
							break;
						}

						break;
					}
				}
				if ((*player)->rotate == RIGHTSIDE_UP) 	
				{
					if ((*player)->can_rot_left) (*player)->rotate = NORMAL;
				} else {
					if ((*player)->can_rot_left) (*player)->rotate++;
				}
				(*(*player)->is_Rotate_L_pressed) = false;
			}
			if (engine->frame % 2)
			{
				if ((*player)->block_speed == MAX_BLOCK_SPEED)
				{

					switch ((*player)->rotate)
					{
						case NORMAL:
						{
							if ((*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color != -1)
							{
								(*player)->logic = GEM_HIT;
								break;
							}
							if ((*player)->bottom_block_y == 11)
							{
								(*player)->logic = GEM_HIT;
								break;
							}
							if ((*player)->bp_count == 32)
							{
								printf("y=%i,bph=%i\n",(*player)->bottom_block_y,(*player)->bph_y);
								(*player)->bottom_block_y++;
								(*player)->bp_count = 0;
							} 
							(*player)->bph_y+=8;
							(*player)->tph_y=(*player)->bph_y-32;
							(*player)->bp_count+=8;
							(*player)->top_block_x = (*player)->bottom_block_x;
							(*player)->top_block_y = (*player)->bottom_block_y-1;

							break;
						}
						case LEFTSIDE_DOWN:
						{
							if (
							(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color != -1
							||
							(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color != -1

							)
							{
								(*player)->logic=GEM_HIT;
								break;
							}
							if ((*player)->bottom_block_y == 11)
							{
								(*player)->logic = GEM_HIT;
								break;
							}
							if ((*player)->bp_count == 32)
							{
								printf("y=%i,bph=%i\n",(*player)->bottom_block_y,(*player)->bph_y);
								(*player)->bottom_block_y++;
								(*player)->bp_count = 0;
							} 
							(*player)->bph_y+=8;
							(*player)->tph_y=(*player)->bph_y;
							(*player)->bp_count+=8;
							(*player)->top_block_x=(*player)->bottom_block_x-1;
							(*player)->top_block_y=(*player)->bottom_block_y;

							break;
						}
						case UPSIDE_DOWN:
						{


							if ((*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color != -1)
							{
								(*player)->logic = GEM_HIT;
								break;
							}
							if ((*player)->top_block_y == 11)
							{
								(*player)->logic = GEM_HIT;
								break;
							}
							if ((*player)->bp_count == 32)
							{
								printf("y=%i,bph=%i\n",(*player)->bottom_block_y,(*player)->bph_y);
								(*player)->bottom_block_y++;
								(*player)->bp_count = 0;
							} 
							(*player)->bph_y+=8;
							(*player)->tph_y=(*player)->bph_y+32;
							(*player)->bp_count+=8;
							(*player)->top_block_x=(*player)->bottom_block_x;
							(*player)->top_block_y=(*player)->bottom_block_y+1;

							break;
						}
						case RIGHTSIDE_UP:
						{
							if (
							(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].color != -1
							||
							(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].color != -1

							)
							{
								(*player)->logic = GEM_HIT;
								break;
							}

							if ((*player)->bottom_block_y == 11)
							{
								(*player)->logic = GEM_HIT;
								break;
							}
							if ((*player)->bp_count == 32)
							{
								printf("y=%i,bph=%i\n",(*player)->bottom_block_y,(*player)->bph_y);
								(*player)->bottom_block_y++;
								(*player)->bp_count = 0;
							} 
							(*player)->bph_y+=8;
							(*player)->tph_y=(*player)->bph_y;
							(*player)->bp_count+=8;
							(*player)->top_block_x=(*player)->bottom_block_x+1;
							(*player)->top_block_y=(*player)->bottom_block_y;

							break;
						}
					}

					(*player)->block_speed=0;
				}
				(*player)->block_speed++;
			}		
			break;
		}

		case GEM_HIT:
		{
			if ((*player)->top_block_y > -1)
			{
				(*player)->field[(*player)->top_block_x][(*player)->top_block_y].color = (*player)->top_block;
			}
			if ((*player)->bottom_block_y > -1)
			{
				(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y].color = (*player)->bottom_block;
			}
			(*player)->top_block = -1;
			(*player)->top_block = -1;
			(*player)->bph_y=-40;
			(*player)->tph_y=(*player)->bph_y - 32;
			(*player)->logic = DROP_GEM;
			break;
		}
		case GEM_BREAK_CHK:
		{
			(*player)->did_brake=false;

			(*player)->gem_broke = 0;

			for (int i=0;i<FIELD_WIDTH;i++)
			{
				for (int j=0;j<FIELD_HEIGHT;j++)
				{
					/* checks for gem breaker -- Every gem breaker is an even number */
					if (
					(*player)->field[i][j].color != -1
					&&
					(*player)->field[i][j].color % 2 == 0
					)
					{
						if ((*player)->List->find(i,j) == false)
						{
							int currentcolor = (*player)->field[i][j].color;
							/*right*/
							if (i+1 != 6) gembreaker(i+1,j,currentcolor, &(*player) );
							/*left*/
							if (i-1 != -1) gembreaker(i-1,j,currentcolor, &(*player));
							/*up*/
							if (j-1 != -1) gembreaker(i,j-1,currentcolor, &(*player) );
							/*down*/
							if (j+1 != 12) gembreaker(i,j+1,currentcolor, &(*player) );
														
						}
						if ((*player)->did_brake == true) break;
						
					}
				}
				if ((*player)->did_brake == true) break;
			}
			if (*player == Player1)
			{
				if ((*player)->gem_broke != 0)
				{
					Player2->pending_blocks += Player1->gem_broke;
					printf("Player2 pending blocks: %i\n",Player2->pending_blocks);
					
				}
			}
			if (*player == Player2)
			{
				if ((*player)->gem_broke != 0)
				{
					Player1->pending_blocks += Player2->gem_broke;
					printf("Player1 pending blocks: %i\n",Player1->pending_blocks);
					
				}
			}

			
			(*player)->List->clear();
			if ((*player)->did_brake == true) 
			{
				(*player)->logic = GEM_PAUSE;
			} else {
				if ((*player)->pending_blocks != 0)
				{
					(*player)->logic = GEM_SEND;
				} else {
					(*player)->logic = GAMEOVER_CHECK;
				}
			}
			break;
		}
		
		case DROP_GEM:
		{
			bool doagain=false;
			for (int i=0;i<FIELD_WIDTH;i++)
			{
				for (int j=0;j<FIELD_HEIGHT;j++)
				{
					if ((*player)->field[i][j].color != -1)
					{
						if (j+1 != 12)
						{
							if ((*player)->field[i][j+1].color == -1)
							{
								(*player)->field[i][j+1].color = (*player)->field[i][j].color;
								(*player)->field[i][j].color = -1;

								doagain=true;
							}
						}
					}
				//	if (doagain == true) break;
				
				}
			//	if (doagain == true) break;
			
			}
			if (doagain == true)
			{
				(*player)->logic = GEM_DROP_PAUSE;
			} else {
				(*player)->logic = GEM_BREAK_CHK;
			}
			break;
		}
		case GEM_PAUSE:
		{
			if (engine->frame % 2)
			{

				if ((*player)->gem_pause == 5)
				{
					(*player)->gem_pause = 0;
					(*player)->logic = DROP_GEM;
				} else {
					(*player)->gem_pause++;
				}
			}
			break;
		}
		case GEM_DROP_PAUSE:
		{
			if (engine->frame % 2)
			{
				if ((*player)->drop_gem_pause == 1)
				{
					(*player)->drop_gem_pause = 0;
					(*player)->logic = DROP_GEM;
				} else {
					(*player)->drop_gem_pause++;
				}
			}
			break;
		}
		case GEM_SEND:
		{
			if ((*player)->pending_blocks !=0)
			{
			//	if (is_Single_Player)
			//	}
				for (int i=0;i<(*player)->pending_blocks;i++)
				{
					int col1 = rand() % 6;
					int col2 = rand() % 4;

					int rcg = 1;//(*Player1->character)->counter_gems[col1][col2];

					int k=0; 
					bool foundaspot=false;

					for (int k=0;k< FIELD_HEIGHT;k++)
					{
						for (int j=0;j < FIELD_WIDTH;j++)
						{
							if ((*player)->field[j][k].color == -1)
							{
								(*player)->field[j][k].color = rcg;
								foundaspot = true;
								break;
							}	
						}
						if (foundaspot == true) break;
					}
				}
				if (is_Single_Player == false)
				{
					if (*player == Player2)
					{
						Player1->Mood = 1;
						Player2->Mood = 2;

					} else
					if (*player == Player1)
					{
						Player2->Mood = 1;
						Player1->Mood = 2;
					}
				}

			}
			//	{

			(*player)->pending_blocks = 0;
			(*player)->logic =DROP_GEM;

			break;
		}
		case GAMEOVER_CHECK:
		{
			if ((*player)->field[2][0].color != -1)
			{
				if (*player == Player2)
				{
					Player1->logic = ROUND_END;
					Rounds[current_round].winner = 1;
				} else {
					Player2->logic = ROUND_END;
					Rounds[current_round].winner = 2;
				}
				
				(*player)->logic = ROUND_END;
			} else {
				(*player)->logic = SET_RND_BLOCK;
			}
			break;
		}
		case ROUND_END:
		{
			round_finish_timer++;

			if (round_finish_timer > 300)
			{
				
				engine->Keys->up.is_key_pressed = false;
				engine->Keys->down.is_key_pressed = false;
				engine->Keys->enter.is_key_pressed = false;
				round_finish_timer = 0;
				Player1->logic = ROUND_CLEAR;
				Player2->logic = ROUND_CLEAR;
			}
			break;
		}
		case ROUND_CLEAR:
		{
			if (*player == Player1)
			{
				
				nblock *dnb=headnextblock;
				while (headnextblock->next != NULL)
				{
					nblock *tmp=headnextblock;
					headnextblock = headnextblock->next; 
					if (tmp != NULL)
					{
						delete tmp;
						tmp=NULL;
					}
				}
			
				for (int i=0;i<FIELD_WIDTH;i++)
				{
					for (int j=0;j<FIELD_HEIGHT;j++)
					{
						Player1->field[i][j].color = -1;
						Player2->field[i][j].color = -1;
					}
				}
				Player1->nextblocknum=0;
				Player2->nextblocknum=0;
				Player1->pending_blocks = 0;
				Player2->pending_blocks = 0;
				ready_timer=0;
				round_timer=0;

				Player1->logic = SET_RND_BLOCK;
				Player2->logic = SET_RND_BLOCK;


				if (current_round==max_round)
				{
					int p1_total_wins = 0;
					int p2_total_wins = 0;

					for (int i=0;i<max_round;i++)
					{
						if (Rounds[i].winner == 1)
						{
							p1_total_wins++;
						} else {
							p2_total_wins++;
						}
					}

					if (p1_total_wins > p2_total_wins)
					{
						Player1->is_winner = true;
						Player2->is_winner = false;
					} else {
						Player1->is_winner = true;
						Player2->is_winner = false;

					}
					game_play_mode=GAMEOVER_QUOTE;
				} else {
					game_play_mode = ROUND_NUMBER; 
				}
			}
			break;
		}

	}
	
//	engine->doublebuffer();
	//engine->frame_rate_start();
// }
}



int gembreaker(int x,int y, int color, Player **player)
{
	/*check left is a gem of the same color*/
	if ((*player)->field[x][y].color != -1)
	{ 
		if (
		(*player)->field[x][y].color ==  color
		||
		(*player)->field[x][y].color ==  color + 1
		)
		{					
			if ((*player)->List->find(x,y) == false)
			{
				(*player)->did_brake = true;
				(*player)->List->add(x,y);
				(*player)->field[x][y].color = -1;
				(*player)->explodemap[x][y] = 0;
				(*player)->gem_broke++;
				/*right*/
				if (x+1 != 6) gembreaker(x+1,y,color, &(*player) );
				/*left*/
				if (x-1 != -1) gembreaker(x-1,y,color, &(*player) );
				/*up*/
				if (y-1 != -1) gembreaker(x,y-1,color, &(*player));
				/*down*/
				if (y+1 != 12)gembreaker(x,y+1,color, &(*player));
			}
		}
	}
}

/* Next block functions */

bool deleteblock()
{
	if (headnextblock->used == 2) 
	{
		nblock *dnb=headnextblock;
		if (headnextblock->next == NULL)
		{
			headnextblock=NULL;
		} else {
			headnextblock = NULL;
			headnextblock = dnb->next;
		}
		
		delete dnb;
		dnb=NULL;
	//	printf("deleted\n");
		return true;
	}
	return false;
}


/* Round class */ 

void addblock()
{
	if (nextblock == NULL)
	{
		nextblock = new nblock();
		nextblock->top.color = rand() % 7;
		nextblock->bottom.color = rand() % 7;
		nextblock->used=0;
		headnextblock = nextblock;
		nextblock->next = NULL;
		//printf("added\n");
	
	} else 
	if (nextblock->next == NULL)
	{
		nblock *newblock = new nblock;
	
		newblock->top.color = rand() % 7;
		newblock->bottom.color = rand() % 7;
		newblock->used=0;
		newblock->next = NULL;
		nextblock->next = newblock;
		nextblock = nextblock->next;
		//printf("attached\n");
	}
}

nblock* getcurrentblock(int number)
{
	nblock *find=headnextblock;
	for (int i=0;i<number;i++)
	{
		find = find->next;
	}
	return find;
}

int round::clear_fields()
{
}




round::round()
{
	is_roundover=false;
	number=0;
	clear_fields();
}
