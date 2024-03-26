#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Applicant {
    std::string universityName;
    std::string address;
    std::vector<std::string> specialties;
    std::vector<int> lastYearCompetition;
    std::vector<int> tuitionFee;
};

void inputApplicantData(Applicant& applicant) {
    std::cout << "Enter University Name: ";
    std::cin >> applicant.universityName;

    std::cout << "Enter Address: ";
    std::cin >> applicant.address;

    int numSpecialties;
    std::cout << "Enter the number of Specialties: ";
    std::cin >> numSpecialties;

    for (int i = 0; i < numSpecialties; ++i) {
        std::string specialty;
        int competition, fee;

        std::cout << "Enter Specialty: ";
        std::cin >> specialty;
        applicant.specialties.push_back(specialty);

        std::cout << "Enter Last Year Competition: ";
        std::cin >> competition;
        applicant.lastYearCompetition.push_back(competition);

        std::cout << "Enter Tuition Fee: ";
        std::cin >> fee;
        applicant.tuitionFee.push_back(fee);
    }
}

void printApplicantData(const Applicant& applicant) {
    // Тело функции остается без изменений
}

void deleteApplicant(std::vector<Applicant>& applicants, int index) {
    // Тело функции остается без изменений
}

void searchBySpecialty(const std::vector<Applicant>& applicants, const std::string& specialty) {
    for (const auto& applicant : applicants) {
        for (int i = 0; i < applicant.specialties.size(); ++i) {
            if (applicant.specialties[i] == specialty) {
                printApplicantData(applicant);
            }
        }
    }
}

void writeToFile(const std::vector<Applicant>& applicants, const std::string& filename) {
    // Тело функции остается без изменений
}

void readFromFile(std::vector<Applicant>& applicants, const std::string& filename) {
    // Тело функции остается без изменений
}

int main() {
    std::vector<Applicant> applicants;

    Applicant newApplicant;
    inputApplicantData(newApplicant);
    applicants.push_back(newApplicant);

    printApplicantData(applicants[0]);

    deleteApplicant(applicants, 0);

    searchBySpecialty(applicants, "Computer Science");

    writeToFile(applicants, "applicants.txt");

    readFromFile(applicants, "applicants.txt");

    return 0;
}
