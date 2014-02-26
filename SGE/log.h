#ifndef LOG_H
#define LOG_H
class log
{
      public:
             log();
             ~log();
             int write(char* message);
      private:
};

log::log()
{
          
}

log::~log()
{
}

int log::write(char* message)
{
    FILE* flog=NULL;
    
    flog = fopen("log.txt","a+");
    
    fputs (message,flog);
    
    fclose(flog);
}

#endif
