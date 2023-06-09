#pragma once
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;

	//Заполняет Stack вершинами (по возрастанию времени завершения)
	void fillOrder(int v, bool visited[], stack<int>& Stack);

	//Рекурсивная функция для ПвШ, начиная с v
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);

	//Основная функция, которая находит и выводит компоненты сильной связности
	void printSCCs();

	//Функция, разворачивающая данный орграф
	Graph getTranspose();
};