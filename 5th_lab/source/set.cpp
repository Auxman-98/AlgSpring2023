#include <iostream>
#include <list>
#include <stack>
#include "set.hpp"
using namespace std;

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::printSCCs()
{
	stack<int> Stack;
	int count = 0;

	// ������� ��� ������� ��� ������������ (�� ������ ���)
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// ���������� ������� � ����� �� ��������� ������� �� ���������
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	// �������� ���������� ����
	Graph gr = getTranspose();

	// ������� ��� ������� ��� ������������ (�� ������ ���)
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// ������ ���������� ��� ������� � �������, ����������� �� �����
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// ����������� ���������� ������� ��������� ���������� �������
		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			count++;
			cout << endl;
		}
	}
	cout << count << endl;
}

Graph Graph::getTranspose()
{
	Graph g(V); 
	for (int v = 0; v < V; v++)
	{
		// ����������� �� ���� ��������, ������� � ������
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::fillOrder(int v, bool visited[], stack<int>& Stack)
{
	//������� ������ ���� ���������� � ����������� ���
	visited[v] = true;

	// ����������� �� ���� ��������, ������� � ������
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	// ��� �������, ���������� �� v, ������ ����������, ��������� v
	Stack.push(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
	//������� ������ ���� ���������� � ����������� ���
	visited[v] = true;
	cout << v << " ";

	//����������� �� ���� ��������, ������� � ������
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}
