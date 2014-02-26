#ifndef CHARACTER_SELECT_H
#define CHARACTER_SELECT_H

int Select_Char_Box_x=282;
int Select_Char_Box_y=300; 

int Select_Char_Big_Box1_X=60;
int Select_Char_Big_Box2_X=540;

int Select_Char_Big_Box_Y=50;

int Character_Select_Render();
int render_small_boxes();
int render_big_boxes();

int render_Chars_Per_Pic();
int render_Cursors();


int total_boxes=3;


int Cursor_Move_Space=82;

int player1_curs_X=282;
int player2_curs_X=Select_Char_Box_x+Cursor_Move_Space*(total_boxes-1);
int Character_Select_Logic();

char Player1_selected_big_name[255];
int Player1_selected_big_ID=0;

char Player2_selected_big_name[255];
int Player2_selected_big_ID=0;

int Player1_selected_char_ID=0;
int Player2_selected_char_ID=0;

int Cursor_Max_Right=Select_Char_Box_x + (Cursor_Move_Space*(total_boxes-1));
int Cursor_Max_Left=Select_Char_Box_x;

bool Player1_Has_Selected=false;
bool Player2_Has_Selected=false;

bool Has_Selected=false;
bool Has_Paused=false;
int pause_time=0;



#include "Character_Select.cpp"
#endif
