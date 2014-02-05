/*	Stephen Willson CS201
	This program will ask the user how many integers they want to enter
	and then prompt for those values. It then prints out how many of each
	integer there are. */

#include <iostream>
using namespace std;

void sort(int *data, int n);
void repeats(int *data, int n);

int main (int argc, char **argv)
{
	int n;
	cout << "How many numbers would you like to enter? ";
	cin >> n;
	
	//create array, get values, and assign to spot in array
	int *data = new int[n];
	for(int i = 0; i < n; i++)
	{
		int item;
		cout << "Enter value " << i+1 << ": ";
		cin >> item;
		data[i] = item;
	}

	//calls crappy bubble sort method and repeats method
	sort(data,n);
	repeats(data,n);

	delete[] data;
	system("pause");
	return 0;
}

//traditional crappy bubble sort
void sort(int *data, int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if (data[i] > data[j])
			{
				int tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
}

//gets&&prints frequency of each int in the array
void repeats (int *data, int n)
{
	int currnum=0;
	int numcount=1;
	for(int i=0; i < n; i++)
	{
		//first pass, sets the current number to first item in array
		if(i==0)
			currnum=data[i];

		//if current number == next item in array, increase count
		else if(currnum == data[i])
			numcount++;

		//if current number != next item in array, print out total count, set current 
		//number to next item in array, reset count
		else
		{
			cout << "There are " << numcount << " " << currnum << "'s." << endl;
			currnum = data[i];
			numcount=1;
		}

		//when it gets to the last number in array, set currnum == that value and print
		if(i == (n-1))
		{
			currnum = data[i];
			cout << "There are " << numcount << " " << currnum << "'s." << endl;
		}
	}
}