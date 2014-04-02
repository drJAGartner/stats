/******************************
 * dice.cc				*
 * variable faced dice object *
 * v1.0 - April 1, 2014		*
 *****************************/

#include "./dice.h"
#include <iostream>

minstd_rand0 *dice::rNum;
int dice::nDiceInst=0;

dice::dice(unsigned int numFaces, bool verbose):numF(numFaces)
{
	loudDice = verbose;
	if(loudDice) cout << "New Dice with " << numFaces << " faces" << endl;
	if(rNum==NULL)
	{
		rNum = new minstd_rand0(time(NULL));
		if(loudDice) cout << "New Seed" << endl;
	}
	nDiceInst++;
}

dice::~dice()
{
	
	if(nDiceInst==1)
	{
		if(loudDice) cout << "No Dice" << endl;
		delete rNum;
	} else {
		if(loudDice) cout << "There are/is now " << --nDiceInst << " dice" << endl;
	}
}

int dice::rollDice()
{
	int result = (*rNum)()%numF+1;
	if(loudDice) cout << "Rolled a " << result << endl;
	return result;
}

void dice::vOut(bool bOut)
{
	loudDice = bOut;
	return;
}