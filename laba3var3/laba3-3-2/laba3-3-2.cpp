#include <iostream>
#include <fstream>
#include <clocale>
#include <string>

using namespace std;

// Функция записи строки в файл
void writeToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}

// Функция чтения строки из файла и записи слов в другой файл
void readFromFile(const string& filename, const string& outputFilename) {
    ifstream file(filename);
    ofstream outputFile(outputFilename);
    if (file.is_open() && outputFile.is_open()) {
        string word;
        while (file >> word) {
            if (!isdigit(word[0])) {
                outputFile << word << ' ';
            }
        }
        file.close();
        outputFile.close();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string input;
    cout << "Введите строку символов: ";
    getline(cin, input);

    string filename = "input.txt";
    writeToFile(filename, input);

    string outputFilename = "output.txt";
    readFromFile(filename, outputFilename);

    return 0;
}
