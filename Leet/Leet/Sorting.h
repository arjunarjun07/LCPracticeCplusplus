#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Sorting
{
public:
	void BubleSort(std::vector<int> &list);

	void SelectionSort(std::vector<int>& list);

	void InsertionSort(std::vector<int>& list);

	void MergeSort(std::vector<int>& list, int l, int r);

	void printData(std::vector<int>& list);
};