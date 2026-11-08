#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Employee {
  protected:
    string name;

  private:
    int id;

  public:
    int getEmployeeID() { return id; }
    void setEmployeeID(int emp_id) { id = emp_id; }
};

class PermenantEmployee : public Employee {
  protected:
    float basicSalary = 0;
};

class Payroll : public PermenantEmployee {
  public:
    Payroll(string n, int emp_id, int bs_salary) {
        name = n;
        setEmployeeID(emp_id);
        basicSalary = bs_salary;

        cout << "Name: " << name << endl;
        cout << "ID: " << getEmployeeID() << endl;
        cout << "Base Salary: " << basicSalary << endl;
        cout << "Final Salary: " << calculateSalary() << endl;
    }

    float calculateSalary() {
        int final_salary =
            basicSalary + (basicSalary * 20 / 100) + (basicSalary * 10 / 100);
        cout << fixed << setprecision(2);
        return float(final_salary);
    }
};

int main() {
    string name;
    getline(cin, name);

    int employeeID;
    cin >> employeeID;

    int baseSalary;
    cin >> baseSalary;

    Payroll employee1(name, employeeID, baseSalary);

    return 0;
}