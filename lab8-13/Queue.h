#pragma once
#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* array;
    int front;
    int rear;
    int maxSize;
    int count;

public:
    Queue(int size);
    ~Queue();

    void enqueue(int element);
    int dequeue();
    int getMin();
    int getMax();
    void printQueue();
    int getCount();
};

#endif  // QUEUE_H