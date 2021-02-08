#include "colourfunc.hpp"
#include <math.h>

flameColour::flameColour()
{
	maxVal = 255;
	maxOut = 255;
	yellowIntercept = 180;
	whiteIntercept = 255;
}

int flameColour::slope(int intercept)
{
	return int(maxOut / (maxOut - intercept));
}

int flameColour::yAxisIntercept(int intercept)
{
	return int(-slope(intercept) * intercept);
}

char flameColour::getR(int v)
{
	// Rotkanal
	double t = 255 * sin(M_PIl * v / 255 / 2);
	return (char)t;
}

char flameColour::getG(int v)
{
	// Grünchannel fängt später als rot an
	// Skalierung, so dass es bei v=max maximal wird
	double t = -255/2*cos(M_PIl*v/255)+255/2;
	if(t<=0) 
	{
		t = 0;
	}
	return (char)t;
}

char flameColour::getB(int v)
{
	// beim Maximum gebe vollen Bluechannel aus, damit es weiß wird
	// sonst n
	if (v == maxOut)
	{
		return (char)255;
	}
	return (char)0;
}
