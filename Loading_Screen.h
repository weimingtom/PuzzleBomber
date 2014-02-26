#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H


extern void Loading_Logic(); 
void Loading_Render();

bool Is_Fadedout(int spritenum, char* imagename);
void FadeOutText(int spritenum, char* textname);

char Bomb_Name[] = "bomb";
char Bomb_Filename[] = "bomb.png";
int Bomb_Index = 1;
int Bomb_Sprite_Number=5;
int Bomb_X=670;
int Bomb_Y=520;

char Loading_Name[] = "loading";
char Loading_Text[] = "L   o   a   d   i   n   g  .  .  .";
int Loading_X=300;
int Loading_Y=520;
int Loading_Index=1;



#include "Loading_Screen.cpp"
#endif
