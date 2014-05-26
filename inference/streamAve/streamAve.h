// dice object for dice rolling experiments

#ifndef STREAMAVE_H
#define STREAMAVE_H

#include <iostream>
#include <math.h>

using namespace std;

class streamAve
{
public:
  streamAve() : nEntry(0) {}
  void Reset() ;
  void EnterData(double nVal);
  
  int GetEntryCount() {return nEntry;}
  double GetMean();
  double GetVariance();
  double GetStandardDeviation();
private:
	int nEntry;
  double nAve;
  double nVar;
};

#endif