#include "Heap.h"

MyHeap::MyHeap()
{
}

MyHeap::~MyHeap()
{
}

vector<int> MyHeap::Build_Heap(vector<int> list, HEAPTYPE type)
{
	int heap_size = list.size();

	for (int i = std::floor(heap_size/2.f) - 1; i >= 0; i--)
	{
		//Root nodes
		cout << list[i] << "-" << i << endl;

		//apply heapify

		if (type == HEAPTYPE::Max)
		{
			MaxifyHeap(list, i);
		}
		else
		{
			MinifyHeap(list, i);
		}
	}

	return list;
}



int MyHeap::LEFT(int i, const vector<int> &list)
{
	int indx = 2 * i + 1;
	
	if (indx < list.size())
	{
		return indx;
	}

	return -1;
}

void MyHeap::MaxifyHeap(vector<int> &list, int indx)
{
	auto left = 2 * indx + 1;
	auto right = 2 * indx + 2;

	auto largest = indx;

	if (left < list.size() && list[indx] < list[left])
	{
		largest = left;
	}

	if (right < list.size() && list[largest] < list[right])
	{
		largest = right;
	}

	if (largest != indx)
	{
		swap(list[indx], list[largest]);
		MaxifyHeap(list, largest);
	}
}

void MyHeap::MinifyHeap(vector<int> &list, int indx)
{
	auto left = 2 * indx + 1;
	auto right = 2 * indx + 2;

	auto largest = indx;

	if (left < list.size() && list[left] < list[indx])
	{
		largest = left;
	}

	if (right < list.size() && list[right] < list[largest])
	{
		largest = right;
	}

	if (largest != indx)
	{
		swap(list[indx], list[largest]);
		MinifyHeap(list, largest);
	}
}

int MyHeap::RIGHT(int i, const vector<int>& list)
{
	int indx = 2 * i + 2;

	if (indx < list.size())
	{
		return indx;
	}

	return -1;
}

int MyHeap::PARENT(int i, const vector<int>& list)
{
	if (i >= 1)
	{
		int indx = std::floor((i-1)/2.f);
		return indx;
	}
	return -1;
}


