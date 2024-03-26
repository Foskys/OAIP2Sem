#include "stack.h"
#include <iostream>
#include <fstream>

using namespace std;

// Инициализация стека
void initializeStack(Stack& stack) {
    stack.top = nullptr;
}

// Проверка на пустоту стека
bool isEmpty(const Stack& stack) {
    return stack.top == nullptr;
}

// Добавление элемента в стек
void push(Stack& stack, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
}

// Удаление элемента из стека
void pop(Stack& stack) {
    if (!isEmpty(stack)) {
        Node* temp = stack.top;
        stack.top = stack.top->next;
        delete temp;
    }
}

// Возвращение верхнего элемента стека
int top(const Stack& stack) {
    if (!isEmpty(stack)) {
        return stack.top->data;
    }
    // Возвращаемое значение при пустом стеке - можно задать по умолчанию или бросить исключение
    return -1;
}

// Очистка стека
void clear(Stack& stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

// Сохранение стека в файл
void saveToFile(const Stack& stack, const char* filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        Node* current = stack.top;
        while (current != nullptr) {
            outFile << current->data << endl;
            current = current->next;
        }
        outFile.close();
        cout << "Стек успешно сохранён в файле." << endl;
    }
    else {
        cerr << "Невозможно открыть файл для записи." << endl;
    }
}

// Чтение стека из файла
void readFromFile(Stack& stack, const char* filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        clear(stack); // Очищаем стек перед чтением из файла
        int value;
        while (inFile >> value) {
            push(stack, value);
        }
        inFile.close();
        cout << "Стек успешно считан из файла." << endl;
    }
    else {
        cerr << "Невозможно открыть файл для чтения." << endl;
    }
}

// Объединение двух стеков в один
void mergeStacks(Stack& resultStack, const Stack& stack1, const Stack& stack2) {
    Stack tempStack1 = stack1; // Создаем временные копии стеков
    Stack tempStack2 = stack2;

    // Переносим элементы из первого стека в результирующий
    while (!isEmpty(tempStack1)) {
        push(resultStack, top(tempStack1));
        pop(tempStack1);
    }

    // Переносим элементы из второго стека в результирующий
    while (!isEmpty(tempStack2)) {
        push(resultStack, top(tempStack2));
        pop(tempStack2);
    }
}
