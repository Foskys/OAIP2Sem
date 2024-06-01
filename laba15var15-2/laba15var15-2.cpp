#include <iostream>
#include <ctime>
#include <locale.h>

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

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));
    const int sizeA = 5000;
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
    quickSort(B, 0, sizeB - 1);  // Быстрая сортировка (сортировка Хоара)
    clock_t end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время выполнения быстрой сортировки: " << time_taken << " секунд" << std::endl;

    std::cout << "Задача выполнена успешно!" << std::endl;

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < sizeB; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}