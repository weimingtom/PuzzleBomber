#ifndef SELECT_SCREEN_H
#define SELECT_SCREEN_H


int cursor_space=60;
int Max_downspace=320;

int Max_upspace=200;

extern void Select_Screen_Logic(); 
extern void Select_Screen_Render();

bool is_down_key_pressed();
void move_cursor_down();
void move_cursor_up();


void reset_down_key();
void reset_up_key();
void reset_enter_key();

bool is_up_key_pressed();

bool is_enter_key_pressed();

char Player1_Selected_Name[255];
int Player1_Selected_ID=0;

#include "Select_Screen.cpp"
#endif
