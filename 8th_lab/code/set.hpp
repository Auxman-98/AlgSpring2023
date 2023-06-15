#pragma once
#include <iostream>
#include <fstream>
#include <limits.h>

const int MAX_N = 100;

namespace awhalen
{
	int get_next_vertex(bool visited[], int distances[], int n);
	void dijkstra(int graph[][MAX_N], int n, int start);
}