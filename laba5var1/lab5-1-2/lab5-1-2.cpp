#include <iostream>
#include <fstream>
using namespace std;

const int MAX_NUM = 100; // максимальное количество записей в таблице

// объединение для хранения информации о преподавателях
union Teacher {
	char surname[30]; // фамилия
	char exam[30]; // название экзамена
	char date[30]; // дата экзамена
	struct {
		char surname[30]; // фамилия
		char exam[30]; // название экзамена
		char date[30]; // дата экзамена
	} data;
};
// структура таблицы
struct Table {
	int size; // текущее количество записей в таблице
	Teacher data[MAX_NUM]; // массив записей
};

// функция для ввода данных в таблицу с клавиатуры
void input(Table& table) {
	cout << "Введите количество записей в таблице: ";
	cin >> table.size;
	cin.ignore(); // очистка буфера ввода

	for (int i = 0; i < table.size; i++) {
		cout << "Введите данные для записи #" << i + 1 << ":" << endl;
		cout << "Фамилия преподавателя: ";
		cin.getline(table.data[i].surname, 30);
		cout << "Название экзамена: ";
		cin.getline(table.data[i].exam, 30);
		cout << "Дата экзамена: ";
		cin.getline(table.data[i].date, 30);
	}
}

// функция для записи таблицы в файл
void save(Table& table, const char* filename) {
	ofstream file(filename, ios::binary | ios::trunc);
	file.write((char*)&table, sizeof(Table));
	file.close();
	cout << "Таблица сохранена в файл " << filename << endl;
}

// функция для чтения таблицы из файла
void load(Table& table, const char* filename) {
	ifstream file(filename, ios::binary);
	file.read((char*)&table, sizeof(Table));
	file.close();
	cout << "Таблица загружена из файла " << filename << endl;
}

// функция для вывода таблицы на экран
void display(Table& table) {
	cout << "Текущее количество записей в таблице: " << table.size << endl;

	for (int i = 0; i < table.size; i++) {
		cout << "Запись #" << i + 1 << ":" << endl;
		cout << "Фамилия преподавателя: " << table.data[i].surname << endl;
		cout << "Название экзамена: " << table.data[i].exam << endl;
		cout << "Дата экзамена: " << table.data[i].date << endl;
	}
}

// функция для поиска записей по фамилии преподавателя
void search(Table& table) {
	char surname[30];
	cout << "Введите фамилию преподавателя для поиска: ";
	cin.getline(surname, 30);

	bool found = false;
	for (int i = 0; i < table.size; i++) {
		if (strcmp(table.data[i].surname, surname) == 0) {
			cout << "Запись #" << i + 1 << ":" << endl;
			cout << "Фамилия преподавателя: " << table.data[i].surname << endl;
			cout << "Название экзамена: " << table.data[i].exam << endl;
			cout << "Дата экзамена: " << table.data[i].date << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Запись с фамилией преподавателя \"" << surname << "\" не найдена." << endl;
	}
}

// главная функция программы
int main() {
	setlocale(LC_ALL, "rus");
	Table table;
	char filename[] = "table.dat";
	// меню программы
	int choice;
	do {
		cout << "Меню:" << endl;
		cout << "1. Ввод данных в таблицу" << endl;
		cout << "2. Запись таблицы в файл" << endl;
		cout << "3. Чтение таблицы из файла" << endl;
		cout << "4. Вывод таблицы на экран" << endl;
		cout << "5. Поиск записей по фамилии преподавателя" << endl;
		cout << "0. Выход" << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;
		cin.ignore(); // очистка буфера ввода

		switch (choice) {
		case 1:
			input(table);
			break;
		case 2:
			save(table, filename);
			break;
		case 3:
			load(table, filename);
			break;
		case 4:
			display(table);
			break;
		case 5:
			search(table);
			break;
		case 0:
			cout << "Выход." << endl;
			break;
		default:
			cout << "Неверный пункт меню. Попробуйте еще раз." << endl;
			break;
		}
	} while (choice != 0);

	return 0;
}

