#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Arrays
{
public:
    vector<int> twoSum(vector<int>& nums, int target);

    vector<int> TwoSumModified(vector<int>& nums, int target);

    int maxSubArray(vector<int>& nums);

    void moveZeroes(vector<int>& nums);

    bool containsDuplicate(vector<int>& nums);

    void rotate(vector<int>& nums, int k);

    vector<int> MergeTwoSortedArr(vector<int> nums1, vector<int> nums2);

    vector<int> add_one_to_array_of_digits(vector<int> a);

    int removeDuplicates(vector<int>& nums);

    int removeElement(vector<int>& nums, int val);

    int searchInsert(vector<int>& nums, int target);

    int GetFirstRecurringElement(vector<int> nums);
};