/*
Функция 'Rucksack' использует мемоизацию, чтобы избежать повторных расчётов при вызове функции для одних и тех же параметров.
Для этого используется двумерный массив R, который хранит рассчитанные ранее значения. Каждый элемент R[i][j]  соответствует расчёту максимальной стоимости для i предметов и j веса рюкзака.
*/

#include <iostream>

using namespace std;

int Rucksack(int W, int weight[], int val[], int n) {
	int i, w;

	int** R = new int* [n + 1]; // объявляем двумерный массив
	for (int i = 0; i < n + 1; i++)
		R[i] = new int[W + 1];

	for (i = 0; i <= n; i++)
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0) //         
				R[i][w] = 0;
			else if (weight[i - 1] <= w) //        
			{
				//           
				int nincld = R[i - 1][w];
				//            
				int not_incld = val[i - 1] + R[i - 1][w - weight[i - 1]];
				R[i][w] = max(nincld, not_incld);
			}
			else
				R[i][w] = R[i - 1][w]; //     
		}

	int result = R[n][W];

	//  
	for (int i = 0; i < n + 1; i++)
		delete[] R[i];
	delete[] R;

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int vals[] = { 60, 100, 120 };
	int weights[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(vals) / sizeof(vals[0]);
	cout << " ,       " << W << ": " 
		<< Rucksack(W, weights, vals, n) << endl;

	return 0;
}
