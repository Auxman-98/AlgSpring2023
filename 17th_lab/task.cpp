#include <iostream>
#include <vector>

using namespace std;

bool distroRecursive(int items_num, int boxes_num, int items_max, vector<int>& box_items, int currentBox) {
	if (items_num == 0) // ���� ����� ��������� ����� ����, �� ������������� ���������
		return true;
	if (currentBox >= boxes_num) // ���� ����� ������� ����� ������ ��� ����� ����� ������, �� ������
		return false;
	if (box_items[currentBox] == items_max) // ���� ������ ���� �������� ����. ������ ���������, �� ��������� � ����������
		return distroRecursive(items_num, boxes_num, items_max, box_items, currentBox + 1);
	/*���������� �� �������� ����� ����� ������ ��������� � ������ ���������, ����������� �������� � ������ ����� �� ����-�� �����
	�� ����*/
	for (int i = min(items_num, items_max - box_items[currentBox]); i >= 0; i--)
	{
		box_items[currentBox] += i;
		// ���� items_num - i ��������� � ��������� �� ������ ����� ���������� ������������, �� ���������� ������
		if (distroRecursive(items_num - i, boxes_num, items_max, box_items, currentBox + 1))
			return true;
		box_items[currentBox] -= i;
	}
	return false; // �������� �� ��������� �� ������������
}

/*� ������� ������� ������� ���������, ���� ��������, ������, �������������� �����
��������� ������ � ������������ � ��� ����������*/
vector<int> distroItems(int items_num, int boxes_num, int items_max) {
	vector<int> box_items(boxes_num, 0);
	// ��� ���������� �������� ������������� ���������� ������� ������
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
		cout << "�������� ������������ �� ������: ";
		for (int item : box_items) {
			cout << item << " ";
		}
		cout << endl;
	}
	else
		cout << "������������� ����������" << endl;

	return 0;
}