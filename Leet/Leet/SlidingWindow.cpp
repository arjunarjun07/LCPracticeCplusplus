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

static int gethighestfreqofchar(std::unordered_map<char, int> alpha_map)
{
	auto elem_with_high_freq = max_element(alpha_map.begin(), alpha_map.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b)->bool { return a.second < b.second; });

	return elem_with_high_freq->second;
}

int SlidingWindow::characterReplacement(string str, int k)
{
	/*
	"ABBB"

	1. initiate L & R pointers to slide the string
	2. result - will be the variable in which we will store the max len of str
	3. move R pointer one by one & update the map & its freq
	4. Make sure the current window is valid or not
	{
		[len of the substring - char with high freq = left over chars ]

		which needs to be replaced 'k' times.

		We need to make sure the left over chars <= k - so we can replace it with char with high freq



		if(left over chars > k)
		{
			// The window length is not valid because we can't replace chars more than 'k'.
			so we need to reduce the window size -1 by moving L pointer.
			Untill we find a valid window

			while(left over chars > k)
			{
				reduce the freq of the char at L - pointer
				Move the L pointer by one
			}
		}

		current_res = len (L,R) + 1 //+1 due to zero based index
		result = max(result, current_res);

	}
*/

	int result = 0;

	std::unordered_map<char, int> alpha_map = { };

	int L = 0, R = 0;

	for (; R < str.length(); R++)
	{
		alpha_map[str[R]]++;

		int len_of_substr = R - L + 1;
		int char_with_high_freq = gethighestfreqofchar(alpha_map);

		int left_over_chars = len_of_substr - char_with_high_freq;

		if (left_over_chars > k)
		{
			while (left_over_chars > k)
			{
				--alpha_map[str[L]];
				++L;
			}
		}

		int curr_res = R - L + 1;
		result = std::max(result, curr_res);
	}

	return result;
	
}

int SlidingWindow::characterReplacement1(string s, int k)
{
	int len = s.length();

	int max_str_len = 0;
	int indx_of_first_non_matching_chr = -1;
	int sub_k = k;

	if (s.length() > 0)
	{
		for (int i = 0; i < s.length(); i++)
		{
			int len = 1;
			bool first_non_matching_found = false;
			int nxt_indx_of_i = i + 1;

			int j = i + 1;
			while (j < s.length())
			{
				if (s[i] == s[j])
				{
					++len;
					max_str_len = std::max(len, max_str_len);
				}
				else if(s[i] != s[j])
				{
					if (first_non_matching_found == false)
					{
						first_non_matching_found = true;
						nxt_indx_of_i = j;
					}

					if (sub_k-- != 0)
					{
						++len;
						max_str_len = std::max(len, max_str_len);
					}
					else
					{
						break;
					}
				}

				j++;
			}

			i = nxt_indx_of_i - 1; // -1 because i++ in for loop will act 
			sub_k = k;
		}
	}

	return max_str_len;
}
