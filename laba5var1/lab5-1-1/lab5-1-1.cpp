#include <iostream>
#include <string>
using namespace std;

// Создаем перечисление для определения должности сотрудника 
enum Position {
	Manager,
	Assistant,
	Engineer,
	Analyst,
	Secretary
};

// Создаем структуру сотрудника, содержащую информацию о его имени, образовании, специальности, подразделении, должности, зарплате и дате трудоустройства
struct Employee {
	string name;
	string education;
	string specialty;
	string department;
	Position position;
	double salary;
	int dateOfEmployment; // используем поля битов
};

// Функция для ввода данных о сотруднике
void inputEmployeeData(Employee& e) {
	cout << "Enter employee's name: ";
	cin >> e.name;
	cout << "Enter employee's education: ";
	cin >> e.education;
	cout << "Enter employee's specialty: ";
	cin >> e.specialty;
	cout << "Enter employee's department: ";
	cin >> e.department;
	cout << "Enter employee's position (0 for Manager, 1 for Assistant, 2 for Engineer, 3 for Analyst, 4 for Secretary): ";
	int pos;
	cin >> pos;
	e.position = static_cast<Position>(pos);
	cout << "Enter employee's salary: ";
	cin >> e.salary;
	cout << "Enter employee's date of employment (DDMMYYYY): ";
	cin >> e.dateOfEmployment;
}

// Функция для печати данных о сотруднике
void printEmployeeData(Employee e) {
	cout << "Name: " << e.name << endl;
	cout << "Education: " << e.education << endl;
	cout << "Specialty: " << e.specialty << endl;
	cout << "Department: " << e.department << endl;
	cout << "Position: ";
	switch (e.position) {
	case Manager:
		cout << "Manager" << endl;
		break;
	case Assistant:
		cout << "Assistant" << endl;
		break;
	case Engineer:
		cout << "Engineer" << endl;
		break;
	case Analyst:
		cout << "Analyst" << endl;
		break;
	case Secretary:
		cout << "Secretary" << endl;
		break;
	}
	cout << "Salary: " << e.salary << endl;
	cout << "Date of Employment: " << e.dateOfEmployment << endl;
}

// Функция для удаления данных о сотруднике
void deleteEmployeeData(Employee& e) {
	e.name = "";
	e.education = "";
	e.specialty = "";
	e.department = "";
	e.position = Manager;
	e.salary = 0.0;
	e.dateOfEmployment = 0;
}

// Функция для поиска сотрудника по имени
void searchForEmployee(Employee e[], int size, string name) {
	for (int i = 0; i < size; i++) {
		if (e[i].name == name) {
			cout << "Employee found:" << endl;
			printEmployeeData(e[i]);
			return;
		}
	}
	cout << "Employee not found." << endl;
}

int main() {
	Employee employees[10]; // Массив для хранения данных о сотрудниках
	int currentSize = 0; // Текущий размер массива
	int choice; // Переменная для выбора действия
	while (true) {
		cout << "1. Input employee data" << endl;
		cout << "2. Print employee data" << endl;
		cout << "3. Delete employee data" << endl;
		cout << "4. Search for employee" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			if (currentSize == 10) { // Проверка размера массива
				cout << "Cannot add more employees. Maximum limit reached." << endl;
				break;
			}
			Employee e;
			inputEmployeeData(e); // Ввод данных о сотруднике
			employees[currentSize] = e;
			currentSize++;
			break;
		}
		case 2: {
			for (int i = 0; i < currentSize; i++) { // Печать данных о сотрудниках
				printEmployeeData(employees[i]);
			}
			break;
		}
		case 3: {
			string name;
			cout << "Enter the name of the employee to be deleted: ";
			cin >> name;
			for (int i = 0; i < currentSize; i++) {
				if (employees[i].name == name) {
					deleteEmployeeData(employees[i]); // Удаление данных о сотруднике
					cout << "Employee data deleted." << endl;
					break;
				}
			}
			break;
		}
		case 4: {
			string name;
			cout << "Enter the name of the employee to search for: ";
			cin >> name;
			searchForEmployee(employees, currentSize, name); // Поиск сотрудника по имени
			break;
		}
		case 5: {
			return 0;
		}
		default: {
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
		}
	}
}