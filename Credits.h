#ifndef CREDITS_H
#define CREDITS_H


enum { PROG,SPRTART, BKGRD,SPTHX,DTHX };

int creditstate=PROG;
int ctimer=0;

void Credits_Logic();
void Credits_Render();

void Credits_Reset();
#include "Credits.cpp"

#endif
