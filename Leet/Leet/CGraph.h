#pragma once

#include <vector>
#include <queue>
#include <map>
#include <list>
#include <iostream>
#include <stack>

using namespace std;

class Graph
{
private:
    map<int, bool> visited_map;

    map<int, list<int>> adj_list;

    queue<int> qForBFS;

public:

    void addEdge(int vertex, int w);

    void DFS(int vertex);

    void BFSMain(int root_vertex);
};