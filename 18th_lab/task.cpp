#include <iostream>
#include <vector>

using namespace std;

void smartReset(double* array, int n) // ���� ��������� ��������� � ��� �������� �� ������������� ��������
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < n; i++) {
		cout << "������� " << (i) << " �������: ";
		cin >> array[i];
		bool flag = false; // ������������� ��������� ��� �� ���������
		for (int j = 0; j < i; j++) // �������� �� ������
		{
			if (array[i] == array[j]){
				flag = true;
				break;
			}
		}
		if (flag) // ���� ������ ���
		{
			cout << "����� ������� ��� ���� � ���������" << endl;
			i--;
		}
	}
}

void subsetWithSum(double* array, int n, double sum) // ��������� ������� ������������ � �������� ������
{
	int ires = -1;
	int k = powf(2, n); // ���������� �����������
	for (int i = 0; i < k; i++) // ������� �����������
	{
		int partial = 0;
		bool flag = false; // ������� ������������ ����� �� ���������
		for (int j = 0; j < n; j++)
			if (i & (1 << j)){
				partial += array[j]; // �������� �����
				flag = true; // ������������ ��������
			}
		if (partial == sum && flag) {
			ires = i;
			break; // � ������� ������������� ������� �� ��������
		}
	}

	if (ires == -1)
		cout << "������������ � �������� ������ �� ����������" << endl;
	else {
		cout << "������������ � �������� ������:\n";
		for (int j = 0; j < n; j++)
			if (ires & (1 << j))
				cout << array[j] << " ";
		cout << endl; // ������� �� �����
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double* a;
	double s;
	int n;
	do {
		cout << "������� ������ ���������: ";
		cin >> n;
	} while (n < 1); // �������� �� ���������� �������� n

	a = new double[n]; // �������� ������

	smartReset(a, n);

	cout << "������� ������ ����� �����: ";
	cin >> s;

	subsetWithSum(a, n, s);

	delete[] a; // ����������� ������

	return 0;
}