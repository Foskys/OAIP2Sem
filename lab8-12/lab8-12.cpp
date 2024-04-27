#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Country {
    string name;
    string capital;
    int population;
    double area;
    string president;
};

const int MAX_COUNTRIES = 100;
Country countries[MAX_COUNTRIES];
int numCountries = 0;

void addCountry() {
    if (numCountries == MAX_COUNTRIES) {
        cout << "Максимальное количество государств достигнуто." << endl;
        return;
    }

    Country newCountry;
    cout << "Введите название государства: ";
    getline(cin, newCountry.name);
    cout << "Введите столицу государства: ";
    getline(cin, newCountry.capital);
    cout << "Введите численность населения: ";
    cin >> newCountry.population;
    cout << "Введите площадь государства: ";
    cin >> newCountry.area;
    cin.ignore(); // Очистка буфера ввода
    cout << "Введите фамилию президента: ";
    getline(cin, newCountry.president);

    countries[numCountries] = newCountry;
    numCountries++;

    cout << "Государство успешно добавлено." << endl;
}

void printCountries() {
    if (numCountries == 0) {
        cout << "Нет доступных государств." << endl;
        return;
    }

    cout << "Список государств:" << endl;
    for (int i = 0; i < numCountries; i++) {
        cout << "Государство: " << countries[i].name << endl;
        cout << "Столица: " << countries[i].capital << endl;
        cout << "Численность населения: " << countries[i].population << endl;
        cout << "Площадь: " << countries[i].area << endl;
        cout << "Фамилия президента: " << countries[i].president << endl;
        cout << "--------------------------------------" << endl;
    }
}

void deleteCountry() {
    if (numCountries == 0) {
        cout << "Нет доступных государств." << endl;
        return;
    }

    string countryName;
    cout << "Введите название государства для удаления: ";
    getline(cin, countryName);

    bool found = false;
    for (int i = 0; i < numCountries; i++) {
        if (countries[i].name == countryName) {
            for (int j = i; j < numCountries - 1; j++) {
                countries[j] = countries[j + 1];
            }
            numCountries--;
            found = true;
            cout << "Государство успешно удалено." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Государство не найдено." << endl;
    }
}

void searchCountry() {
    if (numCountries == 0) {
        cout << "Нет доступных государств." << endl;
        return;
    }

    string countryName;
    cout << "Введите название государства для поиска: ";
    getline(cin, countryName);

    bool found = false;
    for (int i = 0; i < numCountries; i++) {
        if (countries[i].name == countryName) {
            cout << "Государство: " << countries[i].name << endl;
            cout << "Столица: " << countries[i].capital << endl;
            cout << "Численность населения: " << countries[i].population << endl;
            cout << "Площадь: " << countries[i].area << endl;
            cout << "Фамилия президента: " << countries[i].president << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Государство не найдено." << endl;
    }
}

void writeToFile() {
    if (numCountries == 0) {
        cout << "Нет доступных государств." << endl;
        return;
    }

    string fileName;
    cout << "Введите имя файла для записи: ";
    getline(cin, fileName);

    ofstream outputFile(fileName);
    if (!outputFile) {
        cout << "Не удалось открыть файл для записи." << endl;
        return;
    }

    for (int i = 0; i < numCountries; i++) {
        outputFile << "Государство: " << countries[i].name << endl;
        outputFile << "Столица: " << countries[i].capital << endl;
        outputFile << "Численность населения: " << countries[i].population << endl;
        outputFile << "Площадь: " << countries[i].area << endl;
        outputFile << "Фамилия президента: " << countries[i].president << endl;
        outputFile << "--------------------------------------" << endl;
    }

    outputFile.close();

    cout << "Данные успешно записаны в файл." << endl;
}

void readFromFile() {
    string fileName;
    cout << "Введите имя файла для чтения: ";
    getline(cin, fileName);

    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Не удалось открыть файл для чтения." << endl;
        return;
    }

    numCountries = 0; // Сброс количества государств

    while (!inputFile.eof()) {
        getline(inputFile, countries[numCountries].name);
        getline(inputFile, countries[numCountries].capital);
        inputFile >> countries[numCountries].population;
        inputFile >> countries[numCountries].area;
        inputFile.ignore(); // Очистка буфера ввода
        getline(inputFile, countries[numCountries].president);

        numCountries++;
    }

    inputFile.close();

    cout << "Данные успешно прочитаны из файла." << endl;
}

void displayMenu() {
    cout << "-----------------------" << endl;
    cout << "Меню:" << endl;
    cout << "1. Добавить государство" << endl;
    cout << "2. Вывести список государств" << endl;
    cout << "3. Удалить государство" << endl;
    cout << "4. Поиск информации" << endl;
    cout << "5. Запись информации в файл" << endl;
    cout << "6. Чтение данных из файла" << endl;
    cout << "0. Выход" << endl;
    cout << "-----------------------" << endl;
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Очистка буфера ввода

        switch (choice) {
        case 1:
            addCountry();
            break;
        case 2:
            printCountries();
            break;
        case 3:
            deleteCountry();
            break;
        case 4:
            searchCountry();
            break;
        case 5:
            writeToFile();
            break;
        case 6:
            readFromFile();
            break;
        case 0:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Неверная опция. Попробуйте еще раз." << endl;
            break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}