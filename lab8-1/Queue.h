#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
public:
    Queue(int maxSize);
    ~Queue();
    void enqueue(char data);
    char dequeue();
    void printQueue();
    int countElements();
    void inputElements(char targetSymbol);

private:
    char* elements;
    int front;
    int rear;
    int maxSize;
};

#endif#pragma once
