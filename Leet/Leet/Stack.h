#pragma once
#include <vector>
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class Mystack
{
private:
	
	std::vector<int> stk;
	int top;

public:

	Mystack();

	void push(int val);

	int pop();

	bool Isempty();
};