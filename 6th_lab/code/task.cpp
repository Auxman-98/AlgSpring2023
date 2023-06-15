#include "set.hpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int graph[MAX_N][MAX_N]; // ������� ��������� �����
	int V; // ���������� ������

	// ��������� ������� ������
	ifstream in("graph-6.txt");
	in >> V;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			in >> graph[i][j];
		}
	}
	in.close();

	vector<awhalen::Edge> result; // ��������� ������ ���������
	awhalen::kruskal(graph, V, result); // ��������� �������� ��������

	awhalen::write_to_file(result);

	return 0;
}