#pragma once
#include <iostream>

struct AAA
{
    int x;
    void print();
};

namespace heap
{
    enum CMP
    {
        LESS = -1, EQUAL = 0, GREAT = 1
    };

    struct Heap
    {
        int size;
        int maxSize;
        void** storage;              // ������    
        CMP(*compare)(void*, void*);

        Heap(int maxsize, CMP(*f)(void*, void*))
        {
            size = 0;
            storage = new void* [maxSize = maxsize];
            compare = f;
        };

        int left(int ix);
        int right(int ix);
        int parent(int ix);
        bool isFull() const
        {
            return (size >= maxSize);
        };
        bool isEmpty() const
        {
            return (size <= 0);
        };
        bool isLess(void* x1, void* x2) const
        {
            return compare(x1, x2) == LESS;
        };
        bool isGreat(void* x1, void* x2) const
        {
            return compare(x1, x2) == GREAT;
        };
        bool isEqual(void* x1, void* x2) const
        {
            return compare(x1, x2) == EQUAL;
        };
        void removeAllMax(); // ������� ��� ��������, ������ ������������� ��������
        void swap(int i, int j);
        void heapify(int ix);
        void insert(void* x);
        void* extractMax();
        void extractMin(); // Remove the minimum element
        void extractI(int i); // Remove the element at index i
        Heap unionHeap(const Heap& otherHeap); //Union two heaps
        void scan(int i) const;
    };

    Heap create(int maxsize, CMP(*f)(void*, void*));
}