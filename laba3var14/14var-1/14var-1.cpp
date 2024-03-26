#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
// Функция для подсчета количества букв "а" в слове
int countLetterA(const string& word) {
    return count(word.begin(), word.end(), 'a') + count(word.begin(), word.end(), 'A');
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");
    
    if (!file1.is_open() || !file2.is_open()) {
        cerr << "Ошибка при открытии файлов." << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;

    while (getline(file1, line)) {
        istringstream iss(line);
        string word;
        vector<string> words;

        while (iss >> word) {
            words.push_back(word);
        }

        // Проверяем, содержится ли в строке два одинаковых слова
        bool hasDuplicate = false;
        for (size_t i = 0; i < words.size(); ++i) {
            for (size_t j = i + 1; j < words.size(); ++j) {
                if (words[i] == words[j]) {
                    hasDuplicate = true;
                    break;
                }
            }
            if (hasDuplicate) break;
        }

        // Если в строке есть два одинаковых слова, копируем ее в FILE2
        if (hasDuplicate) {
            file2 << line << endl;

            // Определяем номер слова с наибольшим количеством букв "а"
            int maxLetterACount = 0;
            int wordNumber = 1;
            for (size_t i = 0; i < words.size(); ++i) {
                int letterACount = countLetterA(words[i]);
                if (letterACount > maxLetterACount) {
                    maxLetterACount = letterACount;
                    wordNumber = i + 1; // Номер слова начинается с 1
                }
            }

            cout << "В строке " << lineNumber + 1 << ", в слове номер " << wordNumber << " больше всего букв 'а'." << endl;
        }

        lineNumber++;
    }

    file1.close();
    file2.close();

    return 0;
}
