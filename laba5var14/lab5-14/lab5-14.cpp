#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Перечисление для типа размещения
enum class AccommodationType {
    Lux,
    Single,
    Double,
    Triple,
    Apartment
};

// Структура для даты приезда и отъезда
struct Dates {
    unsigned int arrivalDate : 5; // День (максимальное значение 31)
    unsigned int arrivalMonth : 4; // Месяц (максимальное значение 12)
    unsigned int departureDate : 5; // День (максимальное значение 31)
    unsigned int departureMonth : 4; // Месяц (максимальное значение 12)
};

// Структура для клиента
struct Client {
    string passportData;
    Dates dates;
    int roomNumber;
    AccommodationType accommodationType;
};

// Функция для ввода данных о клиенте с клавиатуры
Client inputClientData() {
    Client client;
    cout << "Введите паспортные данные: ";
    getline(cin, client.passportData);
    cout << "Введите дату приезда (день месяца): ";
    (cin, client.dates.arrivalDate);
    cout << "Введите месяц приезда: ";
    cin, client.dates.arrivalMonth;
    cout << "Введите дату отъезда (день месяца): ";
    cin, client.dates.departureDate;
    cout << "Введите месяц отъезда: ";
    cin, client.dates.departureMonth;
    cout << "Введите номер комнаты: ";
    cin >> client.roomNumber;
    int type;
    cout << "Выберите тип размещения (0 - Люкс, 1 - Одноместный, 2 - Двухместный, 3 - Трехместный, 4 - Апартаменты): ";
    cin >> type;
    client.accommodationType = static_cast<AccommodationType>(type);
    cin.ignore(); // Очистка буфера ввода
    return client;
}

// Функция для вывода данных о клиенте на экран
void printClientData(const Client& client) {
    cout << "Паспортные данные: " << client.passportData << endl;
    cout << "Дата приезда: " << client.dates.arrivalDate << "/" << client.dates.arrivalMonth << endl;
    cout << "Дата отъезда: " << client.dates.departureDate << "/" << client.dates.departureMonth << endl;
    cout << "Номер комнаты: " << client.roomNumber << endl;
    cout << "Тип размещения: ";
    switch (client.accommodationType) {
    case AccommodationType::Lux:
        cout << "Люкс" << endl;
        break;
    case AccommodationType::Single:
        cout << "Одноместный" << endl;
        break;
    case AccommodationType::Double:
        cout << "Двухместный" << endl;
        break;
    case AccommodationType::Triple:
        cout << "Трехместный" << endl;
        break;
    case AccommodationType::Apartment:
        cout << "Апартаменты" << endl;
        break;
    }
}

// Функция для поиска гостя по дате приезда
vector<Client> searchByArrivalDate(const vector<Client>& clients, int arrivalDate, int arrivalMonth) {
    vector<Client> foundClients;
    for (const auto& client : clients) {
        if (client.dates.arrivalDate == arrivalDate && client.dates.arrivalMonth == arrivalMonth) {
            foundClients.push_back(client);
        }
    }
    return foundClients;
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<Client> clients; // Вектор для хранения клиентов

    // Пример заполнения данных
    clients.push_back({ "AB123456", {10, 2, 15, 2}, 101, AccommodationType::Single });
    clients.push_back({ "CD789012", {12, 2, 18, 2}, 202, AccommodationType::Double });

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить клиента" << endl;
        cout << "2. Вывести всех клиентов" << endl;
        cout << "3. Поиск клиента по дате приезда" << endl;
        cout << "0. Выйти из программы" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера ввода

        switch (choice) {
        case 1: {
            Client newClient = inputClientData();
            clients.push_back(newClient);
            break;
        }
        case 2: {
            cout << "Список клиентов:" << endl;
            for (const auto& client : clients) {
                printClientData(client);
                cout << endl;
            }
            break;
        }
        case 3: {
            int arrivalDate, arrivalMonth;
            cout << "Введите дату приезда для поиска (день месяца): ";
            cin >> arrivalDate;
            cout << "Введите месяц приезда для поиска: ";
            cin >> arrivalMonth;
            cin.ignore(); // Очистка буфера ввода
            vector<Client> foundClients = searchByArrivalDate(clients, arrivalDate, arrivalMonth);
            if (foundClients.empty()) {
                cout << "Клиенты не найдены." << endl;
            }
            else {
                cout << "Найденные клиенты:" << endl;
                for (const auto& client : foundClients) {
                    printClientData(client);
                    cout << endl;
                }
            }
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
