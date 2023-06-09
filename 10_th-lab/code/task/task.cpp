#include <iostream>
#include <fstream>
#include <vector>
#include "inventory.hpp"

int main()
{
	setlocale(LC_ALL, "Rus");
	std::vector<std::vector<int> > graph;
	std::ifstream fin("C:\\Users\\Asus\\source\\repos\\Alg2-10\\Alg2-10\\input_1.txt");
	std::ofstream fout("C:\\Users\\Asus\\source\\repos\\Alg2-10\\Alg2-10\\output_1.txt");
	if (!fin || !fout)
	{
		std::cout << "Ошибка при обращении к файлу!\n";
		system("pause");
		return 1;
	}

	int n;
	fin >> n;
	std::vector<int> tmp(n);
	while (!fin.eof())
	{
		std::copy_n(std::istream_iterator<int>(fin), n, tmp.begin());
		graph.push_back(tmp);
	}

	Graph g(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (graph[i][j] == 1)
				g.addEdge(i, j);
	}

	int res = g.isEulerian();
	if (res == 0)
		fout << "граф - не эйлеров";
	else if (res == 2)
		fout << "граф имеет эйлеров цикл";

	return 0;
}