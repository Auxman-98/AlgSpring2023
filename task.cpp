#include <iostream>
#include <vector>

using namespace std;

void smartReset(double* array, int n) // ввод элементов множества и его проверка на повторяющиеся элементы
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < n; i++) {
		cout << "Введите " << (i) << " элемент: ";
		cin >> array[i];
		bool flag = false; // повторяющихся элементов нет по умолчанию
		for (int j = 0; j < i; j++) // проверка на повтор
		{
			if (array[i] == array[j]){
				flag = true;
				break;
			}
		}
		if (flag) // если повтор был
		{
			cout << "Такой элемент уже есть в множестве" << endl;
			i--;
		}
	}
}

void subsetWithSum(double* array, int n, double sum) // проверяем наличие подмножества с заданной суммой
{
	int ires = -1;
	int k = powf(2, n); // количество подмножеств
	for (int i = 0; i < k; i++) // перебор подмножеств
	{
		int partial = 0;
		bool flag = false; // искомое подмножество пусто по умолчанию
		for (int j = 0; j < n; j++)
			if (i & (1 << j)){
				partial += array[j]; // набираем сумму
				flag = true; // подмножество непустое
			}
		if (partial == sum && flag) {
			ires = i;
			break; // с искомым подмножеством выходим из перебора
		}
	}

	if (ires == -1)
		cout << "Подмножество с заданной суммой не существует" << endl;
	else {
		cout << "Подмножество с заданной суммой:\n";
		for (int j = 0; j < n; j++)
			if (ires & (1 << j))
				cout << array[j] << " ";
		cout << endl; // выходим из цикла
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double* a;
	double s;
	int n;
	do {
		cout << "Введите размер множества: ";
		cin >> n;
	} while (n < 1); // проверка на допустимое значение n

	a = new double[n]; // выделяем память

	smartReset(a, n);

	cout << "Введите нужную сумму чисел: ";
	cin >> s;

	subsetWithSum(a, n, s);

	delete[] a; // освобождаем память

	return 0;
}