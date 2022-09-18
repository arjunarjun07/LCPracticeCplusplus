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

vector<int> TwoPointers::twoSumInputSorted(vector<int>& numbers, int target) 
{
	std::vector<int> indx;
	int lindx = 0;
	int rindx = numbers.size() - 1;

	while (lindx < rindx)
	{
		if (numbers[lindx] + numbers[rindx] == target)
		{
			break;
		}
		else
		{
			if (numbers[lindx] + numbers[rindx] < target)
			{
				lindx++;
			}
			else if(numbers[lindx] + numbers[rindx] > target)
			{
				rindx--;
			}
		}
	}

	indx.push_back(lindx + 1);
	indx.push_back(rindx + 1);

	return indx;
}

vector<vector<int>> TwoPointers::threeSum(vector<int>& nums)
{
	vector<vector<int>> res;

	std::sort(nums.begin(), nums.end());

	int target = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		int a = nums[i];
		
		if (i > 0 && a == nums[i - 1])
		{
			continue;
		}

		int j = i + 1;
		int k = nums.size() - 1;

		vector<int> subsetsum_list;

		while (j < k)
		{
			int b = nums[j];
			int c = nums[k];

			if (b + c == target - a)
			{
				subsetsum_list.push_back(a);
				subsetsum_list.push_back(b);
				subsetsum_list.push_back(c);
								
				res.push_back(subsetsum_list);
				subsetsum_list.clear();

				j = j+1;

				while (j < k && nums[j] == nums[j-1])
				{
					j = j+ 1;
				}
			}

			if (b + c > target - a)
			{
				k--;
			}
			else if (b + c < target - a)
			{
				j++;
			}
		}
	}

	return res;
}

int TwoPointers::maxArea(vector<int>& height)
{
	int l_indx = 0;
	int r_indx = height.size() - 1;

	int area = INT_MIN;

	for (int i = height.size() - 1; i >= 1; i--)
	{
		int len = i;
		int breadth = 1;

		if (l_indx < r_indx)
		{
			if (height[l_indx] < height[r_indx])
			{
				breadth = height[l_indx];
				l_indx++;
			}
			else
			{
				breadth = height[r_indx];
				r_indx--;
			}

			area = std::max(area, len * breadth);
		}
	}

	return area;
}
