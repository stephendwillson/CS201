#ifndef _LLN_H_
#define _LLN_H_

class LLN {

private:
	int stuff;
	LLN *next;
public:
	int getstuff ();
	LLN *getnext();
	void setstuff (int i);
	void setnext (LLN *n);
	LLN (int i, LLN *n);
	~LLN();
	void addback (int i);
	void printforward ();
	void printbackward ();
};


#endif
