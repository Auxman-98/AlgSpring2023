#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Реализация алгоритма Бойера-Мура для поиска подстроки
int boyer_moore_search(string str, string substr) {
	// Сбор длин строк
	int str_len = str.length();
	int substr_len = substr.length();

	// Создание таблицы смещений
	int bmd_table[256];
	for (int i = 0; i < 256; ++i)
		bmd_table[i] = substr_len;
	for (int i = 0; i < substr_len - 1; ++i)
		bmd_table[substr[i]] = substr_len - i - 1;

	// Поиск подстрок
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
	// Открытие файлов чтения и записи
	ifstream fin("text-13.txt");
	ofstream fout("result-13.txt");

	// Проверка наличия файлов
	if (!fin) {
		cout << "Ошибка: файл text-13.txt не найден\n";
		return 1;
	}
	if (!fout) {
		cout << "Ошибка: файл result-13.txt не найден\n";
		return 1;
	}

	// Считывание исходной строки
	string text;
	getline(fin, text);

	// Вывод строки поиска
	string pattern;
	cout << "Введите подстроку для поиска: ";
	getline(cin, pattern);

	// Поиск подстрок
	int pos = boyer_moore_search(text, pattern);

	if (pos == -1) {
		fout << "Подстрока не найдена\n";
	}
	else {
		fout << "Подстрока найдена в позиции " << pos << endl;
	}

	// Закрытие файлов
	fin.close();
	fout.close();

	return 0;
}