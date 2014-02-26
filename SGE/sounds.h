#ifndef SOUND_H
#define SOUND_H
#include "SDL/SDL_mixer.h"

class music
{
      public:
             Mix_Music *music_chunk;
             char* filename;
             music* next;
             Mix_Music *load_music();
             int play(int loop);
             int stop();
             int pause();
             log* musiclog;
             music(char* musicfilename);
             ~music();
             bool is_playing;
             bool is_paused;
	     

};

class sound_effect
{
      public:
             Mix_Chunk *sound_chunk;
             char* filename;
             sound_effect* next;
             Mix_Chunk *load_sound();
             log* soundlog;
             sound_effect(char* soundfilename);
             ~sound_effect();
             bool is_playing;
             bool is_paused;
             int play(int loop,int channel);             
};

class sound
{
      public:
             sound(int megahertz,int channels);
             ~sound();
             
             int create_music(char* musicfile);
             int play_music(int index,char* filename,int loop);
             int stop_music(char* filename);
             int pause_music();
             
             int create_sound(char* soundfile);
             int play_sound(int index, char* filename,int loop,int channel);
             
        private:

	     music *Mbuckets[10];

             music *mfirst;
             music *mcurrent;
             music *msearch;
             music *mtemp;
             
             sound_effect *sfirst;
             sound_effect *scurrent;
             sound_effect *ssearch;
             sound_effect *stemp;
             
             char* musichashtable;
             int musicsize;
             char* soundhashtable;
             int soundsize;
             
             int musicaddtotable(int address,char* key);
             int* musicsearchtable(char* key, int index);
             
             int soundaddtotable(int address,char* key);
             int* soundsearchtable(char* key, int index);

	     int hash(char* filename, int nBuckets);
	     int add(char* filename);
	     music* find(char* filename, music* list);

	     
             
};

music::music(char* musicfilename)
{
    music_chunk = NULL;
    filename=NULL;
    musiclog=NULL;
    filename = new char[strlen(musicfilename)+1];
    strcpy(filename,musicfilename);
    music_chunk = load_music();
    is_playing = false;
    is_paused=false;
    musiclog = new log;
}

music::~music()
{
     Mix_FreeMusic( music_chunk );
     delete musiclog;
     musiclog=NULL;
     delete filename;
     filename=NULL;
}

Mix_Music* music::load_music()
{
    
    music_chunk = Mix_LoadMUS( filename );        
    
}

int music::stop()
{
    if (is_playing == true)
    {
        Mix_HaltMusic(); 
	is_playing = false;
    }
}

int music::pause()
{
    if (is_paused == false)
    {
        Mix_PauseMusic();
        is_paused = true;
    }
}

int music::play(int loop=-1)
{
      if (is_playing == false && is_paused == false)
      {
           if (music_chunk != NULL)
           {
               Mix_PlayMusic(music_chunk,loop);
      
               is_playing = true;
           }
      } else 
      if (is_paused == true)
      {
           Mix_ResumeMusic(); 
      }
}

sound_effect::sound_effect(char* soundfilename)
{
    filename=NULL;
    sound_chunk=NULL;
    soundlog=NULL; 


    filename = new char[strlen(soundfilename)+1];

    strcpy(filename,soundfilename);
    sound_chunk = load_sound();
    is_playing = false;
    is_paused=false;
    soundlog = new log;
}


sound_effect::~sound_effect()
{
     delete soundlog;
     soundlog=NULL;
     delete filename;
     filename=NULL;
}

Mix_Chunk* sound_effect::load_sound()
{
    return Mix_LoadWAV( filename );

}

int sound_effect::play(int loop=0,int channel=-1)
{
    if (sound_chunk != NULL)
    {
       Mix_PlayChannel(channel,sound_chunk,loop);
    }
}

sound::sound(int megahertz=22050,int channels=2)
{
    if( Mix_OpenAudio( megahertz, MIX_DEFAULT_FORMAT, channels, 4096 ) == -1 )
    {
        
    }
    for (int i=0;i<10;i++)
    {
		Mbuckets[i] = NULL;
    }
     mfirst=NULL;
     mcurrent=NULL;
     msearch=NULL;
     mtemp=NULL;
     
     sfirst=NULL;
     scurrent=NULL;
     ssearch=NULL;
     stemp=NULL;
     
     musicsize=8;
     soundsize=8;

     musichashtable = NULL;
     soundhashtable = NULL;
     
     musichashtable = new char[musicsize];
     soundhashtable = new char[soundsize];

     for (int o=0;o<musicsize;o++)
     {
	musichashtable[o] = '\0';
     }
     for (int o=0;o<soundsize;o++)
     {
	soundhashtable[o] = '\0';
     }
    // memset(musichashtable,0,sizeof(musichashtable));
    // memset(soundhashtable,0,sizeof(soundhashtable));
     
}

sound::~sound()
{
     bool is_done=false;
     bool is_sdone=false;
     
     if (musichashtable != NULL)
     {
         delete musichashtable;
         musichashtable = NULL;
     }
     
     if (soundhashtable != NULL)
     {
         delete soundhashtable;
         soundhashtable = NULL;
     }
     msearch=mfirst;
     

     
     while(is_done == false)
     {
         if (msearch != NULL)
         {
              mtemp = msearch;
              msearch = msearch->next;
              delete mtemp;
              mtemp = NULL;
         } else
         if (msearch==NULL) is_done=true;
     }
   
     is_done = false;

    
     
     while(is_sdone == false)
     {
         if (ssearch != NULL)
         {
              stemp = ssearch;
              ssearch = ssearch->next;
              delete stemp;
              stemp = NULL;
         } else
         if (ssearch==NULL) is_sdone=true;
     }
     
     Mix_CloseAudio();

}



int sound::create_music(char* musicfile)
{
	add(musicfile);
/*
    if (mfirst ==  NULL)
    {
              mfirst = new music(musicfile);
              //mfirst->filename = new char[strlen(musicfile)+1];
              //strcpy(mfirst->filename,musicfile);
              
              mcurrent = mfirst;
              mcurrent->next = NULL;
              
              musicaddtotable((int) mcurrent,musicfile);
              
    }else {
              if (mcurrent->next == NULL)
              {
                  mcurrent->next = new music(musicfile);
                //  mcurrent->next->filename = new char[strlen(musicfile)+1];
                //  strcpy(mcurrent->next->filename,musicfile);
                 
                  mcurrent = mcurrent->next;
		  mcurrent->next = NULL;
                  
                  musicaddtotable((int) mcurrent,musicfile);
              }
    }
*/ 
}

int sound::play_music(int index,char* filename,int loops=-1)
{
   // msearch = (music*) musicsearchtable(filename, index);
   // msearch->play(loops);  

   int whichBucket = hash(filename,10);
   music *match = find(filename,Mbuckets[whichBucket]);
   match->play(loops);
}

int sound::stop_music(char* filename)
{

   int whichBucket = hash(filename,10);
   music *match = find(filename,Mbuckets[whichBucket]);
   match->stop();
     
    return 0;
}

int sound::pause_music()
{
    Mix_PauseMusic();
    return 0;
}


int sound::create_sound(char* soundfile)
{
    if (sfirst ==  NULL)
    {
              sfirst = new sound_effect(soundfile);
             // sfirst->filename = new char[strlen(soundfile)+1];
             // strcpy(sfirst->filename,soundfile);
              
              scurrent = sfirst;
              scurrent->next = NULL;
              
              soundaddtotable((int) scurrent,soundfile);
              
    }else {
              if (scurrent->next == NULL)
              {
                  scurrent->next = new sound_effect(soundfile);
               //   scurrent->next->filename = new char[strlen(soundfile)+1];
               //   strcpy(scurrent->next->filename,soundfile);
                  
                  scurrent = scurrent->next;
		  scurrent->next=NULL;
                  soundaddtotable((int) scurrent,soundfile);
              }
    } 
}

int sound::play_sound(int index,char* filename,int loop=0,int channel=-1)
{
    ssearch = (sound_effect*) soundsearchtable(filename, index);
    ssearch->play(loop,channel);  
}


int sound::musicaddtotable(int address,char* key)
{
    char* temphashtable=NULL;
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
    
    
    temphashtable = new char[12];
    //memset(temphashtable,0,sizeof(temphashtable));

    for (int z=0;z<12;z++)
    {
		temphashtable[z] = '\0';
    }
    
    sprintf(temphashtable,"%i",i);
    
    newhashtable = new char[musicsize*2];
   
    for (int z=0;z<musicsize*2;z++)
    {
	newhashtable[z] = '\0';
    }

    
    strcpy(newhashtable,musichashtable);
     

    strcat(newhashtable,temphashtable);  
    
    //printf("%s",temphashtable); 
    
    delete temphashtable;
    temphashtable=NULL;
    
    if (musichashtable != NULL)
    {
         delete musichashtable;
         musichashtable=NULL;
    }
    
     musichashtable=newhashtable;
     temphashtable=NULL;
     musicsize *= 2;
    
}

int* sound::musicsearchtable(char* key, int index)
{
    
    char* temp = new char[255];
    int j=0;
    int found=0;
    
    int postion=(index-1)*10;

  
    for (int z=0;z<255;z++)
    {
		temp[z] = '\0';
    }

    
    for (int i=postion;i < postion+10;i++)
    {
        temp[j] = musichashtable[i];
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

int sound::soundaddtotable(int address,char* key)
{
    char* temphashtable=NULL;
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
    
    
    temphashtable = new char[12];

    for (int z=0;z<12;z++)
    {
	temphashtable[z] = '\0';
    }

    
    sprintf(temphashtable,"%i",i);
    
    newhashtable = new char[soundsize*2];

    for (int z=0;z<soundsize*2;z++)
    {
		newhashtable[z] = '\0';
    }
    
    strcpy(newhashtable,soundhashtable);
     

    strcat(newhashtable,temphashtable);  
    
    //printf("%s",temphashtable); 
    
    delete temphashtable;
    temphashtable=NULL;
    
    if (soundhashtable != NULL)
    {
         delete soundhashtable;
         soundhashtable=NULL;
    }
    
     soundhashtable=newhashtable;
     temphashtable=NULL;
     soundsize *= 2;
    
}

int* sound::soundsearchtable(char* key, int index)
{
    
    char* temp = new char[255];
    int j=0;
    int found=0;
    int postion=(index-1)*10;


    for (int z=0;z<255;z++)
    {
	temp[z] = '\0';
    }
    
    for (int i=postion;i < postion+10;i++)
    {
        temp[j] = soundhashtable[i];
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



int sound::add(char* filename)
{
	int whichBucket = hash(filename,10);
	music *match = find(filename,Mbuckets[whichBucket]);
	if (match != NULL)
	{
	//	strcpy(match->filename,filename);
	} else {
		music* newOne = new music(filename);
		newOne->next = Mbuckets[whichBucket];
		Mbuckets[whichBucket] = newOne;
	}
}


int sound::hash(char* filename, int nBuckets)
{
	unsigned long hashcode = 0;
	for (int i = 0; i < strlen(filename);i++)
	{
		hashcode = hashcode * Multiplier + filename[i];
	}
	
	return (hashcode % nBuckets);
}

music *sound::find(char* filename, music* list)
{
	for (music *cur = list;cur != NULL;cur = cur->next)
	{
		if (strcmp(cur->filename,filename) == 0) return cur;
	}
	return NULL;
}

#endif
