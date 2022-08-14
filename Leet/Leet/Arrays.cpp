// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Arrays.h"

vector<int> Arrays::twoSum(vector<int>& nums, int target) {

        vector<int> index_v;

        std::map<int, int> num_index;

        //use multimap instead of this
        for (int i = 0; i < nums.size(); i++)
            num_index.insert(std::pair<int, int>(nums[i], i));

        std::sort(nums.begin(), nums.end());

        int index_b = 0; int index_end = nums.size() - 1;

        while (index_b < nums.size() && index_end >= 0 && index_b != index_end)
        {
            if (nums[index_b] + nums[index_end] < target)
            {
                index_b++;
            }
            else if (nums[index_b] + nums[index_end] > target)
            {
                index_end--;
            }
            else if (nums[index_b] + nums[index_end] == target)
            {
                index_v.push_back(num_index[nums[index_b]]);
                index_v.push_back(num_index[nums[index_end]]);
                break;
            }
        }

        return index_v;

    }

vector<int> Arrays::TwoSumModified(vector<int>& nums, int target)
    {
        vector<int> index;

        std::multimap<int, int> num_map;

        for (int i = 0; i < nums.size(); i++)
        {
            int elem = nums[i];

            /*
                a + b = Target
                b = Target - a;

                b is the complimentary num which will get added with a to get the Target

                That is why we are cal "diff as target - nums[i]"

                //--------- In case of two subract ----------------

                a-b = target
                b = a - target
            */

            int diff = target - nums[i];

            auto itr = num_map.find(diff);

            if (itr != num_map.end())
            {
                index.push_back(i);
                index.push_back(itr->second);
                break;
            }
            else
            {
                num_map.insert(std::pair<int, int>(elem, i));
            }
        }

        return index;
    }

int Arrays::maxSubArray(vector<int>& nums) {

    /*int sum = nums[0];
    int overall_sum = INT_MIN;

    if (nums.size() == 1)
    {
        return nums[0];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        sum = nums[i];
        int last_sum = sum;

        for (int j = i + 1; j < nums.size(); j++)
        {
            sum += nums[j];

            if (sum >= last_sum)
            {
                last_sum = sum;
            }
        }

        if (last_sum >= overall_sum)
        {
            overall_sum = last_sum;
        }
    }

    return overall_sum;*/

    int sum = 0, ans = INT_MIN;

    for (auto el : nums)
    {
        sum = max(sum + el, el);
        ans = max(ans, sum);

    }
    return ans;
}

void Arrays::moveZeroes(vector<int>& nums) {

    int counter = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (counter++ >= nums.size())
        {
            break;
        }

        if (nums[i] == 0)
        {
            nums.erase(nums.begin() + i);
            --i;
            nums.push_back(0);
        }
    }
}

bool Arrays::containsDuplicate(vector<int>& nums) {

    /*
        Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

        Example 1:

        Input: nums = [1,2,3,1]
        Output: true
        Example 2:

        Input: nums = [1,2,3,4]
        Output: false
        Example 3:

        Input: nums = [1,1,1,3,3,4,3,2,4,2]
        Output: true
    */

    bool contains_duplicate = false;

    std::map<int, int> item_and_index;

    for (int i = 0; i < nums.size(); i++)
    {
        if (item_and_index.find(nums[i]) != item_and_index.end())
        {
            contains_duplicate = true;
            break;
        }
        else
        {
            item_and_index.insert(std::pair<int, int>(nums[i], i));
        }
    }

    return contains_duplicate;
}

void Arrays::rotate(vector<int>& nums, int k) {

    /*
        Given an array, rotate the array to the right by k steps, where k is non-negative.

        Example 1:

        Input: nums = [-1,-100,3,99], k = 2
        Output: [3,99,-1,-100]

        Explanation:
        rotate 1 steps to the right: [99,-1,-100,3]
        rotate 2 steps to the right: [3,99,-1,-100]
    */

    for (int i = 0; i < k; i++)
    {
        int last_element = nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), last_element);
    }
}

vector<int> Arrays::MergeTwoSortedArr(vector<int> nums1, vector<int> nums2)
{
    vector<int>::iterator ptr1;
    vector<int>::iterator ptr2;

    if (nums1.size() == 0)
    {
        return nums2;
    }
    else
    {
        nums1;
    }

    int unfilled_slots = nums2.size();

    for (ptr2 = nums2.begin(); ptr2 < nums2.end(); ptr2++)
    {
        for (ptr1 = nums1.begin(); ptr1 < nums1.end(); ptr1++)
        {
            if (*ptr2 <= *ptr1)
            {
                nums1.insert(ptr1, *ptr2);

                nums1.pop_back();

                --unfilled_slots;

                break;
            }
            else if (*ptr2 > *ptr1 && (nums1.end() - ptr1 == unfilled_slots))
            {
                nums1.insert(ptr1, *ptr2);

                nums1.pop_back();

                --unfilled_slots;

                break;
            }
        }
    }

    return nums1;
}

vector<int> Arrays::add_one_to_array_of_digits(vector<int> a)
{
    vector<int> new_v;
    vector<int>::reverse_iterator rit = a.rbegin();

    int carry = 0;

    while (rit != a.rend())
    {
        int digit = *rit;

        if (rit == a.rbegin())
        {
            digit += 1;

            if (digit <= 9)
            {
                *rit = digit;
                break;
            }
        }

        //-- actual logic --

        digit += carry;

        if (digit == 10)
        {
            *rit = 0;
            carry = 1;
        }
        else
        {
            *rit = digit;
            carry = 0;
            break;
        }

        ++rit;
    }

    if (carry == 1)
    {
        a.insert(a.begin(), 1);
    }

    new_v = a;

    return new_v;

}

int Arrays::removeDuplicates(vector<int>& nums)
{
    /*
    Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
        */

    for (int i = 0; i < nums.size(); i++)
    {
        int nxt_index = i + 1;
        while (nxt_index < nums.size() && nums[i] == nums[nxt_index])
        {
            nums.erase(nums.begin() + nxt_index);
            //++nxt_index;
        }
    }

    return nums.size();
}

int Arrays::removeElement(vector<int>& nums, int val)
{
    for (int ind = 0; ind < nums.size(); ind++)
    {
        if (nums[ind] == val)
        {
            nums.erase(nums.begin() + ind);
            --ind;
        }
    }

    return nums.size();
}

int Arrays::searchInsert(vector<int>& nums, int target) {

    //Need to modify with binary tree

    int b_index = 0;
    int e_index = nums.size() - 1;

    if (target > nums[nums.size() - 1])
    {
        return e_index + 1;
    }
    else if (target < nums[0])
    {
        return 0;
    }

    while (nums[b_index] != target && nums[e_index] != target)
    {
        if (nums[b_index] < target)
        {
            b_index++;
        }

        if (nums[e_index] > target)
        {
            e_index--;
        }
    }

    return (nums[b_index] == target) ? b_index : (nums[e_index] == target) ? e_index : b_index;
}