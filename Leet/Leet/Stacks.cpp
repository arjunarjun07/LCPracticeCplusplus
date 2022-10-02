#include "Stacks.h"


Stacks::Stacks()
{
}

Stacks::~Stacks()
{
}

bool Stacks::isValid(string s)
{
	bool valid = false;

	std::stack<char> paranth_stk;

	int open_c = 0;
	int close_c = 0;

	for (auto var : s)
	{
		if (var == '(' || var == '{' || var == '[')
		{
			open_c++;
			paranth_stk.push(var);
		}
		else
		{
			close_c++;

			if (!paranth_stk.empty())
			{
				char top = paranth_stk.top();

				if (var == ')' && top == '(')
				{
					paranth_stk.pop();
				}
				else if (var == '}' && top == '{')
				{
					paranth_stk.pop();
				}
				else if (var == ']' && top == '[')
				{
					paranth_stk.pop();
				}
			}
		}
	}

	valid = (paranth_stk.empty() == true && open_c == close_c)? true : false;

	return valid;
}

