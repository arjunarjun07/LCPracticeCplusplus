#include "SlidingWindow.h"
#include <algorithm>
#include <unordered_map>
#include <map>

int SlidingWindow::maxProfit(std::vector<int>& prices)
{
	int profit = 0;
	
	bool hav_we_bought_the_stock = false;

	int l = 0, r = 1;

	while (r < prices.size())
	{
		if (prices[l] < prices[r])
		{
			profit = std::max(profit, prices[r] - prices[l]);
		}
		else
		{
			l = r;
		}

		r++;
	}


	return profit;
}

int SlidingWindow::lengthOfLongestSubstring(string s)
{
	int max_len = 0;
	unordered_map<char, int> char_frequency;

	if (s.empty())
	{
		return 0;
	}
	else if (s.size() == 1)
	{
		return 1;
	}

	for (int i = 0; i < s.size(); i++)
	{
		int j = i;
		while (j < s.size())
		{
			if (char_frequency.find(s[j]) == char_frequency.end())
			{
				char_frequency[s[j]]++;
				max_len = std::max(max_len, (int)char_frequency.size());
				j++;
			}
			else
			{
				break;
			}
		}

		char_frequency.clear();
	}

	return max_len;
}
}