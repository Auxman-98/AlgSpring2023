#include <iostream>
#include <fstream>
#include <vector>
#include "set.hpp"

int main()
{
	setlocale(LC_ALL, "Rus");

	std::vector<std::vector<int> > graph;
	std::ifstream fin("C:\\Users\\Asus\\source\\repos\\Alg2-5\\Alg2-5\\input_2.txt");
	if (!fin) {
		cout << "Ошибка при открытии файла!\n";
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
	std::cout << "Компоненты сильной связности и их количество:" << std::endl;
	g.printSCCs();

	return 0;
}