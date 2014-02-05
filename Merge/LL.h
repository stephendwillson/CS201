#ifndef _LLH_
#define _LLH_
#include <string>
using namespace std;

class LL;
class LLN;

class LL {

 private:
  LLN *head;
 public:
  LL ();
  ~LL ();
  void print ();
  void addfront (string str);
  int count();
  LLN * randnode ();

  void sort (); //Sorts a LL in alphabetical order
};

class LLN {
 private:
  LLN *next;
  string s;
 public:
  LLN (string str, LLN *n);
  ~LLN ();
  void print ();
  int count();
  LLN * randnode();
  LLN * randnode(int wh);


  LLN *sort (); //Sorts the list from this point down;
                //returns the new head of this sorted list

  LLN *split (); //Splits a list in half from this point down.  this is
                 //the head of one list; the other list is returned.

  LLN *merge (LLN *b); //merges this with b into a single
                       //sorted list, returning the head
};
#endif
