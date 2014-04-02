/**************************************
* rollin' dice				  *
* this is an example of how to use	  *
* the dice class, with verbose output *
**************************************/


#include "./dice.h"
#include <iostream>

using namespace std;
int main()
{
	unsigned int inNum=0;
	cout << "Number of faces for die 1: ";
	cin >> inNum;
	dice *d1 = new dice(inNum, true);
	cout << "Number of faces for die 2: ";
	cin >> inNum;
	dice *d2 = new dice(inNum, true);
	cout << endl;
	
	cout << "How many rolls: ";
	cin >> inNum;
	
	for(int j=0; j<inNum; j++)
	{
		int val1 = d1->rollDice();
		int val2 = d2->rollDice();
		int tot = val1 + val2;
		cout << "Total dice roll: " << tot << endl;
		if(j%2==0)
		{
			d1->vOut(false);
			d2->vOut(false);
		} else {
			d1->vOut(true);
			d2->vOut(true);
		}
	}
	
	delete d1;
	delete d2;
}