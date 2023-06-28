#include "CGraph.h"


void Graph::addEdge(int vertex, int w)
{
	adj_list[vertex].push_back(w);
}

void Graph::addEdgeWeighted(int vertex, int w, int weight)
{
	if (w == -1)
	{
		//Vertex with no edge

		adj_list_weighted[vertex] = list<pair<int, int>>();
		return;
	}

	adj_list_weighted[vertex].push_back(make_pair(w, weight));
}

//Depth First 
void Graph::DFS(int vertex)
{
	visited_map[vertex] = true;
	std::cout << vertex << " ";

	//for each adj nodes, do DFS

	for (auto it = adj_list[vertex].begin(); it != adj_list[vertex].end(); it++)
	{
		bool isKeyFoundInVisitedMap = visited_map.contains(*it);

		if (isKeyFoundInVisitedMap == false || (isKeyFoundInVisitedMap && visited_map[*it] == false))
		{
			DFS(*it);
		}
	}
}

//Breadth First
void Graph::BFSMain(int root_vertex)
{
	//push first node into queue
	qForBFS.push(root_vertex);

	//process all neighbour nodes
	while (!qForBFS.empty())
	{
		int qfront = qForBFS.front();
		visited_map[qfront] = true;

		cout << qfront << " ";

		qForBFS.pop();

		for (auto it = adj_list[qfront].begin(); it != adj_list[qfront].end(); it++)
		{
			bool isKeyFoundInVisitedMap = visited_map.contains(*it);

			if (isKeyFoundInVisitedMap == false || (isKeyFoundInVisitedMap && visited_map[*it] == false))
			{
				qForBFS.push(*it);
			}
		}
	}
}

vector<int> Graph::BellManFord(int root_vertex)
{
	if (adj_list_weighted.size() == 0)
	{
		return vector<int>();
	}

	vector<int> dist(adj_list_weighted.size(), INT_MAX);
	dist[root_vertex] = 0;

	//u - source vertex

	for (auto& [u, edges] : adj_list_weighted)
	{
		//v - destination vertex
		//w - weight of edge u-v

		for (auto& [v, wght] : edges)
		{
			if (dist[u] != INT_MAX && dist[u] + wght < dist[v])
			{
				dist[v] = dist[u] + wght;
			}
		}
	}

	//check for negative weight cycle

	for (auto& [u, edges] : adj_list_weighted)
	{
		for (auto& [v, wght] : edges)
		{
			if (dist[u] != INT_MAX && dist[u] + wght < dist[v])
			{
				cout << "Graph contains negative weight cycle" << endl;
				return vector<int>();
			}
		}
	}

	return dist;
}

vector<int> Graph::Dijkstra(int root_vertex)
{
	auto minHeapComp = [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; };

	if (adj_list_weighted.size() == 0)
	{
		return vector<int>();
	}

	vector<int> dist(adj_list_weighted.size(), INT_MAX);
	dist[root_vertex] = 0;

	//min heap to get min distance vertex
	vector < pair<int, int>> vctrHeap;

	for (auto& [u, edges] : adj_list_weighted)
	{
		vctrHeap.push_back(make_pair(u, dist[u]));
	}

	std::make_heap(vctrHeap.begin(), vctrHeap.end(), minHeapComp);

	while (!vctrHeap.empty())
	{
		int u = vctrHeap.front().first;
		
		std::pop_heap(vctrHeap.begin(), vctrHeap.end(), minHeapComp);
		vctrHeap.pop_back();


		for (auto& [v, wght] : adj_list_weighted[u])
		{
			if (dist[u] != INT_MAX && dist[u] + wght < dist[v])
			{
				dist[v] = dist[u] + wght;

				//decrease distance value in min heap
				for (auto& [heapV, heapWght] : vctrHeap)
				{
					if (heapV == v)
					{
						heapWght = dist[v];
						break;
					}
				}

				std::make_heap(vctrHeap.begin(), vctrHeap.end(), minHeapComp);
			}
		}
	}

	return dist;
}
