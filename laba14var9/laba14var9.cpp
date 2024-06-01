// 9 var
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string clientName;
    int passportNumber;
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

    void insertItem(string client, int number) {
        int index = hashFunction(number);
        Node* newNode = new Node{ client, number, nullptr };
        newNode->next = table[index];
        table[index] = newNode;
    }

    void deleteItem(int number) {
        int index = hashFunction(number);
        Node* temp = table[index];
        Node* prev = nullptr;

        if (temp != nullptr && temp->passportNumber == number) {
            table[index] = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->passportNumber != number) {
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
            if (entry->passportNumber == number) {
                cout << "Имя клиента: " << entry->clientName << ", Номер паспорта: " << entry->passportNumber << endl;
                return;
            }
            entry = entry->next;
        }
        cout << "Паспорт с номером " << number << " не найден." << endl;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            Node* entry = table[i];
            cout << i;
            while (entry != nullptr) {
                cout << " --> " << entry->clientName << ":" << entry->passportNumber;
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
    string client;

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
            cout << "Введите имя клиента и номер паспорта: ";
            cin >> client >> number;
            h.insertItem(client, number);
            break;
        case 3:
            cout << "Введите номер паспорта для удаления: ";
            cin >> number;
            h.deleteItem(number);
            break;
        case 4:
            cout << "Введите номер паспорта для поиска: ";
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