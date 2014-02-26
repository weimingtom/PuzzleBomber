#include "Load_Game.h" 

int load_game(void* passing)
{
	srand(time(NULL));

	load_texture();



	for (int i = 0;i<TITLE_SCREENSIZE_WIDTH;i++)
	{
		for (int j=0;j<TITLE_SCREENSIZE_HEIGHT;j++)
		{
			titlescreen[i][j] = -1;
		}
	}

	SDL_Delay(3250 );
	loading_mode=LSCR_FADEOUT;
	SDL_KillThread( loading_thread );
	return 0;
}


