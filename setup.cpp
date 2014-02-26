 #include "setup.h"

int init_engine()
{
	engine = new Engine;
    	engine->screen_width=SCREEN_WIDTH;
    	engine->screen_height=SCREEN_HEIGHT;
	engine->init_engine();
	engine->frame_per_second = 20;
	engine->set_title(TITLE);
	engine->set_transparency_color(0xff,0x0,0xff);



	engine->Images->create_image("bomb.png");	
	engine->Images->get_image(1,"bomb.png")->sprites->create_sprites("bomb",4,0,0,64,64,0);
        engine->Texts->create_font("BADABB.TTF",40);

	engine->Texts->create_text("loading","BADABB.TTF",1);	

		
	Player1 = new Player();
	Player2 = new Player();
	cpu = new CPU();


	Player1->FIELD_POSITION_X = 74;
	Player1->FIELD_POSITION_Y = 144;

	Player2->FIELD_POSITION_X = 534;
	Player2->FIELD_POSITION_Y = 144;


	cpu->FIELD_POSITION_X = 534;
	cpu->FIELD_POSITION_Y = 144;

    Player1->is_left_key_pressed =  &engine->Keys->a.is_key_pressed;
	Player1->is_right_key_pressed = &engine->Keys->d.is_key_pressed;

	Player1->is_left_key_down =  &engine->Keys->a.key_pressed_down;
	Player1->is_right_key_down = &engine->Keys->d.key_pressed_down;

	Player1->is_Rotate_L_pressed =  &engine->Keys->q.key_pressed_down;
    Player1->is_Rotate_R_pressed =  &engine->Keys->e.key_pressed_down;
	Player1->is_up_key_pressed =    &engine->Keys->w.key_pressed_down;
	Player1->is_down_key_pressed =  &engine->Keys->s.key_pressed_down;
	Player1->is_Special_pressed =   &engine->Keys->one.key_pressed_down;




	Player2->is_left_key_pressed =  &engine->Keys->left.key_pressed_down;
	Player2->is_right_key_pressed = &engine->Keys->right.key_pressed_down;
	Player2->is_Rotate_L_pressed =  &engine->Keys->l.key_pressed_down;
        Player2->is_Rotate_R_pressed =  &engine->Keys->k.key_pressed_down;
	Player2->is_up_key_pressed =    &engine->Keys->up.key_pressed_down;
	Player2->is_down_key_pressed =  &engine->Keys->down.key_pressed_down;
	Player2->is_Special_pressed =   &engine->Keys->m.key_pressed_down;

	Player2->is_left_key_down =  &engine->Keys->left.key_pressed_down;
	Player2->is_right_key_down = &engine->Keys->right.key_pressed_down;



	Player1->logic = SET_RND_BLOCK;
	Player2->logic = SET_RND_BLOCK;
	cpu->logic = SET_RND_BLOCK;

	countergems = new bool();
	gauge_on = new bool();

	*countergems = true;
	*gauge_on = true;


	engine->sound_system->create_sound("hit.wav");
	engine->sound_system->create_sound("explode.wav");
	engine->sound_system->create_sound("select.wav");
	engine->sound_system->create_sound("selected.wav");
	engine->sound_system->create_sound("KO.wav");
	engine->sound_system->create_sound("party.wav");


	return 0;
}

int clean_up()
{
	delete gauge_on;
	gauge_on = NULL;

	delete countergems;
	countergems = NULL;

	delete engine;
	engine=NULL;

	delete kitteh;
	kitteh=NULL;
	
	delete prinny;
	prinny=NULL;

	delete bart;
	bart=NULL;

	delete Player1;
	Player1=NULL;
	
	delete Player2;
	Player2=NULL;
	return 0;
}

