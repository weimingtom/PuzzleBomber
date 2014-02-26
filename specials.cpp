#include "specials.h"

void kitteh_special_render(void** address)
{

	Player* player =  (Player*) address;
	
	if (player == Player1)
	{
		if (Player1->special_pause) return ;

		switch(p1_pb_state)
		{
			case 0:
			{
				int blockcount=0;

				for (int i = 0;i<FIELD_WIDTH;i++)
				{
					for (int j=0;j<FIELD_HEIGHT;j++)
					{
						if (Player2->field[i][j].color != -1 && Player2->field[i][j].is_bomb == false)
						{
							blockcount++;
						}
					}
				}

				if (blockcount <= p1_pb_total_count)
				{
					p1_pb_total_count = blockcount / 2;
					p1_pb_count=0;
				}


				if (p1_pb_total_count == p1_pb_count)
				{
					p1_pb_total_count=-1;
					p1_pb_count = 0;
					Player1->specialp = false;
       					for (int i=0;i<6;i++)
					{
						for (int j=0;j<12;j++)
						{
							p1_sp_field[i][j].checked = false;
						}
					}					
				} else {
					p1_pb_count++;
					p1_pb_state=1;
				}
				break;
			}
			case 1:
			{
				bool chose = false;
				for (int k=0;k < FIELD_WIDTH;k++)
				{
					for (int l=FIELD_HEIGHT-1;l > -1;l--)
					{
						if (Player2->field[k][l].color != -1 && Player2->field[k][l].is_bomb == false && p1_sp_field[k][l].checked==false)
						{
							p1_pb_x = Player2->FIELD_POSITION_X+(BLOCK_SIZE*k);
							p1_pb_y =( Player2->FIELD_POSITION_Y+(BLOCK_SIZE*l))-73;
							p1_sp_field[k][l].checked = true;
							p1_pb_state = 2;
							chose = true;
							Player2->field[k][l].color = 1;
							break;
						}
							
					}
					if (chose == true) break;

				}

				break;
			}
			case 2:
			{
				if (p1_pb_timer >= 15)
				{
					p1_pb_timer=0;
					p1_pb_state=0;
				} else {
					engine->Images->show(0,paint_brush, p1_pb_x, p1_pb_y);
					p1_pb_timer++;
				}
				break;
			}
		}
	} else 
	if (player == Player2)
	{
		if (Player2->special_pause) return ;

		switch(p2_pb_state)
		{
			case 0:
			{
				int blockcount=0;

				for (int i = 0;i<FIELD_WIDTH;i++)
				{
					for (int j=0;j<FIELD_HEIGHT;j++)
					{
						if (Player1->field[i][j].color != -1 && Player1->field[i][j].is_bomb == false)
						{
							blockcount++;
						}
					}
				}

				if (blockcount <= p2_pb_total_count)
				{
					p2_pb_total_count = blockcount / 2;
					p2_pb_count=0;
				}


				if (p2_pb_total_count == p2_pb_count)
				{
					p2_pb_total_count=-1;
					p2_pb_count = 0;
					Player2->specialp = false;
       					for (int i=0;i<6;i++)
					{
						for (int j=0;j<12;j++)
						{
							p2_sp_field[i][j].checked = false;
						}
					}					
				} else {
					p2_pb_count++;
					p2_pb_state=1;
				}
				break;
			}
			case 1:
			{
				bool chose = false;
				for (int k=0;k < FIELD_WIDTH;k++)
				{
					for (int l=FIELD_HEIGHT-1;l > -1;l--)
					{
						if (Player1->field[k][l].color != -1 && Player1->field[k][l].is_bomb == false && p2_sp_field[k][l].checked==false)
						{
							p2_pb_x = Player1->FIELD_POSITION_X+(BLOCK_SIZE*k);
							p2_pb_y =( Player1->FIELD_POSITION_Y+(BLOCK_SIZE*l))-73;
							p2_sp_field[k][l].checked = true;
							p2_pb_state = 2;
							chose = true;
							Player1->field[k][l].color = 1;
							break;
						}
							
					}
					if (chose == true) break;

				}

				break;
			}
			case 2:
			{
				if (p2_pb_timer >= 30)
				{
					p2_pb_timer=0;
					p2_pb_state=0;
				} else {
					engine->Images->show(0,paint_brush, p2_pb_x, p2_pb_y);
					p2_pb_timer++;
				}
				break;
			}
		}
	}
}

void kitteh_special(void** address)
{
	Player* player =  (Player*) address;

	if ((Player*) address == Player1)
	{
		//checks for number of blocks on the field
		int blockcount=0;

		if (Player1->gaugebar != 80) 
		{
			Player1->specialp = false;
			return ;
		}
	
		for (int i = 0;i<FIELD_WIDTH;i++)
		{
			for (int j=0;j<FIELD_HEIGHT;j++)
			{
				if (Player2->field[i][j].color != -1 && Player2->field[i][j].is_bomb == false)
				{
					blockcount++;
				}
			}
		}

		if (blockcount < 10)
		{
			Player1->specialp = false;			
			return ;
		}
			
		Player1->gaugebar=0;
		switch(p1_pb_state)
		{
			case 0:
			{
				p1_pb_total_count = blockcount / 2;
				p1_pb_state = 1;
				break;
			}
			case 1:
			{

				break;
			}
			break;
		}
	} else 
	if ((Player*) address == Player2)
	{
		//checks for number of blocks on the field
		int blockcount=0;

		if (Player2->gaugebar != 80) 
		{
			Player2->specialp = false;
			return ;
		}
	
		for (int i = 0;i<FIELD_WIDTH;i++)
		{
			for (int j=0;j<FIELD_HEIGHT;j++)
			{
				if (Player1->field[i][j].color != -1 && Player1->field[i][j].is_bomb == false)
				{
					blockcount++;
				}
			}
		}

		if (blockcount < 10)
		{
			Player2->specialp = false;			
			return ;
		}
			
		Player2->gaugebar=0;
		switch(p2_pb_state)
		{
			case 0:
			{
				p2_pb_total_count = blockcount / 2;
				p2_pb_state = 1;
				break;
			}
			case 1:
			{

				break;
			}
			break;
		}

	}

}
