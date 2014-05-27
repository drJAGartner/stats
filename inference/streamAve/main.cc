/**************************************
* testing stats                       *
* used to demonstrate how the         *
* typical methods of calculating      *
* a streaming average and variance    *
* diverges.                           *
**************************************/


#include "./streamAve.h"
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
  double sumX=0.0;
  double sumX2=0.0;
  streamAve *pRecorder = new streamAve();
  for(int j=0; j<nEntries; j++)
  {
    double pVal = (j*1)%2;
    pRecorder->EnterData(pVal);
    sumX += pVal;
    sumX2 += pVal*pVal;
  }
  
  double oldStdDev = sqrt((1.0/nEntries)*(sumX2-sumX*sumX/nEntries));
  cout << "Using Knuth method, the variance is: " << pRecorder->GetStandardDeviation() << endl;
  cout << "Using direct computation, the variance is:" << oldStdDev << endl << endl;
  
  cout << "Test2: Sum of 2, 6 sided dice rolls" << endl;
  dice *myDice6 = new dice(6, false);
  pRecorder->Reset();
  sumX=0.0;
  sumX2=0.0;
  
  for(int j=0; j<nEntries; j++)
  {
    double pVal = myDice6->rollDice() + myDice6->rollDice();
    pRecorder->EnterData(pVal);
    sumX += pVal;
    sumX2 += pVal*pVal;
  
  }
  
  oldStdDev = sqrt((1.0/nEntries)*(sumX2-sumX*sumX/nEntries));
  cout << "Using Knuth method, the variance is: " << pRecorder->GetStandardDeviation() << endl;
  cout << "Using direct computation, the variance is:" << oldStdDev << endl << endl;
  
  cout << "Test3: Sum of 2, 100 sided dice rolls" << endl;
  dice *myDice100 = new dice(100, false);
  pRecorder->Reset();
  sumX=0.0;
  sumX2=0.0;
  
  for(int j=0; j<nEntries; j++)
  {
    double pVal = myDice100->rollDice() + myDice100->rollDice();
    pRecorder->EnterData(pVal);
    sumX += pVal;
    sumX2 += pVal*pVal;
  
  }
  
  oldStdDev = sqrt((1.0/nEntries)*(sumX2-sumX*sumX/nEntries));
  cout << "Using Knuth method, the variance is: " << pRecorder->GetStandardDeviation() << endl;
  cout << "Using direct computation, the variance is:" << oldStdDev << endl;
  
  delete myDice6;
  delete myDice100;
  delete pRecorder;
}