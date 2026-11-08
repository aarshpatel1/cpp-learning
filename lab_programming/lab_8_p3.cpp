#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Employee {
  public:
    virtual void calculateSalary() = 0;

    virtual void displayType() { cout << "Employee: General" << endl; }

    virtual ~Employee() { cout << "Employee destructor" << endl; }
};

class PermanentEmployee : public Employee {
  public:
    double basicSalary, bonus;

    PermanentEmployee(const double basicSalary, const double bonus) {
        this->basicSalary = basicSalary;
        this->bonus = bonus;
    }

    void calculateSalary() override {
        cout << "Salary: " << fixed << setprecision(2) << (basicSalary + bonus)
             << endl;
    };

    ~PermanentEmployee() override {
        cout << "PermanentEmployee destructor" << endl;
    }
};

class ContractEmployee : public Employee {
  public:
    double hoursWorked, hourlyRate;

    ContractEmployee(const double hoursWorked, const double hourlyRate) {
        this->hoursWorked = hoursWorked;
        this->hourlyRate = hourlyRate;
    }

    void calculateSalary() override {
        cout << "Salary: " << fixed << setprecision(2)
             << (hoursWorked * hourlyRate) << endl;
    }

    ~ContractEmployee() override {
        cout << "ContractEmployee destructor" << endl;
    }
};

class Intern : public Employee {
  public:
    double stipend, performanceBonus;

    Intern(const double stipend, const double performanceBonus) {
        this->stipend = stipend;
        this->performanceBonus = performanceBonus;
    }

    void calculateSalary() override {
        cout << "Salary: " << fixed << setprecision(2)
             << (stipend + performanceBonus) << endl;
    }

    ~Intern() override { cout << "Intern destructor" << endl; }
};

int main() {
    int n;
    cin >> n;

    vector<Employee *> arr;

    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        double n1, n2;
        cin >> n1;
        cin >> n2;
        if (type == 'P') {
            arr.push_back(new PermanentEmployee(n1, n2));
        } else if (type == 'C') {
            arr.push_back(new ContractEmployee(n1, n2));
        } else if (type == 'I') {
            arr.push_back(new Intern(n1, n2));
        }
    }

    for (Employee *employee : arr) {
        employee->displayType();
        employee->calculateSalary();
    }

    for (const Employee *employee : arr) {
        delete employee;
    }

    return 0;
}
