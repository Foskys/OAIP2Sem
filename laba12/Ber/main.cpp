#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else if (A2->x > A1->x)
        rc = heap::LESS;
    return rc;
#undef A2
#undef A1 
}

int main()
{
    setlocale(LC_ALL, "rus");
    int k, choice;
    heap::Heap h1 = heap::create(30, cmpAAA);

    for (;;)
    {
        cout << "1 - вывод кучи на экран" << endl;
        cout << "2 - добавить элемент" << endl;
        cout << "3 - удалить максимальный элемент" << endl;
        cout << "4 - удалить минимальный элемент" << endl;
        cout << "5 - удалить элемент по индексу" << endl;
        cout << "6 - объединить две кучи" << endl;
        cout << "7 - удалить все элементы, равные максимальному значению" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;  cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            h1.scan(0);
            break;
        case 2: {
            AAA* a = new AAA;
            cout << "введите ключ" << endl;
            cin >> k;
            a->x = k;
            h1.insert(a);
        }
              break;
        case 3:
            h1.extractMax();
            break;
        case 4:
            h1.extractMin();
            break;
        case 5: {
            int index;
            cout << "Введите индекс элемента, который нужно удалить: ";
            cin >> index;
            h1.extractI(index);
        }
            break;
        case 6: {
            int maxsize2;
            cout << "Введите максимальный размер второй кучи: ";
            cin >> maxsize2;
            heap::Heap h2 = heap::create(maxsize2, cmpAAA);
            for (;;) {
                cout << "Добавить элемент во вторую кучу (1 - да, 0 - нет): ";
                int addChoice;
                cin >> addChoice;
                if (addChoice == 0)
                    break;
                else if (addChoice == 1) {
                    AAA* a = new AAA;
                    cout << "Введите ключ: ";
                    cin >> k;
                    a->x = k;
                    h2.insert(a);
                }
                else {
                    cout << "Неверный выбор. Повторите ввод." << endl;
                }
            }
            heap::Heap mergedHeap = h1.unionHeap(h2);
            cout << "Объединенная куча:" << endl;
            mergedHeap.scan(0);
        }
            break;

        case 7:
            h1.removeAllMax();
            break;

        default:
            cout << endl << "Неверный выбор. Повторите ввод." << endl;
        }
    }

    return 0;
}