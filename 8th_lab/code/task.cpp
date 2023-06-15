#include "set.hpp"
using namespace std;

int main()
{
	int n;
	int graph[MAX_N][MAX_N] = { 0 };
	ifstream fin("graph-8.txt");
	fin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			fin >> graph[i][j];
		}
	fin.close();
	awhalen::dijkstra(graph, n, 3);

	return 0;
}