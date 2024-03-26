#include <iostream> 
#include <fstream> 
using namespace std;
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addElement(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void deleteElement(int value) {
        setlocale(LC_ALL, "Russian");
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Элемент не найден в списке." << endl;
    }

    bool findElement(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    void displayList() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void saveListToFile(const string& fileName) {
        setlocale(LC_ALL, "Russian");
        ofstream file(fileName);

        if (file.is_open()) {
            Node* current = head;
            while (current != nullptr) {
                file << current->data << " ";
                current = current->next;
            }

            file.close();
        }
        else {
             cout << "Не удается открыть файл." << endl;
        }
    }

    void readListFromFile(const string& fileName) {
        setlocale(LC_ALL, "Russian");
        ifstream file(fileName);
        int value;

        if (file.is_open()) {
            while (file >> value) {
                addElement(value);
            }

            file.close();
        }
        else {
            cout << "Не удается открыть файл." << endl;
        }
    }

    int sumNegativeLastDigit3() {
        int sum = 0;
        Node* current = head;

        while (current != nullptr) {
            if (current->data < 0 && abs(current->data) % 10 == 3) {
                sum += current->data;
            }

            current = current->next;
        }

        return sum;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    LinkedList list;

    int choice, value;
    string fileName;

    do {
        cout << "\nMenu:\n1.Добавить элемент\n2.Удалить элемент\n3.Найти элемент\n4.Отобразить список\n5.Сохранить список в файл\n6.Прочитать список из файла\n7.Сумма отрицательных элементов с последней цифрой 3\n0.Выход\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение для добавления: ";
            cin >> value;
            list.addElement(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteElement(value);
            break;
        case 3:
            cout << "Введите значение, чтобы найти: ";
            cin >> value;
            if (list.findElement(value)) {
            cout << "Элемент найден в списке." << endl;
            }
            else {
                cout << "Элемент не найден в списке." << endl;
            }
            break;
        case 4:
            cout << "Содержимое списка: ";
            list.displayList();
            break;
        case 5:
            cout << "Введите имя файла для сохранения: ";
            cin >> fileName;
            list.saveListToFile(fileName);
            break;
        case 6:
            cout << "Введите имя файла для чтения: ";
            cin >> fileName;
            list.readListFromFile(fileName);
            break;
        case 7:
            cout << "Сумма отрицательных элементов с последней цифрой 3: " << list.sumNegativeLastDigit3() << endl;
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}