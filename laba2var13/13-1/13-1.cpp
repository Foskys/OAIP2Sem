#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX_SIZE 1000 // Максимальное количество чисел в файле fileA
int main() {
    setlocale(LC_CTYPE, "rus");
    FILE* fileA, * fileB;
    int numbers[MAX_SIZE];
    int count[MAX_SIZE] = { 0 };
    int size = 0;

    // Открытие файла для чтения
    fileA = fopen("fA.txt", "r");
    if (fileA == NULL) {
        printf("Ошибка при открытии файла fA.txt.\n");
        return 1;
    }

    // Считывание чисел из файла fileA
    while (fscanf_s(fileA, "%d", &numbers[size]) == 1) {
        size++;
    }

    // Подсчет количества повторений каждого числа
    for (int i = 0; i < size; i++) {
        int current = numbers[i];
        int found = 0;

        for (int j = 0; j < i; j++) {
            if (numbers[j] == current) {
                found = 1;
                break;
            }
        }

        if (!found) {
            for (int j = i; j < size; j++) {
                if (numbers[j] == current) {
                    count[i]++;
                }
            }
        }
    }

    // Открытие файла для записи
    fileB = fopen("fB.txt", "w");
    if (fileB == NULL) {
        printf("Ошибка при открытии файла fB.txt.\n");
        return 1;
    }

    // Запись чисел, встречающихся более двух раз, в файл fileB
    for (int i = 0; i < size; i++) {
        if (count[i] > 2) { // Изменено условие для чисел, встречающихся более двух раз
            fprintf(fileB, "%d\n", numbers[i]);
        }
    }

    // Закрытие файлов
    fclose(fileA);
    fclose(fileB);

    printf("Программа успешно завершила работу. Результат записан в файл fB.txt\n");

    return 0;
}
