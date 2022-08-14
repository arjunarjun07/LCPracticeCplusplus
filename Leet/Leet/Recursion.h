#pragma once
#include <iostream>
using namespace std;

class Recursion
{
public:

    void print_natural_nums(int n);

    int sum_of_n(int n);

    void print_arr(int a[], int n);

    int count_digits(int num);

    int sum_of_digits(int num);

    int GCD(int a, int b);

    void reverse(string& str, int l, int h);

    void convertbinary(int num);

    bool IsPrime(int num, int divisor);

    void print_even_nums_in_range(int num);

    void print_odd_nums_in_range(int num);
    
    bool CheckPallindrome(string& str, int start_i, int end_i);

    int RaisePower(int num, int pow);

};