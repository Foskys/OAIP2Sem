#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    string inputString;
    int k;

    // Ввод строки с клавиатуры
    cout << "Введите строку: ";
    getline(cin, inputString);

    // Ввод значения k
    cout << "Введите длину первой подстроки (k): ";
    cin >> k;

    // Запись строки в файл
    ofstream outFile("FILEK.txt");
    if (!outFile.is_open()) {
        cerr << "Ошибка при открытии файла." << endl;
        return 1;
    }

    outFile << inputString;
    outFile.close();

    // Чтение из файла
    ifstream inFile("FILEK.txt");
    if (!inFile.is_open()) {
        cerr << "Ошибка при открытии файла." << endl;
        return 1;
    }

    string fileContent;
    getline(inFile, fileContent);
    inFile.close();

    // Разбиение строки на две подстроки
    string firstSubstring = fileContent.substr(0, k);
    string secondSubstring = fileContent.substr(k);

    // Вывод результатов
    cout << "Первая подстрока: " << firstSubstring << endl;
    cout << "Вторая подстрока: " << secondSubstring << endl;

    return 0;
}
