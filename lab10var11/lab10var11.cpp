#include <iostream>
using namespace std;
double Pn(double x, int n)
{
    if (n == 0) return 0;
    if (n == 1) return 2 * x;
    if (n > 1) return (((2 * n) / (n - 1)) * Pn(x, n - 1) - (((n - 1) / (2 * n)) * Pn(x, n - 2)));
}
int main()
{
    setlocale(LC_CTYPE, "rus");
    int x, n;
    cout << Pn(2, 2) << endl;
    return 0;
}
