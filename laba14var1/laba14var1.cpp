// 1 var
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string productName;
    int year;
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

    void insertItem(string product, int year) {
        int index = hashFunction(year);
        Node* newNode = new Node{ product, year, nullptr };
        newNode->next = table[index];
        table[index] = newNode;
    }

    void deleteItem(int year) {
        int index = hashFunction(year);
        Node* temp = table[index];
        Node* prev = nullptr;

        if (temp != nullptr && temp->year == year) {
            table[index] = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->year != year) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void searchItem(int year) {
        int index = hashFunction(year);
        Node* entry = table[index];
        while (entry != nullptr) {
            if (entry->year == year) {
                cout << "Название товара: " << entry->productName << ", Год выпуска: " << entry->year << endl;
                return;
            }
            entry = entry->next;
        }
        cout << "Товар, выпущенный в " << year << " году, не найден." << endl;
    }

    void displayHash() {
        for (int i = 0; i < size; i++) {
            Node* entry = table[i];
            cout << i;
            while (entry != nullptr) {
                cout << " --> " << entry->productName << ":" << entry->year;
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

    int choice, year;
    string product;

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
            cout << "Введите название товара и год выпуска: ";
            cin >> product >> year;
            h.insertItem(product, year);
            break;
        case 3:
            cout << "Введите год выпуска товара для удаления: ";
            cin >> year;
            h.deleteItem(year);
            break;
        case 4:
            cout << "Введите год выпуска товара для поиска: ";
            cin >> year;
            h.searchItem(year);
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