#include <iostream>
#include <fstream>
using namespace std;

const int MAX_V = 100;

int n; // количество вершин в графе
int graph[MAX_V][MAX_V]; // матрица смежности
int parent[MAX_V]; // массив родительских вершин
int key[MAX_V]; // массив ключей
bool visited[MAX_V]; // массив, хранящий информацию о посещении вершин

// Функция, находящая вершину с минимальным ключом
int minKey() {
	int m = INT_MAX, index;

	for (int i = 0; i < n; i++)
		if (!visited[i] && key[i] < m)
			m = key[i], index = i;

	return index;
}

void prim() {
	for (int i = 0; i < n; i++) {
		key[i] = INT_MAX;
		visited[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < n - 1; i++) {
		int u = minKey();
		visited[u] = true;

		for (int v = 0; v < n; v++) {
			if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream fin("graph-7.txt");
	ofstream fout("result-7.txt");

	// считываем матрицу смежности из файла
	fin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> graph[i][j];

	prim();

	fout << "Минимальное покрывающее дерево графа:\n";
	for (int i = 1; i < n; i++)
		fout << parent[i] << " - " << i << " " << graph[i][parent[i]] << endl;

	fin.close();
	fout.close();

	return 0;
}