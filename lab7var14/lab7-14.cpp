#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    Stack stack1, stack2, mergedStack;
    initializeStack(stack1);
    initializeStack(stack2);
    initializeStack(mergedStack);

    int choice;
    do {
        cout << "Меню:\n"
            << "1. Добавить в стек 1\n"
            << "2. Добавить в стек 2\n"
            << "3. Объединить стеки\n"
            << "4. Сохранить объединённый стек в файл\n"
            << "5. Считать объединённый стек из файла\n"
            << "6. Выйти\n"
            << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int value1;
            cout << "Введите значение для добавления в стек 1: ";
            cin >> value1;
            push(stack1, value1);
            break;
        case 2:
            int value2;
            cout << "Введите значение для добавления в стек 2: ";
            cin >> value2;
            push(stack2, value2);
            break;
        case 3:
            mergeStacks(mergedStack, stack1, stack2);
            cout << "Стеки успешно объединены." << endl;
            break;
        case 4:
            saveToFile(mergedStack, "stack.txt");
            break;
        case 5:
            readFromFile(mergedStack, "stack.txt");
            break;
        case 6:
            cout << "Завершение программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    } while (choice != 6);

    clear(stack1);
    clear(stack2);
    clear(mergedStack);

    return 0;
}
