#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum class HEAPTYPE
{
	Max,
	Min
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

	~MyHeap();

private:

};