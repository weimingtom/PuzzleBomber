#include "Character.h"
#include "stage.h"
#include <string.h>



Character::Character(Engine** engine)
{
	Intro_Flip_Current_Sprite=0;
	TheEngine = engine;
	myStage = new stage(engine);
	isintrodone = false;
	isintrodone2 = false;
	for (int i=0;i<6;i++)
	{
		for (int j=0;j<4;j++)
		{
			counter_gems[i][j] = -1;
		}
	}
	Mood=0;
}

int Character::Load_Big_Personal_Flip()
{
	(*TheEngine)->Images->get_image(Personal_Big_ID,Personal_Big_Filename)->Create_Flip_Image();
}

int Character::Load_Idle_Flip()
{
	(*TheEngine)->Images->get_image(Idle_Pic_ID, Idle_Pic_Filename)->Create_Flip_Image();
	
}

int Character::Show_Big_Personal_Flip(int x, int y)
{
	(*TheEngine)->Images->get_image(Personal_Big_ID,Personal_Big_Filename)->Show_Flipped_Image(x, y, -1, -1, -1, -1);	
}

int Character::Load_Big_Personal(char* filename, void* data=NULL, int size=0)
{
	if (data != NULL)
	{
		(*TheEngine)->Images->create_image(filename, data,size);
	} else {
		(*TheEngine)->Images->create_image(filename);
	}
	strcpy(Personal_Big_Filename,filename);
	Load_Big_Personal_Flip();
	
}

int Character::Show_Big_Personal(int x, int y)
{
	Show(Personal_Big_Filename, Personal_Big_ID,x,y);
}

int Character::Load_Personal_Pic(char* filename,void* data=NULL, int size=0)
{
	if (data == NULL)
	{
		(*TheEngine)->Images->create_image(filename);
	} else {
		(*TheEngine)->Images->create_image(filename,data,size);
	}
	strcpy(Personal_Pic_Filename,filename);

}

int Character::Show_Personal_Pic(int x, int y)
{
	Show(Personal_Pic_Filename, Personal_Pic_ID,x,y);
}

int Character::Show(char* filename, int pID,int x, int y)
{
	(*TheEngine)->Images->show(pID,filename,x,y);
}

int Character::Load_Idle_Pic(char* filename,void *data=NULL, int size=0)
{
	if (data != NULL)
	{
		(*TheEngine)->Images->create_image(filename,data,size);
		strcpy(Idle_Pic_Filename,filename);
		Load_Idle_Flip();

	} else {
		(*TheEngine)->Images->create_image(filename);
		strcpy(Idle_Pic_Filename,filename);
		Load_Idle_Flip();
	}

}

int Character::Idle_Animate(int x, int y)
{
	if ((*TheEngine)->frame % 2)
	{
		current_Idle_sprite+=1;

		if (current_Idle_sprite == num_of_Idle_sprite)
		{
			current_Idle_sprite=0;
		}
	}
}

int Character::Idle_Animate_Flip(int x, int y)
{
	
	if ((*TheEngine)->frame % 2)
	{
		current_Idle_sprite2+=1;

		if (current_Idle_sprite2 == num_of_Idle_sprite)
		{
			current_Idle_sprite2=0;
		}
	}

}

int Character::Load_Win1(char* filename, void* data=NULL, int size=0)
{
	if (data==NULL)
	{
		(*TheEngine)->Images->create_image(filename);
	} else {
		(*TheEngine)->Images->create_image(filename,data,size);
	}
	strcpy(Load_Win1_Filename,filename);
	
}

int Character::Win1_Animate(int x,int y)
{
	(*TheEngine)->Images->show(Win1_ID,Load_Win1_Filename,x,y,current_Win1_sprite_1*Win1_Sprite_Width,0,Win1_Sprite_Width,Win1_Sprite_Height);
	if ((*TheEngine)->frame % 2)
	{
		current_Win1_sprite_1+=1;

		if (current_Win1_sprite_1 == num_of_win1_sprite)
		{
			current_Win1_sprite_1=0;
		}
	}

}

int Character::Win1_Animate2(int x,int y)
{
	(*TheEngine)->Images->show(Win1_ID,Load_Win1_Filename,x,y,current_Win1_sprite_2*Win1_Sprite_Width,0,Win1_Sprite_Width,Win1_Sprite_Height);
	if ((*TheEngine)->frame % 2)
	{
		current_Win1_sprite_2+=1;

		if (current_Win1_sprite_2 == num_of_win1_sprite)
		{
			current_Win1_sprite_2=0;
		}
	}

}

int Character::Load_Intro(char* filename, void* data=NULL, int size=0)
{
	if (data == NULL)
	{
		(*TheEngine)->Images->create_image(filename);
	} else {
		(*TheEngine)->Images->create_image(filename,data,size);
	}
	strcpy(Intro_Filename,filename);
	Load_Intro_Flip();
	
}

int Character::Load_Intro_Flip()
{
	(*TheEngine)->Images->get_image(Intro_ID, Intro_Filename)->Create_Flip_Image();
	
}

int Character::Intro_Animate_Render()
{
	(*TheEngine)->Images->show(Intro_ID,Intro_Filename,Intro_X,Intro_Y,Intro_Current_Sprite*Intro_Sprite_Width,0,Intro_Sprite_Width,Intro_Sprite_Height);
	
}


int Character::Intro_Animate_Flip_Render()
{
	(*TheEngine)->Images->get_image(Intro_ID, Intro_Filename)->Show_Flipped_Image(Intro_Flip_X,Intro_Flip_Y,Intro_Flip_Current_Sprite*Intro_Sprite_Width,0,Intro_Sprite_Width,Intro_Sprite_Height);
	
}


int Character::Intro_Animate()
{
	if (Intro_Current_Sprite == Intro_Sprite_Num)
	{
		isintrodone = true;
	} else {
		Intro_Current_Sprite+=1;
	}
	if (Intro_Move == true)
	{
		if (Intro_X > Intro_Stop_X_Spot && Intro_Stop_At == X_SPOT )
		{
			isintrodone = true;
			return 0;
		} else	
		if (Intro_Current_Sprite == Intro_Sprite_Num)
		{
			Intro_Current_Sprite=0;
		}

			
		if ((*TheEngine)->frame % 2 && isintrodone == false)
		{

			if (Intro_Current_Sprite % 3 == 0 )
			{
				if (Intro_X > Intro_Stop_X_Spot && Intro_Stop_At == X_SPOT )
				{
					isintrodone = true;
					return 0;
				}		
				Intro_X+=20;
		
			}	
		}
	}
}

int Character::Intro_Animate_Flip()
{

	if (Intro_Flip_Current_Sprite == Intro_Sprite_Num)
	{
		isintrodone2 = true;
	} else {
		Intro_Flip_Current_Sprite+=1;
	}

	if (Intro_Move2 == true)
	{

		if (Intro_Flip_X < Intro_Flip_Stop_X_Spot && Intro_Flip_Stop_At == X_SPOT ) 
		{
			isintrodone2 = true;
			return 0;
		} else 
		if (Intro_Flip_Current_Sprite == Intro_Sprite_Num)
		{
			Intro_Flip_Current_Sprite=0;
		} 

		if ((*TheEngine)->frame % 2 && isintrodone2 == false)
		{
			if (Intro_Flip_Current_Sprite % 3 == 0 )
			{	
				if (Intro_Flip_X < Intro_Flip_Stop_X_Spot && Intro_Flip_Stop_At == X_SPOT ) 
				{
					isintrodone2 = true;
					return 0;
				}		
				Intro_Flip_X-=20;
			}
		}
	}
}

int Character::Idle_Animate_Render(int x, int y)
{
	(*TheEngine)->Images->show(Idle_Pic_ID,Idle_Pic_Filename,x,y,current_Idle_sprite*Idle_Sprite_Width,0,Idle_Sprite_Width,Idle_Sprite_Height);
}

int Character::Idle_Animate_Flip_Render(int x, int y)
{
	(*TheEngine)->Images->get_image(Idle_Pic_ID,Idle_Pic_Filename)->Show_Flipped_Image(x,y,current_Idle_sprite2*Idle_Sprite_Width,0,Idle_Sprite_Width,Idle_Sprite_Height);

}


void Character::Load_Attack(char* filename,void* data=NULL, int size=0)
{
	if (data == NULL)
	{
		(*TheEngine)->Images->create_image(filename);
	} else {
		(*TheEngine)->Images->create_image(filename,data,size);
	}
	strcpy(Attack_Filename,filename);
	Load_Attack_Flip();
	
}

void Character::Load_Attack_Flip()
{
	(*TheEngine)->Images->get_image(0, Attack_Filename)->Create_Flip_Image();

}

void Character::Attack_Animate_Render(int x, int y)
{
	(*TheEngine)->Images->show(0,Attack_Filename,x,y,Attack_Current_Sprite*Attack_Sprite_Width,0,Attack_Sprite_Width,Attack_Sprite_Height);
}


void Character::Attack_Animate_Flip_Render(int x, int y)
{
	(*TheEngine)->Images->get_image(0,Attack_Filename)->Show_Flipped_Image(x,y,Attack_Current_Sprite_F*Attack_Sprite_Width,0,Attack_Sprite_Width,Attack_Sprite_Height);

}


bool Character::Attack_Animate(int x,int y)
{
	if ((*TheEngine)->frame % 2)
	{
		Attack_Current_Sprite+=1;

		if (Attack_Current_Sprite == Attack_Sprite_Num)
		{
			Attack_Current_Sprite=0;
			return true;
		}
	}
	return false;
}

bool Character::Attack_Animate_F(int x,int y)
{
	if ((*TheEngine)->frame % 2)
	{
		Attack_Current_Sprite_F+=1;

		if (Attack_Current_Sprite_F == Attack_Sprite_Num)
		{
			Attack_Current_Sprite_F=0;
			return true;
		}
	}
	return false;
}


void Character::Load_Hurt(char* filename, void* data=NULL, int size=0)
{
	if (data == NULL)
	{
		(*TheEngine)->Images->create_image(filename);
	} else {
		(*TheEngine)->Images->create_image(filename,data,size);
	}
	strcpy(Hurt_Filename,filename);
	Load_Hurt_Flip();

}

void Character::Load_Hurt_Data(int total, int width, int height)
{
	Hurt_Current_Sprite=0;
	Hurt_Sprite_Num=total;
	Hurt_Sprite_Width=width;
	Hurt_Sprite_Height=height;
	Hurt_Current_Sprite_F=0;

}


void Character::Load_Hurt_Flip()
{
	(*TheEngine)->Images->get_image(0, Hurt_Filename)->Create_Flip_Image();

}


void Character::Hurt_Animate_Render(int x, int y)
{
	(*TheEngine)->Images->show(0,Hurt_Filename,x,y,Hurt_Current_Sprite*Hurt_Sprite_Width,0,Hurt_Sprite_Width,Hurt_Sprite_Height);
}


bool Character::Hurt_Animate(int x,int y)
{
	if ((*TheEngine)->frame % 2)
	{
		Hurt_Current_Sprite+=1;

		if (Hurt_Current_Sprite == Hurt_Sprite_Num)
		{
			Hurt_Current_Sprite=0;
			return true;
		}
	}
	return false;
}

bool Character::Hurt_Animate_F(int x,int y)
{
	if ((*TheEngine)->frame % 2)
	{
		Hurt_Current_Sprite_F+=1;

		if (Hurt_Current_Sprite_F == Hurt_Sprite_Num)
		{
			Hurt_Current_Sprite_F=0;
			return true;
		}
	}
	return false;
}

void Character::Hurt_Animate_Flip_Render(int x, int y)
{
	(*TheEngine)->Images->get_image(0,Hurt_Filename)->Show_Flipped_Image(x,y,Hurt_Current_Sprite_F*Hurt_Sprite_Width,0,Hurt_Sprite_Width,Hurt_Sprite_Height);

}

void Character::load_win_quote(char* filename,void* data=NULL, int size=0)
{
	if (data == NULL)
	{
		(*TheEngine)->Images->create_image(filename);
	} else {
		(*TheEngine)->Images->create_image(filename,data,size);
	}
	strcpy(win_quote_filename,filename);
	
}

void Character::show_win_quote(int x, int y)
{
	(*TheEngine)->Images->show(0,win_quote_filename,x,y);

}

void Character::setname(char *newname)
{
	strcpy(name,newname);
	(*TheEngine)->Texts->create_text(name,"BADABB.TTF",1);

}

void Character::showname(int x, int y)
{
	(*TheEngine)->Texts->show_text(0,name,name,x,y,0,0,0);	
}

Character::~Character()
{
	delete myStage;
	myStage=NULL;
}

void Character::Set_Idle_Data(int total,int width,int height)
{
	num_of_Idle_sprite=total;
	current_Idle_sprite=0;
	current_Idle_sprite2=0;

	Idle_Sprite_Width=width;
	Idle_Sprite_Height=height;

}

void Character::Load_Win1_Data(int total,int width, int height)
{
	Win1_Sprite_Width=width;
	Win1_Sprite_Height=height;

	current_Win1_sprite_1=0;
	current_Win1_sprite_2=0;
	num_of_win1_sprite=total;		
}

void Character::Load_Intro_Data(int total, int width, int height)
{
	Intro_Current_Sprite=0;
	Intro_Sprite_Width=width;
	Intro_Sprite_Height=height;
	Intro_Sprite_Num=total;

}

void Character::Set_Moving_Intro(int player1_start_x, int player1_start_y, int player1_stop_x, int player2_start_x, int player2_start_y, int player2_stop_x)
{
	Intro_X=player1_start_x;
	Intro_Y=player1_start_y;
	Intro_Move=true;
	Intro_Move2=true;
	Intro_Stop_At = X_SPOT;
	Intro_Stop_X_Spot = player1_stop_x;

	Intro_Flip_X = player2_start_x;
	Intro_Flip_Stop_At = X_SPOT;
	Intro_Flip_Stop_X_Spot = player2_stop_x;
	Intro_Flip_Y = player2_start_y;

}

void Character::Set_Counter_Gem(int** setgem[4][5])
{

}

void Character::Set_Attack_Data(int total,int width,int height)
{
	Attack_Sprite_Width=width;
	Attack_Sprite_Height=height;
	Attack_Sprite_Num=total;

}

void Character::Set_Attack_Pos(int x, int y, int x2, int y2)
{
	Attack_X=x;
	Attack_Y=y;
	Attack_Current_Sprite=0;
	Attack_Current_Sprite_F=0;
	Attack_X_F=x2;
	Attack_Y_F=y2;

}

void Character::setquote(char* quote)
{
	strcpy(win_quote,quote);
}	
