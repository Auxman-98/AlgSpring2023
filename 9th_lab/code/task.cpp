#include "set.hpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int** graph = awhalen::read_from_file("graph-9.txt", n);
	awhalen::Bellman_Ford(graph, n, 0, "result-9.txt");	

	return 0;
}