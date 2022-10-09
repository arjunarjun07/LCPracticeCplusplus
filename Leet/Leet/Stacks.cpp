#include "Stacks.h"
#include <string>
#include <unordered_map>
#include <algorithm>


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

void Stacks::BackTrack(int lparanth_count, int rparanth_count, int &n, vector<string> &res, std::string &current_str)
{
	if (lparanth_count == rparanth_count && lparanth_count == n)
	{
		res.push_back(current_str);
		return;
	}

	if (lparanth_count < n) // We need n opening paranthesis "(" in order to form a pair
	{
		string str = current_str + "(";
		BackTrack(lparanth_count + 1, rparanth_count, n, res, str);
	}

	if (rparanth_count < lparanth_count) // we need have closing paranthesis exactly match the pair & also we can not have closing paranthesis in result str before filling the respective opening paranthesis
	{
		string str = current_str + ")";
		BackTrack(lparanth_count, rparanth_count + 1, n, res, str);
	}
}

vector<string> Stacks::generateParenthesis(int n)
{
	vector<string>res;
	string current_str = "";

	BackTrack(0, 0, n, res, current_str);

	return res;
}

vector<int> Stacks::dailyTemperatures(vector<int>& temperatures)
{
	vector<int> res(temperatures.size(), 0);
	std::stack<std::pair<int, int>> temp_stk;

	for (int i = 0; i < temperatures.size(); i++)
	{
		while (!temp_stk.empty() && temperatures[i] > temp_stk.top().first)
		{
			std::pair<int, int> temp_obj = temp_stk.top();

			int temp_of_stk_top = temp_obj.first;
			int index_of_stk_top = temp_obj.second;

			int num_of_days_to_see_greater_temp = i - index_of_stk_top;

			res[index_of_stk_top] = num_of_days_to_see_greater_temp;

			temp_stk.pop();
		}

		temp_stk.push(std::pair<int,int>(temperatures[i], i));
	}

	return res;
}

int Stacks::carFleet(int target, vector<int>& pos, vector<int>& speed)
{
	
	{
		vector<pair< int, int >> nums;

		for (int i = 0; i < pos.size(); i++)
		{
			nums.push_back({ pos[i] , speed[i] });
		}

		sort(nums.begin(), nums.end());

		stack< double > stk;


		for (int i = nums.size() - 1; i >= 0; i--)
		{
			double t = (target - nums[i].first) / ((double)nums[i].second);

			if (stk.empty() || stk.top() < t)
			{
				stk.push(t);
			}
		}

		return stk.size();
	}
}

