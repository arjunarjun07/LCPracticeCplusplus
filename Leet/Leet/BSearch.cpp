#include "BSearch.h"
#include <math.h>
#include <algorithm>

BSearch::BSearch()
{
}

BSearch::~BSearch()
{
}

int BSearch::search(vector<int>& nums, int target) 
{
	int l = 0;
	int r = nums.size() - 1;

	while (l <= r)
	{
		int mid = std::floor((l + r) / 2);

		if (target == nums[mid])
		{
			return mid;
		}
		else if(nums[mid] < target)
		{
			l = mid + 1;
		}
		else if (nums[mid] > target)
		{
			r = mid - 1;
		}
	}

	return -1;
}

bool BSearch::searchMatrix(vector<vector<int>>& matrix, int target)
{
	bool key_found = false;

	int row = matrix.size();
	int col = matrix[0].size();

	int top = 0;
	int bottom = row - 1;

	while (top <= bottom)
	{
		int mid_r = std::floor((top + bottom) / 2);

		if (search(matrix[mid_r], target) != -1)
		{
			return true;
		}
		else
		{
			if (matrix[mid_r][0] < target)
			{
				top = top + 1;
			}
			else if (matrix[mid_r][0] > target)
			{
				bottom = bottom - 1;
			}
		}
	}

	return key_found;
}

int BSearch::minEatingSpeed(vector<int>& piles, int h)
{
	auto max = *max_element(piles.begin(), piles.end());

	int l = 1;	int r = max;
	int res = max;

	while (l <= r)
	{
		int mid = std::floor((l + r) / 2);

		int curr_hrs = 0;
		for (const auto vals : piles)
		{
			curr_hrs += std::ceil(vals / (double)mid);
		}

		if (curr_hrs <= h) //with current eating speed(k) the time taken (curr_hrs) is less than the expected hrs(h). So we need to slow down the speed to match h.
		{
			res = std::min(res, mid);
			r = mid - 1;
		}
		else //with current eating speed(k) the time taken (curr_hrs) is greater than the expected hrs(h). So we need to speed up the speed to match h.
		{
			l = mid + 1;
		}
	}

	return res;
}

int BSearch::search_n(vector<int>& nums, int target)
{
	int res_index = -1;

	auto it = is_sorted_until(nums.begin(), nums.end());

	if (it != nums.end())
	{
		vector<int> left(nums.begin(), it);
		vector<int> right(it, nums.end());

		res_index = search(left, target);

		if (res_index == -1)
		{
			int index_of_last_elem_in_left = left.size() - 1;
			res_index = search(right, target);

			if(res_index != -1)
				res_index = res_index + index_of_last_elem_in_left + 1;
		}
	}
	else
	{
		res_index = search(nums, target);

	}

	return res_index;
}

double BSearch::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	double median = 0;

	/*
		Median = (n+1)/2 th term - if n is ODD
		Median = (n/2 + (n+1)/2 )/2 th term - if n is EVEN - (Find avg of n/2 & n/2 + 1 th terms)
	*/

	int i = 0; 
	int j = 0;
	int k = 0;

	vector<int> result;
	std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(result), [](int x, int y) { return (x < y); });

	int result_size = result.size();

	int is_odd = (result_size % 2 == 1) ? true : false;

	int mid = -1;

	if (is_odd)
	{
		/*
			siz = 5
			mid = siz/2 = 5/2 = 2.5 = 2
				= mid + 1 = 2 + 1 = 3 
			0based index = we need 3rd term = mid - 1 = 2
		*/

		mid = result_size / 2 + 1 -1; //-1 for 0 based index pos
		median = result[mid];
	}
	else
	{
		auto mid_term = result[(result_size/2) - 1];
		auto mid_term_plus_one = result[((result_size / 2) + 1 - 1)];

		median = (mid_term + mid_term_plus_one) / 2.f;
	}

	return median;
}