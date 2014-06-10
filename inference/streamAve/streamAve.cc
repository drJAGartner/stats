/******************************************************
 * streamAve.cc                                       *
 *                                                    *
 * V1.0 - May 26, 2014                                *
 *  Calculates means via knuth alone                  *
 *****************************************************/

#include "./streamAve.h"
#include <iostream>

void streamAve::Reset()
{
  nEntry=0;
}

void streamAve::EnterData(double nVal)
{
  nEntry++;
  
  if(nEntry==1)
  {
    nAve = nVal;
    nVar = 0;
  } else {
    double nAveOld = nAve;
    nAve = nAve + (nVal-nAve)/nEntry;
    nVar = nVar + (nVal-nAveOld)*(nVal-nAve);
  }
}

double streamAve::GetMean()
{
  return (nEntry>0) ? nAve : 0.0;
}

double streamAve::GetVariance()
{
  return (nEntry>1) ? nVar/(nEntry-1) : 0.0;
}

double streamAve::GetStandardDeviation()
{
  return sqrt(GetVariance());
}


int nEntry;
double nAve;
double nVar;