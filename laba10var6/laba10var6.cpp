#include <iostream>
using namespace std;

int A(int m, int n)
{
    if (m == 0) return n + 1;
    if (m > 0) return A(m - 1, n);
    if (m > 0 && n > 0) return A(m - 1, A(m, n - 1));

    if (m < 0 && n < 0)
    {
        cout << "нет" << endl;
        return 0;
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    cout << "Введите m, n: ";
    cin >> m >> n;
    cout << A(m, n);
    return 0;
}