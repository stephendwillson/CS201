#include <iostream>
#include "LLN.h"
using namespace std;

int LLN::getstuff () {return stuff;}

void LLN::setstuff (int i) {stuff = i;}

LLN *LLN::getnext () {return next;}

void LLN::setnext (LLN *n) {next = n;}

LLN::LLN (int i, LLN *n) {stuff = i; next = n;}

LLN::~LLN () {delete next;}

void LLN::addback (int i) { //helper method

	if (next == NULL) next = new LLN (i,next);
	else next->addback (i);
}

void LLN::printforward () {

	cout << stuff << endl;
	if (next != NULL) next->printforward();
}

void LLN::printbackward () {

	if (next != NULL) next->printbackward();
	cout << stuff << endl;
}
