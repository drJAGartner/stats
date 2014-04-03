// dice object for dice rolling experiments

#include <time.h>
#include <iostream>
#include <random>
#include "/Users/josephgartner/Projects/math/geo/point.h"

using namespace std;

class dart
{
public:
	dart(float minX, float maxX, float minY, float maxY);
	~dart();
	point toss();
private:
	float xRange;
	float xFloor;
	float yRange;
	float yFloor;
	
	static int nDartInst;
	static minstd_rand0* rNum;
};
