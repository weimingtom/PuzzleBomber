#include "xylist.h"

xylist::xylist()
{
	head = NULL;
	current=NULL;	
}

int xylist::add(int x, int y)
{
	if (head == NULL)
	{
		head = new cord();
		head->x = x;
		head->y = y;
		current = head;
		current->next = NULL;
	} else
	if (current->next == NULL)
	{
		current->next = new cord();
		current = current->next;
		current->next = NULL;
		current->x =x;
		current->y = y;
	}
}

bool xylist::find(int x, int y)
{
	cord* temp=head;
	
	while (temp != NULL)
	{
		if (temp->x == x && temp->y == y) return true;
		temp = temp->next;
	}
	return false;
}

int xylist::clear()
{
	cord* temp=head;
	

	while(head != NULL)
	{
		cord* del=NULL;
		if (head != NULL)
		{
			del = head;
			head = head->next;
			delete del;
			del = NULL;
		}
		
	} 
}
