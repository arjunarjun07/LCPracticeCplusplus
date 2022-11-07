#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class TwoPointers
{
public:

    bool isPalindrome(string s);

    vector<int> twoSumInputSorted(vector<int>& numbers, int target);

    vector<vector<int>> threeSum(vector<int>& nums);

    int maxArea(vector<int>& height);

    int trap(vector<int>& height);

    int findDuplicate(vector<int>& nums);
};