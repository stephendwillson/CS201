/* Stephen Willson CS201
   This program performs division using string manipulation on two
   strings the user enters.*/

#include <iostream>
#include <string>
using namespace std;

int main (int argc, char **argv);
string getDividend();
string getDivisor();
string subtract (string a, string b);
bool compare (string a, string b);

//asks for input/checks for bad input/does dividing by calling other methods
int main (int argc, char **argv)
{

	string a = getDividend();
	string b = getDivisor();

	for (int i=0; i < a.length(); i++)
		for (int j=0; j < b.length(); j++)
			if(!(a[i] >= '0' && a[i] <= '9') || !(b[j] >= '0' && b[j] <= '9'))
			{
				cout << "That wasn't even a number. Ending program." << endl;
				//system("pause");
				return 0;
			}

	if(b.length() == 1 && b[0] == '0')
	{
		cout << "Dividing by 0 is NOT COOL! Ending program before the world implodes." << endl;
		//system("pause");
		return 0;
	}

	string qtnt="";
	string rmndr="";

	//does actual dividing by comparing to see if subtraction is possible, then actually calling subtract method
	//essentially sets remainder equal to 1st digit of a, tries to subtract
	//if it can't subtract, will glue next digit of a onto remainder and try again
	//keeps doing this until subtract is possible
	//also keeps track of number of subtracts to give correct quotient
	for(int i=0; i < a.length(); i++)
	{
		int subsint=0;
		char subschar;
		rmndr += a[i];

		if(compare(rmndr,b))
		{
			while(compare(rmndr,b))
			{
				rmndr=subtract(rmndr,b);
				subsint++;
				subschar = subsint + '0';
			}

			qtnt += subschar;
		}
		else if(!(compare(rmndr,b)))
			qtnt+="0";
	}

	//removes leading 0's
	while (qtnt.length()>1 && qtnt[0]=='0')
				qtnt = qtnt.substr(1);
	while (rmndr.length()>1 && rmndr[0]=='0')
				rmndr = rmndr.substr(1);

	cout << "Quotient: " << qtnt << endl;
	cout << "Remainder: " << rmndr << endl;

	system("pause");
	return 0;
}

//asks for dividend (all the cool kids are doing it)
string getDividend()
{
	cout << "Enter in a dividend, dude: ";
	string a;
	getline(cin,a);

	return a;
}

//asks for divisor (no WAY!)
string getDivisor()
{
	cout << "Enter in a divisor, brah: ";
	string b;
	getline(cin,b);

	return b;
}

//subtracts by using 9's complement
string subtract (string astr, string bstr)
{
	string s="";

	//pads beginning of both strings with 0 until they're equal in length
	while (astr.length() < bstr.length())
		astr = "0"+astr;
	while (bstr.length() < astr.length())
		bstr = "0"+bstr;

	//adds one more 0, just in case there's a carry in the addition
	astr = "0"+astr;
	bstr = "0"+bstr;

	//sets carry flag and count (count determines whether it's on the first character; if so, a 1 is added)
	int cflag=0;
	int count=0;

	//loops through each character, starting in ones column, and adds
	for (int i = astr.length()-1; i>=0; i--)
	{
		count++;
		int aint = astr[i]-'0';
		int bint = bstr[i]-'0';
		bint = 9-bint;
		int sval = aint+bint+cflag;
		if(count==1)
			sval+=1;
		cflag = sval/10;
		int sdig = sval%10;
		char result = sdig+'0';
		s = result + s;
	}
	return s;
}

//checks to see if subtraction is possible without giving negatives
bool compare (string astr, string bstr)
{
	while (astr.length() < bstr.length())
		astr = "0"+astr;
	while (bstr.length() < astr.length())
		bstr = "0"+bstr;

	if(astr < bstr)
		return false;
	else
		return true;
}