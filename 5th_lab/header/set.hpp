#pragma once
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;

	//��������� Stack ��������� (�� ����������� ������� ����������)
	void fillOrder(int v, bool visited[], stack<int>& Stack);

	//����������� ������� ��� ���, ������� � v
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);

	//�������� �������, ������� ������� � ������� ���������� ������� ���������
	void printSCCs();

	//�������, ��������������� ������ ������
	Graph getTranspose();
};