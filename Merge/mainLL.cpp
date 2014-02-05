#include <iostream>
#include <ctime>
#include <cstdlib>
#include "LL.h"
using namespace std;

int main () {

 //srand (time(NULL));
 LL MyLL2;

 MyLL2.addfront ("IT");
 MyLL2.addfront ("IS");
 MyLL2.addfront ("AN");
 MyLL2.addfront ("ANCIENT");
 MyLL2.addfront ("MARINER");
 MyLL2.addfront ("AND");
 MyLL2.addfront ("HE");
 MyLL2.addfront ("STOPPETH");
 MyLL2.addfront ("ONE");
 MyLL2.addfront ("OF");
 MyLL2.addfront ("THREE");
 MyLL2.addfront ("BY");
 MyLL2.addfront ("THY");
 MyLL2.addfront ("LONG");
 MyLL2.addfront ("GREY");
 MyLL2.addfront ("BEARD");
 MyLL2.addfront ("AND");
 MyLL2.addfront ("GLITTERING");
 MyLL2.addfront ("EYE");
 MyLL2.addfront ("NOW");
 MyLL2.addfront ("WHEREFORE");
 MyLL2.addfront ("STOPPST");
 MyLL2.addfront ("THOU");
 MyLL2.addfront ("ME");
 MyLL2.sort();
 MyLL2.print();
 system("pause");
}
