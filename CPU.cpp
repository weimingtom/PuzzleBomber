#include "CPU.h"

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

int CPU::ACPU()
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

void CPU::Easy_Mode()
{
	switch(logic)
	{
	
		case CPU_SET_RND_BLOCK:
		{
		//	generate_rand_block(&(*player));
		//	set_block(&(*player));
		//	logic = GEM_DROP;
		//	(*player)->Change_Rotation(NORMAL);
			break;
		}
		
		break;
	}
}
