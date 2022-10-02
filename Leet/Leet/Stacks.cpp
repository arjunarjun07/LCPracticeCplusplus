#include "Stacks.h"
#include <string>


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

long int Stacks::evaluateRPN(vector<string>& tokens)
{
	std::stack<long int> operandstk;

	for (auto op : tokens)
	{
		if (op != "+" && op != "-" && op != "*" && op != "/")
		{
			operandstk.push(stol(op));
		}
		else
		{
			//operators possible 
			// + - * / - all binary operators so pop two times
			long int res = 0;

			long int right_op = operandstk.top();
			operandstk.pop();

			long int left_op = operandstk.top();
			operandstk.pop();

			if (op == "+")
			{
				res = left_op + right_op;
			}
			else if (op == "-")
			{
				res = left_op - right_op;
			}
			else if(op == "*")
			{
				res = left_op * right_op;
			}
			else if(op == "/")
			{
				res = left_op / right_op;
			}

			operandstk.push(res);
		}
	}

	return operandstk.top();
}

