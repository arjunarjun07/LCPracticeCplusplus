#pragma once
#include <vector>
#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class Queue
{
private:

	std::vector<int> q;
	int front;
	int rear;

public:

	Queue();

	void enqueue(int val);

	int dequeue();

	bool Isempty();
};