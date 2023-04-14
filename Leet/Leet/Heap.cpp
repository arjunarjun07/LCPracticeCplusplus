#include "Heap.h"
#include <algorithm>
#include <queue>
#include <map>

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

int MyHeap::lastStoneWeight(vector<int>& stones)
{
	std::priority_queue<int> max_heap;

	for (auto elem: stones)
	{
		max_heap.push(elem);
	}

	while (max_heap.size() > 1) 
	{
		auto first_greatest_stone = max_heap.top();
		max_heap.pop();

		auto second_greatest_stone = max_heap.top();
		max_heap.pop();

		auto diff_weights = std::abs(first_greatest_stone - second_greatest_stone);

		if (diff_weights != 0)
		{
			max_heap.push(diff_weights);
		}

	}


	int res = (max_heap.size() > 0) ? max_heap.top() : 0;

	return res;
}

class myComparator
{
public:
	bool operator() (const POINT& p1, const POINT& p2)
	{
		auto p1_dis = (pow(p1.x, 2) + pow(p1.y, 2));
		auto p2_dis = (pow(p2.x, 2) + pow(p2.y, 2));

		bool result = (p1_dis > p2_dis) ? true : false;

		return result;
	}
};

int MyHeap::cal_euclidian_distance(POINT p1, POINT p2)
{
	// Calculating distance
	return (pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); //no need of sqrt - for this problem only
}

vector<vector<int>> MyHeap::kClosest(vector<vector<int>>& points, int k)
{
	// cal euclidian dist between the point & origin
	// build min heap using priority queue
	// pop k nodes from the priority queue

	vector<vector<int>> result;

	priority_queue<POINT, vector<POINT>, myComparator > min_heap;

	POINT origin(0, 0);

	for (auto each_point_in : points)
	{
		POINT p1(each_point_in[0], each_point_in[1]);

		int euclidian_dist = cal_euclidian_distance(origin, p1);

		min_heap.push(p1);
	}

	while (min_heap.size() > 0 && k-- > 0)
	{
		auto p1 = min_heap.top();
		min_heap.pop();

		vector<int> point_as_vector{ p1.x, p1.y };
		
		result.push_back(point_as_vector);

		point_as_vector.clear();
	}

	return result;
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

KthLargest::KthLargest(int k, vector<int>& nums)
{
	copy(nums.begin(), nums.end(), back_inserter(nums_heap));
	kthLargest = k;

	std::make_heap(nums_heap.begin(), nums_heap.end(), std::greater<>{});

	while (nums_heap.size() > k)
	{
		pop_heap(nums_heap.begin(), nums_heap.end(), std::greater<>{});
		nums_heap.pop_back();
	}
}

int KthLargest::add(int val)
{
	int res_val = -1;

	nums_heap.push_back(val);
	push_heap(nums_heap.begin(), nums_heap.end(), std::greater<>{});

	//Need to fetch kth largest from the heap
	while (nums_heap.size() > kthLargest)
	{
		pop_heap(nums_heap.begin(), nums_heap.end(), std::greater<>{});
		nums_heap.pop_back();
	}

	res_val = nums_heap[0];

	return res_val;
}

