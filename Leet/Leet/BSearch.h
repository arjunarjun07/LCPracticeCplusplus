#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class BSearch
{
public:
	BSearch();
	~BSearch();

	int search(vector<int>& nums, int target);

	bool searchMatrix(vector<vector<int>>& matrix, int target);

	int minEatingSpeed(vector<int>& piles, int h);

	int search_n(vector<int>& nums, int target);

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

private:

};

class TimeMap
{
    pair<int, string> timestmp_val_pair;
    multimap<string, pair<int, string>> multimapdata_set;

public:
    TimeMap()
    {

    }

    void set(string key, string value, int timestamp)
    {
        multimapdata_set.insert({ key, {timestamp, value} });
    }

    string get(string key, int timestamp)
    {
        string res_val = "";

        int count_of_key = multimapdata_set.count(key);

        if (count_of_key)
        {
            auto range = multimapdata_set.equal_range(key);

            //iterate the range & find the pair which is max of the given range & also <= curr_timestamp            


            auto it1 = range.first;
            auto it2 = range.second;
            int diff = -1;

            while (it1 != range.second && it2 != range.first)
            {
                diff = distance(it1, it2);
                int d = diff / 2;

                advance(it1, d);
                auto mid = it1;

                if (mid->second.first <= timestamp)
                {
                    res_val = mid->second.second;
                    advance(mid, 1);
                    it1 = mid;
                }
                else
                {
                    advance(mid, -1);
                    it2 = mid;
                }
            }
        }

        return res_val;
    }
};

