#include <iostream>
#include <string>
#include <vector>

enum Gender { Male, Female };

struct Citizen {
    std::string name;
    std::string birthdate;
    std::string address;
    Gender gender;
    int birthyear; // Уберем это поле, так как оно не требуется в текущей реализации
};

void inputData(Citizen& c) {
    std::cout << "Enter name:";
    std::cin >> c.name;
    std::cout << "Enter birthdate (dd.mm.yyyy): ";
    std::cin >> c.birthdate;
    std::cout << "Enter address: ";
    std::cin >> c.address;
    std::string g;
    while (true) {
        std::cout << "Enter gender (M/F): ";
        std::cin >> g;
        if (g == "M" || g == "m") {
            c.gender = Male;
            break;
        }
        else if (g == "F" || g == "f") {
            c.gender = Female;
            break;
        }
        else
            std::cout << "Invalid input for gender" << std::endl;
    }
}

void printData(Citizen c) {
    std::cout << "Name: " << c.name << std::endl;
    std::cout << "Birthdate: " << c.birthdate << std::endl;
    std::cout << "Address: " << c.address << std::endl;
    std::cout << "Gender: " << (c.gender == Male ? "Male" : "Female") << std::endl;
}

void deleteData(Citizen& c) {
    c.name = "";
    c.birthdate = "";
    c.address = "";
    c.gender = Male; // Установим пол на мужской, но это не совсем корректно
    // Заметка: в реальном приложении может потребоваться другое поведение
}

std::vector<Citizen> searchByYear(const std::vector<Citizen>& citizens, int year) {
    std::vector<Citizen> results;
    for (const auto& citizen : citizens) {
        if (std::stoi(citizen.birthdate.substr(6, 4)) == year) {
            results.push_back(citizen);
        }
    }
    return results;
}

int main() {
    std::vector<Citizen> citizens;
    int n;
    std::cout << "Enter number of citizens: ";
    std::cin >> n;
    citizens.resize(n);
    for (int i = 0; i < n; i++) {
        inputData(citizens[i]);
    }

    while (true) {
        std::cout << "1. Print data" << std::endl;
        std::cout << "2. Delete data" << std::endl;
        std::cout << "3. Search by birth year" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            for (int i = 0; i < n; i++) {
                printData(citizens[i]);
                std::cout << std::endl;
            }
        }
        else if (choice == 2) {
            int index;
            std::cout << "Enter index of citizen to delete: ";
            std::cin >> index;
            deleteData(citizens[index]);
        }
        else if (choice == 3) {
            int year;
            std::cout << "Enter birth year to search: ";
            std::cin >> year;
            std::vector<Citizen> results = searchByYear(citizens, year);
            if (!results.empty()) {
                std::cout << "Citizens found: " << std::endl;
                for (const auto& result : results) {
                    printData(result);
                }
            }
            else {
                std::cout << "No citizens found." << std::endl;
            }
        }
        else if (choice == 4) {
            break;
        }
    }
    return 0;
}
