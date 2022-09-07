#include "Stack.h"

stack::stack()
{
	stk = vector<int>(MAX_STACK_SIZE, 0);
	top = -1;
}

void stack::push(int val)
{
	if (top < MAX_STACK_SIZE - 1 )
	{
		stk[++top] = val;
	}
	else
	{
		cout << "stack overflow";
	}
}

int stack::pop()
{
	if (top >= 0)
	{
		int val = stk[top];
		stk.erase(stk.begin() + top);
		stk.push_back(0);
		top = top - 1;

		return val;
	}
	else
	{
		std::cout << "stk underflow";
		return -1;
	}
}

bool stack::Isempty()
{
	return (top < 0);
}