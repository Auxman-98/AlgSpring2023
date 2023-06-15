#include "set.hpp"
using namespace std;

namespace awhalen
{
	// Сравнение рёбер по весу
	bool compare_edges(Edge e1, Edge e2) {
		return e1.weight < e2.weight;
	}

	// Поиск подмножества, которому принадлежит i-ый элемент
	int find(Subset subsets[], int i) {
		if (subsets[i].parent != i)
			subsets[i].parent = find(subsets, subsets[i].parent);
		return subsets[i].parent;
	}

	// Объединение двух подмножеств
	void merge(Subset subsets[], int x, int y) {
		int x_root = find(subsets, x);
		int y_root = find(subsets, y);

		if (subsets[x_root].rank < subsets[y_root].rank)
			subsets[x_root].parent = y_root;
		else if (subsets[x_root].rank > subsets[y_root].rank)
			subsets[y_root].parent = x_root;
		else {
			subsets[y_root].parent = x_root;
			subsets[x_root].rank++;
		}
	}
	
	// Реализация алгоритма Краскала
	void kruskal(int graph[][MAX_N], int V, vector<Edge>& result) {
		int E = 0;
		vector<Edge> edges;

		// Заполняем вектор edges рёбрами графа
		for (int i = 0; i < V; i++)
			for (int j = i + 1; j < V; j++) {
				if (graph[i][j] != 0) {
					Edge e = { i, j, graph[i][j] };
					edges.push_back(e);
				}
			}

		// Сортируем все рёбра по весу
		sort(edges.begin(), edges.end(), compare_edges);

		// Создаём набор подмножеств для каждой вершины графа
		Subset* subsets = new Subset[V];
		for (int i = 0; i < V; i++) {
			subsets[i].parent = i;
			subsets[i].rank = 0;
		}

		// Проходим по всем рёбрам, начиная с рёбер с минимальным весом
		for (int i = 0; i < edges.size(); i++) {
			// Находим подмножества вершин, которым принадлежат рёбра
			int c = find(subsets, edges[i].from);
			int d = find(subsets, edges[i].to);

			// Если подмножества различны, то объединяем их
			if (c != d) {
				result.push_back(edges[i]);
				merge(subsets, c, d);
				E++;
			}
			// Если уже добавлено V-1 рёбер, то заканчиваем алгоритм
			if (E == V - 1) {
				break;
			}
		}

		delete[] subsets;
	}

	void write_to_file(vector<Edge>& result) {
		ofstream out("result-6.txt");
		int totalWeight = 0;
		for (int i = 0; i < result.size(); i++) {
			out << "Ребро " << i + 1 << ": " << result[i].from << " - "
				<< result[i].to << " с весом " << result[i].weight << endl;
			totalWeight += result[i].weight;
		}
		out << "Общий вес МПД: " << totalWeight << endl;
		out.close();
	}
}