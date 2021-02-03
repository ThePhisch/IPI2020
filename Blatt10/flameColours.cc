#include "colourfunc.hh"
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
	double t = 255 * sin(M_PIl * v / 255 / 2);
	return (char)t;
}

char flameColour::getG(int v)
{
	// return char(v * slope(yellowIntercept) + yAxisIntercept(yellowIntercept) - 1);
	// double t = 255 * exp((v - 255) / 80) + v * 20 / 255 - 20;
	double t = -255/2*cos(M_PIl*v/255)+255/2;
	if(t<=0) 
	{
		t = 0;
	}
	return (char)t;
}

char flameColour::getB(int v)
{
	if (v == maxOut)
	{
		return (char)255;
	}
	return (char)0;
}
