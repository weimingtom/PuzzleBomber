#include "Texture.h"
#include "specials.h"
#include "Scott_Bigheadshot.h"
#include "Scott_Idle.h"
#include "Scott_Win.h"
#include "Scott_Intro.h"
#include "Scott_Attack.h"
#include "Scott_Hurt.h"
#include "scott_WinQuote.h"
#include <string.h>

void load_texture()
{

	engine->sound_system->create_music("charsel.mp3");
	engine->Images->create_image("titlebg.png");

	engine->Images->create_image(tempred);
        engine->Images->create_image(tempbackground);
	engine->Images->create_image(scoreboard_pic);
	/*
	* Load pieces
	*/
	engine->Images->create_image(Blue_Breaker_Filename);
	engine->Images->create_image(Green_Breaker_Filename);
	engine->Images->create_image(Yellow_Breaker_Filename);
	engine->Images->create_image(Red_Breaker_Filename);
	engine->Images->create_image(Yellow_Gem);
	engine->Images->create_image(Red_Gem);
	engine->Images->create_image(Blue_Gem);
	engine->Images->create_image(Green_Gem);

	/*bomb bombs*/
	engine->Images->create_image(Blue_Bomb);
	engine->Images->create_image(Green_Bomb);
	engine->Images->create_image(Red_Bomb);
	engine->Images->create_image(Yellow_Bomb);

	/*load boxes*/
	engine->Images->create_image(Select_Char_Box);
	engine->Images->create_image(Select_Char_Big_Box);

	engine->Images->create_image(SC_Name);
	engine->Images->create_image(door_filename);
	engine->Images->create_image("VS.png");
	engine->Images->create_image(Jar_filename);
	engine->Images->create_image(ready_Filename);
	engine->Images->create_image(explode_filename);

	engine->Images->create_image(nextblockracket);
	engine->Images->create_image("quotebox.png");
	engine->Images->create_image(infobox);
	engine->Images->create_image(WinBall_Filename);
	engine->Images->create_image(WonBall_Filename);

	engine->Images->create_image(gaugebar);
	engine->Images->create_image(gaugebarp);

	engine->Images->create_image("CGemDialog.png");
	engine->Images->create_image("redgemsmall.png");
	engine->Images->create_image("greengemsmall.png");
	engine->Images->create_image("bluegemsmall.png");
	engine->Images->create_image("yellowgemsmall.png");
	engine->Images->create_image("puzzlebomber.png");

	engine->Texts->create_font(FontName_File,70);
	engine->Texts->create_font(FontName_File,25);


	
        /*Load Characters*/

        /*load kitteh*/

	kitteh = new Character(&engine);

	characters[0] =  (long int*) kitteh;

	//Character *temp = (Character*) characters[0];

	
	engine->Images->create_image(paint_brush);
	
	loadkitteh(&kitteh);

	//Bart
	bart = new Character(&engine);
	bart->ID = 2;
	bart->setname("Bart");
	bart->Load_Personal_Pic("bart_headshot.png");
	bart->Load_Big_Personal("bart_Bigheadshot.png");

	bart->Load_Idle_Pic("Bart_idle.png");
	bart->Set_Idle_Data(4,40,60);
	
	bart->Load_Win1("bart_win.png");
	bart->Load_Win1_Data(5,60,60);

	bart->Load_Intro("bart_intro.png");
	bart->Load_Intro_Data(15,60,60);
	bart->Intro_Move = false;
	bart->Intro_Move2 = false;

	bart->myStage->LoadBG("bartback.png");
	bart->myStage->LoadBGPattern("s1bkg.jpg");
	bart->Intro_X = 290;
	bart->Intro_Y = 290;
	bart->Intro_Flip_X = 450;
	bart->Intro_Flip_Y = 290;
	
	bart->Load_Attack("bart_attack.png");
	bart->Set_Attack_Data(15,60,60);
	bart->Set_Attack_Pos(0,290,290,290);

	bart->Load_Hurt("bart_hurt.png");
	bart->Load_Hurt_Data(12,60,60);

	bart->load_win_quote("bart_winquote.png");
	bart->setquote("Don't have a cow, man!");
	bart->myStage->LoadBGMusic("bart.mp3");




	bart->counter_gems[0][0] = 7;bart->counter_gems[1][0]=5;bart->counter_gems[2][0]=5;bart->counter_gems[3][0] =1;bart->counter_gems[4][0]=1;bart->counter_gems[5][0]=3;  
	bart->counter_gems[0][1] = 7;bart->counter_gems[1][1]=1;bart->counter_gems[2][1]=1;bart->counter_gems[3][1] =5;bart->counter_gems[4][1]=5;bart->counter_gems[5][1]=3;  

	bart->counter_gems[0][2] = 7;bart->counter_gems[1][2]=5;bart->counter_gems[2][2]=5;bart->counter_gems[3][2] =1;bart->counter_gems[4][2]=1;bart->counter_gems[5][2]=3;  

	bart->counter_gems[0][3] = 7;bart->counter_gems[1][3]=1;bart->counter_gems[2][3]=1;bart->counter_gems[3][3] =5;bart->counter_gems[4][3]=5;bart->counter_gems[5][3]=3;  


	//prinny
	prinny = new Character(&engine);
	prinny->ID=3;
	prinny->setname("Prinny");
	prinny->Load_Personal_Pic("prinny-headshot.png");
	prinny->Load_Big_Personal("prinny_Bigheadshot.png");

	prinny->Load_Idle_Pic("prinny_idle.png");
	prinny->Set_Idle_Data(6,50,50);
	prinny->Load_Win1("prinny_win.png");
	prinny->Load_Win1_Data(6,50,50);

	prinny->Load_Intro("prinny_intro.png");
	prinny->Load_Intro_Data(18,50,50);
	prinny->Intro_Move = false;
	prinny->Intro_Move2 = false;
	prinny->Intro_X = 290;
	prinny->Intro_Y = 290;
	prinny->Intro_Flip_X = 450;
	prinny->Intro_Flip_Y = 290;
	

	prinny->Load_Attack("prinny_attack.png");
	prinny->Set_Attack_Data(6,50,50);
	prinny->Set_Attack_Pos(0,290,290,290);


	prinny->Load_Hurt("prinny_hurt.png");
	prinny->Load_Hurt_Data(6,50,50);

	prinny->load_win_quote("prinny-winquote.png");
	prinny->setquote("CAN I REALLY BE A HERO?!?!?!?!?!?!?!");


	prinny->myStage->LoadBG("prinny-stage.png");
	prinny->myStage->LoadBGPattern("s1bkg.jpg");
	prinny->myStage->LoadBGMusic("prinny.mp3");


	prinny->counter_gems[0][0] = 3;prinny->counter_gems[1][0]=1;prinny->counter_gems[2][0]=1;prinny->counter_gems[3][0] =5;prinny->counter_gems[4][0]=5;prinny->counter_gems[5][0]=7;  
	prinny->counter_gems[0][1] = 3;prinny->counter_gems[1][1]=1;prinny->counter_gems[2][1]=1;prinny->counter_gems[3][1] =5;prinny->counter_gems[4][1]=5;prinny->counter_gems[5][1]=7;  

	prinny->counter_gems[0][2] = 3;prinny->counter_gems[1][2]=5;prinny->counter_gems[2][2]=5;prinny->counter_gems[3][2] =1;prinny->counter_gems[4][2]=1;prinny->counter_gems[5][2]=7;  

	prinny->counter_gems[0][3] = 3;prinny->counter_gems[1][3]=5;prinny->counter_gems[2][3]=5;prinny->counter_gems[3][3] =1;prinny->counter_gems[4][3]=1;prinny->counter_gems[5][3]=7;  

        
	scott = new Character(&engine);
	scott->ID = 4;
	scott->setname("Scott Pilgram");

	scott->Load_Personal_Pic("scott-hshot.png",Scott_Bigheadshot,14508);	
	scott->Load_Big_Personal("scott-headshot.png", Scott_Bigheadshot,14508);
	scott->Load_Idle_Pic("scott-idle.png", Scott_Idle,4790);
	scott->Set_Idle_Data(7,43,68);
	scott->Load_Win1("scott_win.png", Scott_Win,1244);
	scott->Load_Win1_Data(1,30,73);

	scott->Load_Intro("scott_intro.png", Scott_Intro, 9134);
	scott->Load_Intro_Data(6,122,86);
	scott->Intro_Move = false;
	scott->Intro_Move2 = false;
	scott->Intro_X = 290;
	scott->Intro_Y = 290;
	scott->Intro_Flip_X = 450;
	scott->Intro_Flip_Y = 290;

	scott->Load_Attack("scott_attack.png", Scott_Attack,5355);
	scott->Set_Attack_Data(6,96,56);
	scott->Set_Attack_Pos(0,290,290,290);


	scott->Load_Hurt("scott_hurt.png",Scott_Hurt,1404);
	scott->Load_Hurt_Data(2,46,86);
	scott->load_win_quote("scott_winquote.png",scott_WinQuote,75312);
	scott->setquote("That's it! You cocky cock! You'll pay for your crimes against humanity.");
	scott->myStage->LoadBG("prinny-stage.png");
	scott->myStage->LoadBGPattern("s1bkg.jpg");
	scott->myStage->LoadBGMusic("prinny.mp3");



	for (int l=0; l < 6;l++)
	{
		for (int m=0;m < 12;m++)
		{
			p1_sp_field[l][m].checked = false;
		}
	}
	
	/*Texture*/

	engine->Texts->create_text(Game_Code_Title,FontName_File,2);
	engine->Texts->create_text(Enter_Code,FontName_File,1);
	engine->Texts->create_text(Sel_Mode_Code,FontName_File,2);
	engine->Texts->create_text(Single_Player_Code,FontName_File,1);
	engine->Texts->create_text(VS_Player_Code,FontName_File,1);
	engine->Texts->create_text(curs_name,FontName_File,1);
	engine->Texts->create_text(BT_Name,FontName_File,3);
	engine->Texts->create_text(selchar_code,FontName_File,1);
	engine->Texts->create_text(player1_selected_code,FontName_File,1);
	engine->Texts->create_text(player2_selected_code,FontName_File,1);
	engine->Texts->create_text(round_code,FontName_File,1);
	engine->Texts->create_text(nextblockid,FontName_File,3);
	engine->Texts->create_text(scoreid,FontName_File,3);
	engine->Texts->create_text(p1_score,FontName_File,3);
	engine->Texts->create_text(p2_score,FontName_File,3);
	engine->Texts->create_text(kotext,FontName_File,2);
	engine->Texts->create_text(youwin,FontName_File,2);
	engine->Texts->create_text(youlose,FontName_File,2);
	engine->Texts->create_text(winquote,FontName_File,3);
	engine->Texts->create_text(charsel,FontName_File,3);
	engine->Texts->create_text(exitgame,FontName_File,3);
	engine->Texts->create_text(curz,FontName_File,3);
	engine->Texts->create_text(chaintext,FontName_File,3);
	engine->Texts->create_text(chaintext2, FontName_File,3);
	engine->Texts->create_text(penblkcde1, FontName_File,3);
	engine->Texts->create_text(penblkcde2, FontName_File,3);
	engine->Texts->create_text(p1_ccode, FontName_File,3);
	engine->Texts->create_text(ggemblown_code, FontName_File,3);
	engine->Texts->create_text(ggembg_code,FontName_File,3);
	engine->Texts->create_text(gtotals_code,FontName_File,3);
	engine->Texts->create_text(ocurz_code,FontName_File,3);
	engine->Texts->create_text(p1charname_code,FontName_File,3);
	engine->Texts->create_text(p2charname_code,FontName_File,3);
	//Option Screen
	engine->Texts->create_text(Opt_Code,FontName_File,1);
	engine->Texts->create_text(optiontitle_code,FontName_File,2);
	engine->Texts->create_text(optionround_code,FontName_File,3);
	engine->Texts->create_text("roundchoice",FontName_File,3);

	engine->Texts->create_text(optionexit_code,FontName_File,3);

	engine->Texts->create_text("credittext",FontName_File,3);
	
	engine->Texts->create_text("option_keys",FontName_File,3);


    engine->sound_system->create_music("vs.mp3");
	
}

int exp_animation(int x,int y, Player** player)
{
		engine->Images->show(explode_ID,explode_filename,(*player)->FIELD_POSITION_X+(BLOCK_SIZE*x),(*player)->FIELD_POSITION_Y+(BLOCK_SIZE*y),(*player)->field[x][y].color,0,explode_sprite_width,explode_sprite_height);

		if (explode_current_sprite == explode_sprite_num)
		{
			explode_current_sprite=0;
		}
		
}

void loadkitteh(Character** kittehref)
{
	(*kittehref)->ID=1;

	(*kittehref)->setname("Kitteh");

	(*kittehref)->Load_Personal_Pic(Kitteh_Personal_Filename);

	(*kittehref)->Load_Big_Personal("kitteh_Bigheadshot.png");

	(*kittehref)->Load_Idle_Pic(kitteh_Idle_Filename);
	(*kittehref)->Set_Idle_Data(6,42,42);
	
	(*kittehref)->Load_Win1(kitteh_Win_Filename);
	(*kittehref)->Load_Win1_Data(6,41,49);

	(*kittehref)->Load_Intro("kitteh_intro.png");
	(*kittehref)->Load_Intro_Data(18,42,42);
	(*kittehref)->Set_Moving_Intro(0, 300, 290, 800, 300, 470);
	
	(*kittehref)->counter_gems[0][0] = 3;(*kittehref)->counter_gems[1][0]=1;(*kittehref)->counter_gems[2][0]=1;(*kittehref)->counter_gems[3][0] =1;(*kittehref)->counter_gems[4][0]=1;(*kittehref)->counter_gems[5][0]=7;  
	(*kittehref)->counter_gems[0][1] = 3;(*kittehref)->counter_gems[1][1]=5;(*kittehref)->counter_gems[2][1]=5;(*kittehref)->counter_gems[3][1] =5;(*kittehref)->counter_gems[4][1]=5;(*kittehref)->counter_gems[5][1]=7;  

	(*kittehref)->counter_gems[0][2] = 3;(*kittehref)->counter_gems[1][2]=1;(*kittehref)->counter_gems[2][2]=1;(*kittehref)->counter_gems[3][2] =1;(*kittehref)->counter_gems[4][2]=1;(*kittehref)->counter_gems[5][2]=7;  

	(*kittehref)->counter_gems[0][3] = 3;(*kittehref)->counter_gems[1][3]=5;(*kittehref)->counter_gems[2][3]=5;(*kittehref)->counter_gems[3][3] =5;(*kittehref)->counter_gems[4][3]=5;(*kittehref)->counter_gems[5][3]=7;  

	(*kittehref)->Load_Attack("kitteh_attack.png");
	(*kittehref)->Set_Attack_Data(6,42,42);
	(*kittehref)->Set_Attack_Pos(0,300,290,300);

	(*kittehref)->Load_Hurt("hurt.png");
	(*kittehref)->Load_Hurt_Data(6,50,42);

	(*kittehref)->load_win_quote("winquote.png");
	(*kittehref)->setquote("Meow.....MEEEEOOOOOWWWWW!!!!!");
	
	(*kittehref)->special = &kitteh_special;
	(*kittehref)->special_render = &kitteh_special_render;

	(*kittehref)->myStage->LoadBG("74_large.jpg");
	(*kittehref)->myStage->LoadBGPattern("s1bkg.jpg");
	(*kittehref)->myStage->LoadBGMusic("kitteh.mp3");

}
