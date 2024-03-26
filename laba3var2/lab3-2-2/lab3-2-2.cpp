#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//функции чтения/записи
void read(ifstream& f, string str) {
	getline(f, str);
}
void write(ofstream& f, string str) {
	f << str;
}
int main() {
	ofstream fout("fout.txt");
	ifstream fin("fin.txt");
	string str;
	//вводим в консоль, записываем и читаем
	getline(cin, str);
	write(fout, str);
	read(fin, str);
	int count = 0, arr[50], size = 0, index = 0;
	str += " ";
	//подсчет размера каждой группы
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') count++;
		else {
			arr[size] = count;
			size++;
			count = 0;
		}
	}
	//поиск самой маленькой группы
	int min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	string group;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' && str[i - 1] != ' ') count++;
		else if (count == index) group += str[i];
	}
	//выводим самую маленькую группу
	cout << group << endl;
	return 0;
}