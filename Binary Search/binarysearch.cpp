/*  Stephen Willson CS201
	This program will prompt the user for a file name. It computes the length
	of each record and the number of records. It then prompts the user for a
	string they'd like to search for. It should then binary search for the string.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (int argc, char **argv);

int main (int argc, char **argv) 
{
	int ct=0;
	int reclngth=0;

	cout << "Please enter a filename: ";
	string s;
	getline(cin,s);

	fstream bacon(s);
	bacon >> reclngth; //get first 4 bytes (record length)

	bacon.seekp(0,ios::end);
	int sz = bacon.tellp(); //gets number of bytes in the file by seeking to the end, then setting
							//that equal to sz
	
	ct = (sz-4)/reclngth; //number of records in the file

	if(ct==0) //kill program if there's nothing to search
	{
		cout << "There are no records to search!" << endl;
		return 9001;
	}

	cout << "Please enter a string you'd like to search for:  ";
	string search;
	getline(cin,search);

	int l=1,h=(sz-4)/reclngth,m=0,checkct=0; //l, h, and m based on entire strings, not individual chars
	bool isthere=false;

	while(l <= h && !isthere)
	{
		string check="";
		m=(l+h)/2;
	
		bacon.seekg(m*reclngth+4-reclngth); //make sure m will always be at the start of a word

		for(int i=0; i < reclngth; i++) //build a string to compare to
		{
			char c = bacon.get();
			check+=c;
		}

		if(search == check) //actual binary search stuff
		{
			isthere=true;
			cout << "Found it!" << endl;
		}
		else if(check < search)
			l = m + 1;
		else 
			h = m - 1;
		checkct++;
	}

	if(!isthere) //gets the string before and after string searched for and prints them out
	{
		bacon.seekg(h*reclngth+4-reclngth); //build 'before' string, making sure it's at the start of a word
		string before="";
		for(int i=0; i < reclngth; i++)
		{
			char c = bacon.get();
			before+=c;
		}

		if(h > 0)
			bacon.seekg(l*reclngth+4-reclngth); //build 'after', also making sure it's at the start of a word
		else
		{
			bacon.clear();
			bacon.seekg(4);
		}

		string after="";
		for(int i=0; i < reclngth; i++)
		{
			char c = bacon.get();
			after+=c;
		}

		if(h==0)
			cout << "Your string would fall at the beginning of the list, right before '" << after << "'." << endl;
		else if(h > 0 && h < ct)
			cout << "Your string would be between '" << before << "' and '" << after << "'." << endl;	
		else
			cout << "Your string would fall at the end of the list, right after '" << before << "'." << endl;
	}
	cout << "Examined " << checkct << " string(s) to attempt to locate yours." << endl;
	return 0;
}