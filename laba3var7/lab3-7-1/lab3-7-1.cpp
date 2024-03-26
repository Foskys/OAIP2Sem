#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    //потоки для чтения/записи
    ifstream in("in.txt");
    ofstream out("out.txt");
    string line;
    unsigned int amount = 0;
    bool exist = false;
    //пока есть строки в файле
    while (getline(in, line)) {
        for (unsigned int i = 0; i < line.length(); i++)
            if (isdigit((unsigned char)line[i]))
                exist = true;

        if (!exist) {
            out << line << '\n';
            if (line[0] == 'A' || line[0] == 'a') //проверяем начинается ли строка с буквы А
                amount++;
        }
        else
            exist = false;
    }
    out << '\n' << amount; //записываем количество строк начинающихся с буквы А
}