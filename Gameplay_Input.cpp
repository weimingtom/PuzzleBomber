#include "Gameplay.h"

void UserInput(Player** player)
{

	if (is_Half_A_Frame())
	{
		if ((*(*player)->is_down_key_pressed) == true)
		{				
			/*react depending on the block rotation*/
			(*player)->PushDown();
		}

		/* 
			Up Keypressed ---- Auto Drop
	*/
	if (*(*player)->is_up_key_pressed)
	{
		(*player)->PullDown();
	}
	/*Left Key is pressed*/
	if (*(*player)->is_left_key_down)
	{	
		(*player)->PushLeft();	
	}
	/* Right Key Pressed -- Moves Block to the right if it can*/
	if ((*(*player)->is_right_key_down) )
	{
		(*player)->PushRight();
	}
	/* Rotate Block Right*/
	if ( (*(*player)->is_Rotate_R_pressed))
	{
		(*player)->Rotate_Block_Right(&engine);
	}
	/* Rotate Block Left */

	if (*(*player)->is_Rotate_L_pressed)
	{
		(*player)->Rotate_Block_Left();
	}

	if (  (*player == Player1  && is_Single_Player == true)  || (is_Single_Player == false && (*player == Player1 || *player == Player2 )) )
	{	
		if ( (*(*player)->is_Special_pressed && (*player)->specialp == false))
		{
			(*player)->specialp = true;
			(*(*(*player)->character)->special)((void**) (*player));
			(*(*player)->is_Special_pressed) = false;
		}
	}
}
}
