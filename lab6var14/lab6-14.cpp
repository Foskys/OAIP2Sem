#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void remove(int data) {
        if (!head)
            return;

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current && current->data != data) {
            prev = current;
            current = current->next;
        }

        if (!current)
            return;

        prev->next = current->next;
        delete current;
    }

    bool search(int data) {
        Node* current = head;
        while (current) {
            if (current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void sumOfNegativesMultipleOf5() {
        int sum = 0;
        Node* current = head;
        while (current) {
            if (current->data < 0 && current->data % 5 == 0)
                sum += current->data;
            current = current->next;
        }
        if (sum == 0)
            cout << "Нет отрицательных элементов, кратных 5" << endl;
        else
            cout << "Сумма отрицательных элементов, кратных 5: " << sum << endl;
    }

    void writeToFile(const char* filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Ошибка открытия файла" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
        cout << "Список записан в файл " << filename << endl;
    }

    void readFromFile(const char* filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Ошибка открытия файла" << endl;
            return;
        }
        int data;
        while (file >> data) {
            append(data);
        }
        file.close();
        cout << "Список считан из файла " << filename << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    LinkedList list;
    while (true) {
        cout << "1. Добавить элемент\n"
            << "2. Удалить элемент\n"
            << "3. Поиск элемента\n"
            << "4. Вывести список\n"
            << "5. Записать список в файл\n"
            << "6. Считать список из файла\n"
            << "7. Найти сумму отрицательных элементов, кратных 5\n"
            << "8. Выйти\n"
            << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Введите элемент: ";
            cin >> data;
            list.append(data);
            break;
        }
        case 2: {
            int data;
            cout << "Введите элемент для удаления: ";
            cin >> data;
            list.remove(data);
            break;
        }
        case 3: {
            int data;
            cout << "Введите элемент для поиска: ";
            cin >> data;
            if (list.search(data))
                cout << "Элемент найден" << endl;
            else
                cout << "Элемент не найден" << endl;
            break;
        }
        case 4:
            list.display();
            break;
        case 5: {
            char filename[100];
            cout << "Введите имя файла для записи: ";
            cin >> filename;
            list.writeToFile(filename);
            break;
        }
        case 6: {
            char filename[100];
            cout << "Введите имя файла для чтения: ";
            cin >> filename;
            list.readFromFile(filename);
            break;
        }
        case 7:
            list.sumOfNegativesMultipleOf5();
            break;
        case 8:
            cout << "Выход" << endl;
            return 0;
        default:
            cout << "Неверный ввод. Пожалуйста, выберите существующий пункт меню." << endl;
        }
    }

    return 0;
}
