#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101];

void printMask(int mask, int n)
{
	for (int i = 0; i < n; i++) {
		if (mask % 2)
			cout << arr[i] << " ";
		mask /= 2;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите мощность множества: ";
	cin >> n;
	cout << "Введите элементы множества:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int t;
	cout << "Введите нужную сумму подмножества: ";
	cin >> t;
	for (int mask = 1; mask < (1 << n); mask++)
	{
		int tmp = mask, curSum = 0;
		for (int i = 0; i < n; i++) {
			if (tmp % 2)
				curSum += arr[i];
			tmp /= 2;
		}
		if (curSum == t) {
			cout << "Элементы подмножества с заданной суммой: ";
			printMask(mask, n);
			return 0;
		}
	}
	cout << "Подмножества с заданной суммой не существует" << endl;
	
	return 0;
}
