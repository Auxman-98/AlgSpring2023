#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

namespace awhalen
{
	// �������� ����� Graph
	struct Edge
	{
		int src, dest;
	};

	class Graph 
	{
	public:
		// ������������� ������ ���������
		vector<vector<int> > adj_list;
		// �����������
		Graph(const vector<Edge>& edges, int n);
	};

	// ���������� ����� ������� Graph
	void colorGraph(const Graph& graph, int n);
}