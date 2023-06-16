#include "set.hpp"
using namespace std;
using namespace awhalen;

int main()
{
	vector<Edge> edges = {
		{0,1}, {0,6}, {1,2}, {1,4}, {1,6}, {2,3}, {2,4},
		{3,5}, {4,5}, {4,7}, {5,8}, {6,7}, {7,8}
	};

	int n = 9;

	Graph graph(edges, n);

	colorGraph(graph, n);

	return 0;
}