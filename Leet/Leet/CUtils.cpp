#include "CUtils.h"

#include <stdexcept>
#include <iostream>

int square(int val)
{
	if (val < 0)
	{
		throw std::runtime_error::exception("negative num");
	}

	return val * val;
}

/*!
 * @brief 
 * @param low 
 * @param high 
*/

InRange::InRange(int low, int high) : _mLow(low), _mHigh(high)
{
	std::cout << "Constructor";
}

/*!
 * @brief 
 * @
*/
InRange::~InRange()
{
}

bool InRange::checkRange(int valToCheck)
{
	if (_mLow <= valToCheck && valToCheck <= _mHigh)
	{
		return true;
	}

	return false;
}
