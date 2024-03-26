#include <iostream>
using namespace std;

// Структура элемента очереди
struct Node {
    char data;
    Node* next;
};

// Класс очереди
class Queue {
private:
    Node* front; // Указатель на начало очереди
    Node* rear;  // Указатель на конец очереди
    int maxSize; // Максимальный размер очереди
    int size;    // Текущий размер очереди

public:
    // Конструктор
    Queue(int maxSize) {
        front = nullptr;
        rear = nullptr;
        this->maxSize = maxSize;
        size = 0;
    }

    // Деструктор
    ~Queue() {
        while (!isEmpty())
            dequeue();
    }

    // Проверка на пустоту
    bool isEmpty() {
        return (front == nullptr);
    }

    // Проверка на переполнение
    bool isFull() {
        return (size == maxSize);
    }

    // Добавление элемента в очередь
    void enqueue(char data) {
        if (isFull()) {
            cout << "Очередь переполнена!" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Удаление элемента из очереди
    char dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return '\0';
        }

        Node* temp = front;
        char data = temp->data;
        front = front->next;
        delete temp;
        size--;
        return data;
    }

    // Вывод всех элементов очереди
    void display() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Очередь: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Поиск и удаление всех элементов до заданного символа
    void removeBefore(char target) {
        while (!isEmpty() && front->data != target) {
            dequeue();
        }
        if (!isEmpty() && front->data == target) {
            cout << "Найден символ " << target << " в очереди. Удаление элементов до него выполнено." << endl;
        }
        else {
            cout << "Символ " << target << " не найден в очереди." << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    Queue queue(maxSize);

    char choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить символ в очередь" << endl;
        cout << "2. Вывести все символы из очереди" << endl;
        cout << "3. Удалить элементы до заданного символа" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            char symbol;
            cout << "Введите символ: ";
            cin >> symbol;
            queue.enqueue(symbol);
            break;
        }
        case '2':
            queue.display();
            break;
        case '3': {
            char target;
            cout << "Введите символ, до которого нужно удалить элементы: ";
            cin >> target;
            queue.removeBefore(target);
            break;
        }
        case '4':
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Некорректный ввод!" << endl;
        }
    } while (choice != '4');

    return 0;
}
