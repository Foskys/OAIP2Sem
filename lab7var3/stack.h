#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    Node* next;
};

void push(int value);
void pop();
void clear();
void removeFirstPositive();
void display();
void saveToFile(const char* filename);
void loadFromFile(const char* filename);
void count();

#endif