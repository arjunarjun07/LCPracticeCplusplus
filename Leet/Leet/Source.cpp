// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <functional>
#include <thread>
#include <memory>
#include <future>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    int countSubstrings1(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = i - 1, y = i + 1;
            ans++;
            while (x >= 0 and y < n and s[x] == s[y]) {
                ans++;
                x--;
                y++;
            }
            x = i, y = i + 1;
            while (x >= 0 and y < n and s[y] == s[x]) {
                ans++;
                x--;
                y++;
            }
        }
        return ans;
    }

    int countSubstrings(std::string s)
    {
        int pallindrome_count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int new_l = s.length() - i;
            for (int j = 1; j <= new_l; j++)
            {
                cout << endl << i << "," << j;


                if (j == 1)
                {
                    ++pallindrome_count;
                }
                else
                {
                    string check_str = s.substr(i, j);
                    string rev_str = string(check_str.rbegin(), check_str.rend());

                    if (check_str == rev_str)
                    {
                        ++pallindrome_count;
                    }
                }

            }
        }
        return pallindrome_count;
    }

    string addBinary(string a, string b)
    {
        string new_binary;

        string temp;

        if (a.size() < b.size())
        {
            temp = a;
            a = b;
            b = temp;
        }

        int carry = 0;

        int j = a.size() - 1;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            int ch_of_b = (b[i] == '0') ? 0 : 1;
            int ch_of_a = (a[j--] == '0') ? 0 : 1;

            int current_bit_val = ch_of_a + ch_of_b + carry;

            if (current_bit_val == 2)
            {
                current_bit_val = 0;
                carry = 1;
            }
            else if (current_bit_val == 3)
            {
                current_bit_val = 1;
                carry = 1;
            }
            else if (current_bit_val == 1)
            {
                carry = 0;
            }

            char ch = (current_bit_val == 0) ? '0' : '1';
            new_binary.push_back(ch);
        }

        if (carry == 1 && j < 0)
        {
            new_binary.push_back('1');
        }
        else if (carry == 1 && j >= 0)
        {
            while (carry == 1 && j >= 0)
            {
                int ch_of_a = (a[j--] == '0') ? 0 : 1;

                int current_bit_val = ch_of_a + carry;

                if (current_bit_val == 2)
                {
                    current_bit_val = 0;
                    carry = 1;
                }
                else if (current_bit_val == 3)
                {
                    current_bit_val = 1;
                    carry = 1;
                }
                else if (current_bit_val == 1)
                {
                    carry = 0;
                }

                char ch = (current_bit_val == 0) ? '0' : '1';
                new_binary.push_back(ch);
            }

            if (carry == 1)
            {
                new_binary.push_back('1');
            }
        }

        while (j >= 0)
        {
            new_binary.push_back(a[j--]);
        }

        std::reverse(new_binary.begin(), new_binary.end());

        return new_binary;
    }

    bool isPalindrome(int x) {

        vector<int> digits;

        if (x > 0)
        {
            while (x > 0)
            {
                int digit = x % 10;

                digits.push_back(digit);

                x /= 10;
            }

            int index_begin = 0, index_end = digits.size() - 1;

            while (index_begin != index_end && index_begin < digits.size() / 2)
            {
                if (digits[index_begin++] != digits[index_end--])
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }

        return true;
    }

    int romanToInt(string s) {

        int num = 0;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s.at(i);

            if (ch == 'M')
            {
                num += 1000;
            }
            else if (ch == 'D')
            {
                num += 500;
            }
            else if (ch == 'C')
            {
                if (i + 1 < s.length() && s.at(i + 1) == 'D')
                {
                    num += 400;
                    ++i;
                }
                else if (i + 1 < s.length() && s.at(i + 1) == 'M')
                {
                    num += 900;
                    ++i;
                }
                else
                {
                    num += 100;
                }
            }
            else if (ch == 'X')
            {
                if (i + 1 < s.length() && s.at(i + 1) == 'L')
                {
                    num += 40;
                    ++i;
                }
                else if (i + 1 < s.length() && s.at(i + 1) == 'C')
                {
                    num += 90;
                    ++i;
                }
                else
                {
                    num += 10;
                }
            }
            else if (ch == 'L')
            {
                num += 50;
            }
            else if (ch == 'I')
            {
                if (i + 1 < s.length() && s.at(i + 1) == 'V')
                {
                    num += 4;
                    ++i;
                }
                if (i + 1 < s.length() && s.at(i + 1) == 'X')
                {
                    num += 9;
                    ++i;
                }
                else
                {
                    num += 1;
                }
            }
            else if (ch == 'V')
            {
                num += 5;
            }

        }

        return num;
    }

    static bool comp(const string& s1, const string& s2)
    {
        return (s1.size() < s2.size());
    }

    string longestCommonPrefix(vector<string>& strs) {

        auto min_elem = std::min_element(strs.begin(), strs.end(), Solution::comp);
        int len_of_shortest_str = (*min_elem).length();

        string common_prefix = "";

        for (int index = 0; index < len_of_shortest_str; index++)
        {
            std::map<char, int> char_countr;

            int count = 0;
            bool is_init_once = false;
            char prev_ch = '\0';

            for (int word_index = 0; word_index < strs.size(); word_index++)
            {
                if (is_init_once == false)
                {
                    prev_ch = strs[word_index].at(index);
                    is_init_once = true;
                }

                char curr_ch = strs[word_index].at(index);

                if (prev_ch == curr_ch)
                {
                    count++;
                }

                char_countr.insert_or_assign(curr_ch, count);
            }

            if (char_countr[strs[0].at(index)] == strs.size())
            {
                common_prefix.push_back(strs[0].at(index));
            }
            else
            {
                return common_prefix;
            }

            char_countr.clear();
        }

        return common_prefix;
    }

    bool isValid(string s) {

        int sum = 0;

        stack<char> paranth;

        for (char& ch : s)
        {
            if (ch == '{' || ch == '(' || ch == '[')
            {
                // if (paranth.empty() || ('{' == paranth.top()) || ('(' == paranth.top()) || ('[' == paranth.top()))
                {
                    paranth.push(ch);
                }
            }
            else if (ch == '}' || ch == ')' || ch == ']')
            {
                if (ch == '}' && !paranth.empty() && paranth.top() == '{')
                {
                    paranth.pop();
                }
                else if (ch == ')' && !paranth.empty() && paranth.top() == '(')
                {
                    paranth.pop();
                }
                else if (ch == ']' && !paranth.empty() && paranth.top() == '[')
                {
                    paranth.pop();
                }
                else
                {
                    //not a valid match
                    return false;
                    break;
                }
            }
        }

        return (paranth.empty());

    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //ref: https://www.codespeedy.com/merge-two-linked-list-in-cpp/

        if (list1->next == NULL && list2->next != NULL)
        {
            ListNode* temp = list2->next;
            list2->next = list1;
            list1->next = temp;

            return list2;
        }
        else if (list2->next == NULL && list1->next != NULL)
        {
            ListNode* temp = list1->next;
            list1->next = list2;
            list2->next = temp;

            return list1;
        }
        else if (list1->next && list2->next)
        {
            ListNode* t1 = list1->next;
            ListNode* t2 = list2->next;

            if (list1->val <= list2->val)
            {
                list1->next = list2;
                list2->next = t1;

                return mergeTwoLists(t1, t2);
            }
            else
            {
                list2->next = list1;
                list1->next = t2;

                return mergeTwoLists(t2, t1);
            }
        }
        else if ((list1->next == NULL && list2->next == NULL))
        {
            list1->next = list2;

            return list1;
        }
    }

    bool check_index_range(int main_index, int substr_len)
    {
        string main;
        string sub;


    }

    int chkstrstr(string haystack, string needle)
    {
        int substr_index = -1;

        if (needle.length() > 0 && haystack.length() > 0 && (haystack.length() >= needle.length()))
        {
            for (int index = 0; index < haystack.length(); index++)
            {
                if (haystack[index] == needle[0])
                {
                    int char_match_count = 0;
                    int test_index = index;
                    for (int j = 0; j < needle.length(); j++)
                    {
                        if (index < haystack.length() && haystack[test_index++] == needle[j])
                        {
                            ++char_match_count;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (char_match_count == needle.length())
                    {
                        substr_index = index;
                        break;
                    }
                }
            }
        }

        return substr_index;
    }

    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;

        do
        {
            if (s[i] == ' ')
            {
                i--;
            }
        } while (s[i] == ' ');

        int index_to_start = s.size() - 1 - i;

        int last_word_count = 0;
        for (std::string::reverse_iterator rit = s.rbegin() + index_to_start; rit != s.rend(); ++rit)
        {
            if (*rit != ' ')
            {
                ++last_word_count;
            }
            else
            {
                break;
            }
        }

        return last_word_count;
    }

    void print_multimap_smaple()
    {
        multimap<int, int> gquiz1;

        gquiz1.insert({ 1, 20 });
        gquiz1.insert({ 1, 30 });
        gquiz1.insert({ 1, 100 });

        gquiz1.insert({ 2, 10 });

        gquiz1.insert({ 3, 40 });
        gquiz1.insert({ 3, 50 });

        gquiz1.insert({ 4, 60 });

        cout << "\nThe multimap gquiz1 is : \n";
        cout << "\tKEY\tELEMENTS\n";

        multimap<int, int>::iterator itr;
        for (itr = gquiz1.begin(); itr != gquiz1.end(); itr++)
        {
            int key_count = gquiz1.count(itr->first);

            cout << '\t' << itr->first << '\t';

            auto range = gquiz1.equal_range(itr->first);

            for (auto i = range.first; i != range.second; ++i)
            {
                std::cout << i->second << ' ';
            }
            cout << endl;

            while (--key_count != 0)
            {
                ++itr;
            }
        }

        cout << endl;

    }
};


void insert(ListNode** head_ref, int new_data)
{
    ListNode* new_node = new ListNode();
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//function to print a singly linked list 
void Print(ListNode* head)
{
    ListNode* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print(int x)
{
    cout << "x=" << x << endl;
}

int main()
{
    try
    {
        int test = 7;

        Solution s;

        vector<int> nums1 = { -3, 4, 3, 90 };
    }
    catch (exception e)
    {
        cout << e.what();
    }
}
