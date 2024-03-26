#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int MAX_CLIENT = 100;
enum { MAX_NAME = 50 };
enum { MAX_NUMBER = 50 };
enum { MAX_DATE = 50 };

struct Date {
    unsigned short Date, Month, Year;
};

enum  Account_Type {
    Short_term, Long_term, Common, Pension
};

struct Client {
    char First_name[MAX_NAME];
    char Second_name[MAX_NAME];
    char Last_name[MAX_NAME];
    Account_Type type;
    char Number[MAX_NUMBER];
    unsigned long Summ;
    Date date;
    Date date_open;
};

void menu();
void Read(Client*&, int&);
void Print(Client*, int);
void Clear(Client*&, int&);
void Search(Client*, int);

int main() {
    Client* client = new Client[MAX_CLIENT];
    int size = 0;
    int choice;
    while (true) {
        menu();
        cin >> choice;
        switch (choice) {
        case 1: {
            Read(client, size);
            break;
        }
        case 2: {
            Print(client, size);
            break;
        }
        case 3: {
            Clear(client, size);
            break;
        }
        case 4: {
            Search(client, size);
            break;
        }
        case 5: {
            delete[] client;
            return 0;
        }
        default: {
            cout << "Enter correct number" << endl;
            break;
        }
        }
    }
    return 0;
}

void menu() {
    cout << "Choose one action:" << endl;
    cout << "1. Add client" << endl;
    cout << "2. Show list" << endl;
    cout << "3. Delete element" << endl;
    cout << "4. Search element" << endl;
    cout << "5. Exit" << endl;
}

void Read(Client*& client, int& size) {
    if (size >= MAX_CLIENT) {
        cout << "Error: Maximum number of clients reached." << endl;
        return;
    }

    cout << "Enter name, surname, patronymic: " << endl;
    cin >> client[size].First_name >> client[size].Second_name >> client[size].Last_name;

    cout << "Enter type of account (0 - Short term, 1 - Long term, 2 - Common, 3 - Pension): " << endl;
    int k;
    cin >> k;
    if (k < 0 || k > 3) {
        cout << "Error: Invalid account type." << endl;
        return;
    }
    client[size].type = static_cast<Account_Type>(k);

    cout << "Enter account number: " << endl;
    cin >> client[size].Number;

    cout << "Enter account sum: " << endl;
    cin >> client[size].Summ;
    if (client[size].Summ < 0) {
        cout << "Error: Invalid account sum." << endl;
        return;
    }

    cout << "Enter date of last change (DD MM YYYY): " << endl;
    cin >> client[size].date.Date >> client[size].date.Month >> client[size].date.Year;

    cout << "Enter date of account open (DD MM YYYY): " << endl;
    cin >> client[size].date_open.Date >> client[size].date_open.Month >> client[size].date_open.Year;

    ++size;
}

void Print(Client* client, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Client: " << endl;
        cout << "Name, Surname, Patronymic: " << client[i].First_name << " " << client[i].Second_name << " " << client[i].Last_name << endl;
        cout << "Account type: ";
        switch (client[i].type) {
        case Short_term:
            cout << "Short term";
            break;
        case Long_term:
            cout << "Long term";
            break;
        case Common:
            cout << "Common";
            break;
        case Pension:
            cout << "Pension";
            break;
        }
        cout << endl;
        cout << "Account number: " << client[i].Number << endl;
        cout << "Account sum: " << client[i].Summ << endl;
        cout << "Date of last change: " << setw(2) << setfill('0') << client[i].date.Date << ".";
        cout << setw(2) << setfill('0') << client[i].date.Month << ".";
        cout << setw(2) << setfill('0') << client[i].date.Year << endl;
        cout << "Date of account open: " << setw(2) << setfill('0') << client[i].date_open.Date << ".";
        cout << setw(2) << setfill('0') << client[i].date_open.Month << ".";
        cout << setw(2) << setfill('0') << client[i].date_open.Year << endl;
    }
}

void Clear(Client*& client, int& size) {
    for (int i = 0; i < size; ++i) {
        if (client[i].Summ < 100) {
            for (int j = i; j < size - 1; ++j) {
                client[j] = client[j + 1];
            }
            --size;
            --i;
        }
    }
}

void Search(Client* client, int size) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (client[i].Summ > 100) {
            cout << "Client found:" << endl;
            cout << "Name, Surname, Patronymic: " << client[i].First_name << " " << client[i].Second_name << " " << client[i].Last_name << endl;
            cout << "Account type: ";
            switch (client[i].type) {
            case Short_term:
                cout << "Short term";
                break;
            case Long_term:
                cout << "Long term";
                break;
            case Common:
                cout << "Common";
                break;
            case Pension:
                cout << "Pension";
                break;
            }
            cout << endl;
            cout << "Account number: " << client[i].Number << endl;
            cout << "Account sum: " << client[i].Summ << endl;
            cout << "Date of last change: " << setw(2) << setfill('0') << client[i].date.Date << ".";
            cout << setw(2) << setfill('0') << client[i].date.Month << ".";
            cout << setw(2) << setfill('0') << client[i].date.Year << endl;
            cout << "Date of account open: " << setw(2) << setfill('0') << client[i].date_open.Date << ".";
            cout << setw(2) << setfill('0') << client[i].date_open.Month << ".";
            cout << setw(2) << setfill('0') << client[i].date_open.Year << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No clients with account sum greater than 100 found." << endl;
    }
}
