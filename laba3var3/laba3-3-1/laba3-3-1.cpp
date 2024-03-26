#include <fstream>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    ofstream file1("FILE1.txt");
    file1 << "Vadim Berezka\n";
    file1 << "Alexey\n";
    file1 << "Stas Dach\n";
    file1 << "Matematica\n";
    file1 << "Gutor\n";
    file1.close();

    ifstream inFile("FILE1.txt");
    ofstream outFile("FILE2.txt");

    int k;
    cout << "Введите значение k: ";
    cin >> k;

    int lineCount = 0;
    int vowelCount = 0;
    char c;


    while (inFile.get(c)) {

        if (lineCount >= k && lineCount <= k + 3) {
            outFile.put(c);

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
                vowelCount++;
            }
        }
        if (c == '\n') {
            lineCount++;
        }
    }

    cout << "Количество гласных букв в файле FILE2: " << vowelCount << endl;

    inFile.close();
    outFile.close();

    return 0;
}
