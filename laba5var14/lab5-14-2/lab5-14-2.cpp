#include <iostream>
#include <fstream>
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
    unsigned int arrivalDate;
    unsigned int arrivalMonth;
    unsigned int departureDate;
    unsigned int departureMonth;
};

// Структура для клиента
struct Client {
    string passportData;
    string lastName;
    int roomNumber;
    AccommodationType accommodationType;
    Dates dates;
};

// Функция для ввода данных о клиенте с клавиатуры
Client inputClientData() {
    Client client;
    cout << "Введите паспортные данные: ";
    cin >> client.passportData;
    cout << "Введите фамилию: ";
    cin >> client.lastName;
    cout << "Введите дату приезда (день месяца): ";
    cin >> client.dates.arrivalDate;
    cout << "Введите месяц приезда: ";
    cin >> client.dates.arrivalMonth;
    cout << "Введите дату отъезда (день месяца): ";
    cin >> client.dates.departureDate;
    cout << "Введите месяц отъезда: ";
    cin >> client.dates.departureMonth;
    cout << "Введите номер комнаты: ";
    cin >> client.roomNumber;
    int type;
    cout << "Выберите тип размещения (0 - Люкс, 1 - Одноместный, 2 - Двухместный, 3 - Трехместный, 4 - Апартаменты): ";
    cin >> type;
    client.accommodationType = static_cast<AccommodationType>(type);
    return client;
}

// Функция для записи данных о клиенте в файл
void writeClientDataToFile(const Client& client, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << client.passportData << " " << client.lastName << " "
            << client.dates.arrivalDate << " " << client.dates.arrivalMonth << " "
            << client.dates.departureDate << " " << client.dates.departureMonth << " "
            << client.roomNumber << " " << static_cast<int>(client.accommodationType) << endl;
        file.close();
        cout << "Данные успешно записаны в файл." << endl;
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
}

// Функция для чтения данных о клиенте из файла
void readClientDataFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string passportData, lastName;
        int arrivalDate, arrivalMonth, departureDate, departureMonth, roomNumber;
        int accommodationTypeInt;
        AccommodationType accommodationType;
        while (file >> passportData >> lastName >> arrivalDate >> arrivalMonth >> departureDate >> departureMonth >> roomNumber >> accommodationTypeInt) {
            accommodationType = static_cast<AccommodationType>(accommodationTypeInt);
            cout << "Паспортные данные: " << passportData << endl;
            cout << "Фамилия: " << lastName << endl;
            cout << "Дата приезда: " << arrivalDate << "/" << arrivalMonth << endl;
            cout << "Дата отъезда: " << departureDate << "/" << departureMonth << endl;
            cout << "Номер комнаты: " << roomNumber << endl;
            cout << "Тип размещения: " << accommodationTypeInt << endl;
            cout << endl;
        }
        file.close();
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
}

// Функция для поиска клиента по фамилии в файле
void searchClientByLastName(const string& filename, const string& lastName) {
    ifstream file(filename);
    if (file.is_open()) {
        string passportData, fileLastName;
        int arrivalDate, arrivalMonth, departureDate, departureMonth, roomNumber;
        int accommodationTypeInt;
        AccommodationType accommodationType;
        bool found = false;
        while (file >> passportData >> fileLastName >> arrivalDate >> arrivalMonth >> departureDate >> departureMonth >> roomNumber >> accommodationTypeInt) {
            accommodationType = static_cast<AccommodationType>(accommodationTypeInt);
            if (fileLastName == lastName) {
                found = true;
                cout << "Паспортные данные: " << passportData << endl;
                cout << "Фамилия: " << fileLastName << endl;
                cout << "Дата приезда: " << arrivalDate << "/" << arrivalMonth << endl;
                cout << "Дата отъезда: " << departureDate << "/" << departureMonth << endl;
                cout << "Номер комнаты: " << roomNumber << endl;
                cout << "Тип размещения: " << accommodationTypeInt << endl;
                cout << endl;
            }
        }
        if (!found) {
            cout << "Клиент с фамилией '" << lastName << "' не найден." << endl;
        }
        file.close();
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
}

int main() {
    setlocale(LC_ALL,"rus");
    string filename = "clients.txt";

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить клиента" << endl;
        cout << "2. Вывести всех клиентов" << endl;
        cout << "3. Поиск клиента по фамилии" << endl;
        cout << "0. Выйти из программы" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Client newClient = inputClientData();
            writeClientDataToFile(newClient, filename);
            break;
        }
        case 2: {
            cout << "Список клиентов:" << endl;
            readClientDataFromFile(filename);
            break;
        }
        case 3: {
            string lastName;
            cout << "Введите фамилию для поиска: ";
            cin >> lastName;
            searchClientByLastName(filename, lastName);
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
