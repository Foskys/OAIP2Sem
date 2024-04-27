#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int maxSize;
    char targetSymbol;

    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    Queue queue(maxSize);

    cout << "Введите эталонный символ: ";
    cin >> targetSymbol;

    queue.inputElements(targetSymbol);

    return 0;
}   