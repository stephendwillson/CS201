#ifndef _LL_H_
#define _LL_H_

#include "LLN.h"
class LL {
private:
	LLN *head;
public:
	LLN *gethead();
	void sethead (LLN *h);
	LL();
	~LL();
	void addfront (int i);
	void addback (int i);
	void printforward ();
	void printbackward ();
};
#endif
