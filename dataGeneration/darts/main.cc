/**************************************
* rollin' dice				  *
* this is an example of how to use	  *
* the dice class, with verbose output *
**************************************/


//#include "/Users/josephgartner/Projects/math/geo/point.h"
#include "./darts.h"

#include <iostream>

using namespace std;
int main()
{
	unsigned int inNum=0;
	cout << "Number of trials: ";
	cin >> inNum;
	int nInCircle = 0;
	dart *d1 = new dart(0,1,0,1);
	
	for(int j=0; j<inNum; j++)
	{
		point hitP = d1->toss();
		if(hitP.distanceToOrigin()<1.0) nInCircle++;
	}
	
	float estPi = 4.0*nInCircle/inNum;
	
	cout << "Estimate for pi is " << estPi << ", based on " << inNum << " trails" << endl;
	
	delete d1;
}