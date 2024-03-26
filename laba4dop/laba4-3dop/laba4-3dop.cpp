#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct SanatoriumInfo {
    string name; //структура "Имя"
    string location; //структура "Местоположение"
    string profile; //структура "Профиль"
    int tickets; //структура "Билеты"
};

int main()
{
    vector<SanatoriumInfo> sanatoriums; //вектор sanatoriums содержит структуру SanatoriumInfo
    map<string, vector<SanatoriumInfo>> sanatoriumsByProfile; //map sanatoriumsByProfile содержит string и вектор SanatoriumInfo
    int n; //определение n
    cout << "Enter the number of sanatoriums: "; //пользователь вводит количество санаториев
    cin >> n;
    cout << "Enter the information about the sanatoriums:" << endl; //пользователь вводит информацию о санаториях
    for (int i = 0; i < n; i++) //цикл ввода данных
    {
        SanatoriumInfo sanatorium; //структура SanatoriumInfo
        cout << "Name: "; //выводится "Имя"
        cin >> sanatorium.name; //вводится значение
        cout << "Location: "; //выводится "Местоположение"
        cin >> sanatorium.location; //вводится значение
        cout << "Profile: "; //выводится "Профиль"
        cin >> sanatorium.profile; //вводится значение
        cout << "Tickets: "; //выводится "Билеты"
        cin >> sanatorium.tickets; //вводится значение
        sanatoriums.push_back(sanatorium); //добавление санатория в вектор
        sanatoriumsByProfile[sanatorium.profile].push_back(sanatorium); //добавление санатория в map
    }

    cout << "Table of sanatoriums:" << endl; //выводится "Таблица санаториев:"
    cout << "Name\tLocation\tProfile\tTickets\n"; //выводятся заголовки столбцов
    for (auto& sanatorium : sanatoriums) //цикл перебирает каждый элемент sanatoriums
    {
        cout << sanatorium.name << "\t" << sanatorium.location << "\t" << sanatorium.profile << "\t" << sanatorium.tickets << endl; //выводятся данные о санатории
    }

    cout << "Table of sanatoriums grouped by profile:" << endl; //выводится "Таблица санаториев, сгруппированных по профилю:"
    cout << "Name\tLocation\tTickets\n"; //выводятся заголовки столбцов
    for (auto& sanatoriumsGroup : sanatoriumsByProfile) //цикл перебирает каждую группу санаториев по профилю
    {
        for (auto& sanatorium : sanatoriumsGroup.second) //цикл перебирает каждый элемент группы
        {
            cout << sanatorium.name << "\t" << sanatorium.location << "\t" << sanatorium.tickets << endl; //выводятся данные о санатории
        }
    }

    // Запрашиваем у пользователя профиль для поиска
    string profile;
    cout << "Enter the profile to search: ";
    cin >> profile;
    // Проверяем, есть ли в карте санатории с таким профилем
    if (sanatoriumsByProfile.find(profile) != sanatoriumsByProfile.end())
    {
        // Если есть, выводим информацию о найденных санаториях
        cout << "Sanatoriums with profile " << profile << " found:" << endl;
        cout << "Name\tLocation\tTickets\n";
        for (auto& sanatorium : sanatoriumsByProfile[profile])
        {
            cout << sanatorium.name << "\t" << sanatorium.location << "\t" << sanatorium.tickets << endl;
        }
    }
    else
    {
        // Если не нашли, сообщаем об этом
        cout << "Sanatoriums with profile " << profile << " not found." << endl;
    }

    return 0;
}
