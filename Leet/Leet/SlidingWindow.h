#pragma once
#include <iostream>
#include <vector>

using namespace std;

class SlidingWindow
{
public:
	int maxProfit(std::vector<int>& prices);

	int lengthOfLongestSubstring(string s);

	int characterReplacement(string s, int k);

	int characterReplacement1(string s, int k);
};