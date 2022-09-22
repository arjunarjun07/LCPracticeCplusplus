#include "SlidingWindow.h"
#include <algorithm>
#include <unordered_map>

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