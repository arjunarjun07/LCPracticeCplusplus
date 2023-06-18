#include "CGraph.h"


void Graph::addEdge(int vertex, int w)
{
	adj_list[vertex].push_back(w);
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