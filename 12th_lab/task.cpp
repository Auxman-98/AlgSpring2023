#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> build_prefix_function(string pattern) {
	const int p = pattern.length();
	vector<int> prefix_function(p);
	prefix_function[0] = 0;
	int k = 0;
    for (int i = 1; i < p; i++) {
        while (k > 0 && pattern[i] != pattern[k]) {
            k = prefix_function[k - 1];
        }
        if (pattern[i] == pattern[k]) {
            k++;
        }
        prefix_function[i] = k;
    }
    return prefix_function;
}

vector<int> search_pattern(string pattern, string text) {
    vector<int> prefix_function = build_prefix_function(pattern);
    vector<int> res;
    int t = text.length();
    int p = pattern.length();
    int j = 0;
    for (int i = 0; i < t; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix_function[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == p) {
            res.push_back(i - p + 1);
            j = prefix_function[j - 1];
        }
    }
    return res;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string pattern;
    cout << "������� ������� ��� ������: ";
    cin >> pattern;
    string finName;
    cout << "������� ��� ����� � �������: ";
    cin >> finName;

    ifstream fin(finName);
    if (!fin) {
        cerr << "������ ��� �������� ����� \"" << finName << "\" ��� ������!\n";
        return -1;
    }

    string text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    vector<int> res = search_pattern(pattern, text);

    if (res.size() == 0) {
        cout << "������� �� ������ � ������.\n";
    }
    else {
        string outName;
        cout << "������� ��� ����� ��� ������ ����������: ";
        cin >> outName;

        ofstream fout(outName);
        if (!fout) {
            cout << "������ ��� �������� ����� \"" << outName << "\" ��� ������!\n";
            return -1;
        }

        fout << "������� \"" << pattern << "\" ������ � ������ � ��������� ��������:\n";
        for (int i = 0; i < res.size(); i++) {
            fout << res[i] << " ";
        }
        fout << endl;

        fout.close();
    }

	return 0;
}