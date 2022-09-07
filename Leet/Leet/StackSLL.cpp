#include "StackSLL.h"

StackSLL::StackSLL()
{
	top = nullptr;
}

void StackSLL::push(int val)
{
	Nodee* n = new Nodee();

	if (!n)
	{
		std::cout << "stack overflow";
		return;
	}

	n->data = val;

	if (top == nullptr)
	{
		top = n;
	}
	else
	{
		n->next = top;
		top = n;
	}
}

int StackSLL::pop()
{
	int val = -1;

	if (top)
	{
		val = top->data;

		Nodee* top_node = top;
		top = top->next;

		delete(top_node);
	}
	else
	{
		cout << "stack underflow";
	}

	return val;
}

bool StackSLL::Isempty()
{
	return (top) ? true : false;
}

StackSLL::~StackSLL()
{
	while (top)
	{
		Nodee* temp = top;
		top = top->next;

		delete(temp);
	}
}
