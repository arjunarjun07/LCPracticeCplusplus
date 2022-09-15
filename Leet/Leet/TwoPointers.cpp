#include "TwoPointers.h"

bool TwoPointers::isPalindrome(string s)
{
	bool res = true;

	s.erase(std::remove_if(s.begin(),
		s.end(),
		[](unsigned char x) {return (!isalnum(x)); }),
		s.end());

	int len = s.size();

	int l_indx = 0;
	int r_indx = len - 1;

	bool IsOddLen = len % 2;


	if (len > 0)
	{
		while (l_indx <= r_indx)
		{
			if (IsOddLen && l_indx == r_indx)
			{
				res = true;
				break;
			}

			if (tolower(s[l_indx]) != tolower(s[r_indx]))
			{
				res = false;
				break;
			}

			l_indx++;
			r_indx--;
		}

	}

	return res;
}
