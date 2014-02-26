#ifndef STAGE_H
#define STAGE_H
class stage
{
	public:
		Engine** eng;
		Thread *MusicThread;
		char BGName[255];
		char BGPatterName[255];
		char MusicFile[255];

		stage(Engine** engine);
		void LoadBG(char *stagebgimg);
		void DrawBG(int x, int y);
		void LoadBGPattern(char *patimg);
		void DrawBGPattern(int x, int y);

		void LoadBGMusic(char *musicfile);
		int PlayThread();
		bool Stop(char* musicfile);

	//	bool PlayMusic();
	private:
};

#include "stage.cpp"
#endif
