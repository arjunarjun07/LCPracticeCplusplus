#pragma once
#include "Recursion.h"

void Recursion::print_natural_nums(int n)
{
    if (n < 1)
        return;

    if (n >= 1)
    {
        cout << " " << n;
        print_natural_nums(n - 1);
    }

}

int Recursion::sum_of_n(int n)
{
    if (n == 0)
        return 0;
    else
    {
        cout << " " << n << endl;
        return n + sum_of_n(n - 1);
    }
}

void Recursion::print_arr(int a[], int n)
{
    if (n < 0)
        return;
    else
    {
        print_arr(a, n - 1);
        cout << a[n];
    }
}

int Recursion::count_digits(int num)
{
    if (num == 0)
        return 0;
    else
    {
        return 1 + count_digits(num / 10);
    }
}

int Recursion::sum_of_digits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 10) + sum_of_digits(num / 10);
    }
}

int Recursion::GCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
    else if (a != 0 && b != 0)
    {
        if (a > b)
            return GCD(b, a % b);
        else
            return GCD(a, b % a);
    }
}

void Recursion::reverse(string& str, int l, int h)
{
    if (l < h)
    {
        swap(str[l], str[h]);
        reverse(str, l + 1, h - 1);
    }
}

void Recursion::convertbinary(int num)
{
    if (num == 0)
    {
        cout << "0";
        return;
    }
    else if (num == 1)
    {
        cout << "1";
        return;
    }
    else
    {
        convertbinary(num / 2);
        cout << num % 2;
    }

}

bool Recursion::IsPrime(int num, int divisor)
{
    static int number = num;

    if (number % divisor == 0)
    {
        return false;
    }

    if (divisor <= number / 2)
    {
        return IsPrime(number, divisor + 1);
    }
    else
    {
        return true;
    }
}

void Recursion::print_even_nums_in_range(int num)
{
    if (num <= 0)
    {
        return;
    }
    else
    {
        print_even_nums_in_range(num - 1);

        if (num % 2 == 0)
            std::cout << " " << num;

    }
}

void Recursion::print_odd_nums_in_range(int num)
{
    if (num <= 0)
    {
        return;
    }
    else
    {
        print_odd_nums_in_range(num - 1);

        if (num % 2 != 0)
            std::cout << " " << num;

    }
}

bool Recursion::CheckPallindrome(string& str, int start_i, int end_i)
{
    if (str[start_i] != str[end_i])
    {
        return false;
    }

    if (start_i < end_i)
    {
        return CheckPallindrome(std::ref(str), start_i + 1, end_i - 1);
    }
    else
    {
        return true;
    }
}

int Recursion::RaisePower(int num, int pow)
{
    if (pow == 1)
    {
        return num;
    }
    else
    {
        return num * RaisePower(num, pow - 1);
    }
}