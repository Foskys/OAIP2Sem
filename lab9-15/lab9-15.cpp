#include <iostream>
#include <fstream>
#include <cstring> // Для функции strcmp и strcpy_s
#include <cstdlib> // Для функции exit
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address {
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};

int menu() {
    int c;
    cout << endl;
    cout << "1. Ввод имени" << endl;
    cout << "2. Удаление имени" << endl;
    cout << "3. Вывод на экран" << endl;
    cout << "4. Поиск" << endl;
    cout << "5. Запись в файл" << endl;
    cout << "6. Считывание из файла" << endl;
    cout << "7. Выход" << endl;
    cout << endl;
    cout << "Ваш выбор: ";
    cin >> c;
    cout << endl;
    return c;
}

void insert(Address* e, Address** phead, Address** plast) {
    if (*plast == nullptr) {
        *phead = e;
        *plast = e;
    }
    else {
        (*plast)->next = e;
        e->prev = *plast;
        *plast = e;
    }
}

Address* setElement() {
    Address* temp = new Address();
    if (!temp) {
        cerr << "Ошибка выделения памяти" << endl;
        return nullptr;
    }
    cout << "Введите имя: ";
    cin.ignore();
    cin.getline(temp->name, NAME_SIZE);
    cout << "Введите город: ";
    cin.getline(temp->city, CITY_SIZE);
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void outputList(Address* phead) {
    Address* t = phead;
    while (t != nullptr) {
        cout << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    cout << endl;
}

void find(const char name[NAME_SIZE], Address* phead) {
    Address* t = phead;
    while (t != nullptr) {
        if (strcmp(name, t->name) == 0) {
            cout << t->name << ' ' << t->city << endl;
            return;
        }
        t = t->next;
    }
    cerr << "Имя не найдено" << endl;
}

void delet(const char name[NAME_SIZE], Address** phead, Address** plast) {
    Address* t = *phead;
    while (t != nullptr) {
        if (strcmp(name, t->name) == 0) {
            if (t->prev != nullptr)
                t->prev->next = t->next;
            else
                *phead = t->next;
            if (t->next != nullptr)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
            delete t;
            cout << "Элемент удален" << endl;
            return;
        }
        t = t->next;
    }
    cerr << "Имя не найдено" << endl;
}

void writeToFile(Address* phead) {
    ofstream file("mlist.txt");
    if (!file) {
        cerr << "Ошибка открытия файла" << endl;
        return;
    }
    cout << "Сохранение в файл" << endl;
    Address* t = phead;
    while (t != nullptr) {
        file << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    file.close();
}

void readFromFile(Address** phead, Address** plast) {
    ifstream file("mlist.txt");
    if (!file) {
        cerr << "Ошибка открытия файла" << endl;
        return;
    }
    cout << "Загрузка из файла" << endl;
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    while (file >> name >> city) {
        Address* newNode = new Address();
        if (!newNode) {
            cerr << "Ошибка выделения памяти" << endl;
            return;
        }
        strcpy_s(newNode->name, NAME_SIZE, name);
        strcpy_s(newNode->city, CITY_SIZE, city);
        newNode->next = nullptr;
        insert(newNode, phead, plast);
    }
    file.close();
}

int main() {
    Address* head = nullptr;
    Address* last = nullptr;
    setlocale(LC_CTYPE, "Rus");

    while (true) {
        switch (menu()) {
        case 1:
            insert(setElement(), &head, &last);
            break;
        case 2: {
            char dname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.ignore();
            cin.getline(dname, NAME_SIZE);
            delet(dname, &head, &last);
            break;
        }
        case 3:
            outputList(head);
            break;
        case 4: {
            char fname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.ignore();
            cin.getline(fname, NAME_SIZE);
            find(fname, head);
            break;
        }
        case 5:
            writeToFile(head);
            break;
        case 6:
            readFromFile(&head, &last);
            break;
        case 7:
            exit(0);
        default:
            exit(1);
        }
    }
    return 0;
}
