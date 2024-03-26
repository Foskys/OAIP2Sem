#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Client
{
    char FIO[50];
    char type[15];
    int number;
    double amount;
    char date[11];
};

void Input(Client* C)
{
    cout << "enter FIO" << endl;
    cin >> C->FIO;
    cout << "enter type of account" << endl;
    cin >> C->type;
    cout << "enter number of account" << endl;
    cin >> C->number;
    cout << "enter amount of account" << endl;
    cin >> C->amount;
    cout << "enter date of last change" << endl;
    cin >> C->date;
}

void Ouput(Client* C)
{
    cout << "FIO: " << C->FIO << endl;
    cout << "type of account: " << C->type << endl;
    cout << "number of account: " << C->number << endl;
    cout << "amount of account: " << C->amount << endl;
    cout << "date of last change: " << C->date << endl;
}

void Write(Client* C)
{
    ofstream file("table.txt", ios::out | ios::app);
    file << C->FIO << " " << C->type << " " << C->number << " " << C->amount << " " << C->date << endl;
    file.close();
}

void Read()
{
    char buf[255];
    ifstream file("table.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file.getline(buf, 255);
            cout << buf << endl;
        }
    }
    file.close();
}

void Search(int* number)
{
    char buf[255];
    ifstream file("table.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file.getline(buf, 255);
            if (strstr(buf, "123") != NULL)
            {
                cout << buf << endl;
            }
        }
    }
    file.close();
}


int main()
{
    setlocale(LC_ALL, "rus");
    Client C;
    Input(&C);
    Ouput(&C);
    Write(&C);
    Read();
    system("pause");
    return 0;
}