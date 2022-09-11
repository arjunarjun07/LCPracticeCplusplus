// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Arrays.h"
#include <unordered_map>

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

int Arrays::GetFirstRecurringElement(vector<int> nums)
{
    /*
    *   Array = [2,5,1,2,3,5,1,2,4]
    *   return 2
    */

    int first_recurr_elem = 0;

    map<int, int> elem_and_indx;

    if (nums.size() == 0 || nums.size() == 1)
    {
        return 0;
    }


    for (int i = 0; i < nums.size(); i++)
    {
        if (elem_and_indx.find(nums[i]) != elem_and_indx.end())
        {
            first_recurr_elem = nums[i];
            break;
        }
        else
        {
            elem_and_indx.insert(pair<int, int>(nums[i], i));
        }

    }


    return first_recurr_elem;
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

//---------------- Neetcode ------------------------------------

bool Arrays::isAnagram(string s, string t)
{
    bool IsAnag = true;

    std::map<char, int> ch_map;

    int l_s1 = s.length();
    int l_s2 = t.length();

    if (l_s1 != l_s2)
    {
        IsAnag = false;
    }
    else if(l_s1 == l_s2 && l_s1 != 0 && l_s2 != 0)
    {
        for (int i = 0; i < l_s1; i++)
        {
            std::map<char, int>::iterator it1 = ch_map.find(s[i]);

            if (it1 == ch_map.end())
            {
                ch_map[s[i]] = 1;
            }
            else
            {
                ++(it1->second);
            }

            std::map<char, int>::iterator it2 = ch_map.find(t[i]);

            if (it2 == ch_map.end())
            {
                ch_map[t[i]] = -1;
            }
            else
            {
                --(it2->second);
            }

        }

        for (std::map<char, int>::iterator it = ch_map.begin(); it != ch_map.end(); it++)
        {
            if (it->second != 0)
            {
                IsAnag = false;
                break;
            }
        }
    }

    return IsAnag;
}

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

vector<vector<string>> Arrays::groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result;

    unordered_map<string, vector<string> > store;

    for (std::vector<string>::iterator it_str_vec = strs.begin(); it_str_vec != strs.end(); it_str_vec++)
    {
        std::string s = *it_str_vec;
            
        std::sort(s.begin(), s.end());
    
        // make hash of a sorted string
        store[s].push_back(*it_str_vec);
    }

    for (unordered_map<string, vector<string>>::iterator it = store.begin(); it != store.end(); it++)
    {   
        result.push_back(it->second);   
    }

    return (result);
}

vector<int> Arrays::topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int, int> mp;

    for (int x : nums)
    {
        mp[x]++;
    } 

    //bucket sort

    vector<vector<int>> freq(nums.size() + 1);
    for (auto x : mp)
    {
        freq[x.second].push_back(x.first);
    }

    vector<int> res;
    for (int i = nums.size(); i >= 0 and res.size() < k; i--)
    {
        for (int x : freq[i])
        {
            res.push_back(x);
        }
    }


    return res;
}

vector<int> Arrays::productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n);
    int rp = 1;

    for (int i = 0; i < n; i++) {
        ans[i] = rp;
        rp = rp * nums[i];
    }

    rp = 1;

    for (int i = n - 1; i >= 0; i--) {
        ans[i] = ans[i] * rp;
        rp = rp * nums[i];
    }

    return ans;
}

bool Arrays::isValidSudoku(vector<vector<string>>& board) 
{
    unordered_map<string, int> hashmp;

    for (int k = 0; k < board.size(); k++)
    {
        //validate each row elems
        for (int j = 0; j < board.size(); j++)
        {
            if (board[k][j] != ".")
            {
                hashmp[board[k][j]]++;
            }

           //cout << endl << "(k,j)" << k << "," << j;
        }

        for (auto elm : hashmp)
        {
            if (elm.second >= 2)
            {
                return false;
            }
        }

        hashmp.clear();

        //cout << endl<<"-----------------------------";

        //validate each column elems

        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][k] != ".")
            {
                hashmp[board[i][k]]++;
            }

            //cout << endl << "(i,k)" << i << "," << k;
        }

        //cout << endl << "-----------------------------";

        for (auto elm : hashmp)
        {
            if (elm.second >= 2)
            {
                return false;
            }
        }

        hashmp.clear();
    }

    hashmp.clear();

    for (int s_r_ind = 0; s_r_ind <= 6; s_r_ind += 3)
    {
        for (int s_c_ind = 0; s_c_ind <= 6; s_c_ind += 3)
        {
            for (int k = s_r_ind; k < (s_r_ind + 3); k++)
            {
                for (int l = s_c_ind; l < (s_c_ind + 3); l++)
                {
                    if (board[k][l] != ".")
                        hashmp[board[k][l]]++;
                    //cout << endl << "k,l=" << k << "," << l;
                }
            }

            //cout << endl << "-----------------";

            for (auto elm : hashmp)
            {
                if (elm.second >= 2)
                {
                    return false;
                }
            }

            hashmp.clear();
        }
    }

    return true;
}


//---------------- Neetcode ------------------------------------