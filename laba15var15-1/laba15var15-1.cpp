#include <iostream>
#include <ctime>
#include <locale.h>

// Функция сортировки "пузырьком"
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
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
    bubbleSort(B, sizeB);  // Сортировка "пузырьком"
    clock_t end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Время выполнения сортировки пузырьком: " << time_taken << " секунд" << std::endl;

    std::cout << "Задача выполнена успешно!" << std::endl;

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < sizeB; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}