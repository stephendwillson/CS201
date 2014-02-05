#include "LL.h"
#include <iostream>
using namespace std;

void LL::sort()
{
	if(head==NULL)
		return;
	head = head->sort();
}

LLN *LLN::sort()
{
	if(this == NULL || next==NULL)
		return this;
	LLN *b = split();
    LLN *a = sort();
    b = b->sort();
    return a->merge(b);
}

LLN *LLN::split()
{
    if (this == NULL || next == NULL)
		return NULL;
	
    LLN *b = next;
    next = b->next;
    b->next = next->split();
    return b;
}

LLN *LLN::merge(LLN *b)
{
    if (this == NULL)
		return b;
    if (b == NULL)
		return this;
	
    if (s < b->s)
	{
      next = next->merge(b);
      return this;
    }

    else
	{
      b->next = b->next->merge(this);
      return b;
	}
}
