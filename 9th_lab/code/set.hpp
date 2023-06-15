#pragma once
#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;

namespace awhalen
{
	struct Edge { int from, to, weight; };
	int** read_from_file(string filename, int& n);
	void print_to_file(string output, int* distances, int n);
	void Bellman_Ford(int** graph, int n, int start, string output);
}