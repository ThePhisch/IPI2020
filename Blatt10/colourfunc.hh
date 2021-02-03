#pragma once
class flameColour
{
private:
	int maxVal;
	int maxOut;
	int yellowIntercept;
	int whiteIntercept;
	int slope(int intercept);
	int yAxisIntercept(int intercept);

public:
	flameColour();
	char getR(int v);
	char getG(int v);
	char getB(int v);
};