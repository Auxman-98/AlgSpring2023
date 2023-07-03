#include <iostream>
#include <vector>

using namespace std;

bool distroRecursive(int items_num, int boxes_num, int items_max, vector<int>& box_items, int currentBox) {
	if (items_num == 0) // если число предметов равно нулю, то распределение завершено
		return true;
	if (currentBox >= boxes_num) // если номер данного ящика больше или равно числу ящиков, то ошибка
		return false;
	if (box_items[currentBox] == items_max) // если данный ящик заполнен макс. числом предметов, то переходим к следующему
		return distroRecursive(items_num, boxes_num, items_max, box_items, currentBox + 1);
	/* перебираем от минимума между общим числом предметов и числом предметов, дополняющим предметы в данном ящике до макс-го числа
	до нуля*/
	for (int i = min(items_num, items_max - box_items[currentBox]); i >= 0; i--)
	{
		box_items[currentBox] += i;
		// если items_num - i предметов в следующем за данным ящике получилось распределить, то возвращаем истину
		if (distroRecursive(items_num - i, boxes_num, items_max, box_items, currentBox + 1))
			return true;
		box_items[currentBox] -= i;
	}
	return false; // предметы по умолчанию не распределены
}

/*С помощью булевой функции заполняем, если возможно, вектор, представляющий собой
множество ящиков с разложенными в них предметами*/
vector<int> distroItems(int items_num, int boxes_num, int items_max) {
	vector<int> box_items(boxes_num, 0);
	// при отсутствии способов распределения возвращаем нулевой вектор
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
		cout << "Предметы распределены по ящикам: ";
		for (int item : box_items) {
			cout << item << " ";
		}
		cout << endl;
	}
	else
		cout << "Распределение невозможно" << endl;

	return 0;
}
