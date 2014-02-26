#ifndef MAIN_H
#define MAIN_H

#include "./SGE/Engine.h"

/*
Version (Major Changes, Minor Changes, Bugs)
0.8.8
Things to do:
=============================
xUp to auto drop
xdown to drop block faster
-Blocks goes down by 8 rather than 32
-Left, Right, Down Hold
xCounter Gems blocks
xblock into one big gems
xGame over/Win
xEnd Round Score
xRounds
xDisplay Chain Combos
xScores
xSolid blocks
xCounter cancels
-Gauge Bar
-Character Special Abilities
-more character animatiion
-Options
  -Change Max round

-Character updates

Bugs/"Special Features":
==================================
XCrashes on Windows. The cause is the Title Cursor
-Blocks can go though each other
xChain Combo does chain Properly
xCrashes after the Title screen
xBlock speed not reseted
xBig Block Goes Air born
xSome Fixes with the block going though other blocks
-The "up key" causes the game to crash in the right corner.
*/

/*
   ====== Characters ======
*/
const int NumberOfChar=1;
long int *characters[NumberOfChar];
Character *kitteh=NULL;
Character *bart=NULL;
Character *prinny=NULL;
Character *scott=NULL;

/*
=========== Players =======
*/

const int EMPTY=-1;

Player *Player1;
Player *Player2;

CPU* cpu;

extern Engine* engine=NULL;
int SCREEN_WIDTH=800;
int SCREEN_HEIGHT=570;
const int FIELD_WIDTH=6;
const int FIELD_HEIGHT=12;
const int BLOCK_SIZE=32;


char TITLE[255] = "Puzzler Bomber";
bool quit=false;

bool is_Single_Player=true;

int main_menu_mode=0;
int game_mode=0;
int game_play_mode=0;
bool *countergems;
bool *gauge_on;

extern int field[FIELD_WIDTH+2][FIELD_HEIGHT+4];


int Current_Round=0;
int MAX_BLOCK_SPEED=10;
int smcursor=200;
extern int title_mode=0;
int loading_mode=0;
int col=0;
bool cpuslt=false;

const int TITLE_SCREENSIZE_WIDTH=27;
const int TITLE_SCREENSIZE_HEIGHT=19;

Thread *loading_thread = NULL;

enum { TS_ANIMATION,TS_IDLE };
enum { LSCR_LOAD, LSCR_FADEOUT };
enum { EASY, MEDIUM,HARD };

int titlescreen[TITLE_SCREENSIZE_WIDTH+1][TITLE_SCREENSIZE_HEIGHT+1];


enum { LOADING_SCREEN,TITLE_SCREEN,GAME_SCREEN,SELECT_MODE,OPITION_SCREEN };
enum { CHARACTER_SELECT, VS_SCREEN, GAME_PLAY, CPU_SELECT, CREDITS };
enum { INIT_ROUND, INTRO, ROUND_NUMBER, READY,PLAY_GAME,GAMEOVER_QUOTE };

int difficulty=EASY;

int init_engine();
int clean_up();
int main_loop();
int gembreaker(int x,int y, int color, Player **player);

int mainbgx=0;
int mainbgy=0;

const int total_stages=3;
int stage_char_box_x=282;
int stage_char_box_y=300;
int current_stage=1;
int cpu_sel_count=0;
int randchar=0;
int getrandchar=0;
int stage_char[total_stages];
int total_cpu=3;
int cpu_char[4] = { 0, 1, 2};
bool sound = false;
bool music = false;
bool secert = false;
#endif
