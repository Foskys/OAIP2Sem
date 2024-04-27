#include <iostream>
using namespace std;

double f(double x, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    else {
        return (x * x / n / (n - 1)) * f(x, n - 2);
    }
}

int main() {
    setlocale(LC_ALL,"rus");
    double x;
    int n;

    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите значение n: ";
    cin >> n;

    double result = f(x, n);
    cout << "Результат вычисления: " << result << endl;

    return 0;
}
