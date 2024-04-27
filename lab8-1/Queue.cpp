#include "queue.h"
using namespace std;

Queue::Queue(int maxSize) : front(0), rear(-1), maxSize(maxSize) {
    elements = new char[maxSize];
}

Queue::~Queue() {
    delete[] elements;
}

void Queue::enqueue(char data) {
    if (rear == maxSize - 1) {
        cout << "������� ���������. ���������� �������� � ������� ����� �������.\n";
        return;
    }
    elements[++rear] = data;
}

char Queue::dequeue() {
    if (front > rear) {
        cout << "������� �����. ���������� ������� �� �������.\n";
        return '\0';
    }
    return elements[front++];
}

void Queue::printQueue() {
    for (int i = front; i <= rear; ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

int Queue::countElements() {
    return rear + 1;
}

void Queue::inputElements(char targetSymbol) {
    char inputSymbol;
    while (true) {
        cout << "������� ������: ";
        cin >> inputSymbol;
        enqueue(inputSymbol);
        if (inputSymbol == targetSymbol) {
            break;
        }
    }

    cout << "���������� �������: ";
    printQueue();

    dequeue();
    dequeue();

    int remainingElements = countElements();
    cout << "���������� �������� � �������: " << remainingElements << endl;
}