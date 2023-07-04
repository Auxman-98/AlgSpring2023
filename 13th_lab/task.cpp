#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ���������� ��������� ������-���� ��� ������ ���������
int boyer_moore_search(string str, string substr) {
	// ���� ���� �����
	int str_len = str.length();
	int substr_len = substr.length();

	// �������� ������� ��������
	int bmd_table[256];
	for (int i = 0; i < 256; ++i)
		bmd_table[i] = substr_len;
	for (int i = 0; i < substr_len - 1; ++i)
		bmd_table[substr[i]] = substr_len - i - 1;

	// ����� ��������
	int i = substr_len - 1, j = substr_len - 1;
	while (i < str_len) {
		if (str[i] == substr[j]) {
			if (j == 0)
				return i;
			--i;
			--j;
		}
		else {
			i += bmd_table[str[i]];
			j = substr_len - 1;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	// �������� ������ ������ � ������
	ifstream fin("text-13.txt");
	ofstream fout("result-13.txt");

	// �������� ������� ������
	if (!fin) {
		cout << "������: ���� text-13.txt �� ������\n";
		return 1;
	}
	if (!fout) {
		cout << "������: ���� result-13.txt �� ������\n";
		return 1;
	}

	// ���������� �������� ������
	string text;
	getline(fin, text);

	// ����� ������ ������
	string pattern;
	cout << "������� ��������� ��� ������: ";
	getline(cin, pattern);

	// ����� ��������
	int pos = boyer_moore_search(text, pattern);

	if (pos == -1) {
		fout << "��������� �� �������\n";
	}
	else {
		fout << "��������� ������� � ������� " << pos << endl;
	}

	// �������� ������
	fin.close();
	fout.close();

	return 0;
}