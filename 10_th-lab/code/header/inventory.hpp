#pragma once
#include <list>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;

	bool isConnected();
public:
	Graph(int V);
	~Graph();

	void addEdge(int v, int w);

	int isEulerian();
	

	void DFSUtil(int v, bool visited[]);
};