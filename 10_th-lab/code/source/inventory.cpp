#include <fstream>
#include <vector>
#include "inventory.hpp"
using namespace std;

int** an::inputGraph(string fileName, int& n)
{
    ifstream fin("input_1.txt");
    fin >> n;
    int** graph = new int* [n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            fin >> graph[i][j];
        }
    }
    fin.close();
    return graph;
}

void an::printResult(string filename, vector<int>& result)
{
    ofstream fout(filename);
    for (int i = 0; i < result.size(); i++) {
        fout << result[i] << " ";
    }
    fout.close();
}

// ����������� ������� ��� ������ �������� ����� � �����
void an::findEulerCycle(int** graph, int n, int v, vector<int>& result)
{
    // ��� ������ ������� �������� ��� � ��������, ��� ������������
    vector<int> unvisited;
    for (int i = 0; i < n; i++) {
        if (graph[v][i])
            unvisited.push_back(i);
    }
    while (!unvisited.empty())
    {
        int u = unvisited.back();
        unvisited.pop_back();
        // ������� �����, ����� �������� ���������� ��������� �������
        graph[v][u] = 0;
        graph[u][v] = 0;
        an::findEulerCycle(graph, n, u, result);
    }
    // ��������� ������� � ��������� (���� ��� ����)
    result.push_back(v);
}

// ������� �������� �������/���������� � ����� �������� �����
bool an::hasEulerCycle(int** graph, int n)
{
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) degree++;
        }
        if (degree % 2 != 0) odd++;
    }
    return (odd == 0);
}