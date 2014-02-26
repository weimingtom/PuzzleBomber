#ifndef TEXTURE_H
#define TEXTURE_H


extern void load_texture();
void animate_door();

void loadkitteh(Character** kittehref);

/*
Gem Breakers
*/

char Blue_Bomb[] = "cbluegem.png";
char Green_Bomb[] = "cgreengem.png";
char Red_Bomb[] = "credgem.png";
char Yellow_Bomb[] = "cyellowgem.png";

char Blue_Breaker_Filename[] = "bluebreaker.png";
char Green_Breaker_Filename[] = "greenbreaker.png";
char Yellow_Breaker_Filename[] = "yellowbreaker.png";
char Red_Breaker_Filename[] = "redbreaker.png";

char Yellow_Gem[] = "yellowgem.png";
char Red_Gem[] = "redgem.png";
char Blue_Gem[] = "bluegem.png";
char Green_Gem[] = "greengem.png";

int Blue_Breaker_Num=2;
int Green_Breaker_Num=3;
int Yellow_Breaker_Num=4;
int Red_Breaker_Num=5;

int Blue_Gem_Num=8;
int Green_Gem_Num=9;
int Yellow_Gem_Num=6;
int Red_Gem_Num=7;



char Select_Char_Box[] = "box.png";
int Select_Char_Box_ID=10;

char Select_Char_Big_Box[] = "bigbox.png";
int Select_Char_Big_Box_ID=11; 

char SC_Name[] = "curs.png";
int  SC_ID=12;

char Kitteh_Personal_Filename[] = "kitteh_headshot.png";
int  kitteh_Personal_pic_ID=13;

char Kitteh_Big_Personal_Filename[] = "kitteh_Bigheadshot.png";
int Kitteh_Big_Personal_ID=14;

char kitteh_Idle_Filename[] = "kitteh_idle.png";
int Kitteh_Idle_ID=15;

char kitteh_Win_Filename[] = "kitteh_win.png";
int Kitteh_Win_1_ID=16;

//var for kitteh's Specials
Field p1_sp_field[6][12];
int p1_pb_total_count=0;
int p1_pb_count=-1;
int p1_pb_state=0;
int p1_pb_x=0;
int p1_pb_y=0;
int p1_pb_timer=0;

Field p2_sp_field[6][12];
int p2_pb_total_count=0;
int p2_pb_count=-1;
int p2_pb_state=0;
int p2_pb_x=0;
int p2_pb_y=0;
int p2_pb_timer=0;




char paint_brush[] = "paint_brush.png";

char door_filename[] = "door.png";
int door_filename_ID=17;
int door_L_x=-400;
int door_L_y=0;

int door_R_x=800;
int door_R_y=0;

char VS_filename[]="veruses";
int VS_ID=18;

char Jar_filename[] = "jar.png";
int Jar_ID=19;
int Jar_Player1_X=40;
int Jar_Player1_Y=80;
int Jar_Player2_X=500;
int Jar_Player2_Y=80;

char WinBall_Filename[] = "wins.png";
char WonBall_Filename[] = "wons.png";

char kitteh_intro_Filename[] = "kitteh_intro.png";
int kitteh_intro_ID=20;

char kitteh_win_quote[] = "winquote.png";

char ready_Filename[] = "ready.png";
int ready_ID=21;

char nextblockracket[] = "NextBlock.png";
int p1_nbr_x = 300;
int p1_nbr_y = 80;

int p2_nbr_x = 430;
int p2_nbr_y = 80;

char infobox[] = "infobox.png";

char tempred[] = "s1bkg.jpg";
char tempbackground[] = "74_large.jpg";
char scoreboard_pic[] = "scoreboard.png";

char explode_filename[]="explode.png";
int explode_ID=22;
int explode_x=0;
int explode_y=0;
int explode_current_sprite=0;
int explode_sprite_width=32;
int explode_sprite_height=32;
int explode_sprite_num=6;

char gaugebar[] = "gauge.png";
char gaugebarp[] = "gagep.png";


char Game_Code_Title[256]="pbtitle";
char Game_Title[256] = "PUZZLE BOMBER";
int  Game_Title_X=350;
int  Game_Title_Y=240;
int  Game_Title_ID=2;

int Tile_FontSize=70;

char Enter_Code[256] = "pressenter";
char Enter_Text[256] = "Press Enter!";
int Enter_ID=3;
int Enter_X=250;
int Enter_Y=460;

int Enter_FontSize=50;

char Sel_Mode_Code[256] = "selmode";
int Sel_Mode_FontSize=70;
char Sel_Mode_Text[256] = "Puzzle Bomber";
int Sel_Mode_X=250;
int Sel_Mode_Y=40;
int Sel_Mode_ID=4;

char Single_Player_Name[256] = "Single Play";
char Single_Player_Code[256]="singlemode";
int Single_Player_X=350;
int Single_Player_Y=200;
int Single_player_FontSize=40;
int Single_Player_ID=5;

char VS_Player_Name[256]="Versus Play";
char VS_Player_Code[256]="versusmode";
int VS_Player_FontSize=40;
int VS_Player_ID=6;
int VS_Player_X=350;
int VS_Player_Y=260;



char Opt_Name[256] = "Options";
char Opt_Code[256] = "options";
int Opt_X=350;
int Opt_Y=320;
int Opt_FontSize=40;
int Opt_ID=7;

char curs_Text[256] = "O";
char curs_name[256] = "smcursor";
int curs_ID=8;
int curs_size=30;
int curs_X=320;

char BT_Text[256] = "Use the UP and Down to move the cursor and Enter to Choose!";
char BT_Name[256] = "bottomtext";
int BT_ID=9;
int BT_Size=25;
int BT_X=130;
int BT_Y=520;

char selchar_text[] = "Select Character";
char selchar_code[] = "selchar";
int selchar_ID=10;
int selchar_size=30;
int selchar_x=290;
int selchar_y=20;

char player1_selected_name[255];
char player1_selected_code[]="p1co";
int  player1_selected_ID=11;
int  player1_selected_size=28;
int  player1_selected_x=150;
int  player1_selected_y=260;

char player2_selected_name[255];
char player2_selected_code[]="p2co";
int  player2_selected_ID=12;
int  player2_selected_size=28;
int  player2_selected_x=590;
int  player2_selected_y=260;

char round_code[] = "rndtxt";
char round_text[255];
int round_ID=13;

char nextblockid[] = "nextid";
char scoreid[] = "score";
char p1_score[] = "p1score";
char p2_score[] = "p2score";
char kotext[] = "kotext";
char youwin[] = "Youwin!";
char youlose[] = "Youlose";

char charsel[] = "charsel";
char exitgame[] = "exitgame";
char curz[] = "curs2";

char winquote[] = "winquote";

char FontName_File[]="BADABB.TTF";

char chaintext[] = "chaintxt";
char chaintext2[] = "chaintxt2";
char ctext[255];
char ctext2[255];


char penblkcde1[] = "penblkcd1";
char penblktxt1[255];

char penblkcde2[] = "penblkcd2";
char penblktxt2[255];

char p1_ccode[] = "ccode";
char p1_ccode_txt[255]; 

char ggemblown_code[] = "gemblow";
char ggemblown_text[255];

char ggembg_code[] = "gembg";
char ggembg_text[255];

char gtotals_code[] = "gtotals";
char gtotals_text[255];

char optiontitle_code[] = "optittlcde";
char optiontitle_text[] = "OPTIONS";

char optionround_code[] = "optnrndcde";
char optionround_text[255];

char optionexit_code[] = "optexit";
char optionext[] = "Exit";

char p1scoretext[255];
char p2scoretext[255];

char p1charname[255];
char p2charname[255];

char p1charname_code[] = "p1charname";
char p2charname_code[] = "p2charname";

char ocurz_code[] = "opcurz";
//char optioncurs_curs[] = "O";

int exp_animation(int x, int y, Player** player);

#include "Texture.cpp"
#endif 
