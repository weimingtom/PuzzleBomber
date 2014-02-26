#ifndef TEXT_H
#define TEXT_H
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "times.h"


static const int TextBucketNum=10;
static const int TextMultiplier = -166417991L;


class phont
{
	public:
		TTF_Font *Font;
		phont *next;
		phont(char* fontname,int fontsize);

};

phont::phont(char* fontname, int fontsize)
{
	Font = NULL;
	next = NULL;
	Font = TTF_OpenFont( fontname, fontsize );     

}


class phontlist
{
	public:
        char* hashtable;
        int size;

	phont *first;
	phont *current;

	phont *search;
	phont *temp;
	int addfont(char* fontname,int fontsize);
	phontlist();
	~phontlist();

	int addtotable(int address,char* key);
	int *searchtable(char* key, int index);
};

int phontlist::addfont(char* fontname, int fontsize)
{
    if (first ==  NULL)
    {
	      
              first = new phont(fontname,fontsize);
              addtotable((int) first,fontname);
              current = first;
              current->next = NULL;
    }else {
              if (current->next == NULL)
              {
                  current->next = new phont(fontname,fontsize);
		  current = current->next;
		  current->next = NULL;
                  addtotable((int) current, fontname);
              }
    }

}

phontlist::phontlist()
{
     first=NULL;
     current=NULL;
     search=NULL;
     size=12;
     hashtable = NULL;
     hashtable = new char[size];
     for (int o=0;o<size;o++)
     {
 	hashtable[o] = '\0';
     }

}

phontlist::~phontlist()
{
     if (hashtable != NULL) 
     {
         delete hashtable;
         hashtable=NULL;
     }
     bool is_done=false;
     search=first;
     
     while(is_done == false)
     {
         if (search != NULL)
         {
              temp = search;
              search = search->next;
              delete temp;
              temp = NULL;
         } else
         if (search==NULL) is_done=true;
     }

}


int phontlist::addtotable(int address,char* key)
{
    char* temphashtable = new char[12];
    char* newhashtable=NULL;
    
    int i=0;
    int j=0;
    
    i = address;

    
    j=0;
 
    for (int k = 0;k<4;k++)
    {   
        j <<= 8;
        j |= (int) *(key+k);
        
    }
 
    i ^= j;
    
    

    
    for (int o=0;o<12;o++)
    {
	temphashtable[o] = '\0';
    }

    
    sprintf(temphashtable,"%i",i);

    int nsize = size+strlen(temphashtable);

 
    
    newhashtable = new char[nsize];

    
    for (int o=0;o<nsize;o++)
    {
	newhashtable[o] = '\0';
    }

    
    
    strcpy(newhashtable,hashtable);
     

    strcat(newhashtable,temphashtable);  
    
    
    //delete temphashtable;
    //temphashtable=NULL;
    
    if (hashtable != NULL)
    {
         delete hashtable;
         hashtable=NULL;
    }
    
     hashtable=newhashtable;
     size = nsize;
    
}

int* phontlist::searchtable(char* key, int index)
{
    
    char* temp = new char[strlen(hashtable)+1];
    int j=0;
    int found=0;
    int postion=(index-1)*10;

    for (int o=0;o<strlen(hashtable);o++)
    {
	temp[o] = '\0';
    }
    
    for (int i=postion;i < postion+10;i++)
    {
        temp[j] = hashtable[i];
        j++;
    }
    
    temp[j] = '\0';
    
    found = atoi(temp);
    
    int l = found;
    
    int m=0;
 
    for (int k = 0;k<4;k++)
    {   
        m <<= 8;
        m |= (int) *(key+k);
        
    }

    l ^= m;

   // delete temp;
   // temp=NULL;
    
    
    return (int*) l;
}




class text
{
      public:
	     int TID;
             TTF_Font *Font;
             SDL_Color TextColor;
             SDL_Surface *mainsurface;
             SDL_Surface *textsurface;
             text(void* mem,int size,phont* fontname,int fontsize, SDL_Surface *tsurface);
             ~text();
             int print(char text[],int x,int y,int r,int g, int b);
	     int printf(char text[], int x, int y, int r, int g, int b);
             SDL_Surface *message;
             int set_text(char message[], int r, int g, int b);
             char* name;
             text* next; 
	     int alpha;
             log* textlog; 
             Uint32 get_pixel32( SDL_Surface *surface, int x, int y );
             void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );


        private:
              int apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);    
};


text::text(void* mem,int size,phont* fontname,int fontsize, SDL_Surface *msurface)
{
    SDL_RWops	*rw_out=NULL;

    textsurface=NULL;
    mainsurface = NULL;
    next=NULL;

    
    name=NULL;
    textlog=NULL;              
    Font = NULL;

    TTF_Init();
    Font =  fontname->Font;
                  
    textlog = new log;
    
   

     mainsurface = msurface;            

     
     TextColor.r = 255;
    TextColor.b = 255;
    TextColor.g = 255;

    message = NULL;
    
     alpha = SDL_ALPHA_OPAQUE;

   
      
}

text::~text()
{
    if (name != NULL)
    {
	 delete name;
	name = NULL;
    }
    delete textlog;
    textlog=NULL;
    SDL_FreeSurface(message);
    message=NULL;
}

int text::set_text(char text[], int r=255,int g=255, int b=255)
{
    if (Font != NULL)
    {
    	TextColor.r = r;
   	TextColor.b = b;
   	TextColor.g = g;

        message = TTF_RenderText_Solid( Font, text, TextColor ); 
    }
}

int text::print(char text[],int x=1,int y=1,int r=255, int g=255, int b=255)
{
    TextColor.r = r;
    TextColor.b = b;
    TextColor.g = g;
    if (message == NULL)
    {
    	message = TTF_RenderText_Solid( Font, text, TextColor ); 
    }
    apply_surface( x, y, message, mainsurface,NULL ); 

   // SDL_FreeSurface(message);
}


int text::printf(char text[],int x=1,int y=1,int r=255, int g=255, int b=255)
{
    TextColor.r = r;
    TextColor.b = b;
    TextColor.g = g;
    apply_surface( x, y, message, mainsurface,NULL ); 

   // SDL_FreeSurface(message);
}

int text::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL)
{
    SDL_Rect offset;


    offset.x = x;
    offset.y = y;


    SDL_BlitSurface( source, clip, destination, &offset );  
}

class texts
{
      public:
             ~texts();
             texts(SDL_Surface *msurf);
	
	     phontlist *fonts;

	     TTF_Font *defautFont;

             int create_font(char* fontname,int size); 
             int create_text(char* name, char* fontname,int fontindex,void* mem=NULL,int size=0);
             int show_text(int index,char* name, char yourtext[],int x,int y,int r, int g, int b);
	     int increase_alpha(int index, char* name);
	     int decrease_alpha(int index, char* name);
	     int set_alpha(char* key, int alpha);

  	     text* buckets[TextBucketNum];
	     int hash(char* name, int nBuckets);
	     text *find(char* name, text* list);
	     int add(char* name,char *fontname, int findex); 
           
      
             SDL_Surface *msurface;
             char* hashtable;
             int size;
             
             int addtotable(int address,char* key);
             text* searchtable(char* key, int index);
             
             text* first;
             text* current;
             
             text* search;
             text* temp;
	     int count;
};

texts::texts(SDL_Surface *msurf)
{
     
     TTF_Init();
     for (int i=0;i<TextBucketNum;i++)
     {
     	 buckets[i] = NULL;
     }
     fonts = NULL;
     msurface=NULL;
     msurface = msurf;
     first=NULL;
     current=NULL;
     search=NULL;
     temp=NULL;
     hashtable=NULL;
     defautFont=NULL;
     fonts = new phontlist();
     
     size=12;
     hashtable = new char[size];
     for (int o=0;o<size;o++)
     {
 	hashtable[o] = '\0';
     }
     
}

texts::~texts()
{
     for (int i=0;i<TextBucketNum;i++)
     {
 		if (buckets[i] != NULL)
		{
		        bool is_done=false;
			text* linkedlist = buckets[i];

    			while(is_done == false)
     			{
         			if (linkedlist != NULL)
         			{
              				text *temp = linkedlist;
              				linkedlist = linkedlist->next;
              				delete temp;
              				temp = NULL;
         			} else
         				if (linkedlist==NULL) is_done=true;
     			}
		

		}
     }
}


int texts::add(char* name, char* fontname, int findex)
{
	int whichBucket = hash(name,TextBucketNum);
	text *match = find(name,buckets[whichBucket]);
	if (match != NULL)
	{
	} else {
		text* newOne = new text(NULL,0,(phont*) fonts->searchtable(fontname,findex),0,msurface);
		newOne->name = new char[strlen(name)];
		strcpy(newOne->name, name);
		newOne->next = buckets[whichBucket];
		buckets[whichBucket] = newOne;
	}
}

int texts::hash(char* name, int nBuckets)
{
	unsigned long hashcode = 0;
	for (int i = 0; i < strlen(name);i++)
	{
		hashcode = hashcode * TextMultiplier + name[i];
	}
	
	return (hashcode % nBuckets);
}


text *texts::find(char* name, text* list)
{
	for (text *cur = list;cur != NULL;cur = cur->next)
	{
		if (strcmp(cur->name,name) == 0) return cur;
	}
	return NULL;
}


int texts::create_font(char* fontname, int fontsize)
{
	fonts->addfont(fontname,fontsize);
}

int texts::create_text(char* name,char* fontname,int fontindex,void* mem, int size)
{
	add(name,fontname,fontindex);
       
}

int texts::show_text(int index,char* name, char yourtext[],int x=0,int y=0,int r=255,int g=255, int b=255)
{


   int whichBucket = hash(name,TextBucketNum);
   text *match = find(name,buckets[whichBucket]);

   if (match != NULL)
   {
   	match->print(yourtext,x,y,r,g,b);
   }

}
int texts::set_alpha(char* name, int alpha)
{
	search = (text*) searchtable(name,0);
	SDL_SetAlpha( search->message, SDL_SRCALPHA, alpha );
	
}
int texts::increase_alpha(int index, char* name)
{

	search = (text*) searchtable(name,index);
	SDL_SetAlpha( search->message, SDL_SRCALPHA, search->alpha );
	search->alpha+=5;
	return search->alpha;
}
int texts::decrease_alpha(int index, char* name) 
{
	search = (text*) searchtable(name,index);
	SDL_SetAlpha( search->message, SDL_SRCALPHA, search->alpha );
	search->alpha-=5;
	return search->alpha;
}



Uint32 text::get_pixel32( SDL_Surface *surface, int x, int y )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void text::put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Set the pixel
    pixels[ ( y * surface->w ) + x ] = pixel;
}

int texts::addtotable(int address,char* key)
{
    char* temphashtable = new char[12];
    char* newhashtable=NULL;
    
    int i=0;
    int j=0;
    
    i = address;

    
    j=0;
 
    for (int k = 0;k<4;k++)
    {   
        j <<= 8;
        j |= (int) *(key+k);
        
    }
 
    i ^= j;
    
    

    
    for (int o=0;o<12;o++)
    {
	temphashtable[o] = '\0';
    }

    
    sprintf(temphashtable,"%i",i);

    int nsize = size+strlen(temphashtable);
 
    
    newhashtable = new char[nsize];

    
    for (int o=0;o<nsize;o++)
    {
	newhashtable[o] = '\0';
    }

    
    
    strcpy(newhashtable,hashtable);
     

    strcat(newhashtable,temphashtable);  
    
    
 
    
    if (hashtable != NULL)
    {
         delete hashtable;
         hashtable=NULL;
    }
    
     hashtable=newhashtable;
     size = nsize;
    
}

text* texts::searchtable(char* key, int index)
{
    int whichBucket = hash(key,TextBucketNum);
    text *match = find(key,buckets[whichBucket]);
    return match;
}
#endif
