/******************************
 * dice.cc				*
 * variable faced dice object *
 * v1.0 - April 1, 2014		*
 *****************************/

#include "./probDist.h"
#include <iostream>

int probDist::factorial(const unsigned int& nN)
{
  if( nN==0) return 1;

  if(bVerbose) cout << nN << "*" << flush;
  if(nN>1) return (nN*this->factorial(nN-1));
  if(bVerbose) cout << endl << flush;
  return 1;
}

fraction probDist::nChooseK(const unsigned int& nN, const unsigned int& nK)
{
  if(nK>nN)
  {
    throw "Usage Error (nChooseK): Cannot compute N choose K where k > N";
    return -1;
  }
  
  fraction retFrac(this->factorial(nN),this->factorial(nK)*this->factorial(nN-nK));
  retFrac.reduceFraction();
  return retFrac;
  
}

fraction probDist::binomial(const unsigned int& nSuc, const unsigned int& nTrial, fraction& fracSuc)
{
  if(nSuc>nTrial)
  {
    throw "Usage Error (binomial): Cannot have more successes than trials.";
    return fraction(-1);
  }
  if(fracSuc.getNum()>fracSuc.getDen())
  {
    throw "Usage Error (binomial): Cannot have a success probability greater than 1";
    return fraction(-2);
  }
  if(fracSuc.getNum()<0)
  {
    throw "Usage Error (binomail): Cannot have a negative success probability";
    return fraction(-3);
  }
  if(bVerbose) cout << "Binomial params-> successes: " << nSuc << ", trials: " << nTrial << ", success frac: " << fracSuc.print() << endl;
  
  //p^k
  if(bVerbose) cout <<"p^k" << endl;
  fraction pST(1);
  for(int i=0; i<nSuc; i++)
  {
    pST = pST*fracSuc;
  }
  //(1-p)^(n-k)
  if(bVerbose) cout <<"(1-p)^(n-k)" << endl;
  fraction pFT(1);
  fraction pFail = (fracSuc*(-1)) + 1;
  for(int i=0; i<(nTrial-nSuc); i++)
  {
    pFT = pFT*pFail;
  }
  // n choose k
  if(bVerbose) cout <<"n choose k" << flush << endl;
  fraction pCT = this->nChooseK(nTrial, nSuc);
  
  return pST*pFT*pCT;
}

float probDist::binomial(const unsigned int& nSuc, const unsigned int& nTrial, const float& pSuc)
{
  if(nSuc>nTrial)
  {
    throw "Usage Error (binomial): Cannot have more successes than trials.";
    return -1.;
  }
  if(pSuc>1)
  {
    throw "Usage Error (binomial): Cannot have a success probability greater than 1";
    return -2.;
  }
  if(pSuc<0)
  {
    throw "UsageError (binomial): Cannot have a negative success probability";
  }
  
  //p^k
  float pST = 1.;
  for(int i=0; i<nSuc; i++)
  {
    pST *= pSuc;
  }
  //(1-p)^(n-k)
  float pFT = 1.;
  float pFail = 1 - pSuc;
  for(int i=0; i<(nTrial-nSuc); i++)
  {
    pFT *= pFail;
  }
  // n choose k
  float pCT = (this->nChooseK(nTrial, nSuc)).getFloat();
  
  return pST*pFT*pCT;
}