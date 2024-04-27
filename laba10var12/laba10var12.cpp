
#include <iostream>
#include <cmath>
using namespace std;

// Рекурсивная функция для вычисления суммы косинусов
double sumCosines(int n, double x) {
    // Базовый случай: когда n = 1, просто возвращаем cos(x)
    if (n == 1)
        return cos(x);
    // Рекурсивный случай: суммируем cos(nx) с результатом для n-1
    return cos(n * x) + sumCosines(n - 1, x);
}

int main() {
    setlocale(LC_ALL, "Rus");
    double x = 0.5; // Значение x
    int n = 5; // Количество слагаемых
    double result = sumCosines(n, x);
    cout << "Сумма косинусов для x=" << x << " и n=" << n << " равна " << result << endl;
    return 0;
}