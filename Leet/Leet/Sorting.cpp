#include "Sorting.h"

void Sorting::BubleSort(std::vector<int> &list)
{
	//sink sort - largest elements will move down on each iteration

	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < (list.size() - i - 1); j++) // Last i elements are already in place -> ( n - i - 1 ) no need to check last i elements because it is already sorted in place
		{
			if (list[j] > list[j+1])
			{
				std::swap(list[j], list[j+1]);
			}
		}
	}
}

void Sorting::SelectionSort(std::vector<int>& list)
{
	//select an element & consider it as min & swap till it reaches its apt position

	int i, j;

	for (i = 0; i < list.size(); i++)
	{
		int smallest = list[i];
		int index_of_smallest = -1;

		for (j = i + 1; j < list.size(); j++)
		{
			if (list[j] < smallest)
			{
				smallest = list[j];
				index_of_smallest = j;
			}
		}

		if(index_of_smallest != -1)
			std::swap(list[i], list[index_of_smallest]);
	}
}

void Sorting::InsertionSort(std::vector<int>& list)
{
	//similar to a sorting way of card deck in hand

	int i, j, key;

	for (int i = 1; i < list.size(); i++)
	{
		key = list[i];
		j = i - 1;

		while (j >= 0 && list[j] > key)
		{
			std::swap(list[j + 1], list[j]);
			j--;
		}
	}
}

// the interval from [s to m] and [m+1 to e] in v are sorted
// the function will merge both of these intervals
// such the interval from [s to e] in v becomes sorted
void MergeSortedIntervals(std::vector<int>& v, int s, int m, int e)
{

	// temp is used to temporary store the vector obtained by merging
	// elements from [s to m] and [m+1 to e] in v
	std::vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s]; 	//Not clear - Copying elements from temp to actual list

}

void Sorting::MergeSort(std::vector<int>& list, int left_indx, int right_indx)
{
	if (left_indx < right_indx)
	{
		int mid = (left_indx + right_indx)/ 2;

		MergeSort(list, left_indx, mid);
		MergeSort(list, mid+1, right_indx);
		MergeSortedIntervals(list, left_indx, mid, right_indx);
	}
	else
	{
		return;
	}
}

void Sorting::printData(std::vector<int>& list)
{
	for (int i = 0; i< list.size(); i++)
	{
		std::cout << "| " << list[i] << " |";
	}
}
