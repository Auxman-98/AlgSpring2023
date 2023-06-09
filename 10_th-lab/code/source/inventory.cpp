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
	adj[w].push_back(v);// ���� �����������������
}

void Graph::DFSUtil(int v, bool visited[])
{
    // ������� ������ ���� ��� ���������� � ����������� ���
    visited[v] = true;

    // ����������� �� ���� ��������, ������� � ������
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

//����� �������� ����, ��� �� ������� ��������� ������� ���������
//� �������� ��������� �������� � ������ ���
bool Graph::isConnected()
{
    // ������� ��� ������� ��� ������������
    bool* visited = new bool[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;

    // ����� ������� � ��������� ��������
    for (i = 0; i < V; i++)
        if (adj[i].size() != 0)
            break;

    // ���� � ����� ��� ����, ���������� �������
    if (i == V)
        return true;

    // �������� ����� ��� �� ������� ��������� �������
        DFSUtil(i, visited);

    // ��������, ��� �� ������� ��������� ������� ��������
    for (i = 0; i < V; i++)
        if (visited[i] == false && adj[i].size() > 0)
            return false;

    return true;
}

/*��� ������� ���������� ���� �� ��������� ��������:
  0 --> ���� ���� �� �������
  2 --> ���� ���� ����� ������� ����*/
int Graph::isEulerian()
{
    //��������, ��� �� ������� ��������� ������� ���������
    if (isConnected() == false)
        return 0;

    //������� ������� � �������� ��������
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;

    //���� ������� ������, ��� 2, �� ���� �� �������� ���������
    if (odd > 2)
        return 0;

    return 2;
}