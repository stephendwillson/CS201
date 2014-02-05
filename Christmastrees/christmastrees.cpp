/*  Stephen Willson CS201
	This program is designed to read in from a file a pair of integers.
	It will then draw Christmas trees using 'ASCII art' with a base height of
	the integer in question and a branch height of double that.*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (int argc, char **argv);

int main (int argc, char **argv)
{
	ifstream input ("prob3.in");
	ofstream output ("prob3.out");
	int a=0, b=0, lg=0;

	while (true)
	{
		if(!input)
			break;
		input >> a >> b;

		if(a>b)
			lg=a;
		else
			lg=b;

		for(int i=0; i <= 3*lg; i++)
		{
			if(i < a*3) //if we're doing tree a
			{
				if(i < a*2) //if we're doing tree a's branches
				{
					for(int j=0; j < 2*a-1-i; j++)//a's branches
						output << " ";
					for(int j=0; j < 2*i+1; j++)
						output << "*";

					if(i < b*2) //if tree b's branches across from a's branches
					{
						for(int j=0; j < a*2+b*2-i*2-1; j++) //b's branches across from a's branches
							output << " ";
						for(int j=0; j < 2*i+1; j++)
							output << "*";
					}

					if(i < b*3 && i >= b*2) //if tree b's stem across from a's branches
					{
						for(int j=0; j < b*2+a*2-i-1; j++)
							output << " ";
						output << "*";
					}
				}

				else //else if we're doing a's stem
				{
					for(int j=0; j < a*2-1; j++) //a's stem
						output << " ";
					output << "*";

					if(i < b*2) //if we're doing b's branches while doing a's stem
					{
						for(int j=0; j < b*2-i+a*2-1; j++)//b's branches across from a's stem
							output << " ";
						for(int j=0; j < 2*i+1; j++)
							output << "*";
					}
					if(i < b*3 && i >= b*2) //if we're doing b's stem across from a's stem
					{
						for(int j=0; j < 2*a+2*b-1; j++)
							output << " ";
						output << "*";
					}
				}
			}

			else //else if tree a's already fully printed
			{
				if(i < b*2)
				{
					for(int j=0; j < 4*a+2*b-i-1; j++)//b's branches if below tree a
						output << " ";
					for(int j=0; j < 2*i+1; j++)
						output << "*";
				}
				else if(i >= b*2 && i < 3*lg)
				{
					for(int j=0; j < 4*a+2*b-1; j++)//b's stem if below tree a
						output << " ";
					output << "*";
				}
			}
			output << endl;
		}
	}

	input.close();
	output.close();

	return 0;
}