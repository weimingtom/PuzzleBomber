#ifndef XYLIST_H
#define XYLIST_H

class cord
{
	public:
		int x;
		int y;
		cord* next;
};

class xylist
{
	public:
		cord* head;
		cord* current;
		int add(int x,int y);
		bool find(int x, int y);
		int clear();
		xylist();
};
#include "xylist.cpp"
#endif
