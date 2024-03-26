#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_STRING_LENGTH = 11; // Увеличил длину строк на 1 для учета нуль-терминатора
union train {

};
struct Train {
    char number[MAX_STRING_LENGTH];
    char dest[MAX_STRING_LENGTH];
    char days[MAX_STRING_LENGTH];
    char arrive[MAX_STRING_LENGTH];
    char depart[MAX_STRING_LENGTH];
};

Train read_enter() {
    cout << "\nEnter train number: ";
    Train t;
    cin.ignore(); // Очищаем буфер после предыдущего ввода
    cin.getline(t.number, MAX_STRING_LENGTH);
    cout << "Enter train destination: ";
    cin.getline(t.dest, MAX_STRING_LENGTH);
    cout << "Enter train days: ";
    cin.getline(t.days, MAX_STRING_LENGTH);
    cout << "Enter train arrive time: ";
    cin.getline(t.arrive, MAX_STRING_LENGTH);
    cout << "Enter train depart time: ";
    cin.getline(t.depart, MAX_STRING_LENGTH);
    cout << endl;
    return t;
}

void print(Train& t) {
    cout << "Train number: " << t.number << endl;
    cout << "Train destination: " << t.dest << endl;
    cout << "Train days: " << t.days << endl;
    cout << "Train arrive time: " << t.arrive << endl;
    cout << "Train depart time: " << t.depart << endl;
}

void write(Train& t) {
    ofstream fout("train.txt", ios::app);
    fout << t.number << " " << t.dest << " " << t.days << " " << t.arrive << " " << t.depart << endl;
    fout.close();
}

int read() {
    ifstream fin("train.txt");
    Train buf;
    int counter = 0;
    while (fin >> buf.number >> buf.dest >> buf.days >> buf.arrive >> buf.depart) {
        print(buf);
        cout << endl;
        counter++;
    }
    fin.close();
    return counter;
}

void find(const char* dest) {
    ifstream fin("train.txt");
    Train buf;
    int counter = 0;
    while (fin >> buf.number >> buf.dest >> buf.days >> buf.arrive >> buf.depart) {
        if (strcmp(dest, buf.dest) == 0) {
            counter++;
            print(buf);
            cout << endl;
        }
    }
    fin.close();
    if (counter == 0)
        cout << "There is no such train!" << endl;
}

int main() {
    setlocale(0, "rus");
    int choice;
    char dest[MAX_STRING_LENGTH];

    while (true) {
        cout << "-------------------------------------------------------------" << endl;
        cout << "1) Add train" << endl;
        cout << "2) Show train list" << endl;
        cout << "3) Find train" << endl;
        cout << "0) Exit" << endl;
        cout << "-------------------------------------------------------------\n" << endl;

        cin >> choice;
        cin.ignore(); // Очищаем буфер после ввода числа выбора

        switch (choice) {
        case 0:
            return 0;
        case 1: {
            Train t = read_enter();
            write(t);
            break;
        }
        case 2:
            read();
            break;
        case 3: {
            cout << "Enter train destination: ";
            cin.getline(dest, MAX_STRING_LENGTH);
            find(dest);
            break;
        }
        default:
            cout << "Wrong choice!" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}
