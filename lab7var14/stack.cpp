#include "stack.h"
#include <iostream>
#include <fstream>

using namespace std;

// ������������� �����
void initializeStack(Stack& stack) {
    stack.top = nullptr;
}

// �������� �� ������� �����
bool isEmpty(const Stack& stack) {
    return stack.top == nullptr;
}

// ���������� �������� � ����
void push(Stack& stack, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack.top;
    stack.top = newNode;
}

// �������� �������� �� �����
void pop(Stack& stack) {
    if (!isEmpty(stack)) {
        Node* temp = stack.top;
        stack.top = stack.top->next;
        delete temp;
    }
}

// ����������� �������� �������� �����
int top(const Stack& stack) {
    if (!isEmpty(stack)) {
        return stack.top->data;
    }
    // ������������ �������� ��� ������ ����� - ����� ������ �� ��������� ��� ������� ����������
    return -1;
}

// ������� �����
void clear(Stack& stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

// ���������� ����� � ����
void saveToFile(const Stack& stack, const char* filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        Node* current = stack.top;
        while (current != nullptr) {
            outFile << current->data << endl;
            current = current->next;
        }
        outFile.close();
        cout << "���� ������� ������� � �����." << endl;
    }
    else {
        cerr << "���������� ������� ���� ��� ������." << endl;
    }
}

// ������ ����� �� �����
void readFromFile(Stack& stack, const char* filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        clear(stack); // ������� ���� ����� ������� �� �����
        int value;
        while (inFile >> value) {
            push(stack, value);
        }
        inFile.close();
        cout << "���� ������� ������ �� �����." << endl;
    }
    else {
        cerr << "���������� ������� ���� ��� ������." << endl;
    }
}

// ����������� ���� ������ � ����
void mergeStacks(Stack& resultStack, const Stack& stack1, const Stack& stack2) {
    Stack tempStack1 = stack1; // ������� ��������� ����� ������
    Stack tempStack2 = stack2;

    // ��������� �������� �� ������� ����� � ��������������
    while (!isEmpty(tempStack1)) {
        push(resultStack, top(tempStack1));
        pop(tempStack1);
    }

    // ��������� �������� �� ������� ����� � ��������������
    while (!isEmpty(tempStack2)) {
        push(resultStack, top(tempStack2));
        pop(tempStack2);
    }
}
