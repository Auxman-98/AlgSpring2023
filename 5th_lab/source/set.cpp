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

	// Пометим все вершины как непосещённые (на первый ПвШ)
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Расположим вершины в стеке по конечному времени их обработки
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	// Создадим развёрнутый граф
	Graph gr = getTranspose();

	// Пометим все вершины как непосещённые (на второй ПвШ)
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Теперь обработаем все вершины в порядке, определённом по стеку
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// Распечатаем компоненту сильной связности выведенной вершины
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
		// Рекурсируем по всем вершинам, смежным с данной
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
	//Пометим данный узел посещённым и распечатаем его
	visited[v] = true;

	// Рекурсируем по всем вершинам, смежным с данной
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	// Все вершины, достижимые из v, сейчас обработаны, продвинем v
	Stack.push(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
	//Пометим данный узел пройденным и распечатаем его
	visited[v] = true;
	cout << v << " ";

	//Рекурсируем по всем вершинам, смежным с данной
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}
