#ifndef SPRITE_H
#define SPRITE_H
class frame
{
	public:
		int width;
		int height;
		int x_postion_in_picture;
		int y_postion_in_picture;
	private:

};

class sprite
{
	public:
       char* name;
       int total_frames;
       frame* frames;
       SDL_Surface* image;
       SDL_Surface* surface;
       
       int show(int frame, int x, int y);
       int animate(int engine_frame, int framesper,int x,int y);
       
       int animated_frame;
       
       sprite(int totalframes,SDL_Surface* thesurface, SDL_Surface* theimage);
       sprite* next;
       ~sprite();
	private:
            int apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
};

class spritelist
{
      public:
             sprite* first;
             sprite* current;
             
             sprite* search;
             sprite* temp;
             
             SDL_Surface *surface;
             SDL_Surface *image;
             char* hashtable;
             int size;
             
             
             int addtotable(int address,char* key);
             int* searchtable(char* key, int index);
             
             spritelist(SDL_Surface* thesurface, SDL_Surface* theimage);
             ~spritelist();
             
             void create_sprites(char* name,int sprites_frames, int start_x, int start_y, int width, int height,int horver);
             sprite* get_sprite(int index,char* name);
      private:
};

sprite::sprite(int totalframes,SDL_Surface* thesurface, SDL_Surface* theimage)
{
    surface = thesurface;
    image = theimage;
    total_frames = totalframes;
    frames = new frame[totalframes];
    animated_frame=0;
}

sprite::~sprite()
{
    delete[] frames;
    frames = NULL;
}

int sprite::show(int frame,int x, int y)
{
	SDL_Rect clip;
	clip.x = frames[frame].x_postion_in_picture;
	clip.y = frames[frame].y_postion_in_picture;
	clip.w = frames[frame].width;    	
	clip.h = frames[frame].height;
	apply_surface( x, y, image, surface,&clip );    
}

int sprite::animate(int engine_frame, int framesper,int x,int y)
{

         show(animated_frame,x,y);
        
         if (engine_frame % framesper == 1)
         {  
              animated_frame++;
         
              if (animated_frame == total_frames) animated_frame = 0;
         } 
}
#endif

int sprite::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL)
{
   
    SDL_Rect offset;


    offset.x = x;
    offset.y = y;


    SDL_BlitSurface( source, clip, destination, &offset );
    
}

int spritelist::addtotable(int address,char* key)
{
    char* temphashtable;
    char* newhashtable;
    
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
    
    
    temphashtable = new char[255];
    for (int z=0;z<255;z++)
    {
	temphashtable[z] = '\0';
    }
    
    sprintf(temphashtable,"%i",i);

    int nsize = size * 2; 
    
    newhashtable = new char[nsize];
    for (int t=0;t<nsize;t++)
    {
	newhashtable[t] = '\0';
    }


    
    strcpy(newhashtable,hashtable);
     

    strcat(newhashtable,temphashtable);  
    
   // printf("%s %i",newhashtable,address); 
    
    delete temphashtable;
    temphashtable=NULL;
    
    if (hashtable != NULL)
    {
         delete hashtable;
         hashtable=NULL;
    }
    
     hashtable=newhashtable;
    // temphashtable=NULL;
     size *= 2;
    
}

int* spritelist::searchtable(char* key, int index)
{
    
    char* temp = new char[255];
    int j=0;
    int found=0;
    int postion=(index-1)*10;

    
    for (int w=0;w<255;w++)
    {
	temp[w] = '\0';
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

    delete temp;
    temp=NULL;
    
    
    return (int*) l;
}

void spritelist::create_sprites(char* name,int sprites_frames, int start_x, int start_y, int width, int height,int horver)
{
     
    if (first ==  NULL)
    {
              first = new sprite(sprites_frames,image,surface);
            //  first->name = new char[strlen(name)+1];
             // strcpy(first->name,name);
              current = first;
              current->next = NULL;
              addtotable((int) first, name);
          
              current->frames = new frame[sprites_frames];
	          for (int x=0;x<sprites_frames;x++)
	          {
                 		current->frames[x].width = width;
		                current->frames[x].height = height;
	                    if (horver == 0)
		                {
			               current->frames[x].y_postion_in_picture = start_y;
			               current->frames[x].x_postion_in_picture = start_x+(width*x);
		                } else {
			              current->frames[x].y_postion_in_picture = start_y+(height*x);
			              current->frames[x].x_postion_in_picture= start_x;
		               } 
              }
    }else {
              if (current->next == NULL)
              {
                  current->next = new sprite(sprites_frames,image,surface);
                 // current->next->name = new char[strlen(name)+1];
                  //strcpy(current->next->name,name);
                  
                 
                  current = current->next;
		  current->next = NULL;
                  addtotable((int) current, name);

                  current->frames = new frame[sprites_frames];
	              for (int x=0;x<sprites_frames;x++)
	              {
                 		current->frames[x].width = width;
		                current->frames[x].height = height;
	                    if (horver == 0)
		                {
			               current->frames[x].y_postion_in_picture = start_y;
			               current->frames[x].x_postion_in_picture = start_x+(width*x);
		                } else {
			              current->frames[x].y_postion_in_picture = start_y+(height*x);
			              current->frames[x].x_postion_in_picture= start_x;
		               } 
                  }
              }
    }  
    
}

spritelist::spritelist(SDL_Surface* thesurface, SDL_Surface* theimage)
{
    first = NULL;
    current=NULL;
    surface = thesurface;
    image=theimage;
    size=8;
    hashtable = new char[size];
    for (int x=0;x<size;x++)
    {
	hashtable[x] = '\0';
    }
}

spritelist::~spritelist()
{
     bool is_done=true;
     
    search =  first;  
     while(is_done == false)
     {
         if (search != NULL)
         {
              temp = search;
              search = search->next;

              delete[] temp->frames;
              temp->frames = NULL;			
	          
              delete temp;
              temp = NULL;
         } else
         if (search==NULL) is_done=true;
     }
}

sprite* spritelist::get_sprite(int index,char* name)
{
      return (sprite*) searchtable(name,index);
}

