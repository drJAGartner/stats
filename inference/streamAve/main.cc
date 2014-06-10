/**************************************
* testing stats                       *
* used to demonstrate how the         *
* typical methods of calculating      *
* a streaming average and variance    *
* diverges.                           *
**************************************/


#include "./streamAve.h"
#include "./streamStat.h"
#include "/Users/josephgartner/Projects/stats/dataGeneration/dice/dice.h"

#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
  int nEntries=100;
  if(argc==2)
  {
    nEntries = atoi(argv[1]);
  } else if(argc>2) {
    cout << "Usage: ./testStat [integer number of test stats]" << endl;
    return 1;
  }
  
  cout << "Testing methods on " << nEntries << " numbers." << endl;
  
  cout << "Test 1: Alternating 1, 0" << endl;
  streamAve *pAve = new streamAve();
  streamStat *pStat = new streamStat();
  for(int j=0; j<nEntries; j++)
  {
    double pVal = (j*1)%2;
    pAve->EnterData(pVal);
    pStat->EnterData(pVal, 0);
  }
  
  cout << "Using Knuth method, the variance is: " << pAve->GetStandardDeviation() << endl;
  cout << "Using direct computation, the variance is:" << pStat->GetStandardDeviation(false) << endl << endl;
  
  cout << "Test2: Sum of 2, 6 sided dice rolls" << endl;
  dice *myDice6 = new dice(6, false);
  pAve->Reset();
  pStat->Reset();
  for(int j=0; j<nEntries; j++)
  {
    double roll1 = myDice6->rollDice();
    double rollSum =  roll1 + myDice6->rollDice();
    pAve->EnterData(rollSum);
    pStat->EnterData(roll1, rollSum);
  
  }
  
  cout << "Using Knuth method, the variance is: " << pAve->GetStandardDeviation() << endl;
  cout << "Using direct computation, the variance is:" << pStat->GetStandardDeviation() << endl;
  
  cout << "Covariance between roll 1 and sum of rolls is: " << pStat->GetCovariance() << endl;
  cout << "Correlation between roll 1 and sum of rolls is: " << pStat->GetCorrelation() << endl;

  
  delete myDice6;
  delete pStat;
  delete pAve;
}