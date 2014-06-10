/******************************************************
 * streamStat.cc
 *
 * V1.0 - June 10, 2014
 *  Calculates (via direct computation):
 *    - Mean (for either variable)
 *    - Variance (for either variable)
 *    - Covariance (combined)
 *    - Correlation coefficient (combined)
 *****************************************************/

#include "./streamStat.h"
#include <iostream>

void streamStat::Reset()
{
  nEntry=0;
  sumX=0;
  sumX2=0;
  sumY=0;
  sumY2=0;
  sumXY=0;
}

void streamStat::EnterData(double nX, double nY)
{
  nEntry++;
  sumX += nX;
  sumY += nY;
  sumX2 += nX*nX;
  sumY2 += nY*nY;
  sumXY += nX*nY;
}

double streamStat::GetMean(bool retY)
{
  if(retY)
    return (nEntry>0) ? sumY/nEntry : 0.0;
  else
    return (nEntry>0) ? sumX/nEntry : 0.0;
}

double streamStat::GetVariance(bool retY)
{
  if(retY)
    return (nEntry>1) ? (sumY2-(sumY*sumY/nEntry))/(nEntry-1) : 0.0;
  else
    return (nEntry>1) ? (sumX2-(sumX*sumX/nEntry))/(nEntry-1) : 0.0;
}

double streamStat::GetStandardDeviation(bool retY)
{
  if(retY)
    return sqrt(GetVariance(true));
  else
    return sqrt(GetVariance(false));
}

double streamStat::GetCovariance()
{
  return (nEntry>1) ? (sumXY-nEntry*GetMean(true)*GetMean(false))/(nEntry-1) : -2.0;
}

double streamStat::GetCorrelation()
{
  return GetCovariance()/(GetStandardDeviation(true)*GetStandardDeviation(false));
}