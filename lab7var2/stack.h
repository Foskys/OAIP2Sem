#pragma once
#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    Node* next;
};

void push(int value);
void pop();
void clear();
void removeFirstNegative();
void display();
void saveToFile(const char* filename);
void loadFromFile(const char* filename);

#endif