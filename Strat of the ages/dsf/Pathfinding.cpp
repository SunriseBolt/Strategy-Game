#include "Pathfinding.h"

void Graph::ComputePaths(int source, const vect &Graph, vector<double> &min_distance, vector<int> &previous)
{
	int n = Graph.size();
	min_distance.clear();
	min_distance.resize(n, weight);
	min_distance[source] = 0;
	previous.clear();
	previous.resize(n, -1);
	set<pair<double, int> > vertex_queue;
	vertex_queue.insert(make_pair(min_distance[source], source));

	while (!vertex_queue.empty()) 
	{
		double dist = vertex_queue.begin()->first;
		int u = vertex_queue.begin()->second;
		vertex_queue.erase(vertex_queue.begin());

		// Visit each edge exiting u
		const vector<node> nodes = Graph[u];
		for (vector<node>::const_iterator node_iter = nodes.begin();
			node_iter != nodes.end();
			node_iter++)
		{
			int v = node_iter->target;
			double weight = node_iter->weight;
			double distance_through_u = dist + weight;
			if (distance_through_u < min_distance[v]) {
				vertex_queue.erase(make_pair(min_distance[v], v));

				min_distance[v] = distance_through_u;
				previous[v] = u;
				vertex_queue.insert(make_pair(min_distance[v], v));

			}

		}
	}
}


list<int> Graph::GetShortest(int vertex, const vector<int> &previous)
{
	list<int> path;
	for ( ; vertex != -1; vertex = previous[vertex])
		path.push_front(vertex);
	return path;
}


//void main()
//{
//	Graph G;
//	// remember to insert edges both ways for an undirected graph
//	vect graph(6);
//	// 0 = a
//	graph[0].push_back(node(1, 7));
//	graph[0].push_back(node(2, 9));
//	graph[0].push_back(node(5, 10));
//	// 1 = b
//	graph[1].push_back(node(0, 7));
//	graph[1].push_back(node(2, 10));
//	graph[1].push_back(node(3, 15));
//	// 2 = c
//	graph[2].push_back(node(0, 9));
//	graph[2].push_back(node(1, 10));
//	graph[2].push_back(node(3, 11));
//	graph[2].push_back(node(5, 20));
//	// 3 = d
//	graph[3].push_back(node(1, 15));
//	graph[3].push_back(node(2, 11));
//	graph[3].push_back(node(4, 6));
//	// 4 = e
//	graph[4].push_back(node(3, 6));
//	graph[4].push_back(node(5, 9));
//	// 5 = f
//	graph[5].push_back(node(0, 10));
//	graph[5].push_back(node(2, 2));
//	graph[5].push_back(node(4, 9));
//
//	vector<double> min_distance;
//	vector<int> previous;
//	G.ComputePaths(0, graph, min_distance, previous);
//	list<int> path = G.GetShortest(4, previous);
//}