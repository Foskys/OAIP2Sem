#ifndef STACK_H
#define STACK_H

// ��������� �������� �����
struct Node {
    int data;
    Node* next;
};

// ��������� ��� �����
struct Stack {
    Node* top;
};

// ���������� �������
void initializeStack(Stack&);
bool isEmpty(const Stack&);
void push(Stack&, int);
void pop(Stack&);
int top(const Stack&);
void clear(Stack&);
void saveToFile(const Stack&, const char*);
void readFromFile(Stack&, const char*);
void mergeStacks(Stack&, const Stack&, const Stack&);

#endif // STACK_FUNCTIONS_H
