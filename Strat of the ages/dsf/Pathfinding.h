#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <queue>

using namespace std;

struct node 
{
	int target;
	double weight;
	node(int arg_target, double arg_weight)
		: target(arg_target), weight(arg_weight) { }
};

typedef vector<vector<node> > vect;
const double max_weight = 1000000;
const double weight = 1;

class Graph
{
private:
public:
	/*
	Computes all possible paths using
	@param int to begin from (0)
	@param vect - the Graph being used for pathfinding
	@param vector<double> - minimum distance Graph traveled
	@param vector<int> - Graph traveled beforehand
	*/
	void ComputePaths(int, const vect&, vector<double>&, vector<int>&);
	/*
	Finds the shortest path from the given vertex using the given vector
	*/
	list<int> GetShortest(int vertex, const vector<int> &previous);
};