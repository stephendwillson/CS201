/* Stephen Willson CS201 */

#ifndef _LLREPEATS_H_
#define _LLREPEATS_H_

#include "LL.h"
int main(int argc, char **argv);
void decide (LL *&h, int num);
void addFront (LL *&h, int num);
void addBack(LL *&h, int num);
void addMiddle(LL *&h, int num);
void print (LL *h);
bool search(LL *h, int num);
void deleteLL (LL *&h);
int end (LL *h);

#endif