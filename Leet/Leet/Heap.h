#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum class HEAPTYPE
{
	Max,
	Min
};

class POINT
{
public:

	int x, y;

	POINT(int x_val = 0, int y_val = 0) :x(x_val), y(y_val)
	{

	}

	~POINT()
	{

	}
};

class MyHeap
{
public:
	
	MyHeap();

	int LEFT(int i, const vector<int>& list);
	int RIGHT(int i, const vector<int>& list);
	int PARENT(int i, const vector<int>& list);

	vector<int> Build_Heap(vector<int> list, HEAPTYPE type);

	void MaxifyHeap(vector<int> &list, int indx);
	void MinifyHeap(vector<int> &list, int indx);

	int lastStoneWeight(vector<int>& stones);

	vector<vector<int>> kClosest(vector<vector<int>>& points, int k);

	int cal_euclidian_distance(POINT p1, POINT p2);

	~MyHeap();

private:

};

class KthLargest {

	int kthLargest;
	vector<int> nums_heap;

public:
	KthLargest(int k, vector<int>& nums);
	int add(int val);
};