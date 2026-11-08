#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    try {
        if (num2 == 0) {
            throw 505;
        }
        cout << num1 / num2;
    } catch (int mynum) {
        cout << "Error: Division by zero" << endl;
    }
    return 0;
}
