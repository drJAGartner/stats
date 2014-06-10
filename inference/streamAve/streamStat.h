#ifndef STREAMSTAT_H
#define STREAMSTAT_H

#include <iostream>
#include <math.h>

using namespace std;

class streamStat
{
public:
  streamStat() : nEntry(0), sumX(0), sumX2(0), sumY(0), sumY2(0), sumXY(0) {}
  void Reset() ;
  void EnterData(double nX, double nY);
  
  int GetEntryCount() {return nEntry;}
  double GetMean(bool retY=true);
  double GetVariance(bool retY=true);
  double GetStandardDeviation(bool retY=true);
  double GetCovariance();
  double GetCorrelation();
private:
	int nEntry;
  double sumX;
  double sumX2;
  double sumY;
  double sumY2;
  double sumXY;
};

#endif