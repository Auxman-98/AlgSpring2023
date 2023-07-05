#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите мощность множества: ";
	cin >> n;
	cout << endl;
	vector<int> set(n);
	cout << "Введите элементы множества:";
	for (int i = 0; i < n; i++){
		cin >> set[i];
	}
	sort(set.begin(), set.end()); // сортировка массива
	sum = array[0]; // начальная сумма
	vector<int> subset = { set[0] }; // начальное подмножество
	for (int i = 1; i < set.size(); i++) {
            if (sum + set[i] >= set[i]) { // проверка условия на включение элемента в подмножество
                sum += set[i];
                subset.push_back(set[i]);
            }
        }
	if (subset = { 0 }){
		cout << "Подмножества с заданной суммой не существует!" << endl;
		return 0;
	}
	cout << "Сумма наибольшего подмножества: " << sum << endl;
	for (int i = 0; i < subset.size(); i++) {
                cout << subset[i] << " "; // вывод элементов подмножества
        }
        cout << endl;

	return 0;
}
