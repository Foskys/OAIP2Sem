﻿#include <iostream>
#include <fstream>
using namespace std;
struct Node {
    double data;
    Node* next;
};

void addElement(Node*& head, double value) {
    setlocale(LC_ALL, "rus");
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    cout << "Элемент добавлен." << endl;
}

void removeElement(Node*& head, double value) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            cout << "Элемент удален." << endl;
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "Элемент не найден." << endl;
}

Node* searchElement(Node* head, double value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Список пуст." << endl;
        return;
    }

    Node* current = head;
    cout << "Список: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void writeToFile(Node* head, const string& filename) {
    ofstream file(filename);

    if (!file) {
        cout << "Не удалось открыть файл." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }

    file.close();
    cout << "Список записан в файл." << endl;
}

Node* readFromFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Не удалось открыть файл." << endl;
        return nullptr;
    }

    Node* head = nullptr;
    double value;
    while (file >> value) {
        addElement(head, value);
    }

    file.close();
    cout << "Список считан из файла." << endl;
    return head;
}

int main() {
    setlocale(LC_ALL, "rus");
    Node* head = nullptr;
    int choice;
    double value;
    string filename;

    do {
        cout << "Меню:\n";
        cout << "1. Добавление элемента\n";
        cout << "2. Удаление элемента\n";
        cout << "3. Поиск элемента\n";
        cout << "4. Вывод списка в консольное окно\n";
        cout << "5. Запись списка в файл\n";
        cout << "6. Считывание списка из файла\n";
        cout << "0. Выход\n";
        cout << "Введите номер пункта: ";
        cin >> choice;

        switch (choice) {
        case 1:
        cout << "Введите значение элемента: ";
        cin >> value;
            addElement(head, value);
            break;
        case 2:
        cout << "Введите значение элемента: ";
        cin >> value;
            removeElement(head, value);
            break;
        case 3:
        cout << "Введите значение элемента: ";
        cin >> value;
            if (searchElement(head, value) != nullptr) {
        cout << "Элемент найден." << endl;
            }
            else {
                cout << "Элемент не найден." << endl;
            }
            break;
        case 4:
            printList(head);
            break;
        case 5:
           cout << "Введите имя файла: ";
           cin >> filename;
           writeToFile(head, filename);
            break;
        case 6:
           cout << "Введите имя файла: ";
           cin >> filename;
            head = readFromFile(filename);
            break;
        case 0:
           cout << "Выход из программы." << endl;
            break;
        default:
           cout << "Неверный номер пункта. Попробуйте еще раз." << endl;
            break;
        }

    cout << endl;

    } while (choice != 0);

    // Освобождение памяти, выделенной для списка
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
