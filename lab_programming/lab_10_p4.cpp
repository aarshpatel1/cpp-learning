#include <fstream>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Employee {
    string name;
    float salary;
};

int main() {
    int n;
    cin >> n;

    ofstream output_file("employee.txt");

    if (!output_file.is_open()) {
        cout << "Error: could not create or open file";
    }

    unordered_map<string, Employee> employee_dictionary;
    float total = 0, average_salary = 0;
    vector<string> insertion_order;

    for (int i = 0; i < n; i++) {
        string id, name;
        float salary;
        cin >> id >> name >> salary;
        employee_dictionary[id] = {name, salary};
        insertion_order.push_back(id);
        total += salary;
    }

    average_salary = total / n;

    // cout << "Total Salary: " << fixed << setprecision(2) << total << endl;
    // cout << "Average Salary: " << fixed << setprecision(2) << average_salary
    //      << endl;
    // cout << "Employees earning at least average salary:" << endl;
    output_file << "Total Salary: " << fixed << setprecision(2) << total
                << endl;
    output_file << "Average Salary: " << fixed << setprecision(2)
                << average_salary << endl;
    output_file << "Employees earning at least average salary:" << endl;

    for (const string &id : insertion_order) {
        const auto &info = employee_dictionary[id];
        if (info.salary >= average_salary) {
            // cout << id << " " << info.name << " " << info.salary << endl;
            output_file << id << " " << info.name << " " << info.salary << endl;
        }
    }

    output_file.close();

    return 0;
}