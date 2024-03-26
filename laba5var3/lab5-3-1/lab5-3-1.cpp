#include <iostream>
#include <string>
using namespace std;

#define sizeS 30 
#define numSubjects 3

enum Subjects {
    Mathematics = 0,
    History,
    Geography,
    Biology,
    Chemistry,
    Literature,
};

union UPuples
{
    char name[100];
    char numcl[50];
    Subjects lessons[numSubjects];
    int marks;
    char sr_ball;
} pu;

struct Puples
{
    string name;
    string numcl;
    Subjects lessons[numSubjects];
    string marks;
    string sr_ball;
};

struct Class {
    unsigned int classNumber : 4;
    unsigned int classLetter : 5;
};
Puples list_of_puple[sizeS], free_puple;
int current_size_pu = 0;

void new_write();
void del_write();
void out_write();

int main()
{
    setlocale(LC_CTYPE, "Rus");
    int choice = 1;

    while (choice != 0)
    {
        cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить\n(Введите выбор) ";
        cin >> choice;
        switch (choice)
        {
        case(1):
            new_write();
            break;

        case(2):
            del_write();
            break;

        case(3):
            out_write();
            break;

        default:
            break;
        }
    }
    return 0;
}

void new_write()
{
    if (current_size_pu < sizeS)
    {
        cout << "\n Запись №" << current_size_pu + 1 << ": ";
        cout << "\n Введите Ф.И.О.: ";
        cin >> pu.name;
        list_of_puple[current_size_pu].name = pu.name;

        Class classInfo;
        int tempNumber;
        cout << "\n Введите номер класса: ";
        cin >> tempNumber;
        classInfo.classNumber = tempNumber;

        cout << "\n Введите букву класса: ";
        char letter;
        cin >> letter;
        classInfo.classLetter = letter;
        cout << "\n и получается: ";
        list_of_puple[current_size_pu].numcl = to_string(classInfo.classNumber) + static_cast<char>(classInfo.classLetter);



        cin >> pu.numcl;
        list_of_puple[current_size_pu].numcl = pu.numcl;
        for (int j = 0; j < numSubjects; j++) {
            cout << "\n Введите предметы(0 - Математика, 1 - История, 2 - География, 3 - Биология, 4 - Химия, 5 - Литература) ";
            int subject;
            cin >> subject;
            list_of_puple[current_size_pu].lessons[j] = static_cast<Subjects>(subject);
        }
        cout << "\n Введите оценки по этим предметам: ";
        cin >> pu.marks;
        list_of_puple[current_size_pu].marks = pu.marks;
        cout << "\n Введите средний балл: ";
        cin >> pu.sr_ball;
        list_of_puple[current_size_pu].sr_ball = pu.sr_ball;
        current_size_pu++;
    }
    else
    {
        cout << " Введено максимальное кол-во строк" << endl;
    }
}

void del_write()
{
    int d;
    cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
    cin >> d;
    if (d == -2)
    {
        for (int i = 0; i < sizeS; i++)
        {
            list_of_puple[i] = free_puple;
        }
        current_size_pu = 0;
    }
    else
    {
        for (int i = d - 1; i < current_size_pu; i++)
        {
            list_of_puple[i] = list_of_puple[i + 1];
        }
        current_size_pu--;
    }
}

void out_write()
{
    string name;
    cout << " Введите Ф.И.О. для поиска записи(для вывода всех записей введите -1): ";
    cin >> name;
    if (name == "-1")
    {

        for (int i = 0; i < current_size_pu; i++)
        {
            cout << "Запись №";
            cout << i + 1;
            cout << ": Ф.И.О. - ";
            cout << list_of_puple[i].name;
            cout << " | Класс - ";
            cout << list_of_puple[i].numcl;
            cout << " | Предметы - ";
            for (int j = 0; j < numSubjects; j++) {
                switch (list_of_puple[i].lessons[j]) {
                case Mathematics:
                    cout << "Математика,";
                    break;
                case History:
                    cout << "История,";
                    break;
                case Geography:
                    cout << "География,";
                    break;
                case Biology:
                    cout << "Биология,";
                    break;
                case Chemistry:
                    cout << "Химия,";
                    break;
                case Literature:
                    cout << "Литература,";
                    break;

                }
            }
            cout << " | Оценки - ";
            cout << list_of_puple[i].marks;
            cout << " | Средний балл - ";
            cout << list_of_puple[i].sr_ball;
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < current_size_pu; i++)
        {
            if (list_of_puple[i].name == name)
            {
                cout << "Запись №";
                cout << i + 1;
                cout << ": Ф.И.О. - ";
                cout << list_of_puple[i].name;
                cout << " | Класс - ";
                cout << list_of_puple[i].numcl;
                cout << " | Предметы - ";
                for (int j = 0; j < numSubjects; j++) {
                    switch (list_of_puple[i].lessons[j]) {
                    case Mathematics:
                        cout << "Математика";
                        break;
                    case History:
                        cout << "История";
                        break;
                    case Geography:
                        cout << "География";
                        break;
                    case Biology:
                        cout << "Биология";
                        break;
                    case Chemistry:
                        cout << "Химия";
                        break;
                    case Literature:
                        cout << "Литература";
                        break;
                    }
                }
                cout << " | Оценки - ";
                cout << list_of_puple[i].marks;
                cout << " | Средний балл - ";
                cout << list_of_puple[i].sr_ball;
                cout << endl;
            }
        }
    }
}
