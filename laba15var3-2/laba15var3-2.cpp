#include <iostream>
#include <ctime>

// Функция быстрой сортировки (сортировка Хоара)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] > pivot) {
                i++;
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        int t = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = t;
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    srand(time(0));
    const int sizeA = 30;
    int A[sizeA];
    for (int i = 0; i < sizeA; i++) {
        A[i] = rand() % 100;
    }

    int maxElementIndex = 0;
    for (int i = 1; i < sizeA; i++) {
        if (A[i] > A[maxElementIndex]) {
            maxElementIndex = i;
        }
    }

    int B[sizeA];
    int sizeB = 0;
    for (int i = maxElementIndex + 1; i < sizeA; i += 2) {
        B[sizeB++] = A[i];
    }

    clock_t start, end;

    start = clock();
    quickSort(B, 0, sizeB - 1);  // Быстрая сортировка (сортировка Хоара)
    end = clock();
    double time_taken_quickSort = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by quickSort is : " << std::fixed << time_taken_quickSort << std::endl;
    // Вывод массивов A и B
    std::cout << "Array A: ";
    printArray(A, sizeA);
    std::cout << "Array B: ";
    printArray(B, sizeB);
    return 0;
}