#ifndef OPTIONS_H
#define OPTIONS_H

enum { GAME_OPTIONS, KEYOPTIONS };

int option_mode=GAME_OPTIONS;

int MIN_OP_Y =150;
int MAX_OP_Y =310;

int OP_CUR=150;

void Options_Render();
void Options_Logic();

#include "Options.cpp"

#endif
