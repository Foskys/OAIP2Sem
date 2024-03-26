#include <iostream>
#include <locale.h>
#include "stack.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int choice, value;
    const char* filename = "stack.txt";
    while (true) {
        cout << "1. Добавить элемент в стек" << endl;
        cout << "2. Удалить элемент из стека" << endl;
        cout << "3. Очистить стек" << endl;
        cout << "4. Удалить первый положительный элемент" << endl;
        cout << "5. Отобразить стек" << endl;
        cout << "6. Сохранить стек в файл" << endl;
        cout << "7. Загрузить стек из файла" << endl;
        cout << "8. Выход" << endl;
        cout << "Введите ваш выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            clear();
            break;
        case 4:
            remove3();
            break;
        case 5:
            display();
            break;
        case 6:
            saveToFile(filename);
            break;
        case 7:
            loadFromFile(filename);
            break;
        case 8:
            return 0;
        default:
            cout << "Неверный выбор" << endl;
        }
    }
    return 0;
}