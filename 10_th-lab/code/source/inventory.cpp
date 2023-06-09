#include <iostream>
#include <list>
#include "inventory.hpp"
using namespace std;

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);// Граф неориентированный
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Пометим данный узел как посещённый и распечатаем его
    visited[v] = true;

    // Рекурсируем по всем вершинам, смежным с данной
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

//Метод проверки того, все ли вершины ненулевой степени соединены
//В основном требуется начинать с обхода ПвШ
bool Graph::isConnected()
{
    // Пометим все вершины как непосещённые
    bool* visited = new bool[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;

    // Найдём вершину с ненулевой степенью
    for (i = 0; i < V; i++)
        if (adj[i].size() != 0)
            break;

    // Если в графе нет рёбер, возвращаем истинно
    if (i == V)
        return true;

    // Начинаем обход ПвШ от вершины ненулевой степени
        DFSUtil(i, visited);

    // Проверим, все ли вершины ненулевой степени посещены
    for (i = 0; i < V; i++)
        if (visited[i] == false && adj[i].size() > 0)
            return false;

    return true;
}

/*Эта функция возвращает одно из следующих значений:
  0 --> если граф не эйлеров
  2 --> если граф имеет эйлеров цикл*/
int Graph::isEulerian()
{
    //Проверим, все ли вершины ненулевой степени соединены
    if (isConnected() == false)
        return 0;

    //Считаем вершины с нечётной степенью
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;

    //Если счётчик больше, чем 2, то граф не является эйлеровым
    if (odd > 2)
        return 0;

    return 2;
}