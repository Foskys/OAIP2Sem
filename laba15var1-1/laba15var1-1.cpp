#include <iostream>
#include <ctime>
using namespace std;
namespace VadimSpace {
    void printArray(int arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}


// Функция пирамидальной сортировки
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[largest])
        largest = left;

    if (right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));
    const int sizeA = 50;
    int A[sizeA];
    for (int i = 0; i < sizeA; i++) {
        A[i] = rand() % 100;
    }

    int B[sizeA];
    int sizeB = 0;
    for (int i = 0; i < sizeA; i += 2) {
        B[sizeB++] = A[i];
    }

    clock_t start = clock();
    heapSort(B, sizeB);  // Пирамидальная сортировка
    clock_t end = clock();


    cout << "Array A: ";
    VadimSpace::printArray(A, sizeA);

    cout << "Array B: ";
    VadimSpace::printArray(B, sizeB);


    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    //cout << "Время выполнения пирамидальной сортировки: " << time_taken << " секунд" << std::endl;
    return 0;
}