#ifndef CHARACTER_H
#define CHARACTER_H

#include "stage.h"

enum { MAX_FRAME,X_SPOT };

enum { IDLE_MOOD,WIN_MOOD,LOSE_MOOD };



class Character 
{
	public:
		Engine** TheEngine;
		Character(Engine** engine);
		~Character();

		stage* myStage;

		void (*special)(void** address);
		void (*special_render)(void** address);		

		int ID;
		char name[255];
		int Mood;
		int current_Win1_sprite_1;
		int current_Win1_sprite_2;
		int num_of_win1_sprite;
		int counter_gems[6][5];
		char win_quote[255];


		void setquote(char* quote);		

		int render_Cursors();
		int Show(char* filename, int pID,int x, int y);
		

		/* Personal Pictures var and functions*/
		char Personal_Pic_Filename[255];
		int Personal_Pic_ID;
		char Personal_Big_Filename[255];
		SDL_Surface *fliped_Big_Personal;
		int Personal_Big_ID;
		int Load_Personal_Pic(char* filename, void* data, int size);
		int Show_Personal_Pic(int x, int y);
		int Load_Big_Personal(char* filename, void* data, int size);
		int Show_Big_Personal(int x, int y);
		int Load_Big_Personal_Flip();
		int Show_Big_Personal_Flip(int x, int y);

		int Idle_Pic_ID;
		int Idle_Sprite_Width;
		int Idle_Sprite_Height;
		char Idle_Pic_Filename[255];
		int num_of_Idle_sprite;
		int current_Idle_sprite;
		int current_Idle_sprite2;		
		int Idle_Animate(int x, int y);
		int Idle_Animate_Flip(int x, int y);
		int Idle_Animate_Render(int x, int y);
		int Idle_Animate_Flip_Render(int x, int y);
		int Load_Idle_Flip();
		int Load_Idle_Pic(char* filename,void *data, int size);
		void Set_Idle_Data(int total,int width,int height);
		void Load_Win1_Data(int total,int width, int height);

		/* Win var and functions */
		int Win_Pic_ID;
		char Win_Pic_Filename[255];
		int Win1_ID;
		char Load_Win1_Filename[255];	
		int Win1_Sprite_Width;
		int Win1_Sprite_Height;
		int Load_Win1(char* filename, void* data, int size);
		int Win1_Animate(int x, int y);
		int Win1_Animate2(int x, int y);

		int Load_Win_Pic(char* filename);
		int Load_Intro(char* filename, void* data, int size);
		int Load_Intro_Flip();
		int Intro_Animate_Flip();
		int Intro_Animate();
		int Intro_Animate_Render();
		int Intro_Animate_Flip_Render();

		int Intro_ID;
		char Intro_Filename[255];
		bool Intro_Move;
		bool Intro_Move2;
		int Intro_Sprite_Width;
		int Intro_Sprite_Height;
		int Intro_Sprite_Num;
		int Intro_Current_Sprite;
		int Intro_X;
		int Intro_Y;
		int Intro_Stop_At;
		int Intro_Stop_X_Spot; 
		int Intro_Flip_Current_Sprite;
		int Intro_Flip_X;
		int Intro_Flip_Y;
		int Intro_Flip_Stop_At;
		int Intro_Flip_Stop_X_Spot;
		bool isintrodone;
		bool isintrodone2;
		
		void Load_Attack(char* filename, void* data, int size);
		void Set_Attack_Data(int total,int width,int height);
		void Set_Attack_Pos(int x, int y, int x2, int y2);
                
		void Load_Attack_Flip();
		void Attack_Animate_Render(int x, int y);
		void Attack_Animate_Flip_Render(int x,int y);
		bool Attack_Animate(int x,int y);
		bool Attack_Animate_F(int x,int y);
		char Attack_Filename[255]; 
		int Attack_Sprite_Width;
		int Attack_Sprite_Height;
		int Attack_Sprite_Num;
		int Attack_Current_Sprite;
		int Attack_X;
		int Attack_Y;
		int Attack_Sprite_Num_F;
		int Attack_Current_Sprite_F;
		int Attack_X_F;
		int Attack_Y_F;

		char Hurt_Filename[255];
		int Hurt_X;
		int Hurt_Y;
		int Hurt_Current_Sprite;
		int Hurt_Sprite_Num;
		int Hurt_Sprite_Width;
		int Hurt_Sprite_Height;
		int Hurt_Current_Sprite_F;
		


		void Load_Hurt(char* filename, void* data, int size);
		void Load_Hurt_Data(int total, int width, int height);

		void Hurt_Animate_Render(int x, int y);
		bool Hurt_Animate(int x,int y);
		void Load_Hurt_Flip();
		bool Hurt_Animate_F(int x,int y);
		void Hurt_Animate_Flip_Render(int x, int y);

		char win_quote_filename[255];
		void load_win_quote(char *filename, void* data, int size);
		void show_win_quote(int x, int y);

		void setname(char* newname);
		void showname(int x,int y);
		void Load_Intro_Data(int total, int width, int height);
		void Set_Moving_Intro(int player1_start_x, int player1_start_y, int player1_stop_x, int player2_start_x, int player2_start_y, int player2_stop_x);
		
		void Set_Counter_Gem(int** setgem[4][5]);
		
		
};

#include "Character.cpp"

#endif
