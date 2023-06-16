#include "set.hpp"
using namespace std;

namespace awhalen 
{
	// конструктор
	Graph::Graph(const vector<Edge>& edges, int n)
	{
		// изменяем размер двумерного вектора до количества n элементов
		adj_list.resize(n);

		// добавляем рёбра в неориентированный graph
		for (Edge e : edges)
		{
			int source = e.src;
			int destination = e.dest;

			adj_list[source].push_back(destination);
			adj_list[destination].push_back(source);
		}
	}

	// Добавляем больше цветов для graph с большим количеством вершин
	string colour[] =
	{
		"", "GREEN", "BLUE", "RED", "YELLOW", "CYAN", "ORANGE", "PURPLE", "BLACK", "WHITE"
	};

	// Присвоение цвета вершине Graph
	void colorGraph(const Graph& graph, int n)
	{
		// отслеживаем цвет, присвоенный каждой вершине
		unordered_map<int, int> result;

		// назначаем цвет от одной вершины к другой
		for (int o = 0; o < n; o++)
		{
			// хранение цвета вершин, смежных o
			set<int> assigned;

			for (int i : graph.adj_list[o]) {
				if (result[i])
					assigned.insert(result[i]);
			}

			// проверяем первый свободный цвет
			int color = 1;
			for (auto& c : assigned) {
				if (color != c)
					break;
				color++;
			}

			// назначаем вершине o первый доступный цвет
			result[o] = color;
		}

		for (int v = 0; v < n; v++) {
			cout << "The color assigned to vertex " << v << " is " 
				<< colour[result[v]] << endl;
		}
	}
}