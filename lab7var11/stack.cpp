#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

Node* top = NULL;

void push(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        cout << "Стек пуст" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete(temp);
}

void clear() {
    while (top != NULL) {
        pop();
    }
}

void remove3() {
    Node* temp = top;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data % 3 == 0) {
            if (prev == NULL) {
                top = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Элементы кратных 3 не найдены" << endl;
}

void display() {
    if (top == NULL) {
        cout << "Стек пуст" << endl;
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void saveToFile(const char* filename) {
    ofstream file(filename);
    Node* temp = top;
    while (temp != NULL) {
        file << temp->data << " ";
        temp = temp->next;
    }
    file.close();
}

void loadFromFile(const char* filename) {
    ifstream file(filename);
    clear();
    int value;
    while (file >> value) {
        push(value);
    }
    file.close();
}
