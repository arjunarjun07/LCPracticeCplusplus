#pragma once

int square(int val);

class InRange
{
public:
	InRange(int low = 0, int high = 0);
	~InRange();

	bool checkRange(int valToCheck);

private:
	int _mLow;
	int _mHigh;
};