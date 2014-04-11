/**************************************
* rollin' dice				  *
* this is an example of how to use	  *
* the dice class, with verbose output *
**************************************/


#include "./probDist.h"
#include <iostream>

using namespace std;
int main()
{
  cout << "Binomial probability for getting k heads in 10 coin flips" << endl;
  probDist* pCalc = new probDist(/*true*/);
  
  fraction fRollP(1,2);
  for(int i=0; i<11; i++)
  {
    fraction fBino = pCalc->binomial(i,10,fRollP);
    cout << "\tNum heads = " << i << ", Prob = " << fBino.print() << "\t= " << fBino.getFloat() << endl;
  }
  
  delete pCalc;
  
}