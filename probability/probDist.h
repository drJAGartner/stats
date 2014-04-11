// dice object for dice rolling experiments

#include <iostream>
#include "/Users/josephgartner/Projects/math/general/fraction/fraction.h"

using namespace std;

class probDist
{
public:
	probDist(bool bSet=false):bVerbose(bSet) { cout << "New pDist" << endl;}
	~probDist() { }
  int factorial(const unsigned int&);
	fraction nChooseK(const unsigned int&, const unsigned int&);
  fraction binomial(const unsigned int&, const unsigned int&, fraction&);
  float binomial(const unsigned int&, const unsigned int&, const float&);
private:
  bool bVerbose;
};
