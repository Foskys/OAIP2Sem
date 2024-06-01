#include <iostream>
#include <ctime>

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

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(time(0));
    const int sizeA = 500;
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
    bubbleSort(B, sizeB);  // Сортировка "пузырьком"
    end = clock();
    double time_taken_bubbleSort = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by bubbleSort is : " << std::fixed << time_taken_bubbleSort << std::endl;

    // Вывод массивов A и B
    std::cout << "Array A: ";
    printArray(A, sizeA);
    std::cout << "Array B: ";
    printArray(B, sizeB);

    return 0;
}