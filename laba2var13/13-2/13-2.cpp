#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_CTYPE, "rus");
    std::ifstream fileF("F1.txt");
    std::ofstream fileG("F2.txt");

    int K;
    std::cout << "Введите число K: ";
    std::cin >> K;

    int num;
    while (fileF >> num) {
        if (num % K == 0) {
            fileG << num << std::endl;
        }
    }

    fileF.close();
    fileG.close();

    return 0;
}