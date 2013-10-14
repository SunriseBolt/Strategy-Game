#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <iterator>
using namespace std;

const double max_weight = 1000000;

struct node {
	int target;
	double weight;
	node(int arg_target, double arg_weight)
		: target(arg_target), weight(arg_weight) { }
};

typedef vector<vector<node> > vect;


void ComputePaths(int source, const vect &Graph, vector<double> &min_distance, vector<int> &previous)
{
	int n = Graph.size();
	min_distance.clear();
	min_distance.resize(n, max_weight);
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
		const vector<node> &nodes = Graph[u];
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


std::list<int> GetShortest(int vertex, const vector<int> &previous)
{
	std::list<int> path;
	for ( ; vertex != -1; vertex = previous[vertex])
		path.push_front(vertex);
	return path;
}


void main()
{
	// remember to insert edges both ways for an undirected graph
	vect Graph(6);
	// 0 = a
	Graph[0].push_back(node(1, 7));
	Graph[0].push_back(node(2, 9));
	Graph[0].push_back(node(5, 10));
	// 1 = b
	Graph[1].push_back(node(0, 7));
	Graph[1].push_back(node(2, 10));
	Graph[1].push_back(node(3, 15));
	// 2 = c
	Graph[2].push_back(node(0, 9));
	Graph[2].push_back(node(1, 10));
	Graph[2].push_back(node(3, 11));
	Graph[2].push_back(node(5, 20));
	// 3 = d
	Graph[3].push_back(node(1, 15));
	Graph[3].push_back(node(2, 11));
	Graph[3].push_back(node(4, 50));
	// 4 = e
	Graph[4].push_back(node(3, 6));
	Graph[4].push_back(node(5, 9));
	// 5 = f
	Graph[5].push_back(node(0, 10));
	Graph[5].push_back(node(2, 2));
	Graph[5].push_back(node(4, 9));

	vector<double> min_distance;
	vector<int> previous;
	ComputePaths(3, Graph, min_distance, previous);
	cout << "Distance from 3 to 4: " << min_distance[4] << std::endl;
	list<int> path = GetShortest(4, previous);
	cout << "Path : ";
	copy(path.begin(), path.end(), ostream_iterator<int>(std::cout, " "));
	cout << endl;
}