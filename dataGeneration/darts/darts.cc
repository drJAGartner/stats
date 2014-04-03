/******************************************************
 * darts.cc								*
 * A dart gives a random floating x, y coordinate	*
 * v1.0 - April 2, 2014						*
 *****************************************************/

#include "./darts.h"
#include <iostream>

minstd_rand0 *dart::rNum;
int dart::nDartInst=0;

dart::dart(float minX, float maxX, float minY, float maxY)
{
	if(maxX < minX)
	{
		cout << "Bad x Range" << endl;
		xRange = 1;
		xFloor = 0;
	} else {
		xFloor = minX;
		xRange = maxX - minX;
	}
	
	if(maxY < minY)
	{
		cout << "Bad y Range" << endl;
		yRange = 1;
		yFloor = 0;
	} else {
		yFloor = minY;
		yRange = maxY - minY;
	}
	
	if(rNum==NULL)
	{
		rNum = new minstd_rand0(time(NULL));
	}
	nDartInst++;
}

dart::~dart()
{
	if(nDartInst==1)
	{
		delete rNum;
	} else {
		--nDartInst;
	}
}

point dart::toss()
{
	float fXCord = ((*rNum)()%10001/10000.0)*xRange + xFloor;
	float fYCord = ((*rNum)()%10001/10000.0)*yRange + yFloor;
	
	return point(fXCord, fYCord);
	
}