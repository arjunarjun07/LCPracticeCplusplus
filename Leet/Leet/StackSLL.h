#pragma once
#include<iostream>

using namespace std;

class Nodee
{
private:
    int data;
    Nodee* next;
    friend class StackSLL;

public:
    Nodee() 
    {
        this->next = nullptr;
    }
};

class StackSLL
{
private:
    Nodee* top;

public:

    StackSLL();

    void push(int val);

    int pop();

    bool Isempty();

    ~StackSLL();
};