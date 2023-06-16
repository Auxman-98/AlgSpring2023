#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

namespace awhalen
{
	// Хранение ребра Graph
	struct Edge
	{
		int src, dest;
	};

	class Graph 
	{
	public:
		// Представление списка смежности
		vector<vector<int> > adj_list;
		// конструктор
		Graph(const vector<Edge>& edges, int n);
	};

	// Присвоение цвета вершине Graph
	void colorGraph(const Graph& graph, int n);
}