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
#include <queue>
#include <unordered_set>
#include <ranges>
#include <stop_token>
#include <future>
#include "CGraph.h"

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

/*
def fun(self, chr:str, n:int):

        if n >= 0:
            print(chr, end=" ")
            self.fun("(", n-1)
            self.fun(")", n-1)
            print("")
        else:
            return;

s = CStack()
s.fun("(", 3)
*/

void fun(string str, int n)
{
    if (n > 0)
    {
        str.append(str);
        fun(str, n - 1);
        fun(str, n - 1);
    }
    else
    {
        std::cout << str;
        return;
        std::cout << "\n";
    }
}

void tfun(array<int, 6> & x)
{
    for (auto el : x)
    {
        std::cout << el << " ";
    }
}

class Compare {
public:
    bool operator()(const std::map<int, string>& L, const std::map<int, string>& R)
    {
        
    }
};

class Point
{
public:
    Point(int x = 0, int y = 0);
    ~Point();

private:
    int x;
    int y;
};

Point::Point(int x, int y)
{
    std::cout << "Constructor"<<endl;
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    std::cout << "Destructor" << endl;
}

void printcube(vector<vector<int>>& sudok, int rw, int col)
{
    //print a cube 3x3

    for (int i = rw; i < rw + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            std::cout << sudok[i][j] << " ";
        }

        std::cout << endl;
    }
}

void myf(std::promise<int> & prom)
{
    int c = 0;

    std::cout << "processing...";
    
    while (c++ < 10)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Done";

    prom.set_value(c);

}


//---------------------------------------------------------------------------

class Entity
{
public:
    virtual ~Entity()
    {
        cout << "\nEntity Destructor";
    }

    virtual void printName() = 0;

protected:
    Entity()
    {
        cout << "\nEntity Constructor";
    }
};

class Shape : public Entity
{
public:
    virtual int getArea() = 0;

    int getLen()
    {
        return _len;
    }

    void setLen(int lenVal)
    {
        _len = lenVal;
    }

    int getWidth()
    {
        return _width;
    }

    void setWidth(int widthVal)
    {
        _width = widthVal;
    }

    virtual ~Shape()
    {
        cout << "\nShape Destructor";
    }

protected:

    Shape(int l, int w) : _len(l), _width(w)
    {
        cout << "\nShape Constructor";
    }

    int _len;
    int _width;
};

class Rect : public Shape
{
public:

    Rect(int len, int width) : Shape(len, width)
    {
        cout << "\nRect Constructor";
    }

    void printName() override
    {
        cout << "\nThis is Rect";
    }

    int getArea() override
    {
        auto area = getLen() * getWidth();
        cout << "\nRect GetArea() = "<<area;
        return area;
    }

    ~Rect()
    {
        cout << "\nRect Destructor";
    }

};

class comp
{
public:

    bool operator()(const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs) const {
        // Custom comparison based on the keys
        return lhs.first < rhs.first; // Use ">" for min-heap and "<" for max-heap
    }
};

class TreeN
{
public:

    int data;
    TreeN* left;
    TreeN* right;


    TreeN(int dat, TreeN* l, TreeN* r) : data(dat), left(l), right(r)
    {

	}
};

class CBinaryTree
{
public:

    CBinaryTree()
    {
		root = nullptr;
	}

    ~CBinaryTree()
    {
        delete root;
    }

    void PreOrder(TreeN* root)
    {
		if (root == nullptr)
			return;

		cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}

    void Inorder(TreeN* root)
    {
		if (root == nullptr)
			return;

		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}

    void Postorder(TreeN* root)
	{
        if (root == nullptr)
            return;

        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }

    void BFS()
    {
        if (root == nullptr)
            return;

        queue<TreeN*> q;
        q.push(root);

        while (!q.empty())
        {
            auto front_node = q.front();
            q.pop();

            std::cout << front_node->data << " ";

            if (front_node->left)
                q.push(front_node->left);

            if (front_node->right)
                q.push(front_node->right);
        }
    }

    bool isValidBST(TreeN* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeN* root, long left, long right) {
        if (!root)
            return true;
        if (root->data < right && root->data > left) {
            return helper(root->left, left, root->data) && helper(root->right, root->data, right);
        }
        return false;
    }

private:
    TreeN* root;
};

mutex m;
condition_variable cv;

#define COUNT 10

void spinloop()
{
    int ctr = 100;
    while (ctr--)
    {
        cout << "Enter: "<< ctr;
    }
}

int main()
{
    
    //https://www.google.com/imgres?imgurl=https%3A%2F%2Fi.ytimg.com%2Fvi%2FFrLWd1tJ_Wc%2Fmaxresdefault.jpg&tbnid=LNPbwgMvGNDt7M&vet=12ahUKEwiw8Ynqp83_AhW3itgFHTbWAWIQMygCegUIARDkAQ..i&imgrefurl=https%3A%2F%2Fm.youtube.com%2Fwatch%3Fv%3DFrLWd1tJ_Wc&docid=zlfm8TTQomG_FM&w=1280&h=720&q=Bellman%20Ford%27s%20Algorithm&ved=2ahUKEwiw8Ynqp83_AhW3itgFHTbWAWIQMygCegUIARDkAQ 

    //BellManFord Algorithm Testing image

    Graph g;

    g.addEdgeWeighted(0, 1, 7);
    g.addEdgeWeighted(0, 2, 12);

    g.addEdgeWeighted(1, 2, 2);
    g.addEdgeWeighted(1, 3, 9);

    g.addEdgeWeighted(2, 4, 10);

    g.addEdgeWeighted(3, 5, 1);

    g.addEdgeWeighted(4, 3, 4);
    g.addEdgeWeighted(4, 5, 5);

    g.addEdgeWeighted(5, -1, -1);

    auto ret = g.Dijkstra(0);

    cout << "Following is Depth First Traversal"
        " (starting from vertex 2) \n";

    // Function call
    g.BFSMain(2);


    map<int, string> mp = { {1,"A"}, {2, "B"}, {3, "C"}};

    std::priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;

    for (auto&[k,val] : mp)
    {
        pq.emplace(k, val);
    }


    auto rett = pq.top();


    vector<vector<int>> sudokuCube = {  {5, 3, 0, 0, 7, 0, 0, 0, 0},
                                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                        {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                        {0, 0, 0, 0, 8, 0, 0, 7, 9} 
                                     };

    for (size_t x = 0; x < 7; x+= 3)
    {
        for (int y = 0; y < 7; y+= 3)
        {
            printcube(sudokuCube, x, y);
            std::cout << "---------------------------\n";
        }

        std::cout << endl;
    }

    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread th(myf, std::ref(prom));
    th.detach();

    auto ans = fut.get();

    std::cout << "mystr";

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

    vector<int> xnums {3,4,1,2,6,7};
    
    //mhp.MaxifyHeap(xnums, 0);

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

    int numfromUser = 0;

    cout << "Enter a number: ";

    std::cin >> numfromUser;

    spinloop();

    return 0;
}