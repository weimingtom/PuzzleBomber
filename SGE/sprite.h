#ifndef SPRITE_H
#define SPRITE_H

static const int MultiplierS = -166417991L;


class frame
{
	public:
		int width;
		int height;
		int x_postion_in_picture;
		int y_postion_in_picture;
	private:

};

static const int SpriteBucketNum=10;

class sprite
{
	public:
       char name[255];
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
            
	     sprite* spritebuckets[SpriteBucketNum];
	     int hash(char* key, int nBuckets);
	     sprite *find(char* key, sprite* list);
	     int add(char* key,int sprites_frames, int start_x, int start_y, int width, int height,int horver);
             
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
    add(name,sprites_frames,start_x,start_y, width,height,horver);

}

spritelist::spritelist(SDL_Surface* thesurface, SDL_Surface* theimage)
{
    for (int i=0;i<SpriteBucketNum;i++)
    {
		spritebuckets[i] = NULL;
    }

    hashtable = NULL;
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
     for (int i=0;i<SpriteBucketNum;i++)
     {
 		if (spritebuckets[i] != NULL)
		{
		        bool is_done=false;
			sprite* linkedlist = spritebuckets[i];

    			while(is_done == false)
     			{
         			if (linkedlist != NULL)
         			{
              				sprite *temp = linkedlist;
              				linkedlist = linkedlist->next;
              				delete temp;
              				temp = NULL;
         			} else
         				if (linkedlist==NULL) is_done=true;
     			}
		

		}
     }
}

sprite* spritelist::get_sprite(int index,char* name)
{
	int whichBucket = hash(name,SpriteBucketNum);
	sprite *match = find(name,spritebuckets[whichBucket]);
	if (match == NULL) printf("no way jose\n");
	return match;
      //return (sprite*) searchtable(name,index);
}

int spritelist::add(char* key,int sprites_frames, int start_x, int start_y, int width, int height,int horver)
{
	int whichBucket = hash(key,SpriteBucketNum);
	sprite *match = find(key,spritebuckets[whichBucket]);
	if (match != NULL)
	{
	//	strcpy(match->filename,filename);
	} else {
		sprite* newOne = new sprite(sprites_frames,image,surface);
	        strcpy(newOne->name,key);

                //newOne->frames = new frame[sprites_frames];
	        for (int x=0;x<sprites_frames;x++)
	        {
                 	newOne->frames[x].width = width;
		        newOne->frames[x].height = height;
	                if (horver == 0)
		        {
			   newOne->frames[x].y_postion_in_picture = start_y;
			   newOne->frames[x].x_postion_in_picture = start_x+(width*x);
		        } else {
			   newOne->frames[x].y_postion_in_picture = start_y+(height*x);
			   newOne->frames[x].x_postion_in_picture= start_x;
		        } 
                }
		newOne->next = spritebuckets[whichBucket];
		spritebuckets[whichBucket] = newOne;
	}
}

int spritelist::hash(char* key, int nBuckets)
{
	unsigned long hashcode = 0;
	for (int i = 0; i < strlen(key);i++)
	{
		hashcode = hashcode * MultiplierS + key[i];
	}
	
	return (hashcode % nBuckets);
}


sprite *spritelist::find(char* key, sprite* list)
{
	for (sprite *cur = list;cur != NULL;cur = cur->next)
	{
		if (strcmp(cur->name,key) == 0) return cur;
	}
	return NULL;
}

#endif
