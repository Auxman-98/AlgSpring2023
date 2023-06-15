#include "set.hpp"
using namespace std;

namespace awhalen
{
	int get_next_vertex(bool visited[], int distances[], int n)
	{
		int min_dist = INT_MAX;
		int min_vertex = -1;
		for (int i = 0; i < n; i++)
			if (!visited[i] && distances[i] < min_dist) {
				min_dist = distances[i];
				min_vertex = i;
			}
		return min_vertex;
	}

	void dijkstra(int graph[][MAX_N], int n, int start)
	{
		bool visited[MAX_N] = { false }; // отслеживание посещения вершин
		int distances[MAX_N];
		for (int i = 0; i < n; i++)
			distances[i] = INT_MAX; // установка расстояний до всех вершин в "бесконечность"
		distances[start] = 0; // расстояние от стартовой вершины
		for (int i = 0; i < n; i++) {
			int v = get_next_vertex(visited, distances, n);
			if (v == -1) // после посещения всех вершин останавливаем алгоритм
				break;
			visited[v] = true;
			for (int j = 0; j < n; j++) {
				if (!visited[j] && graph[v][j] > 0) {
					int d = distances[v] + graph[v][j];
					if (d < distances[j])
						distances[j] = d;
				}
			}
		}
		ofstream fout("result-8.txt");
		for (int i = 0; i < n; i++)
			fout << start << " -> " << i << " : " << distances[i] << endl;
		fout.close();
	}
}