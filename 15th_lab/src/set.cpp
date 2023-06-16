#include "set.hpp"
using namespace std;

namespace awhalen 
{
	// �����������
	Graph::Graph(const vector<Edge>& edges, int n)
	{
		// �������� ������ ���������� ������� �� ���������� n ���������
		adj_list.resize(n);

		// ��������� ���� � ����������������� graph
		for (Edge e : edges)
		{
			int source = e.src;
			int destination = e.dest;

			adj_list[source].push_back(destination);
			adj_list[destination].push_back(source);
		}
	}

	// ��������� ������ ������ ��� graph � ������� ����������� ������
	string colour[] =
	{
		"", "GREEN", "BLUE", "RED", "YELLOW", "CYAN", "ORANGE", "PURPLE", "BLACK", "WHITE"
	};

	// ���������� ����� ������� Graph
	void colorGraph(const Graph& graph, int n)
	{
		// ����������� ����, ����������� ������ �������
		unordered_map<int, int> result;

		// ��������� ���� �� ����� ������� � ������
		for (int o = 0; o < n; o++)
		{
			// �������� ����� ������, ������� o
			set<int> assigned;

			for (int i : graph.adj_list[o]) {
				if (result[i])
					assigned.insert(result[i]);
			}

			// ��������� ������ ��������� ����
			int color = 1;
			for (auto& c : assigned) {
				if (color != c)
					break;
				color++;
			}

			// ��������� ������� o ������ ��������� ����
			result[o] = color;
		}

		for (int v = 0; v < n; v++) {
			cout << "The color assigned to vertex " << v << " is " 
				<< colour[result[v]] << endl;
		}
	}
}