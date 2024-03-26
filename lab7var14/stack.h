#ifndef STACK_H
#define STACK_H

// Структура элемента стека
struct Node {
    int data;
    Node* next;
};

// Структура для стека
struct Stack {
    Node* top;
};

// Объявление функций
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
