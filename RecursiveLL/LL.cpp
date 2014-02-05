#include "LL.h"
#include "LLN.h"
#define NULL 0

LLN *LL::gethead() {return head;}

void LL::sethead (LLN *h) {head = h;}

LL::LL () {head = NULL;}

LL::~LL() {delete head;}

void LL::addfront (int i) {

	head = new LLN (i,head);
}

void LL::addback (int i) {

	if (head==NULL) addfront (i);
	else head->addback (i);
}

void LL::printforward () {

	if (head==NULL) return;
    head->printforward ();
}

void LL::printbackward () {

	if (head==NULL) return;
    head->printbackward ();
}
