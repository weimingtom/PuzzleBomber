#include "Character_Select.h"

int Character_Select_Render()
{
	render_small_boxes();
	render_big_boxes();
	if (cpuslt == false)
	{
		render_Chars_Per_Pic();
		render_Cursors();
	}
	engine->Images->show(0,"CGemDialog.png",200,200);
	engine->Images->show(0,"CGemDialog.png",400,200);

	int fx = 315;
	int fy=211;


	if (current_stage != 1 && is_Single_Player)
	{
		int pstage_char_box_x=282;
		int pstage_char_box_y=300;

		for (int i=0;i<current_stage-1;i++)
		{
					
			switch (stage_char[i])
			{
				case 0:
				{
					kitteh->Show_Personal_Pic(pstage_char_box_x+10,pstage_char_box_y);
					break;
				}
				case 1:
				{
					bart->Show_Personal_Pic(pstage_char_box_x+10, pstage_char_box_y);
					break;
				}
				case 2:
				{
					prinny->Show_Personal_Pic(pstage_char_box_x+10, pstage_char_box_y+20);
					break;
				}
			}
			pstage_char_box_x+=Cursor_Move_Space;
		}
	}

	if (is_Single_Player)
	{

		if (Has_Selected)
		{
			switch (randchar)
			{
				case 0:
				{
					
					Player2_selected_big_ID=Kitteh_Big_Personal_ID;

					strcpy(Player2_selected_big_name,"kitteh_Bigheadshot.png");
					
					kitteh->Win1_Animate2(650,449);
					Player2_selected_char_ID=2;
					int fx2 = 515;
					int fy2=211;
					kitteh->showname(player2_selected_x,player2_selected_y);

	
					for (int y= 0;y<4;y++)
					{
						for (int x=0;x<6;x++)
						{
							switch(kitteh->counter_gems[x][y])
							{
 								case 1:
								{
									engine->Images->show(0,"bluegemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 3:
								{
									engine->Images->show(0,"greengemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 5:
								{
									engine->Images->show(0,"redgemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 7:
								{
									engine->Images->show(0,"yellowgemsmall.png",fx2+(10*x),fy2);
									break;
								}
							}
						}
						fy2+=10;				
					}

					break;
				}
				case 1:
				{
					Player2_selected_big_ID=Kitteh_Big_Personal_ID;

					strcpy(Player2_selected_big_name,"bart_Bigheadshot.png");
					bart->Win1_Animate2(650,449);
					Player2_selected_char_ID=2;
					bart->showname(player2_selected_x,player2_selected_y);


					int fx2 = 515;
					int fy2=211;	
					for (int y= 0;y<4;y++)
					{
						for (int x=0;x<6;x++)
						{
							switch(bart->counter_gems[x][y])
							{
 								case 1:
								{
									engine->Images->show(0,"bluegemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 3:
								{
									engine->Images->show(0,"greengemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 5:
								{
									engine->Images->show(0,"redgemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 7:
								{
									engine->Images->show(0,"yellowgemsmall.png",fx2+(10*x),fy2);
									break;
								}
							}
						}
						fy2+=10;				
					}

					break;
				}	
				case 2:
				{
				//	prinny->Show_Personal_Pic(stage_char_box_x+10, stage_char_box_y+20);
					Player2_selected_big_ID=Kitteh_Big_Personal_ID;

					strcpy(Player2_selected_big_name,"prinny_Bigheadshot.png");
					prinny->showname(player2_selected_x,player2_selected_y);

					prinny->Win1_Animate2(650,449);
					Player2_selected_char_ID=2;
					int fx2 = 515;
					int fy2=211;	
					for (int y= 0;y<4;y++)
					{
						for (int x=0;x<6;x++)
						{
							switch(prinny->counter_gems[x][y])
							{
 								case 1:
								{
									engine->Images->show(0,"bluegemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 3:
								{
									engine->Images->show(0,"greengemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 5:
								{
									engine->Images->show(0,"redgemsmall.png",fx2+(10*x),fy2);
									break;
								}
								case 7:
								{
									engine->Images->show(0,"yellowgemsmall.png",fx2+(10*x),fy2);
									break;
								}
							}
						}
						fy2+=10;				
					}

					break;
				}

				
			
			}


		}
	}


	if (Player1_selected_char_ID == 2)
	{
		if (player1_curs_X == Select_Char_Box_x + Cursor_Move_Space )
		{
			engine->Images->show(0,Player1_selected_big_name, Select_Char_Big_Box1_X+10, Select_Char_Big_Box_Y+40);
			bart->showname(player1_selected_x,player1_selected_y);

			if (Player1_Has_Selected == false) bart->Idle_Animate_Render(100,450);
 
			for (int y= 0;y<4;y++)
			{
				for (int x=0;x<6;x++)
				{
					switch(bart->counter_gems[x][y])
					{
 						case 1:
						{
							engine->Images->show(0,"bluegemsmall.png",fx+(10*x),fy);
							break;
						}
						case 3:
						{
							engine->Images->show(0,"greengemsmall.png",fx+(10*x),fy);
							break;
						}
						case 5:
						{
							engine->Images->show(0,"redgemsmall.png",fx+(10*x),fy);
							break;
						}
						case 7:
						{
							engine->Images->show(0,"yellowgemsmall.png",fx+(10*x),fy);
							break;
						}
					}
				
				}
				fy+=10;				
			}
		}	
	} 

	/* if the Player's cursor is on the first character*/
	if (Player1_selected_big_ID == 14)
	{
		
		
		//kitteh is selected
		if (player1_curs_X == Select_Char_Box_x )
		{
			//show picture of big kitteh
			engine->Images->show(Player1_selected_big_ID,Player1_selected_big_name, Select_Char_Big_Box1_X+10, Select_Char_Big_Box_Y+40);
			
			if (Player1_Has_Selected == false) kitteh->Idle_Animate_Render(100,450); /* render idle state kitteh*/
			/* show character name */
			kitteh->showname(player1_selected_x,player1_selected_y);

			for (int y= 0;y<4;y++)
			{
				for (int x=0;x<6;x++)
				{
					switch(kitteh->counter_gems[x][y])
					{
 						case 1:
						{
							engine->Images->show(0,"bluegemsmall.png",fx+(10*x),fy);
							break;
						}
						case 3:
						{
							engine->Images->show(0,"greengemsmall.png",fx+(10*x),fy);
							break;
						}
						case 5:
						{
							engine->Images->show(0,"redgemsmall.png",fx+(10*x),fy);
							break;
						}
						case 7:
						{
							engine->Images->show(0,"yellowgemsmall.png",fx+(10*x),fy);
							break;
						}
					}
				}
				fy+=10;				
			}
		}
	}
	
	if (Player1_selected_char_ID == 3)
	{
	
		if (player1_curs_X ==  446 )
		{
			engine->Images->show(Player1_selected_big_ID,Player1_selected_big_name, Select_Char_Big_Box1_X+10, Select_Char_Big_Box_Y+40);
			if (Player1_Has_Selected == false) prinny->Idle_Animate_Render(100,450); /* render idle state kitteh*/
			/* show character name */				
			prinny->showname(player1_selected_x,player1_selected_y);

			for (int y= 0;y<4;y++)
			{
				for (int x=0;x<6;x++)
				{
					switch(prinny->counter_gems[x][y])
					{
						case 1:
						{
							engine->Images->show(0,"bluegemsmall.png",fx+(10*x),fy);
							break;
						}
						case 3:
						{
							engine->Images->show(0,"greengemsmall.png",fx+(10*x),fy);
							break;
						}
						case 5:
						{
							engine->Images->show(0,"redgemsmall.png",fx+(10*x),fy);
							break;
						}
						case 7:
						{
							engine->Images->show(0,"yellowgemsmall.png",fx+(10*x),fy);
							break;
						}

 					}
				
				}	
				fy+=10;				
			}

		}
	}
	

	if (Player1_selected_char_ID == 777)
	{
	
		if (player1_curs_X ==  528 )
		{
			engine->Images->show(Player1_selected_big_ID,Player1_selected_big_name, Select_Char_Big_Box1_X+10, Select_Char_Big_Box_Y+80);
			if (Player1_Has_Selected == false) 
			{
				scott->Idle_Animate_Render(100,450); /* render idle state kitteh*/
			}
			/* show character name */				
			scott->showname(player1_selected_x-100,player1_selected_y);

			for (int y= 0;y<4;y++)
			{
				for (int x=0;x<6;x++)
				{
					switch(prinny->counter_gems[x][y])
					{
						case 1:
						{
							engine->Images->show(0,"bluegemsmall.png",fx+(10*x),fy);
							break;
						}
						case 3:
						{
							engine->Images->show(0,"greengemsmall.png",fx+(10*x),fy);
							break;
						}
						case 5:
						{
							engine->Images->show(0,"redgemsmall.png",fx+(10*x),fy);
							break;
						}
						case 7:
						{
							engine->Images->show(0,"yellowgemsmall.png",fx+(10*x),fy);
							break;
						}

 					}
				
				}	
				fy+=10;				
			}

		}
	}



	if (is_Single_Player == false)
	{
		if (Player2_selected_char_ID == 3)
		{
			if (player2_curs_X == 446)
			{
				engine->Images->get_image(Player2_selected_big_ID,Player2_selected_big_name)->Show_Flipped_Image(Select_Char_Big_Box2_X+40,Select_Char_Big_Box_Y+40,-1,-1,-1,-1);

				if (Player2_Has_Selected == false) prinny->Idle_Animate_Flip_Render(650,450);
				prinny->showname(player2_selected_x,player2_selected_y);
				int fx2 = 515;
				int fy2=211;	

				for (int y= 0;y<4;y++)
				{
					for (int x=0;x<6;x++)
					{
						switch(prinny->counter_gems[x][y])
						{
							case 1:
							{
								engine->Images->show(0,"bluegemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 3:
							{
								engine->Images->show(0,"greengemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 5:
							{
								engine->Images->show(0,"redgemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 7:
							{
								engine->Images->show(0,"yellowgemsmall.png",fx2+(10*x),fy2);
								break;
							}

 						}
				
					}	
					fy2+=10;				
				}
			}	
		} 

		if (Player2_selected_char_ID == 2)
		{
			if (player2_curs_X == Select_Char_Box_x + Cursor_Move_Space )
			{
				engine->Images->get_image(Player2_selected_big_ID,Player2_selected_big_name)->Show_Flipped_Image(Select_Char_Big_Box2_X+40,Select_Char_Big_Box_Y+40,-1,-1,-1,-1);

				if (Player2_Has_Selected == false) bart->Idle_Animate_Flip_Render(650,450);
				bart->showname(player2_selected_x,player2_selected_y);
				int fx2 = 515;
				int fy2=211;	

				for (int y= 0;y<4;y++)
				{
					for (int x=0;x<6;x++)
					{
						switch(bart->counter_gems[x][y])
						{
							case 1:
							{
								engine->Images->show(0,"bluegemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 3:
							{
								engine->Images->show(0,"greengemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 5:
							{
								engine->Images->show(0,"redgemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 7:
							{
								engine->Images->show(0,"yellowgemsmall.png",fx2+(10*x),fy2);
								break;
							}

 						}
				
					}	
					fy2+=10;				
				}
			}	
		} 

	
		/* cursor is on a character */
		if (Player2_selected_big_ID != 0)
		{
			if (player2_curs_X == Select_Char_Box_x )
			{
				engine->Images->get_image(Player2_selected_big_ID,Player2_selected_big_name)->Show_Flipped_Image(Select_Char_Big_Box2_X+40,Select_Char_Big_Box_Y+40,-1,-1,-1,-1);

				if (Player2_Has_Selected == false) kitteh->Idle_Animate_Flip_Render(650,450);
			  	kitteh->showname(player2_selected_x,player2_selected_y);
      
				int fx2 = 515;
				int fy2=211;	
				for (int y= 0;y<4;y++)
				{
					for (int x=0;x<6;x++)
					{
						switch(kitteh->counter_gems[x][y])
						{
 							case 1:
							{
								engine->Images->show(0,"bluegemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 3:
							{
								engine->Images->show(0,"greengemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 5:
							{
								engine->Images->show(0,"redgemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 7:
							{
								engine->Images->show(0,"yellowgemsmall.png",fx2+(10*x),fy2);
								break;
							}
						}
					}
					fy2+=10;				
				}
			
			}
		}


		if (Player2_selected_char_ID == 777)
		{
			if (player2_curs_X == 528)
			{
				engine->Images->get_image(Player2_selected_big_ID,Player2_selected_big_name)->Show_Flipped_Image(Select_Char_Big_Box2_X+40,Select_Char_Big_Box_Y+40,-1,-1,-1,-1);

				if (Player2_Has_Selected == false) scott->Idle_Animate_Flip_Render(650,450);
				scott->showname(player2_selected_x,player2_selected_y);
				int fx2 = 515;
				int fy2=211;	

				for (int y= 0;y<4;y++)
				{
					for (int x=0;x<6;x++)
					{
						switch(bart->counter_gems[x][y])
						{
							case 1:
							{
								engine->Images->show(0,"bluegemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 3:
							{
								engine->Images->show(0,"greengemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 5:
							{
								engine->Images->show(0,"redgemsmall.png",fx2+(10*x),fy2);
								break;
							}
							case 7:
							{
								engine->Images->show(0,"yellowgemsmall.png",fx2+(10*x),fy2);
								break;
							}

 						}
				
					}	
					fy2+=10;				
				}
			}	
		} 

	}

	if (cpuslt )
	{
		//cpu select here
 		
		if (Has_Selected == false)
		{
			getrandchar = rand() % total_cpu;
			randchar = cpu_char[getrandchar];
			cpu_sel_count++;
			if (sound) engine->sound_system->play_sound(3,"select.wav");
					
		}
		switch (randchar)
		{
			case 0:
			{
				kitteh->Show_Personal_Pic(stage_char_box_x+10,stage_char_box_y);
				engine->Images->get_image(0,"kitteh_Bigheadshot.png")->Show_Flipped_Image(560,90,-1,-1,-1,-1);

				break;
			}
			case 1:
			{
				bart->Show_Personal_Pic(stage_char_box_x+10, stage_char_box_y);
				engine->Images->get_image(0,"bart_Bigheadshot.png")->Show_Flipped_Image(560,90,-1,-1,-1,-1);

				break;
			}
			case 2:
			{
				prinny->Show_Personal_Pic(stage_char_box_x+10, stage_char_box_y+20);
				engine->Images->get_image(0,"prinny_Bigheadshot.png")->Show_Flipped_Image(560,90,-1,-1,-1,-1);

				break;
			}
		}
		


		if (cpu_sel_count > 50 && Has_Selected == false)
		{
			if (sound) engine->sound_system->play_sound(4,"selected.wav");
			
			switch(randchar)
			{
				case 0:
				{		
					if (is_Single_Player) 
					{
						cpu->character = &kitteh;
						stage_char[current_stage-1] = 0;
					}
					break;
				}
				case 1:
				{
					if (is_Single_Player)
					{
						 cpu->character = &bart;
						 stage_char[current_stage-1] = 1;

					}
					break;
				}
				case 2:
				{
					if (is_Single_Player)
					{
						 cpu->character = &prinny;
						 stage_char[current_stage-1] = 2;

					}
					break;
				}
			}

			
		//	cpu_char[getrandchar];

			cpu_sel_count=0;
			Has_Selected = true;
		}
	}

	/* if both player has selected */
	if (Has_Paused == true && Has_Selected == true)
	{
	
		engine->Images->show(door_filename_ID,door_filename, door_L_x, door_L_y);
		engine->Images->show(door_filename_ID,door_filename, door_R_x, door_R_y);

		
	}		
	
}

int render_Cursors()
{
	/* show player 1 cursor */
	engine->Images->show(SC_ID,SC_Name,player1_curs_X,Select_Char_Box_y);	
	if (is_Single_Player == false)
	{
	/* show player 2 cursor */
		engine->Images->show(SC_ID,SC_Name,player2_curs_X,Select_Char_Box_y);
	}

}

int render_small_boxes()
{
	/*show the text "select your character" */
	engine->Texts->show_text(selchar_ID,selchar_code,selchar_text,selchar_x,selchar_y,0,0,0);
	/*small boxes */
	engine->Images->show(Select_Char_Box_ID,Select_Char_Box,Select_Char_Box_x,Select_Char_Box_y);
	engine->Images->show(Select_Char_Box_ID,Select_Char_Box,Select_Char_Box_x+Cursor_Move_Space,Select_Char_Box_y);
	engine->Images->show(Select_Char_Box_ID,Select_Char_Box,Select_Char_Box_x+Cursor_Move_Space*(total_boxes-1),Select_Char_Box_y);

}

int render_big_boxes()
{
	engine->Images->show(Select_Char_Big_Box_ID,Select_Char_Big_Box,Select_Char_Big_Box1_X,Select_Char_Big_Box_Y);
	engine->Images->show(Select_Char_Big_Box_ID,Select_Char_Big_Box,Select_Char_Big_Box2_X,Select_Char_Big_Box_Y);

}

int render_Chars_Per_Pic()
{
	kitteh->Show_Personal_Pic(Select_Char_Box_x,Select_Char_Box_y);
	bart->Show_Personal_Pic(Select_Char_Box_x+80, Select_Char_Box_y);
	prinny->Show_Personal_Pic(Select_Char_Box_x+170, Select_Char_Box_y+20);
}

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

int Character_Select_Logic()
{
	if ( (*Player1->is_right_key_pressed))
	{
		if (Player1_Has_Selected == false)
		{
			if (player1_curs_X == Cursor_Max_Right && secert == true)
			{
				if (sound) engine->sound_system->play_sound(3,"select.wav");
				player1_curs_X+=Cursor_Move_Space;	
			} else 
			if (player1_curs_X < Cursor_Max_Right)
			{ 
				if (sound) engine->sound_system->play_sound(3,"select.wav");
				player1_curs_X+=Cursor_Move_Space;
			}
		}
		(*Player1->is_right_key_pressed)=false;
	}
	
	if ((*Player1->is_left_key_pressed))
	{
		if (player1_curs_X != Cursor_Max_Left && Player1_Has_Selected == false)
		{
			if (sound) engine->sound_system->play_sound(3,"select.wav");
			player1_curs_X-=Cursor_Move_Space;
		}
		(*Player1->is_left_key_pressed) = false;
		
	}
	
	/* button is pressed to choose a player */
	if ((*Player1->is_Rotate_L_pressed) && Player1_Has_Selected == false)
	{
		if (Player1_selected_big_ID != 0)
		{ 
			if (sound) engine->sound_system->play_sound(4,"selected.wav");			
			Player1_Has_Selected = true;
			switch(Player1_selected_char_ID)
			{
				case 1:
				{		
					Player1->character = &kitteh;
					break;
				}
				case 2:
				{
					Player1->character = &bart;
					break;
				}
				case 3:
				{
					Player1->character = &prinny;
					break;
				}
				case 777:
				{
					Player1->character = &scott;
					break;
				}
			}
			
		}
		(*Player1->is_Rotate_L_pressed) = false;

	}

	if ((*Player2->is_Rotate_L_pressed) && Player2_Has_Selected == false)
	{
		if (Player2_selected_big_ID != 0)
		{
			Player2_Has_Selected = true;
			if (sound) engine->sound_system->play_sound(4,"selected.wav");	
			switch(Player2_selected_char_ID)
			{
				case 1:
				{
					Player2->character = &kitteh;
					break;
				}
				case 2:
				{
					Player2->character = &bart;
					break;
				}
				case 3:
				{
					Player2->character = &prinny;
					break;
				}
				case 777:
				{
					Player2->character = &scott;
					break;
				}
				
	
			}

		}
		(*Player2->is_Rotate_L_pressed) = false;
		
	}

	if (is_Single_Player == false)
	{
		if ((*Player2->is_right_key_pressed))
		{
			if (player2_curs_X == Cursor_Max_Right && secert == true)
			{
				if (sound) engine->sound_system->play_sound(3,"select.wav");
				player2_curs_X+=Cursor_Move_Space;
			} else
			if (player2_curs_X < Cursor_Max_Right)
			{
				if (sound) engine->sound_system->play_sound(3,"select.wav");				
				player2_curs_X+=Cursor_Move_Space;
			}

			(*Player2->is_right_key_pressed) = false;
		
		}

		if ((*Player2->is_left_key_pressed))
		{
			if (player2_curs_X != Cursor_Max_Left && Player2_Has_Selected == false)
			{
				if (sound) engine->sound_system->play_sound(3,"select.wav");				
				player2_curs_X-=Cursor_Move_Space;
			}
			(*Player2->is_left_key_pressed) = false;
		}
	}
	
	
	/* if Player 1 cursor is on the first character then render character Idle state*/
	if (player1_curs_X == Select_Char_Box_x )
	{
		strcpy(Player1_selected_big_name,Kitteh_Big_Personal_Filename);
		Player1_selected_big_ID=Kitteh_Big_Personal_ID;
		Player1_selected_char_ID = 1;
		
		if (Player1_Has_Selected)
		{
			kitteh->Win1_Animate(100,449);
		} else {
			kitteh->Idle_Animate(100,450);
		}
	} else 
	if (player1_curs_X == Select_Char_Box_x+Cursor_Move_Space)
	{
		strcpy(Player1_selected_big_name,"bart_Bigheadshot.png");
		Player1_selected_big_ID=2;
		Player1_selected_char_ID = 2;
		
		if (Player1_Has_Selected)
		{
			bart->Win1_Animate(100,450);
		} else {
			bart->Idle_Animate(100,500);
		}

	} else 
	if (player1_curs_X == 446)
	{
		strcpy(Player1_selected_big_name,"prinny_Bigheadshot.png");
		Player1_selected_big_ID=3;
		Player1_selected_char_ID = 3;
		
		if (Player1_Has_Selected)
		{
			prinny->Win1_Animate(100,450);
		} else {
			prinny->Idle_Animate(100,500);
		}
		
	} else 
	if (player1_curs_X == 528)
	{
		strcpy(Player1_selected_big_name,"scott-headshot.png");
		Player1_selected_big_ID=777;
		Player1_selected_char_ID = 777;
		
		if (Player1_Has_Selected)
		{
			scott->Win1_Animate(100,450);
		//	engine->Images->show(0,"scott_win.png",100,450,122,0,122,86);

		} else {
			scott->Idle_Animate(100,500);
		}
	
	} else {
	//	printf("%i\n",player1_curs_X);
		strcpy(Player1_selected_big_name," ");
		Player1_selected_big_ID=0;
		Player1_selected_char_ID=0;
	}

	/* if Player 2 cursor is on the first character then render character Idle state*/
	if (player2_curs_X == Select_Char_Box_x && is_Single_Player == false)
	{
		strcpy(Player2_selected_big_name,Kitteh_Big_Personal_Filename);
		Player2_selected_big_ID=Kitteh_Big_Personal_ID;
		if (Player2_Has_Selected)
		{
			kitteh->Win1_Animate2(650,449);
		} else {
			kitteh->Idle_Animate_Flip(650,450);
		}
		Player2_selected_char_ID=1;
	} else 
	if (player2_curs_X == Select_Char_Box_x+Cursor_Move_Space && is_Single_Player == false)
	{
		Player2_selected_big_ID=Kitteh_Big_Personal_ID;

		strcpy(Player2_selected_big_name,"bart_Bigheadshot.png");
		
		if (Player2_Has_Selected)
		{
			bart->Win1_Animate2(650,449);
		} else {
			bart->Idle_Animate_Flip(650,450);
		}
		Player2_selected_char_ID=2;

	} else 
	if (player2_curs_X == 446 && is_Single_Player == false)
	{
		Player2_selected_big_ID=Kitteh_Big_Personal_ID;

		strcpy(Player2_selected_big_name,"prinny_Bigheadshot.png");
		
		if (Player2_Has_Selected)
		{
			prinny->Win1_Animate2(650,449);
		} else {
			prinny->Idle_Animate_Flip(650,450);
		}
		Player2_selected_char_ID=3;
	
	} else 
	if (player2_curs_X == 528 && is_Single_Player == false)
	{
		Player2_selected_big_ID=777;

		strcpy(Player2_selected_big_name,"scott-headshot.png");
		
		if (Player2_Has_Selected)
		{
			scott->Win1_Animate2(650,449);
		} else {
			scott->Idle_Animate_Flip(650,450);
		}
		Player2_selected_char_ID=777;
	
	} else {
		strcpy(Player2_selected_big_name," ");
		Player2_selected_big_ID=0;
		Player2_selected_char_ID=0;
	}




	/*check if player's has selected a character or not*/
	if (is_Single_Player == false && Has_Paused==false)
	{
		if (Player1_Has_Selected && Player2_Has_Selected)
		{
			Has_Selected = true;
		}
	} else {
		if (Player1_Has_Selected && Has_Paused==false)
		{
		//	Has_Selected = true;
			cpuslt=true;
		}
	}	

	

	if (Has_Selected == true && Has_Paused==false)
	{
		if (engine->frame % 2)
		{
			pause_time++;
			if (pause_time == 30)
			{
				if (music) engine->sound_system->stop_music("charsel.mp3");
				if (music) engine->sound_system->play_music(0,"vs.mp3",2);
				pause_time=0;
				Has_Paused = true;
			}
		}


	}

	/*go to the VS screen*/
	if (Has_Paused == true && Has_Selected == true)		
	{
		animate_door();
		if (door_L_x == 0)
		{
			if (is_Single_Player && cpuslt) cpuslt=false; 
			game_mode = VS_SCREEN;	
			
		}
	}

	


}

void animate_door()
{
	if (engine->frame % 2)
	{
		if (door_L_x != 0)
		{
			door_L_x+=25;
			door_R_x-=25;
		}
	}
}


