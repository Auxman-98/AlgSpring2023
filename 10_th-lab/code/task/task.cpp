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
		cout << "������� ���� �� ����������!" << endl;
		return 0;
	}
	// �������� ����� ������� � �������� �� �� ����� �����
	std::vector<int> result;
	an::findEulerCycle(graph, n, 0, result);
	// ������������ ������ ����������, ����� �������� ������� ������ � ��������� �����
	std::reverse(result.begin(), result.end());
	// ������� ����������
	an::printResult("output_1.txt", result);

	return 0;
}