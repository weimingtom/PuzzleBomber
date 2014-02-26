#include "Gameplay.h"



int Gameplay_Logic()
{
	
	switch(game_play_mode)
	{
		case INIT_ROUND:
		{
			init_next_block();
			clear_explode_map();
			clear_round();	
			switch_mode(INTRO);
			Player1->reset_drop_field();
			if (is_Single_Player)
			{
				cpu->reset_drop_field();
			} else {
				Player2->reset_drop_field();
			}
			if (music) engine->sound_system->stop_music("vs.mp3");
			break;
		}

		case INTRO:
		{
			if ((*Player1->character)->isintrodone == false)
			{
				(*Player1->character)->Intro_Animate();
			} else {
				(*Player1->character)->Idle_Animate((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
			}

			if (is_Single_Player)
			{
				if ((*cpu->character)->isintrodone2 == false)
				{
					(*cpu->character)->Intro_Animate_Flip();
				} else {
					(*cpu->character)->Idle_Animate_Flip((*cpu->character)->Intro_X,(*cpu->character)->Intro_Y);
				
				}
			} else {
				if ((*Player2->character)->isintrodone2 == false)
				{
					(*Player2->character)->Intro_Animate_Flip();
				} else {
					(*Player2->character)->Idle_Animate_Flip((*Player2->character)->Intro_Flip_X,(*Player2->character)->Intro_Flip_Y);
				} 
			}

			if (is_Single_Player)
			{
				if ((*Player1->character)->isintrodone == true && (*cpu->character)->isintrodone2 == true)
				{
					switch_mode(ROUND_NUMBER);
				}
			} else {
				if ((*Player1->character)->isintrodone == true && (*Player2->character)->isintrodone2 == true)
				{
					switch_mode(ROUND_NUMBER);
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
					if (sound) engine->sound_system->play_sound(6,"party.wav");
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
					Player1->reset_keys();

					if (is_Single_Player == false)
					{
						Player2->reset_keys();
					}
					if (music) 
					{
						if (is_Single_Player) 
						{
							(*cpu->character)->myStage->PlayThread();
						} else {
							(*Player1->character)->myStage->PlayThread();
						}
					}
					game_play_mode = PLAY_GAME;
				}						
			}
				
			break;
		}
		case PLAY_GAME:
		{	

			/*Character Animation*/
			Player1->Animate_Mood();


			if (is_Single_Player)
			{
				cpu->Animate_Mood2();
			} else {
				Player2->Animate_Mood2();
			}
			if (Player1->ischain == true)
			{
				if (Player1->chain_timer > 50)
				{
					Player1->ischain = false;
					Player1->chain_timer = 0;
				} else {
					Player1->chain_timer++;
				}
			}

			if (is_Single_Player)
			{
				if (cpu->ischain == true)
				{

					if (cpu->chain_timer > 50)
					{
						cpu->ischain = false;
						cpu->chain_timer = 0;
					} else {
						cpu->chain_timer++;
					}
				}

			} else {
				if (Player2->ischain == true)
				{

					if (Player2->chain_timer > 50)
					{
						Player2->ischain = false;
						Player2->chain_timer = 0;
					} else {
						Player2->chain_timer++;
					}
				}

			}
	
			if (deleteblock() == true)
			{
				Player1->nextblocknum--;
				if (is_Single_Player)
				{
					cpu->nextblocknum--;
				} else {
					Player2->nextblocknum--;
				}
			} 
			Player1_Gameplay(&Player1);
			if (is_Single_Player)
			{
				Player1_Gameplay((Player**) &cpu);
			} else {
				Player1_Gameplay(&Player2);
			}
			break;
		}
		case GAMEOVER_QUOTE:
		{
			if (is_Single_Player==false)
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
							stage_char_box_x=282;
							stage_char_box_y=300;
							current_stage=1;
							cpu_sel_count=0;
							randchar=0;
							getrandchar=0;
							
							total_cpu=3;
							cpu_char[0] = 0;
							cpu_char[1] = 1;
							cpu_char[2] = 2;

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

			} else {
				if (quote_screen_pause == 100)
				{
					Has_Paused = false;
					Has_Selected = false;
					Player1_Has_Selected = true;
					Player2_selected_big_ID=0;	
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

					quote_screen_pause =0;
					cpuslt=false;
					if (cpu->is_winner==false && Player1->is_winner == true)
					{
						for (int lo=0;lo<total_cpu;lo++)
						{
							if (randchar == cpu_char[lo])
							{
								cpu_char[lo] = -1;
								for (int mo=0; mo <total_cpu;mo++)
								{
									if (cpu_char[mo] == -1)
									{
										int temp = cpu_char[mo];
										cpu_char[mo] = cpu_char[mo+1];
										cpu_char[mo+1] = temp; 
									}
								}
							}
						}
						total_cpu--;

						if (total_cpu != 0)
						{
							stage_char_box_x+=Cursor_Move_Space;
							current_stage++;
	
							game_mode = CHARACTER_SELECT;
						} else {
							stage_char_box_x=282;
							stage_char_box_y=300;
							current_stage=1;
							cpu_sel_count=0;
							randchar=0;
							getrandchar=0;
							
							total_cpu=3;
							cpu_char[0] = 0;
							cpu_char[1] = 1;
							cpu_char[2] = 2;

							total_cpu=3;
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
							smcursor = 200;
							curs2pos = 190;
							is_Single_Player = false;
							game_mode = CREDITS;
						//	main_menu_mode = SELECT_MODE;

						}

					} else {
						stage_char_box_x=282;
						stage_char_box_y=300;
						current_stage=1;
						cpu_sel_count=0;
						randchar=0;
						getrandchar=0;
							
						total_cpu=3;
						cpu_char[0] = 0;
						cpu_char[1] = 1;
						cpu_char[2] = 2;

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

						smcursor = 200;
						curs2pos = 190;
						is_Single_Player = false;
						game_mode = CHARACTER_SELECT;
						main_menu_mode = SELECT_MODE;

					}
					break;
				} else {
					quote_screen_pause++;
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
	switch((*player)->logic)
	{
		case SET_RND_BLOCK:
		{
			generate_rand_block(&(*player));
			set_block(&(*player));
			(*player)->logic = GEM_DROP;
			(*player)->Change_Rotation(NORMAL);
			break;
		}

		case GEM_DROP:
		{
			if ((*player) == Player1)
			{
				UserInput((*(&player)));
			} else {
				if (is_Single_Player)
				{
					cpu->Easy_Mode();
				} else {
					UserInput((*(&player)));
				}
			}
					
			if ((*player)->is_Block_Speed(1/*MAX_BLOCK_SPEED*/))
			{
					
				switch ((*player)->Get_Current_Rotation())
				{
					case NORMAL:
					{
						if (!is_Field_Block_Empty((*(&player)), (*player)->bottom_block_x,(*player)->bottom_block_y+1))
						{
							(*player)->Change_Players_Mode(GEM_HIT);
							break;
						}
						if (is_Field_bottom((*player)->bottom_block_y))
						{
							(*player)->Change_Players_Mode(GEM_HIT);
							break;
						}
						Drop_Block((*(&player)));
						break;
					}
					case LEFTSIDE_DOWN:
					{
						if (
						!is_Field_Block_Empty((*(&player)), (*player)->bottom_block_x, (*player)->bottom_block_y+1)
						||
						!is_Field_Block_Empty((*(&player)), (*player)->top_block_x, (*player)->top_block_y+1)
							)
							{
								(*player)->Change_Players_Mode(GEM_HIT);
								break;
							}
							if (is_Field_bottom((*player)->bottom_block_y))
							{
								(*player)->Change_Players_Mode(GEM_HIT);
								break;
							}
							Drop_Block( (*(&player) ) );
							break;
						}
						case UPSIDE_DOWN:
						{
							if (!is_Field_Block_Empty( (*(&player)), (*player)->top_block_x, (*player)->top_block_y+1))
							{
								(*player)->Change_Players_Mode(GEM_HIT);
								break;
							}
							if (is_Field_bottom((*player)->top_block_y))
							{
								(*player)->Change_Players_Mode(GEM_HIT);
								break;
							}
							Drop_Block( (*(&player)) );
							break;
						}
						case RIGHTSIDE_UP:
						{
							if (
							!is_Field_Block_Empty( (*(&player)), (*player)->bottom_block_x, (*player)->bottom_block_y+1)
							||
							!is_Field_Block_Empty( (*(&player)), (*player)->top_block_x, (*player)->top_block_y+1)

							)
							{
								(*player)->Change_Players_Mode(GEM_HIT);
								break;
							}

							if (is_Field_bottom((*player)->bottom_block_y))
							{
								(*player)->Change_Players_Mode(GEM_HIT);
								break;
							}

							Drop_Block((*(&player)));
							break;
						}
					}

					(*player)->block_speed=0;
				}
				(*player)->block_speed++;		
			break;
		}

		case GEM_HIT:
		{
			if ((*player)->is_not_on_top((*player)->top_block_y))
			{
				(*player)->Set_Block_Color((*player)->top_block_x, (*player)->top_block_y, (*player)->top_block);
				//engine->sound_system->play_sound(1,"hit.wav");
			}
			if ((*player)->is_not_on_top( (*player)->bottom_block_y))
			{
				(*player)->Set_Block_Color((*player)->bottom_block_x, (*player)->bottom_block_y, (*player)->bottom_block);
			}
			/* Check for bombs */
			for (int i=0;i<FIELD_WIDTH;i++)
			{
				for (int j=0;j<FIELD_HEIGHT;j++)
				{
					if ((*player)->field[i][j].is_bomb)
					{
						if ((*player)->field[i][j].bomb_timer == 1)
						{
							(*player)->field[i][j].bomb_timer = 0;
							(*player)->field[i][j].is_bomb = false;
						} else {
							(*player)->field[i][j].bomb_timer--;
						}
					}
	
				}
			}
			(*player)->Reset_Dropping_Block();
			(*player)->Change_Players_Mode(DROP_GEM);
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
					&&
					(*player)->field[i][j].is_bomb == false
					)
					{
						if ((*player)->List->find(i,j) == false)
						{
							
							int currentcolor = (*player)->field[i][j].color;
							/*right*/
							if (i+1 != FIELD_WIDTH) gembreaker(i+1,j,currentcolor, &(*player) );
							/*left*/
							if (i-1 != -1) gembreaker(i-1,j,currentcolor, &(*player));
							/*up*/
							if (j-1 != -1) gembreaker(i,j-1,currentcolor, &(*player) );
							/*down*/
							if (j+1 != FIELD_HEIGHT) gembreaker(i,j+1,currentcolor, &(*player) );
							
												
						}

						
						if ((*player)->did_brake == true)
						{
							(*player)->total_big_gems++; 
							(*player)->big_gem = 0;	
						}
						
					}
				}
			}
			if ((*player)->did_brake == true)
			{
				 (*player)->chain++;

			}

			if (*player == Player1)
			{
				
				if ((*player)->gem_broke != 0)
				{
					
					if (Player1->gem_broke >= 4)
					{
						if (Player1->gaugebar < 80) 
						{
							float addtobar = Player1->gem_broke / 4;
							if (( (Player1->gaugebar + addtobar) + 20) >= 80)
							{
								Player1->gaugebar = 80;
							}  else {
								Player1->gaugebar += (int) addtobar + 20;
							}
						}
					}
					
					if (*countergems == true)
					{
						if (Player1->pending_blocks > 0)
						{
							if (Player1->pending_blocks == Player1->gem_broke)
							{
								Player1->pending_blocks = 0;
								Player1->gem_broke=0;
							} else 
							if (Player1->pending_blocks > Player1->gem_broke)
							{
								Player1->pending_blocks -= Player1->gem_broke;	
								Player1->gem_broke = 0;
							} else
							if (Player1->gem_broke > Player1->pending_blocks)
							{
								Player1->gem_broke -= Player1->pending_blocks;
								Player1->pending_blocks = 0;
							}
									
						}
					}
					if (is_Single_Player)
					{
						cpu->pending_blocks += Player1->gem_broke;
						sprintf(penblktxt2,"%i",cpu->pending_blocks);

					} else {
						Player2->pending_blocks += Player1->gem_broke;
						sprintf(penblktxt2,"%i",Player2->pending_blocks);
					}
					engine->Texts->searchtable(penblkcde2,0)->set_text(penblktxt2);	
				}
			}
			if (is_Single_Player)
			{
				if ((*player)->gem_broke != 0)
				{
					
					if (cpu->gem_broke >= 4)
					{
						
						if (cpu->gaugebar < 80) 
						{
							if ((int) (cpu->gaugebar + ((cpu->gem_broke / 4)+10)) >= 80)
							{
								cpu->gaugebar = 80;
							} else { 
								cpu->gaugebar += (int) (Player2->gem_broke / 4) + 10;
							}
						}
					}
					
					if (*countergems == true)
					{
						if (cpu->pending_blocks > 0)
						{
							if (cpu->pending_blocks == cpu->gem_broke)
							{
								cpu->pending_blocks = 0;
								cpu->gem_broke=0;
							} else 
							if (cpu->pending_blocks > cpu->gem_broke)
							{
								cpu->pending_blocks -= cpu->gem_broke;	
								cpu->gem_broke = 0;
							} else
							if (cpu->gem_broke > cpu->pending_blocks)
							{
								cpu->gem_broke -= Player2->pending_blocks;
								cpu->pending_blocks = 0;
							}
									
						}
					}

					
					Player1->pending_blocks += cpu->gem_broke;
					sprintf(penblktxt1,"%i",Player1->pending_blocks);
					engine->Texts->searchtable(penblkcde1,0)->set_text(penblktxt1);	
				}
			} else {
				if (*player == Player2)
				{
				
					if ((*player)->gem_broke != 0)
					{
					
						if (Player2->gem_broke >= 4)
						{
						
							if (Player2->gaugebar < 80) 
							{
								if ((int) (Player2->gaugebar + ((Player2->gem_broke / 4)+10)) >= 80)
								{
									Player2->gaugebar = 80;
								} else { 
									Player2->gaugebar += (int) (Player2->gem_broke / 4) + 10;
								}
							}
						}
					
						if (*countergems == true)
						{
							if (Player2->pending_blocks > 0)
							{
								if (Player2->pending_blocks == Player2->gem_broke)
								{
									Player2->pending_blocks = 0;
									Player2->gem_broke=0;
								} else 
								if (Player2->pending_blocks > Player2->gem_broke)
								{
									Player2->pending_blocks -= Player2->gem_broke;	
									Player2->gem_broke = 0;
								} else
								if (Player2->gem_broke > Player2->pending_blocks)
								{
									Player2->gem_broke -= Player2->pending_blocks;
									Player2->pending_blocks = 0;
								}
									
							}
						}

					
						Player1->pending_blocks += Player2->gem_broke;
						sprintf(penblktxt1,"%i",Player1->pending_blocks);
						engine->Texts->searchtable(penblkcde1,0)->set_text(penblktxt1);	
					}
				}
			}

			
			(*player)->List->clear();
			if ((*player)->did_brake == true) 
			{
				(*player)->logic = GEM_PAUSE;
			} else {
				if ((*player)->specialp && (*player)->special_pause == true) (*player)->special_pause = false;
				
				if ((*player)->chain > 1)
				{
					if (*player == Player1)
					{
						sprintf(ctext,"%i Chain Combo", (*player)->chain);
						engine->Texts->searchtable(chaintext,0)->set_text(ctext);
						/*
						Counter chain combo
						*/
						if (*countergems == true)
						{
							if (is_Single_Player)
							{
								if (cpu->pending_blocks != 0)
								{
									cpu->pending_blocks *= 2;
								} else {
									cpu->pending_blocks = 2;
								}

							} else {
								if (Player2->pending_blocks != 0)
								{
									Player2->pending_blocks *= 2;
								} else {
									Player2->pending_blocks = 2;
								}
							}
						}
					} else {
						if (*countergems == true)
						{
							if (Player1->pending_blocks != 0)
							{
								Player1->pending_blocks *= 2;
							} else {
								Player1->pending_blocks = 2;
							}
						}
						sprintf(ctext2,"%i Chain Combo", (*player)->chain);
						engine->Texts->searchtable(chaintext2,0)->set_text(ctext2);
					}
					(*player)->total_chains++;
					(*player)->ischain = true;
				}
				(*player)->chain=0;
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
			bool stopdrop=false;

			for (int i=0;i<FIELD_WIDTH;i++)
			{
				for (int j=0;j<FIELD_HEIGHT;j++)
				{
					bool hasdrop=false;
					int j2 = 0;

					if ((*player)->field[i][j].color != -1)
					{
						if (j+1 != FIELD_HEIGHT)
						{
							if ((*player)->field[i][j+1].color == -1 && (*player)->field[i][j].can_drop == true)
							{
								(*player)->field[i][j+1].color = (*player)->field[i][j].color;
								(*player)->field[i][j].color = -1;
								hasdrop = true;
								if ((*player)->field[i][j].checked == true)
								{
									(*player)->field[i][j].checked = false;
									(*player)->field[i][j+1].checked = true;
								}
								if ((*player)->field[i][j].is_bomb == true)
								{
									(*player)->field[i][j].is_bomb = false;
									(*player)->field[i][j+1].is_bomb = true;
									(*player)->field[i][j+1].bomb_timer = (*player)->field[i][j].bomb_timer;
									(*player)->field[i][j].bomb_timer = 0;
									
								}
								doagain = true;
								//end for i=0
							}
							//end for color check
						} 
					}
					
					if (hasdrop == true)
					{
						j2 = j+1;
					} else {
						j2 = j;
					}

					if (is_gembreaker((*player)->field[i][j2].color) == false && (*player)->field[i][j2].color != -1 && (*player)->field[i][j2].checked == false)
					{
						int same_color = (*player)->field[i][j2].color;
						int sblock_width=0;
						int sblock_height=0;
						bool passgo=true;
						/*Find Width*/
						for (int k=i;k<FIELD_WIDTH;k++)
						{
							if ((*player)->field[k][j2].color == same_color && is_gembreaker((*player)->field[k][j2].color) == false && (*player)->field[k][j2].color != -1 && (*player)->field[k][j2].is_bomb == false)
							{
								sblock_width++;
							} else {
								break;
							}
						}
							

						if (hasdrop == true)
						{
							if (j2 > FIELD_HEIGHT) passgo = false;
						}
						if (passgo)
						{
							bool nomatch=false;
							int current_height=0;
							bool is_solid_block=0;
							int numofcol=0;
							/*check for solid blocks, bombs don't count*/
							for (int p=i;p < i+sblock_width;p++)
							{
								for (int l=j2;l<FIELD_HEIGHT;l++)
								{
									if ((*player)->field[p][l].color == same_color && (*player)->field[p][l].is_bomb == false)	
									{
										sblock_height++;
									} else {
										nomatch=true;
										break;
									}
								}
	
								if (sblock_height > 1)
								{
									if (current_height==0)
									{
										current_height = sblock_height;
									} else 
									if (sblock_height < current_height)
									{
										current_height= sblock_height;
									}
									numofcol++;
								}
								sblock_height=0;
							}
							/*solid block is found*/
													
							if (numofcol > 1)
							{
								/*check if there's any blocks on the bottom*/
								int TotalColHeight=0;
								int TotalColCount=0;
								int ColCount=0;

								for (int q=i;q<i+sblock_width;q++)
								{
									for (int r=j2+current_height;r < FIELD_HEIGHT;r++)
									{
										if ((*player)->field[q][r].is_solid == true)
										{
											break;
										}
										TotalColHeight++;
										if ((*player)->field[q][r].color != -1)
										{
											TotalColCount++;	
										}
									}
									if (TotalColHeight == TotalColCount)
									{
										ColCount++;
									}
								}
								if (ColCount > 1)
								{
									for (int s=i;s<i+sblock_width;s++)
									{
										for (int t=j2;t<j2+current_height;t++)
										{
											(*player)->field[s][t].can_drop = false;
											(*player)->field[s][t].checked = true;
											(*player)->field[s][t].is_solid = true;
										}
									}
								} 
							}
						}
					}
					//end for loop for height		
				}
				//end for loop for width
			}
			//end check for solids

			//Moves Solid block down.
			(*player)->reset_checks();

			bool breakout = false;

			for (int u=0;u<FIELD_WIDTH;u++)
			{
				for (int v=0;v<FIELD_HEIGHT;v++)
				{
					if ((*player)->field[u][v].is_solid && (*player)->field[u][v].checked ==false)
					{
						int solidblockw=0;
						int solidblockh=0;						

						/*finds the width*/
						for (int w=u;w<FIELD_WIDTH;w++)
						{
							if ((*player)->field[w][v].is_solid) 
							{
								solidblockw++;
							
							} else {
								break;
							}
						}

						/*find the height*/
						for (int x=v;x<FIELD_HEIGHT;x++)
						{
							if ((*player)->field[u][x].is_solid)
							{
								solidblockh++;
							} else {
								break;
							}
						}

						for (int z=u-1;z<u+solidblockw;z++)
						{
							for (int a=v; a < v+solidblockh;a++)
							{
								(*player)->field[z][a].checked = true;
							}
						}
						int totalblanks=0;
						int blanksfound=0;

						if (v+solidblockh < 12)
						{
							for (int y=u;y<u+solidblockw;y++)
							{
								totalblanks++;
								if ((*player)->field[y][v+solidblockh].color == -1)
								{
									blanksfound++;
								}
							}							

							if (totalblanks==blanksfound && totalblanks != 0)
							{
								
								for (int b=u;b<u+solidblockw;b++)
								{
									for (int c=v+solidblockh-1; c > v-1;c--)
									{
										 (*player)->field[b][c+1].color = (*player)->field[b][c].color;
										 (*player)->field[b][c].color = -1;

										 (*player)->field[b][c].can_drop = true;
										 (*player)->field[b][c+1].can_drop = false;

										 (*player)->field[b][c].is_solid = false;
										 (*player)->field[b][c+1].is_solid = true;
									
			 							 (*player)->field[b][c].checked = false;
										 (*player)->field[b][c+1].checked = true;
									}
								}
								breakout = true;
								doagain=true;
							}
						}
						
					}
				}
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
			(*player)->logic = DROP_GEM;
			break;
		}
		case GEM_DROP_PAUSE:
		{
			(*player)->drop_gem_pause = 0;
			(*player)->logic = DROP_GEM;
			break;
		}
		case GEM_SEND:
		{
			if ((*player)->pending_blocks !=0)
			{
				int colorcol=0;
				int colorrow=0;
				for (int i=0;i<(*player)->pending_blocks;i++)
				{						 
					bool foundaspot=false;

					for (int k=0;k< FIELD_HEIGHT;k++)
					{
						for (int j=0;j < FIELD_WIDTH;j++)
						{
							if ((*player)->field[j][k].color == -1)
							{
								if (Player1 == *player)
								{
									if (is_Single_Player)
									{
										(*player)->field[j][k].color = (*cpu->character)->counter_gems[colorcol][colorrow];
									} else {
										(*player)->field[j][k].color = (*Player2->character)->counter_gems[colorcol][colorrow];
									}

								} else
								if (cpu == *player)
								{
									(*player)->field[j][k].color = (*Player1->character)->counter_gems[colorcol][colorrow];
								} else 
								if (Player2 == *player)
								{
									(*player)->field[j][k].color = (*Player1->character)->counter_gems[colorcol][colorrow];

								}
								
								(*player)->field[j][k].can_drop = true;
								(*player)->field[j][k].is_solid = false;
								(*player)->field[j][k].is_bomb = true;
								(*player)->field[j][k].bomb_timer = 5;
								foundaspot = true;
								colorcol++;
								if (colorcol == 6)
								{
									colorcol=0;
									colorrow++;
									if (colorrow == 4) colorrow=0;
								}
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
						if (is_Single_Player)
						{
							cpu->Mood = 2;
						} else {
							Player2->Mood = 2;
						}

					} else
					if (*player == Player1)
					{
						if (is_Single_Player)
						{
							Player2->Mood = 1;
						} 
						Player1->Mood = 2;
					}
				} else {
					if (*player == Player1)
					{
						Player1->Mood=2;
						cpu->Mood=1;
					} else {
						cpu->Mood=2;
						Player1->Mood=1;
					}
				}

			}

			(*player)->pending_blocks = 0;
			(*player)->logic =DROP_GEM;

			break;
		}
		case GAMEOVER_CHECK:
		{
			if ((*player)->field[2][0].color != -1)
			{
				if (is_Single_Player)
				{
					if (*player == (Player*) cpu)
					{
						Player1->logic = ROUND_END;
						Rounds[current_round].winner = 1;
						Player1->wins++;
					} else {
					
						cpu->logic = ROUND_END;
						Rounds[current_round].winner = 2;
						cpu->wins++;
					}

				} else {
					if (*player == Player2)
					{
						Player1->logic = ROUND_END;
						Rounds[current_round].winner = 1;
						Player1->wins++;
					} else {
					
						Player2->logic = ROUND_END;
						Rounds[current_round].winner = 2;
						Player2->wins++;
					}
				}
				if (music)
				{	
					if (is_Single_Player)
					{
						(*cpu->character)->myStage->Stop((*cpu->character)->myStage->MusicFile);
					} else {

						(*Player1->character)->myStage->Stop((*Player1->character)->myStage->MusicFile);
					}
				}
				if (sound) engine->sound_system->play_sound(5,"KO.wav");

				(*player)->logic = ROUND_END;
			} else {
				(*player)->logic = SET_RND_BLOCK;
			}
			break;
		}
		case ROUND_END:
		{
				
			if(Rounds[current_round].winner == 1)
			{
				if (is_Single_Player == false)
				{
					Player2->Mood = 2;
					Player1->Mood = 3;
						
				} else {		
					Player1->Mood=3;
					cpu->Mood=2;	
				}
			} else {
				if (is_Single_Player == false)
				{
					Player2->Mood = 3;
					Player1->Mood = 2;
						
				} else {
						
					Player1->Mood=2;
					cpu->Mood=3;
				}
			}
			
			round_finish_timer++;
			p1_pb_state=0;
			p1_pb_total_count=-1;
			p1_pb_count = 0;
			Player1->specialp = false;

			p2_pb_state=0;
			p2_pb_total_count=-1;
			p2_pb_count = 0;
			Player2->specialp = false;
       			for (int i=0;i<6;i++)
			{
				for (int j=0;j<12;j++)
				{
					p1_sp_field[i][j].checked = false;
				}
			}	

			if (round_finish_timer > 200)
			{
				
				engine->Keys->up.is_key_pressed = false;
				engine->Keys->down.is_key_pressed = false;
				engine->Keys->enter.is_key_pressed = false;
				round_finish_timer = 0;
				Player1->logic = CALC_SCORE;//ROUND_CLEAR;
				if (is_Single_Player)
				{
					Player2->logic = CALC_SCORE;//ROUND_CLEAR;
				} else {
					cpu->logic = CALC_SCORE;
				}
			}
			if (is_Single_Player)
			{
				if (Player1->Mood == 2)(*Player1->character)->Hurt_Animate((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);
				if (cpu->Mood == 2) (*cpu->character)->Hurt_Animate_F((*cpu->character)->Intro_X,(*cpu->character)->Intro_Y);

			} else {
				if (Player1->Mood == 2) (*Player1->character)->Hurt_Animate((*Player1->character)->Intro_X,(*Player1->character)->Intro_Y);

				if (Player2->Mood == 2)(*Player2->character)->Hurt_Animate_F((*Player2->character)->Intro_X,(*Player2->character)->Intro_Y);
			

			}
			break;
		}
		case CALC_SCORE:
		{
			if (calc_timer == 65)
			{
				calc_timer=0;
				Player1->logic = ROUND_CLEAR;
				if (is_Single_Player)
				{
					cpu->logic = ROUND_CLEAR;
				} else {
					Player2->logic = ROUND_CLEAR;
				}
			} else {
				if (calc_timer == 0)
				{
					if (Rounds[current_round].winner  == 1)
					{
						round_breaks= 100*Player1->total_chains;
						round_gbreaks = 100*Player1->total_big_gems;
					} else 
					if (Rounds[current_round].winner  == 2)
					{
						if (is_Single_Player)
						{
							round_breaks= 100*cpu->total_chains;
							round_gbreaks = 100*cpu->total_big_gems;
	
						} else {
							round_breaks= 100*Player2->total_chains;
							round_gbreaks = 100*Player2->total_big_gems;
						}
					}
					
				}
				calc_timer++;
			}

			break;
		}

		case ROUND_CLEAR:
		{
			if (*player == Player1)
			{
				round_breaks = 0;
				round_gbreaks=0;
		
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
						Player1->field[i][j].is_solid = false;
						Player1->field[i][j].can_drop = true;
						Player1->field[i][j].checked = false;
						Player1->field[i][j].is_bomb = false;
						Player1->field[i][j].bomb_timer = 0;
						if (is_Single_Player)
						{
							cpu->field[i][j].color = -1;
							cpu->field[i][j].is_solid = false;
							cpu->field[i][j].can_drop = true;
							cpu->field[i][j].checked = false;
							cpu->field[i][j].is_bomb = false;
							cpu->field[i][j].bomb_timer = 0;
						} else {
							Player2->field[i][j].color = -1;
							Player2->field[i][j].is_solid = false;
							Player2->field[i][j].can_drop = true;
							Player2->field[i][j].checked = false;
							Player2->field[i][j].is_bomb = false;
							Player2->field[i][j].bomb_timer = 0;
						}

					}
				}

				Player1->Mood=0;
				if (is_Single_Player)
				{
					cpu->Mood=0;
				} else {
					Player2->Mood=0;
				}
				Player1->drop_gem_pause = 0;
				Player2->drop_gem_pause = 0;
				cpu->drop_gem_pause=0;
				Player1->gem_pause = 0;
				Player2->gem_pause = 0;
				cpu->gem_pause=0;
				Player1->top_block = -1;
				Player1->bottom_block = -1;

				cpu->top_block = -1;
				cpu->bottom_block = -1;


				Player2->top_block = -1;
				Player2->bottom_block = -1;

				Player1->top_block_x=2;
				Player1->top_block_y=-2;

				cpu->top_block_x=2;
				cpu->top_block_y=-2;

				Player2->top_block_x=2;
				Player2->top_block_y=-2;

				Player1->bottom_block_x=2;
				Player1->bottom_block_y=-2;
				Player2->bottom_block_x=2;
				Player2->bottom_block_y=-2;
				cpu->bottom_block_x=2;
				cpu->bottom_block_y=-2;



				Player1->rotate = NORMAL;
				Player2->rotate = NORMAL;
				cpu->rotate = NORMAL;



				Player1->block_speed = 0;
				Player2->block_speed =0;
				cpu->block_speed =0;



				Player1->chain_timer = 0;
				Player2->chain_timer=0;
				cpu->chain_timer=0;

				Player1->ischain = false;
				Player2->ischain = false;
				cpu->ischain = false;

				Player1->chain=0;
				Player2->chain=0;
				cpu->chain=0;

				Player1->nextblocknum=0;
				Player2->nextblocknum=0;
				cpu->nextblocknum=0;


				Player1->pending_blocks = 0;
				Player2->pending_blocks = 0;
				cpu->pending_blocks = 0;


				Player1->reset_drop_field();
				Player2->reset_drop_field();
				cpu->pending_blocks = 0;

				Player1->drop_block_y = -64;
				Player1->drop_block_x = -0;
				cpu->drop_block_x= -0;
				cpu->drop_block_y=-64;

		 		Player2->drop_block_y = -64;
				Player2->drop_block_x = -0;
				cpu->drop_block_x=-0;
				cpu->drop_block_y=-64;

				ready_timer=0;
				round_timer=0;
				
				
				Player1->logic = SET_RND_BLOCK;
				cpu->logic = SET_RND_BLOCK;
				Player2->logic = SET_RND_BLOCK;

				if (Rounds[current_round].winner  == 1)
				{
					Player1->score += (Player1->total_chains*100) + (Player1->total_big_gems*100);
					
				} else {
					if (is_Single_Player)
					{
						cpu->score += (cpu->total_chains*100) + (cpu->total_big_gems*100);
						
					} else {
						Player2->score += (Player2->total_chains*100) + (Player2->total_big_gems*100);
					}
				}

				if (is_Single_Player)
				{
					if (Player1->wins == rounds2win || cpu->wins == rounds2win)
					{
						int p1_total_wins = 0;
						int p2_total_wins = 0;

						for (int i=1;i<max_round+1;i++)
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
							cpu->is_winner = false;
						} else {
							Player1->is_winner = false;
							cpu->is_winner = true;

						}
						Player1->gaugebar = 0;
						cpu->gaugebar = 0;

						Player1->wins = 0;
						cpu->wins = 0;
						current_round = 1;
						game_play_mode=GAMEOVER_QUOTE;
					} else {
				
						current_round++;
						game_play_mode = ROUND_NUMBER; 
					}
					
				} else {
					if (Player1->wins == rounds2win || Player2->wins == rounds2win)
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
						Player1->gaugebar = 0;
						Player2->gaugebar = 0;

						Player1->wins = 0;
						Player2->wins = 0;
						current_round = 1;
						game_play_mode=GAMEOVER_QUOTE;
					} else {
				
						current_round++;
						game_play_mode = ROUND_NUMBER; 
					}
				
				}
			}
			break;
		}

	}
	
}

/*================================ FUNCTIONS ==========================================*/

bool is_Half_A_Frame()
{
	return (engine->frame % 2);
}

int is_Hit_Wall_Left(int x)
{
	return (x == 0);
	
}

int is_Hit_Wall_Right(int x)
{
	if ( (x == FIELD_WIDTH-1)) return true;
	return false;
}

int Move_Block_Left(Player **player)
{
	(*player)->bottom_block_x -=1;
}

int Move_Block_Right(Player **player)
{
	(*player)->bottom_block_x +=1;
}

bool is_top_of_field(Player** player)
{
       /*
	if ( 
		(
		(*player)->top_block_x == 2 
		|| 
		(*player)->top_block_x == 3
		) 
		&& 
		(
		(*player)->top_block_y == -1 
		|| 
		(*player)->top_block_y == -2
		)
	||
	
	(
		(
		(*player)->bottom_block_x == 2 
		|| 
		(*player)->bottom_block_x == 3
		) 
		&& 
		(*player)->bottom_block_y == -2
		)
	) return true;
*/
	return false;
}

bool is_block_on_top(int x, int y)
{
	if ( (x == 2 && y == -2) || (x==0)) return true;
	return false;
}


int Set_Block(Player** player, int y)
{
	(*player)->bottom_block_y = y;
}

int Drop_Block(Player** player)
{
	(*player)->drop_block_y+=2;
	if ( ( (*player)->drop_block_y % 32)== 0)
	{
		(*player)->bottom_block_y++;
	}
}

bool is_Field_bottom(int y)
{
	if (y == FIELD_HEIGHT-1) return true;
	return false;
}

bool is_Field_Block_Empty(Player** player, int x, int y)
{
	if ( (*player)->field[x][y].color == EMPTY) return true;
	return false;
}

void set_block(Player** player)
{
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
	(*player)->top_block_y=0;
	(*player)->bottom_block_x = (*player)->top_block_x;
	(*player)->bottom_block_y = (*player)->top_block_y+1;


}

void generate_rand_block(Player** player)
{
	(*player)->top_block= getcurrentblock((*player)->nextblocknum)->top.color;  
	(*player)->bottom_block=getcurrentblock((*player)->nextblocknum)->bottom.color;
		
	getcurrentblock((*player)->nextblocknum)->used++;
			
	(*player)->nextblocknum++;
			
	addblock();

}

void clear_round()
{
	Rounds[current_round].winner=0;
}

void clear_explode_map()
{
	for (int g=0;g<6;g++)
	{
		for (int h=0;h<12;h++)
		{
			explodemap[g][h] = -1;
		}
	}
}

void init_next_block()
{
	if (Player1->List == NULL) Player1->List = new xylist();

	if (is_Single_Player)
	{
		if (cpu->List == NULL) cpu->List = new xylist();
	} else {
		if (Player2->List == NULL) Player2->List = new xylist();
	}


	Player1->List->clear();
	if (is_Single_Player)
	{
		cpu->List->clear();
	} else {
		Player2->List->clear();
	}

	addblock();
	addblock();


}
 

int gembreaker(int x,int y, int color, Player **player)
{
	/*check left is a gem of the same color*/
	if ((*player)->field[x][y].color != -1)
	{ 
		if (
		(
		(*player)->field[x][y].color ==  color
		||
		(*player)->field[x][y].color ==  color + 1
		)

		&&
		(
		(*player)->field[x][y].is_bomb == false
		)
		)
		{					
			if ((*player)->List->find(x,y) == false)
			{
				if ((*player)->specialp && (*player)->special_pause == false) (*player)->special_pause = true;
				if ((*player)->field[x][y].is_solid == true)
				{
					(*player)->big_gem++;
				}
				(*player)->did_brake = true;
				(*player)->List->add(x,y);
				(*player)->field[x][y].color = -1;
				(*player)->field[x][y].is_solid = false;
				(*player)->field[x][y].can_drop = true;
				(*player)->field[x][y].checked = false;
				(*player)->explodemap[x][y] = 0;
				(*player)->gem_broke++;
				
                                if ((*player)->field[x+1][y].is_bomb == true && x+1 != 6)
				{
					(*player)->did_brake = true;
					(*player)->field[x+1][y].color = -1;
					(*player)->field[x+1][y].is_solid = false;
					(*player)->field[x+1][y].can_drop = true;
					(*player)->field[x+1][y].checked = false;
					(*player)->explodemap[x+1][y] = 0;
					(*player)->field[x+1][y].is_bomb = false;
					(*player)->field[x+1][y].bomb_timer=0;
					(*player)->gem_broke++;
					
				}
                                if ((*player)->field[x-1][y].is_bomb == true && x-1 != -1)
				{
					(*player)->did_brake = true;
					(*player)->field[x-1][y].color = -1;
					(*player)->field[x-1][y].is_solid = false;
					(*player)->field[x-1][y].can_drop = true;
					(*player)->field[x-1][y].checked = false;
					(*player)->explodemap[x-1][y] = 0;
					(*player)->field[x-1][y].is_bomb = false;
					(*player)->field[x-1][y].bomb_timer=0;
					(*player)->gem_broke++;
					
				}
                               if ((*player)->field[x][y+1].is_bomb == true && y+1 != 12)
				{
					(*player)->did_brake = true;
					(*player)->field[x][y+1].color = -1;
					(*player)->field[x][y+1].is_solid = false;
					(*player)->field[x][y+1].can_drop = true;
					(*player)->field[x][y+1].checked = false;
					(*player)->explodemap[x][y+1] = 0;
					(*player)->field[x][y+1].is_bomb = false;
					(*player)->field[x][y+1].bomb_timer=0;
					(*player)->gem_broke++;
					
				}
                               if ((*player)->field[x][y-1].is_bomb == true && y-1 != -1)
				{
					(*player)->did_brake = true;
					(*player)->field[x][y-1].color = -1;
					(*player)->field[x][y-1].is_solid = false;
					(*player)->field[x][y-1].can_drop = true;
					(*player)->field[x][y-1].checked = false;
					(*player)->explodemap[x][y-1] = 0;
					(*player)->field[x][y-1].is_bomb = false;
					(*player)->field[x][y-1].bomb_timer=0;
					(*player)->gem_broke++;
					
				}


				/*right*/
				if (x+1 != 6) gembreaker(x+1,y,color, &(*player) );
				/*left*/
				if (x-1 != -1) gembreaker(x-1,y,color, &(*player) );
				/*up*/
				if (y-1 != -1) gembreaker(x,y-1,color, &(*player));
				/*down*/
				if (y+1 != 12)gembreaker(x,y+1,color, &(*player));
				
				if (sound) engine->sound_system->play_sound(2,"explode.wav");
								
			}
		}
	}
}

void bottom_block_check_solid(Player** player)
{
	if (is_gembreaker((*player)->bottom_block ) == false)
	{
		if (
		(*player)->bottom_block_x != 0
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x-1, (*player)->bottom_block_y, player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x-1, (*player)->bottom_block_y-1,player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x, (*player)->bottom_block_y-1,player)			
		)
		{
			(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y].is_solid = true;
			(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y-1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y-1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y].is_solid = true;
		}

			/*
				 [ ][ ]
				 [ ][#]
				    [x]
			*/
		if (
		(*player)->bottom_block_x != 0
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x-1, (*player)->bottom_block_y, player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x-1, (*player)->bottom_block_y+1,player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x, (*player)->bottom_block_y+1,player)			
		)
		{
			(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y].is_solid = true;
			(*player)->field[(*player)->bottom_block_x-1][(*player)->bottom_block_y+1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y].is_solid = true;		
		}



			/*
			[ ][ ]
			[#][ ]
			[x]
			*/

		if (
		(*player)->bottom_block_x != 0
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x, (*player)->bottom_block_y+1, player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x+1, (*player)->bottom_block_y+1,player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x+1, (*player)->bottom_block_y,player)			
		)
		{
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y+1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y].is_solid = true;
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y].is_solid = true;	
		}



			/*
					 
				[#][ ]
				[ ][ ]
			*/
		if (
		(*player)->bottom_block_x != 0
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x+1, (*player)->bottom_block_y, player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x+1, (*player)->bottom_block_y+1,player)
		&&
		is_same_color((*player)->bottom_block,(*player)->bottom_block_x, (*player)->bottom_block_y+1,player)			
		)
		{
			(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y].is_solid = true;
			(*player)->field[(*player)->bottom_block_x+1][(*player)->bottom_block_y+1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y+1].is_solid = true;
			(*player)->field[(*player)->bottom_block_x][(*player)->bottom_block_y].is_solid = true;	
		}
	}

}

void top_block_check_solid(Player** player)
{
	if (is_gembreaker((*player)->top_block ) == false)
	{
		/*
		[ ][ ]
		[ ][t]
		   [b]
		*/
		if (
		(*player)->top_block_x != 0
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x-1, (*player)->top_block_y, player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x-1, (*player)->top_block_y-1,player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x, (*player)->top_block_y-1,player)			
		)
		{
			(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y].is_solid = true;
			(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y-1].is_solid = true;
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y-1].is_solid = true;
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y].is_solid = true;
		}

			/*
				 
				 [ ][t]
				 [ ][b]
			*/
		if (
		(*player)->top_block_x != 0
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x-1, (*player)->top_block_y, player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x-1, (*player)->top_block_y+1,player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x, (*player)->top_block_y+1,player)			
		)
		{
			(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y].is_solid = true;
			(*player)->field[(*player)->top_block_x-1][(*player)->top_block_y+1].is_solid = true;
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].is_solid = true;
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y].is_solid = true;		
		}



			/*
			[ ][ ]
			[#][ ]
			[x]
			*/

		if (
		(*player)->top_block_x != 0
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x, (*player)->top_block_y+1, player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x+1, (*player)->top_block_y+1,player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x+1, (*player)->top_block_y,player)			
		)
		{
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].is_solid = true;
			(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y+1].is_solid = true;
			(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y].is_solid = true;
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y].is_solid = true;	
		}



			/*
					 
				[#][ ]
				[ ][ ]
			*/
		if (
		(*player)->top_block_x != 0
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x+1, (*player)->top_block_y, player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x+1, (*player)->top_block_y+1,player)
		&&
		is_same_color((*player)->top_block,(*player)->top_block_x, (*player)->top_block_y+1,player)			
		)
		{
			(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y].is_solid = true;
			(*player)->field[(*player)->top_block_x+1][(*player)->top_block_y+1].is_solid = true;
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y+1].is_solid = true;
			(*player)->field[(*player)->top_block_x][(*player)->top_block_y].is_solid = true;	
		}
	}
}

bool is_gembreaker(int color)
{

	if (color % 2 == 0) return true;
	return false;
}

bool is_same_color(int color, int x, int y, Player** player)
{
	if ((*player)->field[x][y].color == color) return true;					
	
	return false;

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
