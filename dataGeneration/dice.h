// dice object for dice rolling experiments

#include <time.h>
#include <iostream>
#include <random>

using namespace std;

class dice
{
public:
	dice(unsigned int numFaces=6, bool verbose = false);
	~dice();
	int rollDice();
	void vOut(bool bOut);
private:
	static int nDiceInst;
	const unsigned int numF;
	static minstd_rand0* rNum;
	bool loudDice;
};
