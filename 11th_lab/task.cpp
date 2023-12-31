#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
const int MAX_CHARS = 256;

void buildAutomaton(string pattern, vector<vector<int> >& finite_automaton) {
	const int p = pattern.length();
	finite_automaton.resize(p + 1, vector<int>(MAX_CHARS, 0));
	int ps1 = 0; // длина наидлиннейшего суффикса pattern[0..i-1], который также является префиксом pattern[0..i]
	finite_automaton[0][pattern[0]] = 1; // первый символ

	for (int i = 1; i <= p; i++) {
		for (int c = 0; c < MAX_CHARS; c++) {
			finite_automaton[i][c] = finite_automaton[ps1][c];
		}

		if (i < p) {
			finite_automaton[i][pattern[i]] = i + 1;
			ps1 = finite_automaton[ps1][pattern[i]];
		}
	}
}

vector<int> search_pattern(string pattern, string text) {
	vector<vector<int> > finite_automaton;
	buildAutomaton(pattern, finite_automaton);
	vector<int> matches;
	const int p = pattern.length();
	const int t = text.length();
	int curState = 0;
	for (int i = 0; i < t; i++) {
		curState = finite_automaton[curState][text[i]];
		if (curState == p)
			matches.push_back(i - p + 1);
	}
	return matches;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	string pattern;
	cout << "Введите образец для поиска: ";
	cin >> pattern;
	string filename;
	cout << "Введите имя файла с текстом: ";
	cin >> filename;;

	ifstream fin(filename);
	if (!fin) {
		cerr << "Ошибка при открытии файла \"" << filename << "\" для чтения!\n";
		return -1;
	}

	string text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	fin.close();

	vector<int> result = search_pattern(pattern, text);

	if (result.size() == 0)
		cout << "Образец не найден в тексте!\n";
	else {
		string outFileName;
		cout << "Введите имя файла для записи результата: ";
		cin >> outFileName;

		ofstream outFile(outFileName);
		if (!outFile) {
			cerr << "Ошибка при открытии файла \"" << outFileName << "\" для записи!\n";
			return -1;
		}

		outFile << "Образец \"" << pattern << "\" найден в тексте в следующих позициях:\n";
		for (int i = 0; i < result.size(); i++)
			outFile << result[i] << " ";
		outFile << endl;

		outFile.close();
	}

	return 0;
}