#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int arr[3];
    float avg;
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    try {
        for (int i = 0; i < 3; i++) {
            if (arr[i] < 0) {
                throw 505;
            } else if (arr[i] > 100) {
                throw 506;
            }
            avg += arr[i];
        }
        cout << "Average: " << fixed << setprecision(2) << avg / 3;
    } catch (const int e) {
        if (e == 505) {
            cout << "Error: Negative marks are not allowed" << endl;
        } else if (e == 506) {
            cout << "Error: Marks cannot exceed 100" << endl;
        }
    }

    return 0;
}

// method - 2

#include <iostream>
#include <stdexcept> // Required for standard exceptions
using namespace std;

int main() {
    int arr[3];
    float avg = 0; // Initialize avg to 0

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    try {
        for (int i = 0; i < 3; i++) {
            if (arr[i] < 0) {
                // Throw an exception type meant for logic/value boundaries
                throw invalid_argument("Error: Negative marks are not allowed");
            } else if (arr[i] > 100) {
                throw out_of_range("Error: Marks cannot exceed 100");
            }
            avg += arr[i];
        }
        cout << "Average: " << avg / 3 << endl;
    }
    // This catches invalid_argument specifically
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    // This catches out_of_range specifically
    catch (const out_of_range &e) {
        cout << e.what() << endl;
    }

    return 0;
}
