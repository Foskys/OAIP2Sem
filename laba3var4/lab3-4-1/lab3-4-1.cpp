#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Rus");
    ifstream file1("FILE1.txt");
    if (!file1.is_open()) {
        cerr << "Ошибка открытия файла FILE1.txt\n";
        return 1;
    }

    ofstream file2("FILE2.txt");
    if (!file2.is_open()) {
        cerr << "Ошибка открытия файла FILE2.txt\n";
        return 1;
    }

    int countLinesWithA = 0;
    string line;
    while (getline(file1, line)) {
        bool containsDigit = false;
        for (char c : line) {
            if (isdigit(c)) {
                containsDigit = true;
                break;
            }
        }

        if (!containsDigit) {
            file2 << line << endl;
            if (!line.empty() && line[0] == 'A') {
                countLinesWithA++;
            }
        }
    }

    file1.close();
    file2.close();

    cout << "Количество строк, начинающихся на букву 'A' в файле FILE2: " << countLinesWithA << endl;

    return 0;
}