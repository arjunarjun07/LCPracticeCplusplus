#pragma once
#include <stack>

#include <iostream>
#include <vector>

using namespace std;

class Stacks
{
public:
	Stacks();
	~Stacks();

	bool isValid(string s);

    long int evaluateRPN(vector<string> &tokens);

    vector<int> dailyTemperatures(vector<int>& temperatures);

};

class MinStack
{
public:
    int mini(int a, int b) { return a > b ? b : a; }

    stack<pair<int, int> > s;

    void push(int element)
    {
        /* new max will be given no. if stack is empty else
        we compare given no. to max at current top of
        stack*/

        int new_min = s.empty()
            ? element
            : mini(element, s.top().second);

        // we push the pair of given_element,new_min in s

        s.push({ element, new_min });
    }

    int pop()
    {
        int popped;
        if (!s.empty()) {
            // popped has popped number
            popped = s.top().first;
            s.pop();
        }
        else {
            // print a message or throw exception etc
        }
        return popped;
    }

    int minimum()
    {
        int min_elem = s.top().second;
        return min_elem;
    }
};