#include <iostream>
#include "queue.h"

using namespace std;
Queue::Queue(int size) {
    maxSize = size;
    array = new int[maxSize];
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] array;
}

void Queue::enqueue(int element) {
    if (count == maxSize) {
        cout << "Очередь полна. Невозможно добавить элемент." << endl;
        return;
    }

    if (element < 0) {
        rear = (rear + 1) % maxSize;
        array[rear] = element;
        count++;
    }
}

int Queue::dequeue() {
    if (count == 0) {
        cout << "Очередь пуста. Невозможно удалить элемент." << endl;
        return 0;
    }

    int element = array[front];
    front = (front + 1) % maxSize;
    count--;

    return element;
}

int Queue::getMin() {
    if (count == 0) {
        cout << "Очередь пуста." << endl;
        return 0;
    }

    int min = array[front];
    int current = front;

    for (int i = 0; i < count; i++) {
        if (array[current] < min) {
            min = array[current];
        }
        current = (current + 1) % maxSize;
    }

    return min;
}

int Queue::getMax() {
    if (count == 0) {
        cout << "Очередь пуста." << endl;
        return 0;
    }

    int max = array[front];
    int current = front;

    for (int i = 0; i < count; i++) {
        if (array[current] > max) {
            max = array[current];
        }
        current = (current + 1) % maxSize;
    }

    return max;
}

void Queue::printQueue() {
    if (count == 0) {
        cout << "Очередь пуста." << endl;
        return;
    }

    int current = front;

    for (int i = 0; i < count; i++) {
        cout << array[current] << " ";
        current = (current + 1) % maxSize;
    }

    cout << endl;
}

int Queue::getCount() {
    return count;
}