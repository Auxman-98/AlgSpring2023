#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100;

namespace awhalen
{
	struct Edge { int from, to, weight; }; // ребро
	struct Subset { int parent, rank; }; // подмножество
	bool compare_edges(Edge e1, Edge e2);
	int find(Subset subsets[], int i);
	void merge(Subset subsets[], int x, int y);
	void kruskal(int graph[][MAX_N], int V, vector<Edge>& result);
	void write_to_file(vector<Edge>& result);
}