//Подключаем библиотеки
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//Создаем структуру TRAIN, которая будет содержать информацию о поездах
struct TRAIN {
    string destination;
    int trainNumber;
    string departureTime;
};

//Основная функция
int main() {
    const int N = 3;
    TRAIN trains[N];
    // Ввод данных в массив
    for (int i = 0; i < N; i++) {
        cout << "Enter destination for train #" << i + 1 << ": ";
        cin >> trains[i].destination;
        cout << "Enter train number for train #" << i + 1 << ": ";
        cin >> trains[i].trainNumber;
        cout << "Enter departure time for train #" << i + 1 << ": ";
        cin >> trains[i].departureTime;
    }

    // Сортируем массив по пункту назначения в алфавитном порядке
    sort(trains, trains + N, [](const TRAIN& a, const TRAIN& b) {
        return a.destination < b.destination;
        });

    // Вводим время для сравнения
    string time;
    cout << "Enter time to compare: ";
    cin >> time;

    // Выводим информацию о поездах, отправляющихся после введенного времени
    bool anyTrains = false;
    for (int i = 0; i < N; i++) {
        if (trains[i].departureTime > time) {
            cout << "Train #" << trains[i].trainNumber << " to " << trains[i].destination << " departs at " << trains[i].departureTime << endl;
            anyTrains = true;
        }
    }

    // Если таких поездов не найдено, выводим сообщение
    if (!anyTrains) {
        cout << "No trains found departing after the entered time." << endl;
    }

    return 0;
}
