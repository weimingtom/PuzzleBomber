#ifndef ENGINE_H
#define ENGINE_H

#include "SDL/SDL.h" 
#include "log.h"
#include "timer.h"
#include "text.h"
#include "image.h"
#include "keys.h"
#include "sounds.h"

/*
Things to do:
       
       x Make an easy way to access the node in the linked list. (hash indexing?)
       / Make an Error  System.
       / make windowed strechable and full screen
       x sprites in the image class
       x load image from memory
       x Default font loads from memory.
       x Make font loadable from memory. 
       * flip/rotate image function in the image class
       * Set postion in sound/music
       * Fade ins for music
       * make mouse usable 
       * make joystick usable

*/

#define Thread SDL_Thread

class Engine
{
      public:
             int screen_width;
             int screen_height;
             int screen_bbp;
             int frame_per_second;
             char* title;
             bool is_backbuffer_on;
             keys* Keys;
             images* Images;
             sound* sound_system;
             texts* Texts;
             
             int toggle_screen(int whichsize,int height, int width);
	     Thread *CreateThread(int (*fn)(void *), void *data);    

	     void KillThread(Thread *hwnd);        
        

             
             Engine();
             ~Engine();
             int set_title(char* title);
             int paintbg(int r,int b, int g);  
             bool KeysHandler();
             int init_engine();
             int frame_rate_start();
             int clear_buffer();
             int doublebuffer();
             int set_transparency_color(Uint8 red, Uint8 green,Uint8 blue);
             int start_timer(); 
             bool fullscreen;
             Uint32 get_pixel32( int x, int y ) ;
             Uint8 r;
             Uint8 g;
             Uint8 b;
             int flip_frame();
             int frame;
 	     SDL_Surface *screen;
	     bool check_collision( int x, int y, int x2, int y2 );
      private:
             log* enginelog;
             SDL_Surface *backbuffer;
             SDL_Surface *background;
             
             Timer fps;
             SDL_Event event;
             
             
             int createbackbuffer();
             int insertbackbuffer(SDL_Surface *surface,int x, int y);
             Uint32 get_pixel32( SDL_Surface *surface, int x, int y );
             void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );
             int Cal_Frame_Rate();
             int apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
	     
};

Engine::Engine()
{
     title=NULL;
     Images=NULL;
     sound_system=NULL;
     Texts=NULL;
     Keys=NULL;
     screen=NULL;
     backbuffer=NULL;
     background=NULL;
     enginelog=NULL;

     screen_width=640;
     screen_height=480;
     frame_per_second=15;
     screen_bbp=32;
     
     Keys = new keys;
     
     fullscreen =false;
     frame=0;
}


SDL_Thread *Engine::CreateThread(int (*fn)(void *), void *data)
{
	 return SDL_CreateThread( fn, data );
}

void Engine::KillThread(Thread *hwnd)
{
	SDL_KillThread(hwnd);
}        


bool Engine::check_collision( int x, int y, int x2, int y2 )
{
	int leftA = x;
	int rightA = x+32;
	int topA = y;
	int bottomA = y + 32;

	int leftB = x2;
	int rightB = x2+32;
	int topB = y2;
	int bottomB = y2 + 32;

	if (bottomA <= topB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}
}


Uint32 Engine::get_pixel32(int x, int y )
{
     Uint32 *pixels = (Uint32 *)screen->pixels;
    //Get the requested pixel
    return pixels[ ( y * screen->w ) + x ];
}


int Engine::set_title(char* title)
{
	SDL_WM_SetCaption( title, NULL );
	return 0;
}

int Engine::toggle_screen(int whichsize,int height=0, int width=0)
{
    if (height=0 && width == 0)
    {
        height=screen_height;
        width=screen_width;
    }
    if (whichsize == 0)
    {
        screen = SDL_SetVideoMode( width, height, screen_bbp, SDL_SWSURFACE  | SDL_FULLSCREEN ); 
    } else {
        screen = SDL_SetVideoMode( width, height, screen_bbp, SDL_SWSURFACE );    
    }

    return 0;
}

int Engine::doublebuffer()
{
   //apply_surface(0,0,backbuffer,screen,NULL);     
   flip_frame();                 
}




int Engine::set_transparency_color(Uint8 red, Uint8 green,Uint8 blue)
{
     r = red;
     g = green;
     b = blue;
   // Uint32 colorkey = SDL_MapRGB( backbuffer->format,  red,  green,  blue );

   // SDL_SetColorKey( backbuffer,  SDL_RLEACCEL  | SDL_SRCCOLORKEY, colorkey ); 
    

    Uint32 colorkey2 = SDL_MapRGB( screen->format,  red,  green,  blue );

    SDL_SetColorKey( screen,SDL_SRCCOLORKEY, colorkey2 );     
}
int Engine::createbackbuffer()
{

    backbuffer = SDL_CreateRGBSurface( SDL_SWSURFACE, screen->w, screen->h, screen->format->BitsPerPixel, screen->format->Rmask, screen->format->Gmask, screen->format->Bmask, 0 );
    Uint32 colorkey = SDL_MapRGB( backbuffer->format, r, g, b );

    SDL_SetColorKey( backbuffer,  SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
    

    return 0;
}

int Engine::insertbackbuffer(SDL_Surface *source,int x, int y)
{
    SDL_Rect offset;


    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, backbuffer, &offset );

    return 0;
}


int Engine::clear_buffer()
{
      SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) ); 

}

int Engine::paintbg(int r,int b, int g)
{
      SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, r, b, g ) ); 

}

Engine::~Engine()
{
     delete Texts;
     Texts=NULL;
     
     delete Images;
     Images=NULL;
     
     delete Keys;
     Keys=NULL;
     
     delete sound_system;
     sound_system=NULL;
     
  //   SDL_FreeSurface(backbuffer);
     SDL_FreeSurface(screen);
     
     SDL_Quit(); 
}

int Engine::flip_frame()
{
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
}

int Engine::frame_rate_start()
{
        //Increment the frame counter
        frame++;

        //If we want to cap the frame rate
        if( ( fps.get_ticks() < 1000 / frame_per_second ) )
        {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / frame_per_second ) - fps.get_ticks() );
        }
    
}

bool Engine::KeysHandler()
{
        while( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
/*
            if(event.type == SDL_VIDEORESIZE)
            {
                          screen = SDL_SetVideoMode( event.resize.w, event.resize.h, screen_bbp, SDL_SWSURFACE | SDL_RESIZABLE ); //If there's an error if( screen == NULL ) { windowOK = false; return; } 
                          if (screen == NULL)
                          {
                                     enginelog->write("Engine log: Error resizing the screen\n");
                          }
            }
*/
            if( event.type == SDL_KEYDOWN )
            {
		   Keys->key_down = true;
                   switch(event.key.keysym.sym)
                   {
                        case SDLK_1:
                        {
                             Keys->one.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_2:
                        {
                             Keys->two.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_3:
                        {
                             Keys->three.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_4:
                        {
                             Keys->four.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_5:
                        {
                             Keys->five.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_6:
                        {
                             Keys->six.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_7:
                        {
                             Keys->seven.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_8:
                        {
                             Keys->eight.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_9:
                        {
                             Keys->nine.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_0:
                        {
                             Keys->zero.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_a:
                        {
                             Keys->a.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_b:
                        {
                             Keys->b.key_pressed_down = true;
                             
                             break;
                        }
                         case SDLK_c:
                        {
                             Keys->c.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_d:
                        {
                             Keys->d.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_e:
                        {
                             Keys->e.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_f:
                        {
                             Keys->f.key_pressed_down = true;
                             
                             break;
                        }      
                        case SDLK_g:
                        {
                             Keys->g.key_pressed_down = true;
                             
                             break;
                        }   
                        case SDLK_h:
                        {
                             Keys->h.key_pressed_down = true;
                             
                             break;
                        }  
                        case SDLK_j:
                        {
                             Keys->j.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_k:
                        {
                             Keys->k.key_pressed_down = true;
                             
                             break;
                        }  
                        case SDLK_l:
                        {
                             Keys->l.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_m:
                        {
                             Keys->m.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_n:
                        {
                             Keys->n.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_o:
                        {
                             Keys->o.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_p:
                        {
                             Keys->p.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_q:
                        {
                             Keys->q.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_r:
                        {
                             Keys->r.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_s:
                        {
                             Keys->s.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_t:
                        {
                             Keys->t.key_pressed_down = true;
                             
                             break;
                        } 
                         case SDLK_v:
                        {
                             Keys->v.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_w:
                        {
                             Keys->w.key_pressed_down = true;
                             
                             break;
                        }           
                        case SDLK_x:
                        {
                             Keys->x.key_pressed_down = true;
                             
                             break;
                        } 
                        case SDLK_y:
                        {
                             Keys->y.key_pressed_down = true;
                             
                             break;
                        }    
                        case SDLK_z:
                        {
                             Keys->z.key_pressed_down = true;
                             
                             break;
                        } 
                       case SDLK_DELETE:
                        {
                             Keys->del.key_pressed_down = true;
                             
                             break;
                        }
                       case SDLK_TAB:
                        {
                             Keys->tab.key_pressed_down = true;
                             
                             break;
                        }
                       case SDLK_CLEAR:
                        {
                             Keys->clear.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_RETURN:
                        {
                             Keys->enter.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_SPACE:
                        {
                             Keys->space.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_UP:
                        {
                             Keys->up.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_DOWN:
                        {
                             Keys->down.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_LEFT:
                        {
                             Keys->left.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_RIGHT:
                        {
                             Keys->right.key_pressed_down = true;
                             
                             break;
                        }

                        case SDLK_ESCAPE:
                        {
                             Keys->esc.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_RCTRL:
                        {
                             Keys->rctrl.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_LCTRL:
                        {
                             Keys->lctrl.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_RALT:
                        {
                             Keys->ralt.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_LALT:
                        {
                             Keys->lalt.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_LSHIFT:
                        {
                             Keys->lshift.key_pressed_down = true;
                             
                             break;
                        }
                        case SDLK_RSHIFT:
                        {
                             Keys->rshift.key_pressed_down = true;
                             
                             break;
                        }
                   }
            }
            
            if( event.type == SDL_KEYUP )
            {
		   Keys->key_down = false;
                   switch(event.key.keysym.sym)
                   {
                        case SDLK_1:
                        {
                             if (Keys->one.key_pressed_down == true)
                             {
                                 Keys->one.key_pressed_down=false;
                                 Keys->one.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_2:
                        {
                             if (Keys->two.key_pressed_down == true)
                             {
                                 Keys->two.key_pressed_down=false;
                                 Keys->two.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_3:
                        {
                             if (Keys->three.key_pressed_down == true)
                             {
                                 Keys->three.key_pressed_down=false;
                                 Keys->three.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_4:
                        {
                             if (Keys->four.key_pressed_down == true)
                             {
                                 Keys->four.key_pressed_down=false;
                                 Keys->four.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_5:
                        {
                             if (Keys->five.key_pressed_down == true)
                             {
                                 Keys->five.key_pressed_down=false;
                                 Keys->five.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_6:
                        {
                             if (Keys->six.key_pressed_down == true)
                             {
                                 Keys->six.key_pressed_down=false;
                                 Keys->six.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_7:
                        {
                             if (Keys->seven.key_pressed_down == true)
                             {
                                 Keys->seven.key_pressed_down=false;
                                 Keys->seven.is_key_pressed = true;
                             }
                             
                             break;
                        }   
                        case SDLK_8:
                        {
                             if (Keys->eight.key_pressed_down == true)
                             {
                                 Keys->eight.key_pressed_down=false;
                                 Keys->eight.is_key_pressed = true;
                             }
                             
                             break;
                        }   
                         case SDLK_9:
                        {
                             if (Keys->nine.key_pressed_down == true)
                             {
                                 Keys->nine.key_pressed_down=false;
                                 Keys->nine.is_key_pressed = true;
                             }
                             
                             break;
                        }         
                         case SDLK_0:
                        {
                             if (Keys->zero.key_pressed_down == true)
                             {
                                 Keys->zero.key_pressed_down=false;
                                 Keys->zero.is_key_pressed = true;
                             }
                             
                             break;
                        }           
                        case SDLK_a:
                        {
                             if (Keys->a.key_pressed_down == true)
                             {
                                 Keys->a.key_pressed_down=false;
                                 Keys->a.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_b:
                        {
                             if (Keys->b.key_pressed_down == true)
                             {
                                 Keys->b.key_pressed_down=false;
                                 Keys->b.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_c:
                        {
                             if (Keys->c.key_pressed_down == true)
                             {
                                 Keys->c.key_pressed_down=false;
                                 Keys->c.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_d:
                        {
                             if (Keys->d.key_pressed_down == true)
                             {
                                 Keys->d.key_pressed_down=false;
                                 Keys->d.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_e:
                        {
                             if (Keys->e.key_pressed_down == true)
                             {
                                 Keys->e.key_pressed_down=false;
                                 Keys->e.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_f:
                        {
                             if (Keys->f.key_pressed_down == true)
                             {
                                 Keys->f.key_pressed_down=false;
                                 Keys->f.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_g:
                        {
                             if (Keys->g.key_pressed_down == true)
                             {
                                 Keys->g.key_pressed_down=false;
                                 Keys->g.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_h:
                        {
                             if (Keys->h.key_pressed_down == true)
                             {
                                 Keys->h.key_pressed_down=false;
                                 Keys->h.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_i:
                        {
                             if (Keys->i.key_pressed_down == true)
                             {
                                 Keys->i.key_pressed_down=false;
                                 Keys->i.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_j:
                        {
                             if (Keys->j.key_pressed_down == true)
                             {
                                 Keys->j.key_pressed_down=false;
                                 Keys->j.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_k:
                        {
                             if (Keys->k.key_pressed_down == true)
                             {
                                 Keys->k.key_pressed_down=false;
                                 Keys->k.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_l:
                        {
                             if (Keys->l.key_pressed_down == true)
                             {
                                 Keys->l.key_pressed_down=false;
                                 Keys->l.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_m:
                        {
                             if (Keys->m.key_pressed_down == true)
                             {
                                 Keys->m.key_pressed_down=false;
                                 Keys->m.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_n:
                        {
                             if (Keys->n.key_pressed_down == true)
                             {
                                 Keys->n.key_pressed_down=false;
                                 Keys->n.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_o:
                        {
                             if (Keys->o.key_pressed_down == true)
                             {
                                 Keys->o.key_pressed_down=false;
                                 Keys->o.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_p:
                        {
                             if (Keys->p.key_pressed_down == true)
                             {
                                 Keys->p.key_pressed_down=false;
                                 Keys->p.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_q:
                        {
                             if (Keys->q.key_pressed_down == true)
                             {
                                 Keys->q.key_pressed_down=false;
                                 Keys->q.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_r:
                        {
                             if (Keys->r.key_pressed_down == true)
                             {
                                 Keys->r.key_pressed_down=false;
                                 Keys->r.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_s:
                        {
                             if (Keys->s.key_pressed_down == true)
                             {
                                 Keys->s.key_pressed_down=false;
                                 Keys->s.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_t:
                        {
                             if (Keys->t.key_pressed_down == true)
                             {
                                 Keys->t.key_pressed_down=false;
                                 Keys->t.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_u:
                        {
                             if (Keys->u.key_pressed_down == true)
                             {
                                 Keys->u.key_pressed_down=false;
                                 Keys->u.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_v:
                        {
                             if (Keys->v.key_pressed_down == true)
                             {
                                 Keys->v.key_pressed_down=false;
                                 Keys->v.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_w:
                        {
                             if (Keys->w.key_pressed_down == true)
                             {
                                 Keys->w.key_pressed_down=false;
                                 Keys->w.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_x:
                        {
                             if (Keys->x.key_pressed_down == true)
                             {
                                 Keys->x.key_pressed_down=false;
                                 Keys->x.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_y:
                        {
                             if (Keys->y.key_pressed_down == true)
                             {
                                 Keys->y.key_pressed_down=false;
                                 Keys->y.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_z:
                        {
                             if (Keys->z.key_pressed_down == true)
                             {
                                 Keys->z.key_pressed_down=false;
                                 Keys->z.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_DELETE:
                        {
                             if (Keys->del.key_pressed_down == true)
                             {
                                 Keys->del.key_pressed_down=false;
                                 Keys->del.is_key_pressed = true;
                             }
                             break;
                        }
                        
                        case SDLK_TAB:
                        {
                             if (Keys->tab.key_pressed_down == true)
                             {
                                 Keys->tab.key_pressed_down=false;
                                 Keys->tab.is_key_pressed = true;
                             }
                             break;
                        }
                        case SDLK_CLEAR:
                        {
                             if (Keys->clear.key_pressed_down == true)
                             {
                                 Keys->clear.key_pressed_down=false;
                                 Keys->clear.is_key_pressed = true;
                             }
                             break;
                        }
                        case SDLK_RETURN:
                        {
                             if (Keys->enter.key_pressed_down == true)
                             {
                                 Keys->enter.key_pressed_down=false;
                                 Keys->enter.is_key_pressed = true;
                             }
                             break;
                        }
                        case SDLK_UP:
                        {
                             if (Keys->up.key_pressed_down == true)
                             {
                                 Keys->up.key_pressed_down=false;
                                 Keys->up.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_DOWN:
                        {
                             if (Keys->down.key_pressed_down == true)
                             {
                                 Keys->down.key_pressed_down=false;
                                 Keys->down.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_LEFT:
                        {
                             if (Keys->left.key_pressed_down == true)
                             {
                                 Keys->left.key_pressed_down=false;
                                 Keys->left.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_RIGHT:
                        {
                             if (Keys->right.key_pressed_down == true)
                             {
                                 Keys->right.key_pressed_down=false;
                                 Keys->right.is_key_pressed = true;
                             }
                             
                             break;
                        }

                        case SDLK_ESCAPE:
                        {
                             if (Keys->esc.key_pressed_down == true)
                             {
                                 Keys->esc.key_pressed_down=false;
                                 Keys->esc.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_SPACE:
                        {
                             if (Keys->space.key_pressed_down == true)
                             {
                                 Keys->space.key_pressed_down=false;
                                 Keys->space.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_RCTRL:
                        {
                             if (Keys->rctrl.key_pressed_down == true)
                             {
                                 Keys->rctrl.key_pressed_down=false;
                                 Keys->rctrl.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_LCTRL:
                        {
                             if (Keys->lctrl.key_pressed_down == true)
                             {
                                 Keys->lctrl.key_pressed_down=false;
                                 Keys->lctrl.is_key_pressed = true;
                             }
                             
                             break;
                        }                      
                        case SDLK_RALT:
                        {
                             if (Keys->ralt.key_pressed_down == true)
                             {
                                 Keys->ralt.key_pressed_down=false;
                                 Keys->ralt.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_LALT:
                        {
                             if (Keys->lalt.key_pressed_down == true)
                             {
                                 Keys->lalt.key_pressed_down=false;
                                 Keys->lalt.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_LSHIFT:
                        {
                             if (Keys->lshift.key_pressed_down == true)
                             {
                                 Keys->lshift.key_pressed_down=false;
                                 Keys->lshift.is_key_pressed = true;
                             }
                             
                             break;
                        }
                        case SDLK_RSHIFT:
                        {
                             if (Keys->rshift.key_pressed_down == true)
                             {
                                 Keys->rshift.key_pressed_down=false;
                                 Keys->rshift.is_key_pressed = true;
                             }
                             
                             break;
                        }
                   }
            }

            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                return true;
            }
        }
}

int Engine::start_timer()
{
    fps.start();
    return 0;
}

int Engine::init_engine()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        enginelog->write("Engine Log: Error SDL could not be INIT");
        return false;
    }
    
    
    if (fullscreen == true)
    {
       screen = SDL_SetVideoMode( screen_width, screen_height, screen_bbp, SDL_SWSURFACE | /*SDL_RESIZABLE |*/ SDL_FULLSCREEN);
    } else {
       screen = SDL_SetVideoMode( screen_width, screen_height, screen_bbp, SDL_SWSURFACE /*| SDL_RESIZABLE*/ );
    }
    if (screen == NULL)
    {
       enginelog->write("Engine Log: screen can't not be set.");
       return false;
    }
    

       
    //createbackbuffer();

    Texts=new texts(screen);
    Images=new images(screen,0xff,0,0xff);
    sound_system=new sound();
}

Uint32 Engine::get_pixel32( SDL_Surface *surface, int x, int y )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void Engine::put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Set the pixel
    pixels[ ( y * surface->w ) + x ] = pixel;
}


int Engine::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
#endif
