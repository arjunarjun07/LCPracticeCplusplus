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

void Sorting::printData(std::vector<int>& list)
{
	for (int i = 0; i< list.size(); i++)
	{
		std::cout << "| " << list[i] << " |";
	}
}
