#include <iostream>
#include <string>
#include "BasicLL.h"
#include "LL.h"
using namespace std;


int main (int argc, char **argv) {

	LL d;
	d.addfront(3);
	d.addfront(2);
	d.addfront(1);
	d.addback(4);
	d.addback(5);
	d.addback(6);
	d.printforward();
	d.printbackward();
/*	d = new LL();
	d->stuff = 17;
	d->next = new LL();
	d->next->stuff = -3;
	d->next->next = new LL();
	d->next->next->stuff = 106;
	d->next->next->next = NULL;*/
/*	addback (d,17);
	addback (d,-3);
	addback (d,106);

	print (d);
	printbackward (d);

	killLL (d);*/
	system("pause");
	return 0;
}

