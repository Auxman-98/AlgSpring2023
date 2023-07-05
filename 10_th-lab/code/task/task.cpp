#include <iostream>
#include <fstream>
#include <vector>
#include "inventory.hpp"

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int** graph = an::inputGraph("input_1.txt", n);
	
	
	if (!an::hasEulerCycle(graph, n)) {
		cout << "Эйлеров цикл не существует!" << endl;
		return 0;
	}
	// Выбираем любую вершину и начинаем из неё обход графа
	std::vector<int> result;
	an::findEulerCycle(graph, n, 0, result);
	// Поворачиваем вектор результата, чтобы получить порядок вершин в эйлеровом цикле
	std::reverse(result.begin(), result.end());
	// Выводим результаты
	an::printResult("output_1.txt", result);

	return 0;
}