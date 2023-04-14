// Leet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Arrays.h"
#include "Recursion.h"
#include "SLL.h"
#include "Sorting.h"
#include "Stack.h"
#include "StackSLL.h"
#include "Queue.h"
#include "TwoPointers.h"
#include "SlidingWindow.h"
#include "Stacks.h"
#include <memory>
#include <algorithm>
#include <numeric>
#include "LinkedListClss.h"
#include <array>
#include <forward_list>
#include <list>
#include <deque>
#include <set>
#include <unordered_map>
#include "BSearch.h"
#include "Heap.h"
#include "BinaryTree.h"

class Vertex
{
public:
    int data;
    Vertex* link;

    Vertex(int val = 0)
    {
        data = val;
        link = NULL;
    }

    friend class MySLL;
};

class MySLL
{
public:
    Vertex* head = nullptr;

    MySLL()
    {

    }

    void add_front(int data)
    {
        Vertex* v = new Vertex(data);

        if (!head)
        {
            head = v;

            return;
        }

        v->link = head;
        head = v;
        
    }

    void add_at_end(int data)
    {
        Vertex* v = new Vertex(data);
        
        if (!head)
        {
            head = v;
            return;
        }

        Vertex* temp = head;
        Vertex* prev = nullptr;

        while (temp)
        {
            prev = temp;
            temp = temp->link;
        }

        prev->link = v;
    }

    void add_at_index(int data, int index)
    {

        if (!head)
        {
            cout << "empty sll";
            return;
        }

        Vertex* temp = head;
        int len = getLenofSLL();

        int indx_countr = 0;
        while (temp && indx_countr < index)
        {
            if (indx_countr == index - 1)
            {
                break;
            }

            indx_countr++;
            temp = temp->link;
        }

        Vertex* v = new Vertex(data);
        v->link = temp->link;
        temp->link = v;
    }

    void del_at_index(int index)
    {
        if (!head)
        {
            cout << "empty sll";
            return;
        }

        Vertex* temp = head;
        Vertex* prev = nullptr;

        int indx_countr = 0;
        while (temp && indx_countr < index)
        {
            if (indx_countr == index-1)
            {
                break;
            }

            indx_countr++;
            prev = temp;
            temp = temp->link;
        }

        prev->link = temp->link;
        delete(temp);
    }

    void del_front()
    {
        if (!head)
        {
            cout << "empty sll nothing to delete";
            return;
        }

        Vertex* v = head;
        head = head->link;
        delete(v);
    }

    void del_back()
    {
        if (!head)
        {
            cout << "empty sll nothing to delete";
            return;
        }

        Vertex* temp = head;
        Vertex* prev = nullptr;

        while (temp->link)
        {
            prev = temp;
            temp = temp->link;
        }

        prev->link = nullptr;
        delete(temp);
    }

    void printsll()
    {
        Vertex* t = head;


        cout << "\n";
        while (t)
        {
            cout << "| " << t->data << " | -> ";

            t = t->link;
        }
    }

    int getLenofSLL()
    {
        int len = 0;

        if (!head)
        {
            return 0;
        }

        Vertex* temp = head;
        while (temp)
        {
            len++;
            temp = temp->link;
        }

        return len;
    }

    ~MySLL()
    {

    }

private:

};

void printmydat(const array<array<int, 3>, 3>& two_d_arr)
{
    for (auto each_arrays_in : two_d_arr)
    {
        for (auto each_elem_in : each_arrays_in)
        {
            cout << each_elem_in<<" ";
        }

        cout << endl;
    }
}

int main()
{
    std::cout << "Hello World!\n";

    Arrays arr_ins;
    Recursion rec_ins;    
    LinkedList<int> sll;
    MySLL msll;
    Sorting sort_ins;
    Mystack s1;
    StackSLL s;
    Queue mq;
    TwoPointers tp;
    SlidingWindow sw;
    Stacks stk;
    LinkedlistClss ls;
    BSearch bs;
    MyHeap mhp;
    BinaryTree btree;
    BinarySeacrhTree bst;

    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<string>>board {
         {"5", "3", ".", ".", "7", ".", ".", ".", "."}
        ,{"6", ".", ".", "1", "9", "5", ".", ".", "."}
        ,{".", "9", "8", ".", ".", ".", ".", "6", "."}
        ,{"8", ".", ".", ".", "6", ".", ".", ".", "3"}
        ,{"4", ".", ".", "8", ".", "3", ".", ".", "1"}
        ,{"7", ".", ".", ".", "2", ".", ".", ".", "6"}
        ,{".", "6", ".", ".", ".", ".", "2", "8", "."}
        ,{".", ".", ".", "4", "1", "9", ".", ".", "5"}
        ,{".", ".", ".", ".", "8", ".", ".", "7", "9"}
    };

    std::vector<int> v1 = { 1, 2, 3, 4, 5 };
    //std::deque<int> d;

    std::vector<int> d;

    std::move(std::make_move_iterator(v1.begin()), std::make_move_iterator(v1.end()), std::back_inserter(d));

    /*
        Keep in mind that once you move elements from one container to another, the original container should not be used and the moved-from container should be considered as in unspecified state.
    */

    //v1 still exists

    vector<vector<int>> nums{ {1, 3 }, { -2, 2 }, { 2, -2 }};
    
    //mhp.MaxifyHeap(nums, 0);

    //mhp.kClosest(nums, 2);

    int res = sw.characterReplacement("", 1);

    INT_NODE* root = nullptr;

    root = bst.Insert(root, 5);

    root = bst.Insert(root, 3);
    root = bst.Insert(root, 6);

    root = bst.Insert(root, 2);
    root = bst.Insert(root, 4);

    root = bst.Insert(root, 7);
    root = bst.Insert(root, 9);

    auto srch = bst.Delete(root, 5);

    return 0;
}