#include "Queue.h"

Queue::Queue()
{
	q = vector<int>(MAX_STACK_SIZE, 0);
	front = rear = -1;
}

void Queue::enqueue(int val)
{
	if (rear == -1)
	{
		q[++rear] = val;
		front = rear;
	}
	else if(rear < MAX_STACK_SIZE -1)
	{
		q[++rear] = val;
	}
	else
	{
		cout << "queue overflow";
	}
}

int Queue::dequeue()
{
	cout << rear;

	int val = -1;
	

	if (rear == -1)
	{
		front = rear;
		cout << "queue underflow";
	}
	else if (rear >= 0)
	{
		val = q[front];
		q.erase(q.begin() + front);
		q.push_back(0);

		--rear;
	}

	return val;
}

bool Queue::Isempty()
{
	return (front == rear);
}
