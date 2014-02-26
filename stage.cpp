#include "stage.h"

stage::stage(Engine** engine)
{
	eng = engine;
}

void stage::LoadBG(char *stagegbimg)
{
    (*eng)->Images->create_image(stagegbimg);
    strcpy(BGName,stagegbimg);

}

void stage::DrawBG(int x, int y)
{
	(*eng)->Images->show(0,BGName,x,y);
}

void stage::LoadBGPattern(char* patimg)
{
    (*eng)->Images->create_image(patimg);
    strcpy(BGPatterName,patimg);

}

void stage::DrawBGPattern(int x, int y)
{
	(*eng)->Images->show(0,BGPatterName,x,y);

}

void stage::LoadBGMusic(char *musicfile)
{
	(*eng)->sound_system->create_music(musicfile);
	strcpy(MusicFile,musicfile);
}

int stage::PlayThread()
{
	(*eng)->sound_system->play_music(0,MusicFile);
	return 0;
}

bool stage::Stop(char* filename)
{
	(*eng)->sound_system->stop_music(filename);
}
/*
bool stage::PlayMusic()
{
	MusicThread = (*eng)->CreateThread(PlayThread,(*eng));
	if (MusicThread == NULL) return false;
	return true;
}
*/
