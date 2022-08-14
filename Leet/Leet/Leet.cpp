// Leet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Arrays.h"
#include "Recursion.h"

int main()
{
    std::cout << "Hello World!\n";

    Arrays arr_ins;
    Recursion rec_ins;

    vector<int> v = { 2 };

    int elem = arr_ins.GetFirstRecurringElement(v);

    return 0;
}