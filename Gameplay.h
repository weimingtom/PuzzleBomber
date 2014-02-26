#ifndef GAMEPLAY_H
#define GAMEPLAY_H

//#include "xylist.h"

class nblock
{
	public:
		Field top;
		Field bottom;
		nblock *next;
		int used;
};

class round
{
	public:
		int number;
		//int player1_field[6][12]; //6x12
		int player2_field[6][12];

		bool is_roundover;
		int clear_fields();
		int winner; //1 = player 1 2= player 2
		
		float time;

		bool table;
	
		round();
};


//int drop_block_x=0;
//int drop_block_y=0;

int explodemap[6][12];

round Rounds[5];

int Gameplay_Render();
int Gameplay_Logic();

int curs2pos=190;
int waitpause=0;
bool isfinwait=false;

int switch_mode(int mode);

int current_round=1;

int ready_timer=0;
int round_timer=0;
int round_finish_timer=0;
int calc_timer=0;

int max_round=3;
int rounds2win=2;

int round_breaks=0;
int round_gbreaks=0;

int quote_screen_pause=0;

int Player1_Gameplay(Player** player);

nblock* headnextblock=NULL;
nblock* nextblock=NULL;

void addblock();
nblock* getcurrentblock(int number);
bool deleteblock();

bool is_gembreaker(int color);
bool is_same_color(int color, int x, int y, Player** player);


void top_block_check_solid(Player** player);
void bottom_block_check_solid(Player** player);

void init_next_block();
void clear_explode_map();
void clear_round();

void generate_rand_block(Player** player);
void set_block(Player** player);

bool is_Field_Block_Empty(Player** player, int x, int y);

bool is_Field_bottom(int y);

int Drop_Block(Player** player);
int Set_Block(Player** player, int y);
bool is_top_of_field(Player** player);
bool is_block_on_top(int x, int y);
int Move_Block_Left(Player **player);
int Move_Block_Right(Player **player);
int is_Hit_Wall_Right(int x);
int is_Hit_Wall_Left(int x);
bool is_Half_A_Frame();

/*Gameplay input */
void UserInput(Player** player);

/*Gameplayer Render*/

void show_block(int color, int x, int y);

void draw_block(Player** player); /*Draws Block Line 607*/

void draw_field(Player** player); /*Draws Players Field Gameplay_Render.cpp Line 514*/

void render_player(Player** player); /* Rendering of Blocks Gameplay_Render.cpp Line 3*/

void show_mood(Player** player, bool flipped, bool iscpu); /* shows players mood Gameplay_Render.cpp 648*/

//void bottom_block_check_solid(Player** player);

//bool did_brake=false;

//xylist *List=NULL;

//int p1_gem_pause=0;
//int p1_drop_gem_pause=0;

//SDL_Thread *Player_Thread = NULL;
#include "Gameplay_Render.cpp"
#include "Gameplay.cpp"
#include "Gameplay_Input.cpp"
#endif
