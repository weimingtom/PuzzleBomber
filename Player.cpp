#include "Player.h"

enum moods { IDLE,ATTACK, HURT };

Player::Player()
{
	
	rotation_padding = 0;
	drop_block_y=-64;
	drop_block_x=0;
	special_pause = false;
	specialp = false;
	wins=0;
	total_chains=0;
	total_big_gems=0;
	rotate=0;
	chain_timer=0;
	ischain=false;
	chain=0;
	big_gem=0;
	bp_count=0;
	tph_y=0;
	bph_y=-40;
	bph_x=64;
	tph_x=64;
	tph_y=bph_y - 32;
	Mood=0;
	top_block = -1;
	bottom_block = -1;
	score=0;
	is_left_key_pressed=NULL;	
	is_right_key_pressed=NULL;
	is_Rotate_L_pressed=NULL;
	is_Rotate_R_pressed=NULL;

	is_left_key_down=NULL;	
	is_right_key_down=NULL;



	clear_field();
	List=NULL;
	gem_pause = 0;
	drop_gem_pause = 0;
	did_brake=false;
	can_move_up=true;
	can_rot_left=true;
	can_rot_right=true;
	block_speed=0;
	gem_broke=0;
	pending_blocks = 0;
	nextblocknum=0;
	gaugebar=0;
	for (int i=0; i < 6; i++)
	{
		for (int j=0;j<12;j++)
		{
			 explodemap[i][j] = -1;
		}
	}
}

bool Player::PushRight()
{
	Set_Right_Key_Status(true);
	
	switch (rotate)
	{
		case NORMAL:
		{
			if (is_top_of_field())
			{
				Set_Right_Key_Status(false);
				break;
			}
				
			if (
			!is_Field_Block_Empty(top_block_x+1, top_block_y)
			||						
			!is_Field_Block_Empty(bottom_block_x+1, bottom_block_y)
			)
			{
				Set_Right_Key_Status(false);
				break;
			}
				

				if (is_Hit_Wall_Right( top_block_x)) Set_Right_Key_Status(false);
				break;
			}
			case LEFTSIDE_DOWN:
			{
				if (
				!is_Field_Block_Empty(bottom_block_x+1, bottom_block_y)
				)
				{
					Set_Right_Key_Status(false);
					break;
				}

				if (is_Hit_Wall_Right(bottom_block_x)) Set_Right_Key_Status(false);
				break;
			}
			case UPSIDE_DOWN:
			{
				if (
				!is_Field_Block_Empty(top_block_x+1, top_block_y)
				||						
				!is_Field_Block_Empty(bottom_block_x+1, bottom_block_y)
				)
				{
					Set_Right_Key_Status(false);
					break;
				}

				if (is_Hit_Wall_Right(top_block_x)) Set_Right_Key_Status(false);
				break;
			}
			case RIGHTSIDE_UP:
			{
				if (
				!is_Field_Block_Empty(top_block_x+1, top_block_y)
				)
				{
					Set_Right_Key_Status(false);
					break;
				}

				if (is_Hit_Wall_Right(top_block_x)) Set_Right_Key_Status(false);

				break;
			}
		}

		if (Get_Right_Key_Status()) Move_Block_Right();
		if (is_right_key_pressed != NULL)
		{
			if ((*is_right_key_pressed) == true)
			{
				(*is_right_key_pressed) = true;
			//	(*(*player)->is_right_key_down) = false;
			} else {
				(*is_right_key_down) = true;
		//	(*(*player)->is_right_key_pressed) = false;

			}
		}

}

bool Player::PushLeft()
{
	Set_Left_Key_Status(true);

	switch (Get_Current_Rotation())
	{
		case NORMAL:
		{
						
			if (is_top_of_field())				
			{
				Set_Left_Key_Status(false);
				return false;
			}
			if (
			!is_Field_Block_Empty(top_block_x-1,top_block_y)
			||						
			!is_Field_Block_Empty(bottom_block_x-1, bottom_block_y)
			)
			{
				Set_Left_Key_Status(false);
				break;
			}
			if (is_Hit_Wall_Left(top_block_x)) Set_Left_Key_Status(false);
			break;
		}
		case LEFTSIDE_DOWN:
		{
			if (is_block_on_top( top_block_x, top_block_y))
			{
				Set_Left_Key_Status(false);
				break;
			}
			if (
			!is_Field_Block_Empty(top_block_x-1, top_block_y)
			)
			{
				Set_Left_Key_Status(false);
				break;
			}
			break;
		}
		case UPSIDE_DOWN:
		{
			if (
			!is_Field_Block_Empty(top_block_x-1, top_block_y)
			||						
			!is_Field_Block_Empty(bottom_block_x-1, bottom_block_y)
			)
			{
				Set_Left_Key_Status(false);
				break;
			}
			break;
		}
		case RIGHTSIDE_UP:
		{
			if (
			!is_Field_Block_Empty(bottom_block_x-1, bottom_block_y)
			)
			{
				Set_Left_Key_Status(false);
				break;
			}

			break;
		}
	}

	if (Get_Left_Key_Status()) Move_Block_Left();	
	
	if (is_left_key_pressed != NULL)
	{
		if ((*is_left_key_pressed) == true)
		{
			(*is_left_key_pressed) = true;
		} else {
			(*is_left_key_down) = true;
		}
	}
	return true;		
}

bool Player::PushDown()
{
	switch (Get_Current_Rotation())
	{
		case NORMAL:
		{
			if (is_Field_bottom(bottom_block_y))
			{
				break;				
			}	
			if (
			is_Field_Block_Empty(bottom_block_x, bottom_block_y+1)
			)
			{
				for (int i=0;i<4;i++)
				{
					Drop_Block();
				}
				break;			
			}	
			break;
		}
		case LEFTSIDE_DOWN:
		{
			if (
			(
			is_Field_bottom(bottom_block_y) 
				
			)
			)
			{
				for (int i=0;i<4;i++)
				{
					Drop_Block();
				}
				break;
			}
			if (
			is_Field_Block_Empty(bottom_block_x,bottom_block_y+1)
			&&
			is_Field_Block_Empty(top_block_x,top_block_y+1)
			)
			{
				for (int i=0;i<4;i++)
				{
					Drop_Block();
				}
				break;
			}
			break;
		}
		case UPSIDE_DOWN:
		{
			if (is_Field_bottom(top_block_y) ) 
			{
				break;			
			}	
			if 
			(
			is_Field_Block_Empty(top_block_x,top_block_y+1)
			) 
			{
				for (int i=0;i<4;i++)
				{
					Drop_Block();
				}		
			}	
			break;
		}
		case RIGHTSIDE_UP:
		{

			if ( is_Field_bottom(bottom_block_y) )
			{
				break;
			}

			if (
			(
			is_Field_Block_Empty(bottom_block_x,bottom_block_y+1)
			&&
			is_Field_Block_Empty(top_block_x, top_block_y+1)
			)		
			)
			{
				for (int i=0;i<4;i++)
				{
					Drop_Block();
				}
				break;
			}

			break;
		}
	}
}	

bool Player::PullDown()
{
	switch(Get_Current_Rotation())
	{
		case NORMAL:
		{
			if (is_Field_Block_Empty(bottom_block_x, 12-1))
				{		
					Set_Block(12-1);
					break;
				}
				/*go thoughs the fields*/
				for (int i=0;i<12;i++)
				{
					/*check for an unempty spot*/
					if 
					(
					!is_Field_Block_Empty(bottom_block_x,i+1)
					&& 
					i != 12-1
					)
					{
						Set_Block(i);
						break;
					}

				}
				break;
			}
			case LEFTSIDE_DOWN:
			{
				if (
				is_Field_Block_Empty(bottom_block_x,12-1)
				&&
				is_Field_Block_Empty(top_block_x,12-1)
				)
				{
					Set_Block(12-1);
					break;
				}
						
				for (int i=0;i<12;i++)
				{
					if (
					!is_Field_Block_Empty(bottom_block_x,i+1)
					||
					!is_Field_Block_Empty(top_block_x,i+1)
					)
					{
						Set_Block(i);
						break;
	
					}
				
				}
				(*is_up_key_pressed) = false;
				break;
			}
			case UPSIDE_DOWN:
			{
				if (
				top_block_y != 11
				&&
				is_Field_Block_Empty(top_block_x,12-1)
				&&
				is_Field_Block_Empty(top_block_x,12-2)
				)
				{	
						
					Set_Block(12-2);
					break;
				}
				for (int i=0;i<12;i++)
				{
					if (
					!is_Field_Block_Empty(top_block_x,i+1)
					)
					{
						Set_Block(i-1);
						break;
					}

				}
				break;
			}
			case RIGHTSIDE_UP:
			{
				bool foundempty=false;
				for (int i=0;i<12;i++)
				{
					if (
					!is_Field_Block_Empty(bottom_block_x, i+1)
					)
					{
						foundempty=true;
						Set_Block(  i);	
						break;
	
					}
					if(
					!is_Field_Block_Empty(top_block_x, i+1)
					)
					{
						foundempty=true;
						Set_Block( i);
						break;
					}
				}
				if (
				
				is_Field_Block_Empty(bottom_block_x,12-1) 
				&& 
				is_Field_Block_Empty(top_block_x,12-1)
				&&
				foundempty == false
				)
				{
					Set_Block(12-1);
					break;
				}

				break;
			}

		}
		(*is_up_key_pressed) = false;

}

bool Player::Rotate_Block_Right(Engine** engine)
{
	Set_Right_Rotation_Status(true);

		switch (Get_Current_Rotation())
		{
			case NORMAL:
			{
				if (!is_Field_Block_Empty(bottom_block_x+1, bottom_block_y+1))
				{
					if ((*engine)->check_collision( (32*(top_block_x)),drop_block_y+32,(top_block_x+1) * 32,(drop_block_y)*32) == false)
					{
						Set_Right_Rotation_Status(false);
						break;

					}
				}else	
				if (
				!is_Field_Block_Empty(bottom_block_x+1, bottom_block_y)
				||
				!is_Field_Block_Empty( top_block_x+1, top_block_y)
				)
				{
					Set_Right_Rotation_Status(false);
					break;
				}
				if (is_Hit_Wall_Right( bottom_block_x ))
				{
					Set_Right_Rotation_Status(false);
					break;
				}
				break;
			}
			case LEFTSIDE_DOWN:
			{
				if (!is_Field_Block_Empty(bottom_block_x-1, bottom_block_y-1))
				{
					if ((*engine)->check_collision( 32*(top_block_x),drop_block_y-32,top_block_x-1 * 32, drop_block_y*32 ) == false)
					{
						Set_Right_Rotation_Status(false);
						break;

					}

				} else
				if (
				!is_Field_Block_Empty(bottom_block_x, bottom_block_y+1)
				&&
				!is_Field_Block_Empty(top_block_x, top_block_y+1)
				)
				{
					Set_Right_Rotation_Status(false);
					break;
				}
				break;
			}
			case UPSIDE_DOWN:
			{

				if (!is_Field_Block_Empty(top_block_x-1, top_block_y))
				{
				
					if ((*engine)->check_collision( (32*(top_block_x)),drop_block_y,(top_block_x-1) * 32,(drop_block_y)*32) == false)
					{
						Set_Right_Rotation_Status(false);
						break;

					}
				}else	

				if (is_Hit_Wall_Left(bottom_block_x))
				{
					Set_Right_Rotation_Status(false);
					break;
				}
				if (
				!is_Field_Block_Empty(top_block_x-1, top_block_y)
				||
				!is_Field_Block_Empty(bottom_block_x-1,bottom_block_y)
				)
				{
					Set_Right_Rotation_Status(false);
					break;
				}
				break;
			}
			case RIGHTSIDE_UP:
			{
				if (is_Field_bottom(bottom_block_y))
				{
					Set_Right_Rotation_Status(false);
					break;
				}

				if (
				!is_Field_Block_Empty(bottom_block_x, bottom_block_y+1)
				||
				!is_Field_Block_Empty(top_block_x, top_block_y+1)
				)
				{
					Set_Right_Rotation_Status(false);
					break;
				}
				break;
			}
				
		}

		if (Get_Current_Rotation() == NORMAL) 	
		{
			if (Get_Right_Rotation_Status()) Change_Rotation(RIGHTSIDE_UP);
		} else {
			if (Get_Right_Rotation_Status()) Rotate_Right();
		}

		(*is_Rotate_R_pressed) = false;

}

bool Player::Rotate_Block_Left()
{
	Set_Left_Rotation_Status(true);
	switch (Get_Current_Rotation())
	{
		case NORMAL:
		{
			if (is_top_of_field())
			{
				Set_Left_Rotation_Status(false);
				break;
			}

			if (
			!is_Field_Block_Empty(bottom_block_x-1, bottom_block_y)
			&&
				!is_Field_Block_Empty(top_block_x-1, top_block_y)
				)
				{
					Set_Left_Rotation_Status(false);
					break;
				} 
				if (top_block_x==0) can_rot_left = false;
		
				break;
			}
			case LEFTSIDE_DOWN:
			{
				if (
				!is_Field_Block_Empty(bottom_block_x, bottom_block_y+1)
				||
				!is_Field_Block_Empty(top_block_x, top_block_y+1)
				)
				{

					Set_Left_Rotation_Status(false);
					break;
				}
				if (is_Field_bottom(bottom_block_y)) Set_Left_Rotation_Status(false);
				break;
			}
			case UPSIDE_DOWN:
			{
				if (!is_Field_Block_Empty(top_block_x+1, top_block_y))
				{
					Set_Left_Rotation_Status(false);
					break;
				}

				if (!is_Field_Block_Empty(bottom_block_x+1, bottom_block_y))
				{
					Set_Left_Rotation_Status(false);
					break;
				}

				if (is_Hit_Wall_Right(top_block_x)) Set_Left_Rotation_Status(false);
				break;
			}
			case RIGHTSIDE_UP:
			{
				if (
				!is_Field_Block_Empty(bottom_block_x, bottom_block_y-1)
				||
				!is_Field_Block_Empty(top_block_x, top_block_y-1)		
				)
				{
					Set_Left_Rotation_Status(false);
					break;
				}
				break;
			}
		}
		if (Get_Current_Rotation() == RIGHTSIDE_UP) 	
		{
			if (Get_Left_Rotation_Status()) Change_Rotation( NORMAL);
		} else {
			if (Get_Left_Rotation_Status()) Rotate_Left();
		}
		(*is_Rotate_L_pressed) = false;

}



bool Player::is_top_of_field()
{
       
	if ( 
		(
		top_block_x == 2 
		|| 
		top_block_x == 3
		) 
		&& 
		(
		top_block_y == -1 
		|| 
		top_block_y == -2
		)
	||
	
	(
		(
		bottom_block_x == 2 
		|| 
		bottom_block_x == 3
		) 
		&& 
		bottom_block_y == -2
		)
	) return true;

	return false;
}


int Player::is_Hit_Wall_Left(int x)
{
	return (x == 0);
	
}

int Player::is_Hit_Wall_Right(int x)
{
	if ( (x == 6-1)) return true;
	return false;
}



bool Player::is_block_on_top(int x, int y)
{
	if ( (x == 2 && y == -2) || (x==0)) return true;
	return false;
}

bool Player::is_Field_Block_Empty(int x, int y)
{
	if ( field[x][y].color == -1) return true;
	return false;
}

bool Player::is_Field_bottom(int y)
{
	if (y == 12-1) return true;
	return false;
}


int Player::Drop_Block()
{
	drop_block_y+=2;
	if ( ( drop_block_y % 32)== 0)
	{
		bottom_block_y++;
	}
}

int Player::reset_checks()
{
	for (int i=0;i< 12;i++)
	{
		for (int j=0;j<6;j++)
		{
			field[j][i].checked = false;
		}
	}	
}

int Player::Move_Block_Left()
{
	bottom_block_x -=1;
}

int Player::Move_Block_Right()
{
	bottom_block_x +=1;
}

int Player::Animate_Mood2()
{
	switch(Mood)
	{
		case IDLED:
		{
			(*character)->Idle_Animate_Flip((*character)->Intro_Flip_X,(*character)->Intro_Flip_Y);
			break;
		}
		case ATTACKED:
		{
			if ((*character)->Attack_Animate_F((*character)->Intro_Flip_X,(*character)->Intro_Flip_Y))
			{
				Mood = IDLED;
			}
			break;
		}
		case HURTED:
		{
			if ((*character)->Hurt_Animate_F((*character)->Intro_Flip_X,(*character)->Intro_Flip_Y))
			{
				Mood = IDLED;
			}
			break;
		}
	}

}

int Player::Animate_Mood()
{
	switch(Mood)
	{
		case IDLE:
		{
			(*character)->Idle_Animate((*character)->Intro_X,(*character)->Intro_Y);
			break;
		}
		case ATTACK:
		{
			if ((*character)->Attack_Animate((*character)->Attack_X,(*character)->Attack_Y))
			{
				Mood = IDLE;
			}
			break;
		}
		case HURT:
		{
			if ((*character)->Hurt_Animate((*character)->Intro_X,(*character)->Intro_Y))
			{
				Mood = IDLE;
			}
			break;
		}
	}
}

int Player::reset_keys()
{

	*is_up_key_pressed = false;
	*is_down_key_pressed = false;
	*is_right_key_pressed = false;
	*is_left_key_pressed = false;
	*is_right_key_down = false;
	*is_left_key_down = false;



	*is_Rotate_R_pressed = false;
	*is_Rotate_L_pressed = false;
}

int Player::clear_field()
{
	for (int i=0;i<6;i++)
	{
		for (int j=0;j<12;j++)
		{
			field[i][j].color = -1;
			field[i][j].is_solid = false;
			field[i][j].is_bomb = false;
			field[i][j].bomb_timer = 0;
		}
	}

}

int Player::Change_Players_Mode(int newmode)
{
	logic = newmode;
}

bool Player::is_Block_Speed(int speed2check)
{
	return block_speed == speed2check;
}

int Player::Get_Current_Rotation()
{
	return rotate;
}

int Player::Change_Rotation(int state)
{
	rotate = state;
}

int Player::Rotate_Right()
{
	rotate--;
}

int Player::Rotate_Left()
{
	rotate++;
}

int Player::Set_Right_Key_Status(bool newstatus)
{
	can_move_right = newstatus;
}

int Player::Set_Left_Key_Status(bool newstatus)
{
	can_move_left = newstatus;
}


int Player::Set_Right_Rotation_Status(bool newstatus)
{
	can_rot_right = newstatus;
}

int Player::Set_Left_Rotation_Status(bool newstatus)
{
	can_rot_left = newstatus;
}

bool Player::Get_Right_Rotation_Status()
{
	return can_rot_right;
}

bool Player::Get_Left_Rotation_Status()
{
	return can_rot_left;
}

bool Player::Get_Left_Key_Status()
{
	return can_move_left;
}

bool Player::Get_Right_Key_Status()
{
	return can_move_right;
}

bool Player::is_not_on_top(int y)
{
	return (y > -1); 
}

int Player::Set_Block_Color(int x, int y, int color)
{
	field[x][y].color = color;
}

int Player::Reset_Dropping_Block()
{
	top_block = -1;
	bottom_block = -1;
	drop_block_y=-64;

}
int Player::reset_drop_field()
{
	for (int i=0;i< 12;i++)
	{
		for (int j=0;j<6;j++)
		{
			field[j][i].can_drop = true;
			field[j][i].checked = false;
		}
	}
}	

int Player::Set_Block(int y)
{
	bottom_block_y = y;
}


void CPU::Start_AI(int diff)
{
	switch(diff)
	{
		case easy:
		{
			Easy_Mode();
			break;
		}
		break;
	}
}
/*
int CPU::Animate_Mood()
{
	switch(Mood)
	{
		case IDLED:
		{
			(*character)->Idle_Animate_Flip((*character)->Intro_Flip_X,(*character)->Intro_Flip_Y);
			break;
		}
		case ATTACKED:
		{
			if ((*character)->Attack_Animate_F((*character)->Attack_X_F,(*character)->Attack_Y_F))
			{
				Mood = IDLED;
			}
			break;
		}
		case HURTED:
		{
			if ((*character)->Hurt_Animate_F((*character)->Intro_Flip_X,(*character)->Intro_Flip_Y))
			{
				Mood = IDLED;
			}
			break;
		}
	}

}
*/
/*
int CPU::Anime_Mood_CPU()
{
	switch(Mood)
	{
		case IDLED:
		{
			(*character)->Idle_Animate_Flip((*character)->Intro_Flip_X,(*character)->Intro_Flip_Y);
			break;
		}
		case ATTACKED:
		{
			if ((*character)->Attack_Animate_F((*character)->Attack_X_F,(*character)->Attack_Y_F))
			{
				Mood = IDLED;
			}
			break;
		}
		case HURTED:
		{
			if ((*character)->Hurt_Animate_F((*character)->Intro_Flip_X,(*character)->Intro_Flip_Y))
			{
				Mood = IDLED;
			}
			break;
		}
	}

}
*/

bool CPU::check_left_field()
{
	int count=0;
	for (int i=0;i<12;i++)
	{
		for (int j=0;j < 2; j++)
		{
			if (field[j][i].color != -1)
			{
				count++;
			}
		}
	}

	if (count > 22) return true;
	return false;
}

bool CPU::check_right_field()
{
	int count=0;
	for (int i=0;i<12;i++)
	{
		if (field[4][i].color != -1 || field[5][i].color != -1)
		{
				count++;
		}
	}

	if (count > 22) return true;
	return false;
}



void CPU::Easy_Mode()
{	
	if (check_left_field())
	{
		if (check_right_field())
		{
					
		} else {
			PushRight();
		}
	} else {
		PushLeft();
	}			
}

CPU::CPU()
{
	is_left_key_pressed = NULL;
	is_right_key_pressed=NULL;
}
