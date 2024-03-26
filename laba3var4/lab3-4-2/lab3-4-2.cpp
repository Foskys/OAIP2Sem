#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Rus");
    string inputString;
    cout << "Введите строку, состоящую из цифр и слов, разделенных пробелами: ";
    getline(cin, inputString);

    ofstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для записи\n";
        return 1;
    }

    file << inputString;
    file.close();

    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла для чтения\n";
        return 1;
    }

    string word;
    int maxWordLength = 0;
    while (inputFile >> word) {
        int wordLength = word.length();
        if (wordLength > maxWordLength) {
            maxWordLength = wordLength;
        }
    }

    inputFile.close();

    cout << "Самое длинное слово содержит " << maxWordLength << " символов.\n";

    return 0;
}