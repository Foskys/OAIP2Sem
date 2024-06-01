// 4 var
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string bookName;
    int bookNumber;
    Node* next;
};

struct HashTable {
    Node** table;
    int size;

    HashTable(int size) {
        this->size = size;
        table = new Node * [size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void insertItem(string book, int number) {
        int index = hashFunction(number);
        Node* newNode = new Node{ book, number, nullptr };
        newNode->next = table[index];
        table[index] = newNode;
    }

    void deleteItem(int number) {
        int index = hashFunction(number);
        Node* temp = table[index];
        Node* prev = nullptr;

        if (temp != nullptr && temp->bookNumber == number) {
            table[index] = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->bookNumber != number) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void searchItem(int number) {
        int index = hashFunction(number);
        Node* entry = table[index];
        while (entry != nullptr) {
            if (entry->bookNumber == number) {
                cout << "Название книги: " << entry->bookName << ", Номер книги: " << entry->bookNumber << endl;
                return;
            }
            entry = entry->next;
        }
        cout << "Книга с номером " << number << " не найдена." << endl;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            Node* entry = table[i];
            cout << i;
            while (entry != nullptr) {
                cout << " --> " << entry->bookName << ":" << entry->bookNumber;
                entry = entry->next;
            }
            cout << endl;
        }
    }

    int hashFunction(int x) {
        return (x % size);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "Введите размер хеш-таблицы: ";
    cin >> size;

    HashTable h(size);

    int choice, number;
    string book;

    while (true) {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            h.displayHash();
            break;
        case 2:
            cout << "Введите название книги и номер книги: ";
            cin >> book >> number;
            h.insertItem(book, number);
            break;
        case 3:
            cout << "Введите номер книги для удаления: ";
            cin >> number;
            h.deleteItem(number);
            break;
        case 4:
            cout << "Введите номер книги для поиска: ";
            cin >> number;
            h.searchItem(number);
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор" << endl;
            break;
        }
    }

    return 0;
}