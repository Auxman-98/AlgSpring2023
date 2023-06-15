#include "set.hpp"
using namespace std;

namespace awhalen
{
	int** read_from_file(string input, int& n)
	{
        ifstream fin(input);
        fin >> n;
        int** graph = new int* [n];
        for (int i = 0; i < n; i++) {
            graph[i] = new int[n];
            for (int j = 0; j < n; j++)
                fin >> graph[i][j];
        }
        fin.close();
        return graph;
	}

    void print_to_file(string output, int* distances, int n)
    {
        ofstream fout(output);
        for (int i = 0; i < n; i++)
            fout << i << " " << distances[i] << endl;
        fout.close();
    }

    void Bellman_Ford(int** graph, int n, int start, string output)
    {
        int* distances = new int[n];
        // Инициализация массива расстояний
        for (int i = 0; i < n; i++)
            distances[i] = INT_MAX;
        distances[start] = 0;

        /* Проход по всем вершинам (n - 1) раз, чтобы найти кратчайшие пути
           Максимальное количество рёбер графа равно n-1 */
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    if (graph[j][k] != 0) {
                        int new_distance = distances[j] + graph[j][k];
                        if (new_distance < distances[k])
                            distances[k] = new_distance;
                    }
                }

        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                if (graph[k][j] != 0) {
                    int new_distance = distances[k] + graph[k][j];
                    if (new_distance < distances[j]) {
                        cout << "Отрицательный цикл в графе!" << endl;
                        return;
                    }
                }
            }

        print_to_file(output, distances, n);
    }
}