/* Stephen Willson CS201
   This program will ask the user how many integers they want to enter.
   It will then store them, in sorted order, in a linked list, along with
   the count for how many times an individual integer has been entered.
   Then it will print out the linked list when the user has finished.*/

#include <iostream>
#include <string>
#include "LLRepeats.h"
#include "LL.h"
using namespace std;

//makes list, gets number of ints to enter, asks for ints, does stuff with nodes, prints linked list
int main (int argc, char **argv)
{
	int sz;
	LL *list = NULL;

	cout << "How many integers do you want to enter? ";
	cin >> sz;

	for(int i=0; i < sz; i++)
	{
		cout << "Enter integer number " << i+1 << ": ";
		int num;
		cin >> num;
		decide(list,num);
	}

	print(list);
	deleteLL(list);
	system("pause");
	return 0;
}

//just prints out each node's payload and count
void print (LL *h)
{
	while (h != NULL)
	{
		cout << "You entered "<< h->count << " " << h->value << "'s." << endl;
		h = h->next;
	}
}

/*will always search if a node already contains the entered number
  if so, end the method. if not, check if, to keep in sorted order,
  it would make sense to add to the front, back, or middle, then
  calls appropriate method*/
void decide (LL *&h, int num)
{
	if(search(h,num))
		return;
	else if(h == NULL || h->value > num)
		addFront(h,num);
	else if(num > end(h))
		addBack(h,num);
	else
		addMiddle(h,num);
}
 
//adds node to the front of list
void addFront (LL *&h, int num)
{
	LL *n = new LL();
	n->value = num;
	n->count++;
	n->next = h;
	h = n;
}

//adds node to back of list
void addBack(LL *&h, int num)
{
	LL *P = h;
	while (P->next != NULL) 
		P = P->next;
	P->next = new LL();
	P->next->value = num;
	P->next->count++;
	P->next->next = NULL;
}

//adds to any spot in between the end and beginning of the list; wherever is appropriate
void addMiddle(LL *&h, int num)
{
	LL *P = h;
	while(P->next != NULL)
	{
		if(P->value < num && P->next->value > num)
		{
			LL *n = new LL();
			n->next = P->next;
			P->next = n;
			n->value=num;
			n->count++;
		}
		P=P->next;
	}
}

//returns true if the number is already in the list, ending decide() method
bool search(LL *h, int num)
{
	while(h != NULL)
	{
		if(h->value == num)
		{
			h->count++;
			return true;
		}
		h = h->next;
	}
	return false;
}

//simply finds the node at the end of the linked list and returns the value stored in that node
int end (LL *h)
{
	LL *P = h;
	while (P->next != NULL) 
		P = P->next;
	return P->value;
}

//housekeeping method; deletes all the nodes to free up the memory they took up
void deleteLL (LL *&h) 
{
	while (h != NULL)
	{
		LL *Q = h->next;
		delete h;
		h = Q;
	}
}