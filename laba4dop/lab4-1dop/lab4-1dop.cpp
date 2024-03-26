#include <iostream>
#include <vector>
using namespace std;

struct ExamResult {
    string fullName;
    int numExams;
    vector<int> grades;
};

bool allExamsPassedWithGrades4And5(const ExamResult& result) {
    for (int grade : result.grades) {
        if (grade < 4) {
            return false;
        }
    }
    return true;
}

float calculateSuccessRate(const vector<ExamResult>& results) {
    int passedCount = 0;
    for (const ExamResult& result : results) {
        if (allExamsPassedWithGrades4And5(result)) {
            passedCount++;
        }
    }
    return static_cast<float>(passedCount) / results.size() * 100;
}

int main() {
    setlocale(LC_CTYPE, "Rus");
    vector<ExamResult> examResults = {
        {"Иванов Иван Иванович", 9, {1, 7, 9}},
        {"Петров Петр Петрович", 7, {8, 10}},
        {"Сидоров Сидор Сидорович", 5, {10, 3, 8, 9}},
        {"Алексеев Алексей Алексеевич", 8, {1}}
    };

    float successRate = calculateSuccessRate(examResults);

    cout << "Успеваемость студентов: " << successRate << "%\n";

    return 0;
}