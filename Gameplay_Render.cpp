#include "Gameplay.h"

int Gameplay_Render()
{
/*
	engine->Images->show(0,tempred,0,0);
	engine->Images->show(0,tempred,200,0);
	engine->Images->show(0,tempred,400,0);
	engine->Images->show(0,tempred,600,0);
        engine->Images->show(0,tempbackground,0,180);
	engine->Images->show(0,tempred,0,380);
	engine->Images->show(0,tempred,200,380);
	engine->Images->show(0,tempred,400,380);
	engine->Images->show(0,tempred,600,380);
*/
	/*Draw Stage Based on Player1*/
	
       for (int i=0, j=0; i < 4;i++,j+=200)
       {
		if (is_Single_Player)
		{
			(*cpu->character)->myStage->DrawBGPattern(j,0);
		} else {
       			(*Player1->character)->myStage->DrawBGPattern(j,0);
		} 
       }

	if (is_Single_Player)
	{
		(*cpu->character)->myStage->DrawBG(0,180);
	} else {
		(*Player1->character)->myStage->DrawBG(0,180);
	}

       for (int i=0, j=0; i < 4;i++,j+=200)
       {
		if (is_Single_Player)
		{
			(*cpu->character)->myStage->DrawBGPattern(j,380);
		} else {
       			(*Player1->character)->myStage->DrawBGPattern(j,380);
		} 
       }


	switch(game_play_mode)
	{
		case INIT_ROUND:
		{
			break;
		}

		case INTRO:
		{
			if ((*Player1->character)->isintrodone == false)
			{  
				(*Player1->character)->Intro_Animate_Render();
			} else {
				(*Player1->character)->Idle_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);

			}
			if (is_Single_Player)
			{
				if ((*cpu->character)->isintrodone2 == false)
				{
					(*cpu->character)->Intro_Animate_Flip_Render();
				} else {
					(*cpu->character)->Idle_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
				}
			} else {
				if ((*Player2->character)->isintrodone2 == false)
				{
					(*Player2->character)->Intro_Animate_Flip_Render();
				} else {
					(*Player2->character)->Idle_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
				}					
			}
			
			break;
		}
		case ROUND_NUMBER:
		{
			/*
			shows characters idle state
			*/
			(*Player1->character)->Idle_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
			if (is_Single_Player)
			{
				(*cpu->character)->Idle_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
			} else {
				(*Player2->character)->Idle_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
			}
			sprintf(round_text,"Round %i",current_round); 
			engine->Texts->searchtable(round_code,0)->set_text(round_text,0,155,255);
			engine->Texts->searchtable(round_code,0)->printf("",360,220,0,0,0);
			break;
		}
		case READY:
		{
			/*
			show characters idle state
			*/
			(*Player1->character)->Idle_Animate_Render((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
			if (is_Single_Player)
			{
				(*cpu->character)->Idle_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
			} else {
				(*Player2->character)->Idle_Animate_Flip_Render((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
			}
			engine->Images->show(ready_ID,ready_Filename, 270, 230);
			break;
		}
		case PLAY_GAME:
		{

			
			/* draws the current blocks*/
			draw_block(&Player1);
			if (is_Single_Player)
			{
				draw_block((Player**) &cpu);
			} else {
				draw_block(&Player2);
			}

			/*draws the field*/
			draw_field(&Player1);
			if (is_Single_Player)
			{
				draw_field((Player**) &cpu);
			} else {
				draw_field(&Player2);
			}
			for (int i=0;i<6;i++)
			{
				for (int j=0;j<12;j++)
				{
					if (Player1->explodemap[i][j] != EMPTY)
					{
						exp_animation(i,j, &Player1);
						if (Player1->explodemap[i][j] == 5)
						{
							Player1->explodemap[i][j] = EMPTY;
						} else {
							Player1->explodemap[i][j]++;
						}
					}
					if (is_Single_Player)
					{
						if (cpu->explodemap[i][j] != EMPTY)
						{
							exp_animation(i,j,(Player**) &cpu);
							if (cpu->explodemap[i][j] == 5)
							{
								cpu->explodemap[i][j] = EMPTY;
							} else {
								cpu->explodemap[i][j]++;
							}
						}

					} else {
						if (Player2->explodemap[i][j] != EMPTY)
						{
							exp_animation(i,j, &Player2);
							if (Player2->explodemap[i][j] == 5)
							{
								Player2->explodemap[i][j] = EMPTY;
							} else {
								Player2->explodemap[i][j]++;
							}
						}
					}

				}
			}
			/*Show pending blocks if there is any*/
			if (Player1->pending_blocks > 1)
			{
				engine->Texts->searchtable(penblkcde1,0)->printf("",215,110,0,0,0);
			}
			if (is_Single_Player)
			{
				if (cpu->pending_blocks > 1)
				{
					engine->Texts->searchtable(penblkcde2,0)->printf("",655,110,0,0,0);
				}

			} else {
				if (Player2->pending_blocks > 1)
				{
					engine->Texts->searchtable(penblkcde2,0)->printf("",655,110,0,0,0);
				}
			}
			/*show chain text*/
			if (Player1->ischain == true)
			{
				engine->Texts->searchtable(chaintext,0)->printf("",100,500,255,0,0);

			}
			if (is_Single_Player)
			{
				if (cpu->ischain == true)
				{
					engine->Texts->searchtable(chaintext2,0)->printf("",550,500,255,0,0);
				}

			} else {
				if (Player2->ischain == true)
				{
					engine->Texts->searchtable(chaintext2,0)->printf("",550,500,255,0,0);
				}
			}

			/*Player's mood */
			show_mood(&Player1,false,false);

			if (is_Single_Player)
			{
				show_mood((Player**) &cpu,true,true);
			} else {
				show_mood(&Player2,true,false);
			}

			if (Player1->specialp == true)
			{
				(*(*Player1->character)->special_render)((void**) Player1);
			//	Player1->specialp = false;
			} else
			if (is_Single_Player)
			{
				if (cpu->specialp == true)
				{
					(*(*cpu->character)->special_render)((void**) cpu);
				}

			} else {
				if (Player2->specialp == true)
				{
					(*(*Player2->character)->special_render)((void**) Player2);
				}
			}
			/* show next block*/
			show_block(getcurrentblock(Player1->nextblocknum)->top.color, p1_nbr_x+15,p1_nbr_y+15);
			show_block(getcurrentblock(Player1->nextblocknum)->bottom.color,p1_nbr_x+15,p1_nbr_y+50);
			if (is_Single_Player)
			{

				show_block(getcurrentblock(cpu->nextblocknum)->top.color, p2_nbr_x+15, p2_nbr_y+15);
				show_block(getcurrentblock(cpu->nextblocknum)->bottom.color,p2_nbr_x+15,p2_nbr_y+50);

			} else {
				show_block(getcurrentblock(Player2->nextblocknum)->top.color, p2_nbr_x+15, p2_nbr_y+15);
				show_block(getcurrentblock(Player2->nextblocknum)->bottom.color,p2_nbr_x+15,p2_nbr_y+50);
			}
			render_player(&Player1);
			if (is_Single_Player)
			{
				render_player((Player**) &cpu);
			} else {
				render_player(&Player2);
			}

			break;
		}
		case GAMEOVER_QUOTE:
		{
			if (is_Single_Player==false)
			{
				engine->Images->show(0,infobox,500,150);	
			}
			engine->Images->show(0,"quotebox.png",0,0);

			/*shows the characters Winning Quote*/
			if (Player1->is_winner)
			{
				engine->Texts->searchtable(winquote,0)->set_text((*Player1->character)->win_quote,0,0,0);
				engine->Texts->searchtable(winquote,0)->printf("",30,480,0,0,0);
			//	engine->Texts->show_text(0,winquote,(*Player1->character)->win_quote,30,480,0,0,0);	
				(*Player1->character)->show_win_quote(10,100);
			} else {
				if (is_Single_Player ==false)
				{
					//engine->Texts->show_text(0,winquote,(*Player2->character)->win_quote,30,480,0,0,0);

					engine->Texts->searchtable(winquote,0)->set_text((*Player2->character)->win_quote,0,0,0);
					engine->Texts->searchtable(winquote,0)->printf("",30,480,0,0,0);
	
					(*Player2->character)->show_win_quote(10,100);

				} else {
				//	engine->Texts->show_text(0,winquote,(*cpu->character)->win_quote,30,480,0,0,0);	
					engine->Texts->searchtable(winquote,0)->set_text((*cpu->character)->win_quote,0,0,0);
					engine->Texts->searchtable(winquote,0)->printf("",30,480,0,0,0);

					(*cpu->character)->show_win_quote(10,100);

				}
			}
			if (is_Single_Player==false)
			{
				/*Options */
				engine->Texts->show_text(0,charsel,"Character Select",540,190,0,0,0);	
				engine->Texts->show_text(0,exitgame,"Exit",540,220,0,0,0);
				engine->Texts->show_text(0,curz, "O",520,curs2pos,255,0,0);	
			}

			break;
		}
		
	}
	if (game_play_mode != GAMEOVER_QUOTE )
	{

		

		/*show characters name*/
		sprintf(p1charname,"%s",(*Player1->character)->name);
		engine->Texts->searchtable(p1charname_code,0)->set_text(p1charname,0,0,0);
        	engine->Texts->searchtable(p1charname_code,0)->printf("",300,180,0,0,0);

		if (is_Single_Player)
		{
			sprintf(p2charname,"%s",(*cpu->character)->name);
		} else {
			sprintf(p2charname,"%s",(*Player2->character)->name);
		}

		engine->Texts->searchtable(p2charname_code,0)->set_text(p2charname,0,0,0);
        	engine->Texts->searchtable(p2charname_code,0)->printf("",430,180,0,0,0);

		/*show Some texts*/
		engine->Texts->searchtable(nextblockid,0)->set_text("NEXT",0,115,255);
		engine->Texts->searchtable(nextblockid,0)->printf("",300,50,0,0,0);
		engine->Texts->searchtable(nextblockid,0)->printf("",430,50,0,0,0);
	
		//engine->Texts->show_text(0,nextblockid,"NEXT:",300,50,0,0,0);
      		//engine->Texts->show_text(0,nextblockid,"NEXT:",430,50,0,0,0);

		engine->Texts->searchtable(scoreid,0)->set_text("SCORE",0,115,255);
		engine->Texts->searchtable(scoreid,0)->printf("",300,450,0,0,0);
		engine->Texts->searchtable(scoreid,0)->printf("",440,450,0,0,0);
		//engine->Texts->show_text(0,scoreid,"SCORE:",300,450,0xff,0x00,0);
		//engine->Texts->show_text(0,scoreid,"SCORE:",440,450,0xff,0x00,0);	

        	char p1score[255];

		sprintf(p1score,"%i",Player1->score);

		engine->Texts->searchtable(p1_score,0)->set_text(p1score);
        	engine->Texts->searchtable(p1_score,0)->printf("",300,475,0,0,0);

		sprintf(p1score,"%i",Player2->score);
		engine->Texts->searchtable(p1_score,0)->set_text(p1score);
        	engine->Texts->searchtable(p1_score,0)->printf("",440,475,0,0,0);

		/*show rounds*/
		int spacings = 300;
		for (int y=0; y < rounds2win;y++)
		{
			engine->Images->show(0,WinBall_Filename,spacings,505);
			spacings += 20;
		}

		spacings = 440;
		for (int y=0; y < rounds2win;y++)
		{
			engine->Images->show(0,WinBall_Filename,spacings,505);
			spacings += 20;
		}
		/*mark if a player won a round*/
		spacings = 300;
		for (int z=0;z< Player1->wins;z++)
		{
			engine->Images->show(0,WonBall_Filename,spacings,505);
			spacings +=20;
		}
		spacings = 440;
		if (is_Single_Player)
		{
			for (int z=0;z< cpu->wins;z++)
			{
				engine->Images->show(0,WonBall_Filename,spacings,505);
				spacings +=20;
			}

		} else {
			for (int z=0;z< Player2->wins;z++)
			{
				engine->Images->show(0,WonBall_Filename,spacings,505);
				spacings +=20;
			}
		}
		/*Draw Next Block braket*/
		engine->Images->show(0,nextblockracket,p1_nbr_x,p1_nbr_y);
		engine->Images->show(0,nextblockracket,p2_nbr_x,p2_nbr_y);

		/*Draw Jar*/
		engine->Images->show(Jar_ID,Jar_filename, Jar_Player1_X, Jar_Player1_Y);
		engine->Images->show(Jar_ID,Jar_filename, Jar_Player2_X, Jar_Player2_Y);
		if (*gauge_on == true)
		{
			engine->Images->show(0,gaugebar,290,400);
			engine->Images->show(0,gaugebar,420,400);
			int strt= 298;

			for (int i=0;i<Player1->gaugebar;i++)
			{
				engine->Images->show(0,gaugebarp,strt,408);
				strt++;
			}
			int strt2 = 428;
			if (is_Single_Player)
			{
				for (int j=0;j<cpu->gaugebar;j++)
				{
					engine->Images->show(0,gaugebarp,strt2,408);
					strt2++;
				}

			} else {
				for (int j=0;j<Player2->gaugebar;j++)
				{
					engine->Images->show(0,gaugebarp,strt2,408);
					strt2++;
				}
			}
			
		}


	}



	/*Shows the scoreboard after the round is over*/
	if (Player1->logic == CALC_SCORE || Player2->logic == CALC_SCORE)
	{
		if (Rounds[current_round].winner == 1)
		{ 
			sprintf(ggemblown_text,"Total Chains: %i x 100 = %i", Player1->total_chains,Player1->total_chains*100);
			sprintf(ggembg_text, "Total Gems Broke %i x 100 = %i", Player1->total_big_gems,Player1->total_big_gems*100);
			sprintf(gtotals_text, "Total Score: %i", (Player1->total_chains*100) + (Player1->total_big_gems*100));
		} else {
			sprintf(ggemblown_text,"Total Chains: %i x 100 = %i", Player2->total_chains,Player2->total_chains*100);
			sprintf(ggembg_text, "Total Gems Broke %i x 100 = %i", Player2->total_big_gems,Player2->total_big_gems*100);
			sprintf(gtotals_text, "Total Score: %i", (Player2->total_chains*100) + (Player2->total_big_gems*100));

		}
		engine->Images->show(0,scoreboard_pic,250,80);
		engine->Texts->show_text(0,ggemblown_code,ggemblown_text,300,230,0,0,0);	
		engine->Texts->show_text(0,ggembg_code,ggembg_text,300,260,0,0,0);
		engine->Texts->show_text(0,gtotals_code,gtotals_text,300,320,0,0,0);

	}


}

void render_player(Player** player)
{
	switch((*player)->logic)
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
		case CALC_SCORE:
		{
			break;
		}

		case ROUND_CLEAR:
		{
			break;
		}
	}

}

void draw_field(Player** player)
{
	for (int i=0;i<FIELD_WIDTH;i++)
	{
		for (int j=0;j<FIELD_HEIGHT;j++)
		{
			switch ((*player)->field[i][j].color)
			{
				case 0:
				{
					engine->Images->show(0,Blue_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 1:
				{
					if ((*player)->field[i][j].is_bomb)
					{
						/*Draw Bomb*/
						engine->Images->show(0,Blue_Bomb,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
						/*Draw Bomb Numer*/
						sprintf(p1_ccode_txt,"%i", (*player)->field[i][j].bomb_timer);
						engine->Texts->searchtable(p1_ccode,0)->set_text(p1_ccode_txt);
						engine->Texts->searchtable(p1_ccode,0)->printf("",(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i)+10,(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j)+5);
					} else {
						engine->Images->show(0,Blue_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					}
					break;
				}
				case 2:
				{
					engine->Images->show(0,Green_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 3:
				{
					if ((*player)->field[i][j].is_bomb)
					{
						engine->Images->show(0,Green_Bomb,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
						sprintf(p1_ccode_txt,"%i", (*player)->field[i][j].bomb_timer);
						engine->Texts->searchtable(p1_ccode,0)->set_text(p1_ccode_txt);
						engine->Texts->searchtable(p1_ccode,0)->printf("",(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i)+10,(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j)+5);

					} else {
						engine->Images->show(0,Green_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					}
					break;
				}
				case 4:
				{
					engine->Images->show(0,Red_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 5:
				{
					if ((*player)->field[i][j].is_bomb)
					{
						engine->Images->show(0,Red_Bomb,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
						sprintf(p1_ccode_txt,"%i", (*player)->field[i][j].bomb_timer);
						engine->Texts->searchtable(p1_ccode,0)->set_text(p1_ccode_txt);
						engine->Texts->searchtable(p1_ccode,0)->printf("",(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i)+10,(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j)+5);

					} else {

						engine->Images->show(0,Red_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					}
					break;
				}
				case 6:
				{
					engine->Images->show(0,Yellow_Breaker_Filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					break;
				}
				case 7:
				{
					if ((*player)->field[i][j].is_bomb)
					{
						engine->Images->show(0,Yellow_Bomb,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
						sprintf(p1_ccode_txt,"%i", (*player)->field[i][j].bomb_timer);
						engine->Texts->searchtable(p1_ccode,0)->set_text(p1_ccode_txt);
						engine->Texts->searchtable(p1_ccode,0)->printf("",(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i)+10,(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j)+5);

					} else {
						engine->Images->show(0,Yellow_Gem,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*i),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*j));
					}
					break;
				}


			}
		}
	}

}

void draw_block(Player** player)
{
	if ((*player)->top_block != -1 && (*player)->bottom_block != -1)
	{
		switch ((*player)->rotate)
		{
			case NORMAL:
			{
				(*player)->top_block_x = (*player)->bottom_block_x;
				(*player)->top_block_y = (*player)->bottom_block_y-1;
				(*player)->drop_block_x = (*player)->top_block_x;
				(*player)->rotation_padding = -32;
				break;
			}
			case LEFTSIDE_DOWN:
			{
				(*player)->top_block_x=((*player)->bottom_block_x)-1;
				(*player)->top_block_y=(*player)->bottom_block_y;
				(*player)->drop_block_x = (*player)->top_block_x;
			//	(*player)->drop_block_y = (*player)->bottom_block_y;
				(*player)->rotation_padding = 0;
				break;
			}
			case UPSIDE_DOWN:
			{
			        (*player)->top_block_x=(*player)->bottom_block_x;
				(*player)->top_block_y=(*player)->bottom_block_y+1;
				(*player)->rotation_padding = 32;
				
				break;
			}
			case RIGHTSIDE_UP:
			{
				(*player)->top_block_x=(*player)->bottom_block_x+1;
				(*player)->top_block_y=(*player)->bottom_block_y;
				(*player)->rotation_padding = 0;
				break;
			}
		}
		engine->Images->show((*player)->top_block_ID,(*player)->top_block_name,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*(*player)->top_block_x),((*player)->FIELD_POSITION_Y+(BLOCK_SIZE+(*player)->drop_block_y))+(*player)->rotation_padding);

		engine->Images->show((*player)->bottom_block_ID,(*player)->bottom_block_name,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*(*player)->bottom_block_x),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE+(*player)->drop_block_y));	
	}

}


void show_mood(Player** player,bool flipped, bool iscpu)
{
	int moodz =0;

	if (flipped == true && iscpu == true)
	{
		moodz = cpu->Mood;
	} else {
		moodz = (*player)->Mood;
	}

	switch(moodz)
	{
		case 0:
		{
			if (flipped == false)
			{
				(*(*player)->character)->Idle_Animate_Render((*(*player)->character)->Intro_X,(*(*player)->character)->Intro_Y);
			} else {
				if (iscpu)
				{
					(*cpu->character)->Idle_Animate_Flip_Render( (*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);

				} else {
					(*(*player)->character)->Idle_Animate_Flip_Render((*(*player)->character)->Intro_Flip_X,(*(*player)->character)->Intro_Flip_Y);
				}
			}
			break;
		}
		case 1:
		{
			if (flipped == false)
			{
				(*(*player)->character)->Attack_Animate_Render((*(*player)->character)->Intro_X,(*(*player)->character)->Intro_Y);
			//	(*(*player)->character)->Attack_Animate((*(*player)->character)->Intro_X,(*(*player)->character)->Intro_Y);
			} else {
				if (iscpu)
				{
					(*cpu->character)->Attack_Animate_Flip_Render( (*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);					
			//		(*cpu->character)->Attack_Animate_F( (*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);		
				} else {
					(*(*player)->character)->Attack_Animate_Flip_Render((*(*player)->character)->Intro_Flip_X,(*(*player)->character)->Intro_Flip_Y);
			//		(*(*player)->character)->Attack_Animate_F((*(*player)->character)->Intro_Flip_X,(*(*player)->character)->Intro_Flip_Y);

				}
			}
			break;
		}
		case 2:
		{
			if (flipped == false)
			{
				
				(*(*player)->character)->Hurt_Animate_Render((*(*player)->character)->Intro_X,(*(*player)->character)->Intro_Y);			
			} else {
				if (iscpu)
				{
					(*cpu->character)->Hurt_Animate_Flip_Render((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);
					
				} else {
					(*(*player)->character)->Hurt_Animate_Flip_Render((*(*player)->character)->Intro_Flip_X,(*(*player)->character)->Intro_Flip_Y);
				}		
			}				
			break;
		}
		case 3:
		{
			if (flipped == false)
			{
				(*(*player)->character)->Win1_Animate((*(*player)->character)->Intro_X,(*(*player)->character)->Intro_Y);
			} else {
				if (iscpu)
				{
					(*cpu->character)->Win1_Animate2((*cpu->character)->Intro_Flip_X,(*cpu->character)->Intro_Flip_Y);

				} else {
					(*(*player)->character)->Win1_Animate2((*(*player)->character)->Intro_Flip_X,(*(*player)->character)->Intro_Flip_Y);	
				}
			}
			break;
		}
		break;
	}
}

void show_block(int color, int x, int y)
{
	switch (color)
	{
		case 0:
		{
			engine->Images->show(0,Blue_Breaker_Filename,x,y);
			break;
		}
		case 1:
		{

			engine->Images->show(0,Blue_Gem,x,y);
			break;
		}
		case 2:
		{
			engine->Images->show(0,Green_Breaker_Filename,x,y);
			break;
		}
		case 3:
		{
			engine->Images->show(0,Green_Gem,x,y);
			break;
		}
		case 4:
		{
			engine->Images->show(0,Red_Breaker_Filename,x,y);
			break;
		}
		case 5:
		{
			engine->Images->show(0,Red_Gem,x,y);
			break;
		}
		case 6:
		{
			engine->Images->show(0,Yellow_Breaker_Filename,x,y);
			break;
		}
		case 7:
		{
			engine->Images->show(0,Yellow_Gem,x,y);
			break;
		}
	}
}
