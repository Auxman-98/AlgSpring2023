#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

// Хэш-функция для строки s длины len с началом в позиции pos
int own_hash(const char* s, int len, int pos)
{
	int h = 0;
	for (int i = 0; i < len; ++i)
	{
		h += (int)s[pos + i] * pow(128, len - i - 1);
	}
	return h;
}

// Реализация алгоритма Рабина-Карпа для поиска подстроки
int rabin_karp_search(const char* text, const char* pattern)
{
	int text_len = strlen(text);
	int patt_len = strlen(pattern);

	// Вычисление хэшей для подстроки и первого окна строки
	int pattern_hash = own_hash(pattern, patt_len, 0);
	int text_hash = own_hash(text, patt_len, 0);

	// Поиск подстроки
	for (int i = 0; i <= text_len - patt_len; ++i) {
		if (pattern_hash == text_hash) {
			// Дополнительная проверка на совпадение символов
			int j;
			for (j = 0; j < patt_len; ++j) {
				if (pattern[j] != text[i + j])
					break;
			}
			if (j == patt_len)
				return i;
		}

		// Обновление хэша для следующего окна
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
		cout << "Ошибка: файл text-14.txt не найден\n";
		return 1;
	}
	if (!fout) {
		cout << "Ошибка: файл result-14.txt невозможно создать\n";
		return 1;
	}

	char text[1000];
	fin.getline(text, 1000);

	cout << "Входная строка: " << text << endl;

	char pattern[1000];
	cout << "Введите образец для поиска: ";
	cin.getline(pattern, 1000);

	// Поиск подстроки
	int pos = rabin_karp_search(text, pattern);

	// Вывод результата поиска
	if (pos == -1)
	{
		fout << "Подстрока не найдена в тексте" << endl;
	}
	else
	{
		fout << "Подстрока найдена в позиции " << pos << endl;
	}

	fin.close();
	fout.close();

	return 0;
}