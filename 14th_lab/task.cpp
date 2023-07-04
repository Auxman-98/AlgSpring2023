#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

// ���-������� ��� ������ s ����� len � ������� � ������� pos
int own_hash(const char* s, int len, int pos)
{
	int h = 0;
	for (int i = 0; i < len; ++i)
	{
		h += (int)s[pos + i] * pow(128, len - i - 1);
	}
	return h;
}

// ���������� ��������� ������-����� ��� ������ ���������
int rabin_karp_search(const char* text, const char* pattern)
{
	int text_len = strlen(text);
	int patt_len = strlen(pattern);

	// ���������� ����� ��� ��������� � ������� ���� ������
	int pattern_hash = own_hash(pattern, patt_len, 0);
	int text_hash = own_hash(text, patt_len, 0);

	// ����� ���������
	for (int i = 0; i <= text_len - patt_len; ++i) {
		if (pattern_hash == text_hash) {
			// �������������� �������� �� ���������� ��������
			int j;
			for (j = 0; j < patt_len; ++j) {
				if (pattern[j] != text[i + j])
					break;
			}
			if (j == patt_len)
				return i;
		}

		// ���������� ���� ��� ���������� ����
		if (i < text_len - patt_len)
		{
			text_hash -= (int)text[i] * pow(128, patt_len - 1);
			text_hash = text_hash * 128 + (int)text[i + patt_len];
		}
	}

	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("text-14.txt");
	ofstream fout("result-14.txt");

	if (!fin) {
		cout << "������: ���� text-14.txt �� ������\n";
		return 1;
	}
	if (!fout) {
		cout << "������: ���� result-14.txt ���������� �������\n";
		return 1;
	}

	char text[1000];
	fin.getline(text, 1000);

	cout << "������� ������: " << text << endl;

	char pattern[1000];
	cout << "������� ������� ��� ������: ";
	cin.getline(pattern, 1000);

	// ����� ���������
	int pos = rabin_karp_search(text, pattern);

	// ����� ���������� ������
	if (pos == -1)
	{
		fout << "��������� �� ������� � ������" << endl;
	}
	else
	{
		fout << "��������� ������� � ������� " << pos << endl;
	}

	fin.close();
	fout.close();

	return 0;
}