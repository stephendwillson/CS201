#include <iostream>
#include <string>
#include "LL.h"
using namespace std;

LL::LL () {head = NULL;}

LL::~LL () {delete head;}

LLN::~LLN () {delete next;}

void LL::print () {

 if (head!=NULL) head->print();
}

void LLN::print() {

 cout << s << endl;
 if (next!=NULL) next->print();
}

void LL::addfront (string str) {

 head = new LLN (str,head);
}

LLN::LLN (string str, LLN *n) {

 s = str;
 next = n;
}

int LL::count() {

 if (head) return head->count();
 return 0;
}

int LLN::count() {

 if (next) return 1+next->count();
 return 1;
}

/*LLN * LL::randnode() {

 if (!head) return NULL;
 return head->randnode(rand()%count());
}

LLN * LLN::randnode () {

 return randnode (rand()%count());
}

LLN * LLN::randnode(int wh) {

 if (wh) return next->randnode(wh-1);
 return this;
}
*/
