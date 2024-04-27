#include <iostream>
#include "Queue.h"

using namespace std;
void printMenu() {
    cout << "Меню очереди:" << endl;
    cout << "1. Добавить элемент в очередь" << endl;
    cout << "2. Удалить элемент из очереди" << endl;
    cout << "3. Получить минимальный элемент" << endl;
    cout << "4. Получить максимальный элемент" << endl;
    cout << "5. Вывести все элементы очереди" << endl;
    cout << "6. Посчитать количество элементов в очереди" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите ваш выбор: ";
}

int main() {
    setlocale(LC_ALL,"rus");
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    Queue queue(maxSize);
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Выход..." << endl;
            break;
        case 1: {
            int element;
            cout << "Введите элемент для добавления в очередь: ";
            cin >> element;
            queue.enqueue(element);
            cout << "Элемент добавлен в очередь." << endl;
            break;
        }
        case 2: {
            int element = queue.dequeue();
            if (element != 0) {
                cout << "Удаленный элемент: " << element << endl;
            }
            break;
        }
        case 3: {
            int min = queue.getMin();
            cout << "Минимальный элемент: " << min << endl;
            break;
        }
        case 4: {
            int max = queue.getMax();
            cout << "Максимальный элемент: " << max << endl;
            break;
        }
        case 5:
            cout << "Элементы очереди: ";
            queue.printQueue();
            break;
        case 6: {
            int count = queue.getCount();
            cout << "Количество элементов в очереди: " << count << endl;
            break;
        }
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}