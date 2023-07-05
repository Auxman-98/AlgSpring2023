#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace an
{
	int** inputGraph(string fileName, int& n);
	void printResult(string filename, vector<int>& result);
	void findEulerCycle(int** graph, int n, int v, vector<int>& result);
	bool hasEulerCycle(int** graph, int n);
}