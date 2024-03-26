#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void read(ifstream& f, string str) {
    getline(f, str, '\n');
}
void write(ofstream& f, string str) {
    f << str;
}
int main() {
    //потоки для чтения, записи
    ifstream in("in.txt");
    ofstream out("out.txt");
    char tmp[100] = " "; //буфер для записи самого длинного слова
    string line, prikol;
    getline(cin, line, '\n'); //получаем из потока консоли набранный пользователем текст
    write(out, line); //записываем текст в файл
    out.close(); //закрываем поток для записи
    read(in, prikol); //читаем строку из файла
    char* split = _strdup(prikol.c_str());  //преобразуем string строку в char[] для возможности использовать strtok()
    char* token = strtok(split, " "); //разделяем строку на слова
    while (token != NULL) {
        if (strlen(token) > strlen(tmp)) strcpy(tmp, token); //если слово превосходит самое длинное последнее слово то оно становится самым длинным
        token = strtok(NULL, " "); //переход к следующему слову
    }
    cout << "The longest word is: " << tmp << " and its length is " << strlen(tmp); //вывод результата
}