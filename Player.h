#ifndef PLAYER_H
#define PLAYER_H

#include "xylist.h"

enum { DROPPING, MOVE_LEFT,MOVE_RIGHT,WAIT,BLOCK_DOWN,IS_DEAD };

enum { IDLED, ATTACKED, HURTED };

enum { easy, medium,hard };

enum { SET_RND_BLOCK, GEM_DROP,GEM_HIT, GEM_BREAK_CHK, DROP_GEM,GEM_PAUSE,GEM_DROP_PAUSE, GEM_SEND, GAMEOVER_CHECK,ROUND_END,CALC_SCORE, ROUND_CLEAR};
enum { NORMAL, LEFTSIDE_DOWN, UPSIDE_DOWN, RIGHTSIDE_UP };

class Field
{
	public:
		int color;
		bool is_bomb;
		int bomb_timer;
		bool is_solid;
		bool can_drop; 
		bool checked;
};

class Player
{
	public:
		
		Player();
		bool *is_up_key_pressed;
		bool *is_left_key_pressed;	
		bool *is_right_key_pressed;
		bool *is_down_key_pressed;
		bool* is_Rotate_L_pressed;
		bool* is_Rotate_R_pressed;
		bool* is_Special_pressed;


		bool *is_left_key_down;	
		bool *is_right_key_down;


		int drop_block_y;
		int drop_block_x;

		int rotation_padding;

		bool specialp;
		bool special_pause;

		int reset_keys();

		Character** character;

		int top_block_x;
		int top_block_y;
		int bottom_block_x;
		int bottom_block_y;
		
		int tph_y;
		int bph_y;

		int tph_x;
		int bph_x;

		int bp_count;

		int top_block;
		int bottom_block;

		char top_block_name[255];
		char bottom_block_name[255];

		int top_block_ID;
		int bottom_block_ID;

		int logic;
		int rotate;
		bool can_move_up;
		bool can_move_left;
		bool can_move_right;
		bool can_rot_left;
		bool can_rot_right;
		Field field[6][12];
		int clear_field();
		xylist *List;
		int gem_pause;
		int drop_gem_pause;
		bool did_brake;

		int FIELD_POSITION_X;
		int FIELD_POSITION_Y;
		int block_speed;
		int explodemap[6][12];

		int explode_current_sprite;
	
		int gem_broke;
		int pending_blocks;

		int score;

		int nextblocknum;

		int Mood;
		
		bool is_winner;

		int big_gem;
	
		int chain;

		bool ischain;
		int chain_timer;

		int total_chains;
		int total_big_gems;

		int wins;

		int gaugebar; //total 80

		int Animate_Mood();
		int Animate_Mood2();
		int Change_Rotation(int state);
		int Rotate_Right();
		int Rotate_Left();
		int Get_Current_Rotation();
		int Set_Left_Key_Status(bool newstatus);
		int Set_Right_Key_Status(bool newstatus);
		bool Get_Left_Key_Status();
		bool Get_Right_Key_Status();
		
		int Set_Right_Rotation_Status(bool newstatus);
		int Set_Left_Rotation_Status(bool newstatus);

		bool Get_Right_Rotation_Status();
		bool Get_Left_Rotation_Status();

		bool is_Block_Speed(int speed2check);
		int Change_Players_Mode(int newmode);
		bool is_not_on_top(int y);
		int Set_Block_Color(int x, int y, int color);
		int Reset_Dropping_Block();

		int reset_drop_field();
		int reset_checks();
		
		bool PushDown();
		bool PushLeft();
		bool PushRight();
		bool PullDown();
		bool Rotate_Block_Right(Engine** engine);
		bool Rotate_Block_Left();
		

		bool is_Field_bottom(int y);
		bool is_Field_Block_Empty(int x, int y);
		int Drop_Block();
		bool is_block_on_top(int x, int y);
		int Set_Block(int y);
		int is_Hit_Wall_Left(int x);
		int is_Hit_Wall_Right(int x);
		bool is_top_of_field();
		int Move_Block_Left();
		int Move_Block_Right();
		
	

		
	
};


class CPU : public Player {
	public:
	//	int logic;
	//	Character **character;
	//	int Mood;
	//	int Animate_Mood();
		void Start_AI(int diff);
		void Easy_Mode();
		int easystates;
		bool check_left_field();
		bool check_right_field();
		
		CPU();


};



#include "Player.cpp"

#endif
