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

bool compandgetmax(std::pair<int, int> l, std::pair<int, int> r)
{
	bool res;

	if (l.second < r.second)
	{
		res = true;
	}
	else
	{
		res = false;
	}

	return res;
}

int SlidingWindow::characterReplacement(string s, int k)
{
	int max_len = 0;

	std::map<char, std::pair<int, int>> alpha_map = { {'a',{0,0} }, {'b',{0,0} }, {'c',{0,0} }, {'d',{0,0} },
									  {'e',{0,0} }, {'f',{0,0} }, {'g',{0,0} }, {'h',{0,0} },
									  {'i',{0,0} }, {'j',{0,0} }, {'k',{0,0} }, {'l',{0,0} },
									  {'m',{0,0} }, {'n',{0,0} }, {'o',{0,0} }, {'p',{0,0} },
									  {'q',{0,0} }, {'r',{0,0} }, {'s',{0,0} }, {'t',{0,0} },
									  {'u',{0,0} }, {'v',{0,0} }, {'w',{0,0} }, {'x',{0,0} },
									  {'y',{0,0} }, {'z',{0,0} }
									};

	for (int i = 0; i < s.size(); i++)
	{
		int repeat_chr_count = 1;
		int j = i+1;

		while (j < s.size() && s[j] == s[i])
		{
			repeat_chr_count++;
			j++;
		}

		alpha_map[s[i]] = std::max(alpha_map[s[i]], std::pair<int, int>(i, repeat_chr_count), compandgetmax);
	}

	char chr_with_max_len = '\0';
	int mlen = 0;
	int index_of_chr = -1;

	for (std::map<char, std::pair<int,int>>::iterator it = alpha_map.begin(); it!= alpha_map.end(); it++)
	{
		if (mlen < it->second.second)
		{
			chr_with_max_len = it->first;
			mlen = it->second.second;
			index_of_chr = it->second.first;
		}
	}

	int substr_len_right = 0;
	int index_to_start = index_of_chr + mlen;
	int replace_chr_count = k;
	int same_char_count_in_between_traverse = 0;

	while (index_to_start < s.size() && replace_chr_count > 0)
	{
		if (s[index_to_start] != chr_with_max_len)
		{
			replace_chr_count--;
		}
		else
		{
			same_char_count_in_between_traverse++;
		}

		index_to_start++;
	}

	while (index_to_start < s.size() && s[index_to_start] == chr_with_max_len)
	{
		same_char_count_in_between_traverse++;
		index_to_start++;
	}

	substr_len_right = mlen + same_char_count_in_between_traverse + (k - replace_chr_count);

	int substr_len_left = 0;
	index_to_start = index_of_chr - 1;
	replace_chr_count = k;
	same_char_count_in_between_traverse = 0;

	while (index_to_start >= 0 && replace_chr_count > 0)
	{
		if (s[index_to_start] != chr_with_max_len)
		{
			replace_chr_count--;
		}
		else
		{
			same_char_count_in_between_traverse++;
		}

		index_to_start--;
	}

	while (index_to_start >= 0 && s[index_to_start] == chr_with_max_len)
	{
		same_char_count_in_between_traverse++;
		index_to_start--;
	}

	substr_len_left = mlen + same_char_count_in_between_traverse + (k - replace_chr_count);

	return std::max(substr_len_left, substr_len_right);
}