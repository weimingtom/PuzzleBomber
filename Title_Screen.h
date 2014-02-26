#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

void resetcode();
extern void TitleScreen_Logic(); 
extern void TitleScreen_Render();

int keycode[9] = { 0,0,0,0,0,0,0,0,0 };
int keycodecount=0;

#include "Title_Screen.cpp"
#endif
