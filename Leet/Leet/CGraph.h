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

    map<int, list<pair<int,int>>> adj_list_weighted;

    queue<int> qForBFS;

public:

    void addEdge(int vertex, int w);

    void addEdgeWeighted(int vertex, int w, int weight);

    void DFS(int vertex);

    void BFSMain(int root_vertex);

    vector<int> BellManFord(int root_vertex);
};