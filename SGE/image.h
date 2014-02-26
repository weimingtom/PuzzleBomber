#ifndef IMAGE_H
#define IMAGE_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "sprite.h"

const int FLIP_VERTICAL = 1;
const int FLIP_HORIZONTAL = 2;

//hashed function by Donald E. Knuth Art of Computer Science
static const int ImageBucketNum=10;
static const int Multiplier = -166417991L;

class image
{
      public:
	     char key[255];
	     int value;

             SDL_Surface *mainsurface;
             SDL_Surface* Image;
	     SDL_Surface* Flipped_Image;
             image* next;
             SDL_Surface *load_image();
             SDL_Surface *load_image_mem(void *mem, int size);
             int show_image(int x,int y,int picposx, int picposy,int width, int height);
	     int show_image2(SDL_Surface* Image, int x,int y,int picposx=-1, int picposy=-1,int width=-1,int height=-1);

	     int Create_Flip_Image();
	     int Show_Flipped_Image(int x, int y, int picposx, int pixposy, int width, int height);

	    
	     SDL_Surface* flip_surface( SDL_Surface *surface, int flags );

	     int increase_alpha();
	     int decrease_alpha();
	     int set_alpha(int newalpha);

             char* filename;
             
             spritelist* sprites;
             
             bool isfrommem;
             
             log* imagelog;
             
             Uint8 r;
             Uint8 g;
             Uint8 b;
             
             int alpha; 
             
             int size;
             
             Uint32 get_pixel32( SDL_Surface *surface, int x, int y );
             void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );
             
             image(char* filen,SDL_Surface*  msurface,Uint8 red, Uint8 green, Uint8 blue,void* mem,int size);
             int apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
             ~image();
      private:
};


image::image(char* filen, SDL_Surface*  msurface,Uint8 red, Uint8 green, Uint8 blue,void* mem=NULL,int size=0)
{

    Flipped_Image = NULL;
    filename=NULL;
    sprites=NULL;
    imagelog=NULL;
    next=NULL;
    mainsurface=NULL;
    Image=NULL;
    Flipped_Image=NULL;

    filename = new char[strlen(filen)+1];
    strcpy(filename,filen);


    if (mem == NULL && size==0)
    {
	isfrommem = false;
        Image = load_image();
   } else {
	isfrommem = true;
        Image = load_image_mem(mem,size);
    }
    mainsurface = msurface;  
    imagelog = new log;
    sprites = new spritelist(Image,mainsurface);
    
    r = red;
    g = green;
    b = blue;
    
    alpha=SDL_ALPHA_OPAQUE;
                 
}




image::~image()
{ 
   delete imagelog;
   imagelog=NULL;
   delete filename;
   filename = NULL;
   SDL_FreeSurface(Image);
   delete sprites;
   sprites=NULL;
   if (Flipped_Image != NULL) 
   {
	delete Flipped_Image;
	Flipped_Image = NULL;
   }
}

int image::set_alpha(int newalpha)
{
	SDL_SetAlpha(Image,SDL_SRCALPHA, newalpha);
}

int image::increase_alpha()
{
	SDL_SetAlpha( Image, SDL_SRCALPHA, alpha );
	alpha+=5;
	return alpha;
}

int image::decrease_alpha()
{
	SDL_SetAlpha( Image, SDL_SRCALPHA, alpha );
	alpha-=5;
	return alpha;
}

SDL_Surface* image::flip_surface( SDL_Surface *surface, int flags )
{
    //Pointer to the soon to be flipped surface
    SDL_Surface *flipped = NULL;
    
    //If the image is color keyed
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, 0 );
    }
    //Otherwise
    else
    {
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask );
    }
    
    //If the surface must be locked
    if( SDL_MUSTLOCK( surface ) )
    {
        //Lock the surface
        SDL_LockSurface( surface );
    }
    
    //Go through columns
    for( int x = 0, rx = flipped->w - 1; x < flipped->w; x++, rx-- )
    {
        //Go through rows
        for( int y = 0, ry = flipped->h - 1; y < flipped->h; y++, ry-- )
        {
            //Get pixel
            Uint32 pixel = get_pixel32( surface, x, y );
            
            //Copy pixel
            if( ( flags & FLIP_VERTICAL ) && ( flags & FLIP_HORIZONTAL ) )
            {
                put_pixel32( flipped, rx, ry, pixel );
            }
            else if( flags & FLIP_HORIZONTAL )
            {
                put_pixel32( flipped, rx, y, pixel );
            }
            else if( flags & FLIP_VERTICAL )
            {
                put_pixel32( flipped, x, ry, pixel );
            }
        }    
    }
    
    //Unlock surface
    if( SDL_MUSTLOCK( surface ) )
    {
        SDL_UnlockSurface( surface );
    }
    
    //Copy color key
    if( surface->flags & SDL_SRCCOLORKEY )
    {
        SDL_SetColorKey( flipped, SDL_RLEACCEL | SDL_SRCCOLORKEY, surface->format->colorkey );
    }
    
    //Return flipped surface
    return flipped;
}

Uint32 image::get_pixel32( SDL_Surface *surface, int x, int y )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void image::put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //Set the pixel
    pixels[ ( y * surface->w ) + x ] = pixel;
}



int image::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL)
{
   
    SDL_Rect offset;


    offset.x = x;
    offset.y = y;


    SDL_BlitSurface( source, clip, destination, &offset );
    
}

int image::show_image2(SDL_Surface* Image, int x,int y,int picposx, int picposy,int width,int height)
{
    SDL_Rect clip;
     
       
        clip.x  = picposx;
        clip.y = picposy;
        clip.w = width;
        clip.h = height;

        
    if (Image != NULL)
    {
       apply_surface(x,y,Image,mainsurface,&clip);
    }
}

int image::Create_Flip_Image()
{
	 Flipped_Image = flip_surface( Image, 2 );

}

int image::Show_Flipped_Image(int x, int y, int picposx, int picposy, int width, int height)
{
    SDL_Rect clip;
     
       
        clip.x  = picposx;
        clip.y = picposy;
        clip.w = width;
        clip.h = height;

        
    if (Image != NULL)
    {
       apply_surface(x,y,Flipped_Image,mainsurface,&clip);
    }
	
}


int image::show_image(int x,int y,int picposx=-1, int picposy=-1,int width=-1,int height=-1)
{
    SDL_Rect clip;
     
   // if (picposx == -1 && picposy == -1 && width==-1 && height==-1)
  //  {
       
        clip.x  = picposx;
        clip.y = picposy;
        clip.w = width;
        clip.h = height;

        
  //  } 
    if (Image != NULL)
    {
       apply_surface(x,y,Image,mainsurface,&clip);
    }
}

SDL_Surface* image::load_image_mem(void *mem, int size)
{
	SDL_Surface* optimizedImage = NULL;
	SDL_Surface* tvimage;
	SDL_Surface* timage;
	SDL_RWops	*rw_out;

    	rw_out = SDL_RWFromMem(mem, size); 
    	tvimage = IMG_Load_RW(rw_out, 0);

	timage = SDL_DisplayFormat( tvimage ); 



        optimizedImage = SDL_CreateRGBSurface( SDL_SWSURFACE,  timage->w, timage->h,  timage->format->BitsPerPixel,  timage->format->Rmask,  timage->format->Gmask,  timage->format->Bmask,timage->format->Amask );
    //Copy color key
       Uint32 colorkey = SDL_MapRGB( timage->format, 0xff, 0x00, 0xff );
            

       SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
	
       if( SDL_MUSTLOCK( timage ) )
       {
       		 //Lock the surface
       		SDL_LockSurface( timage );
       }


       for (int x=0;x <  timage->w;x++)
       {
       		for (int y=0;y <  timage->h;y++)
		{
			Uint32 pixel = get_pixel32( timage, x, y );
			put_pixel32( optimizedImage,  x,y, pixel );
		}
    	}

       if( SDL_MUSTLOCK( timage ) )
       {
       		SDL_UnlockSurface( timage );
       }	

	SDL_FreeSurface( tvimage );
	SDL_FreeSurface( timage );
	return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, clip, destination, &offset );
            
}

SDL_Surface* image::load_image() 
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = IMG_Load( filename );
    
    
    
    if (loadedImage == NULL)
    {
        char msg[256];
        
        sprintf(msg, "Image Log: The File %s could not be loaded\n", filename);
        imagelog->write(msg);
        return NULL;
    }
    
    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
        
        //If the image was optimized just fine
       if( optimizedImage != NULL )
       {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xff, 0, 0xff );
            
            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
        }
    }
    
    //Return the optimized image
    return optimizedImage;
}


class images
{
      public:
             ~images();
             images(SDL_Surface *mainsur, Uint8 red, Uint8 green, Uint8 blue);

             int create_image(char* filename, void *data, int size);   
	              
             int show(int index,char* filename,int x,int y,int picposx,int picposy, int width, int height);
             image* get_image(int index,char* filename); 
	     image* first;

             
      private:
             
             image* current;
             
             image*  search;
             image*  temp;

	     image* imagebuckets[ImageBucketNum];
	     int hash(char* filename, int nBuckets);
	     image *find(char* filename, image* list);
	     int add(char* filename, void* data, int size); 
            
             
             SDL_Surface *mainsurface;
             char* hashtable;
             int size;
             
             Uint32 r;
             Uint32 g;
             Uint32 b;
             
             int addtotable(int address,char* key);
             int* searchtable(char* key, int index);
};

images::images(SDL_Surface *mainsur, Uint8 red, Uint8 green, Uint8 blue)
{
    
    for (int i=0;i<ImageBucketNum;i++)
    {
		imagebuckets[i] = NULL;
    }
    mainsurface = mainsur;
    first = NULL;
    current=NULL;
    search=NULL;
    temp=NULL;
    size = 12;
    hashtable=NULL;
    hashtable = new char[size];

    for (int u=0;u<size;u++)
    {
	hashtable[u] = '\0';
    }

    r = red;
    g = green;
    b = blue;
}

images::~images()
{
 

     for (int i=0;i<ImageBucketNum;i++)
     {
 		if (imagebuckets[i] != NULL)
		{
		        bool is_done=false;
			image* linkedlist = imagebuckets[i];

    			while(is_done == false)
     			{
         			if (linkedlist != NULL)
         			{
              				image *temp = linkedlist;
              				linkedlist = linkedlist->next;
              				delete temp;
              				temp = NULL;
         			} else
         				if (linkedlist==NULL) is_done=true;
     			}
		

		}
     }

}


int images::add(char* filename, void* data=NULL, int size=0)
{
	int whichBucket = hash(filename,ImageBucketNum);
	image *match = find(filename,imagebuckets[whichBucket]);
	if (match != NULL)
	{
		//	strcpy(match->filename,filename);
	} else {
		if (data != NULL)
		{
			image* newOne = new image(filename,mainsurface,r,g,b,data,size);
			newOne->next = imagebuckets[whichBucket];
			imagebuckets[whichBucket] = newOne;

		} else {
			image* newOne = new image(filename,mainsurface,r,g,b);
			newOne->next = imagebuckets[whichBucket];
			imagebuckets[whichBucket] = newOne;
		}
	}
}

int images::hash(char* filename, int nBuckets)
{
	unsigned long hashcode = 0;
	for (int i = 0; i < strlen(filename);i++)
	{
		hashcode = hashcode * Multiplier + filename[i];
	}
	
	return (hashcode % nBuckets);
}


image *images::find(char* filename, image* list)
{
	for (image *cur = list;cur != NULL;cur = cur->next)
	{
		if (strcmp(cur->filename,filename) == 0) return cur;
	}
	return NULL;
}


int images::show(int index,char* filename,int x,int y,int picposx=-1,int picposy=-1, int width=-1, int height=-1)
{
    /*
    search = (image*) searchtable(filename,index);
    */
    int whichBucket = hash(filename,ImageBucketNum);
    image *match = find(filename,imagebuckets[whichBucket]);
    match->show_image(x,y,picposx,picposy,width,height);
    
       
}

image* images::get_image(int index,char* filename)
{
       //search = (image*) searchtable(filename,index);
	int whichBucket = hash(filename,ImageBucketNum);
	image *match = find(filename,imagebuckets[whichBucket]);
       return match;
}

int images::create_image(char* filename, void *data=NULL, int size=0)
{
	if (data != NULL)
	{
		add(filename,data,size);
	} else {
		add(filename);
	}
         
}

int images::addtotable(int address,char* key)
{
    char* temphashtable = NULL;
    char* newhashtable = NULL;

    temphashtable = new char[12];
    
    int i=0;
    unsigned long j=0;
    
    i = address;
    
    j=0;
 
    for (int k = 0;k<4;k++)
    {   
        j <<= 8;
        j |= (int) *(key+k);
        
    }
 
    i ^= j;
    
    
    
    for (int z=0;z<12;z++)
    {
	temphashtable[z] = '\0';
    }
    
    sprintf(temphashtable,"%i",i);
    
    int nsize = size+strlen(temphashtable);
    
    newhashtable = new char[nsize];
    

    for (int x=0;x<nsize;x++)
    {
	newhashtable[x] = '\0';
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

int* images::searchtable(char* key, int index)
{
    
    char* temp = NULL;
    temp = new char[strlen(hashtable)+1];
    int j=0;
    int found=0;
    
    int postion=(index-1)*10;
    
    for (int y=0;y<strlen(hashtable);y++)
    {
	temp[y] = '\0';
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

    
    
    return (int*) l;
}
#endif
