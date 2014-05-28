/******************************************************
* roulette dilema                                     *
* dice class used to simulate statistics question:    *
* Given you have a gun with n chambers.  k bullets    *
* are loaded into adjacent slots.  You fire the gun   *
* once and the gun does not fire.  If you are forced  *
* to fire again, should you respin, or not.           *
*******************************************************/


#include "./dice.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv)
{
  if(argc>3) {
    cout << "Usage: ./roulette [number of chambers] [number of trials]" << endl;
    return 1;
  }
  
  unsigned int nTrials = 100;
	unsigned int nChambers=6;
  if(argc>1)
  {
    nChambers = atoi(argv[1]);
    if(argc==3) nTrials = atoi(argv[2]);
  }
  dice *d1 = new dice(nChambers, false);

	
  cout << "Trials for a gun with " << nChambers << " chambers" << endl;
	for(int j=1; j<nChambers; j++)
	{
    cout << "Trials for " <<  j << " loaded chambers." << endl;
    int nSucNoSpin = 0;
    int nSucSpin   = 0;
    for(int i=0; i<nTrials; i++)
    {
      int t1Slot = 0;
      while(t1Slot<=j) t1Slot = d1->rollDice();
      //cout << "t1slot: " << t1Slot << ", arg1: " << (t1Slot+1) << ", test: " << (t1Slot+1)%(1+nChambers) << endl;
      if((t1Slot+1)%(1+nChambers)>j) nSucNoSpin++;
      if(d1->rollDice()>j) nSucSpin++;
    }
    float sucNo = 100.*nSucNoSpin/nTrials;
    float sucSpin = 100.*nSucSpin/nTrials;
    cout << "\t" << nSucNoSpin << " (" << sucNo << "\%) trials were successful with no respin" << endl;
    cout << "\t" << nSucSpin << " (" << sucSpin << "\%) trials were successful with a respin" << endl;
    if(nSucNoSpin>nSucSpin) cout << "\tDo Not Respin" << endl;
    else if(nSucSpin>nSucNoSpin) cout << "\tRespin" << endl;
    else cout << "\tSame probability each way" << endl;
	}
	
	delete d1;
}