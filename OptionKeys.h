#ifndef OPTIONKEYS_H
#define OPTIONKEYS_H

unsigned long* startadd;
unsigned long* getstartadd;

int optionkeycursor_x=45;
int optionkeycursor_y=170;
bool inputmode=false;

void PrintKeys();
void PrintKeysPlayer(int x);
void Option_Keys_Render();
void Option_Keys_Logics();

char* getkeys(int count2,int x, int y);

#include "OptionKeys.cpp"
#endif
