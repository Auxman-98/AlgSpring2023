#include <iostream>
#include <vector>

using namespace std;

bool distroRecursive(int items_num, int boxes_num, int items_max, vector<int>& box_items, int currentBox) {
	if (items_num == 0) // если число предметов равно нулю, то распределение завершено
		return true;
	if (currentBox >= boxes_num) // если номер данного €щика больше или равно числу €щиков, то ошибка
		return false;
	if (box_items[currentBox] == items_max) // если данный €щик заполнен макс. числом предметов, то переходим к следующему
		return distroRecursive(items_num, boxes_num, items_max, box_items, currentBox + 1);
	/*перебираем от минимума между общим числом предметов и числом предметов, дополн€ющим предметы в данном €щике до макс-го числа
	до нул€*/
	for (int i = min(items_num, items_max - box_items[currentBox]); i >= 0; i--)
	{
		box_items[currentBox] += i;
		// если items_num - i предметов в следующем за данным €щике получилось распределить, то возвращаем истину
		if (distroRecursive(items_num - i, boxes_num, items_max, box_items, currentBox + 1))
			return true;
		box_items[currentBox] -= i;
	}
	return false; // предметы по умолчанию не распределены
}

/*— помощью булевой функции заполн€ем, если возможно, вектор, представл€ющий собой
множество €щиков с разложенными в них предметами*/
vector<int> distroItems(int items_num, int boxes_num, int items_max) {
	vector<int> box_items(boxes_num, 0);
	// при отсутствии способов распределени€ возвращаем нулевой вектор
	if (!distroRecursive(items_num, boxes_num, items_max, box_items, 0))
		return vector<int>();
	return box_items;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int items_num = 70;
	int boxes_num = 3;
	int items_max = 24;
	vector<int> box_items = distroItems(items_num, boxes_num, items_max);
	if (!box_items.empty()) {
		cout << "ѕредметы распределены по €щикам: ";
		for (int item : box_items) {
			cout << item << " ";
		}
		cout << endl;
	}
	else
		cout << "–аспределение невозможно" << endl;

	return 0;
}