
#include "json.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;

// Function to display JSON data recursively
void displayJSON(const json &data, int indent = 0) {
    string space(indent, ' ');

    if (data.is_object()) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            cout << space << it.key() << " : ";

            if (it.value().is_structured()) {
                cout << endl;
                displayJSON(it.value(), indent + 4);
            } else {
                cout << it.value() << endl;
            }
        }
    } else if (data.is_array()) {
        int index = 0;

        for (const auto &item : data) {
            cout << space << "[" << index++ << "] : ";

            if (item.is_structured()) {
                cout << endl;
                displayJSON(item, indent + 4);
            } else {
                cout << item << endl;
            }
        }
    } else {
        cout << space << data << endl;
    }
}

int main(int argc, char *argv[]) {
    string filename;

    // Get JSON file path
    if (argc >= 2) {
        filename = argv[1];
    } else {
        cout << "Enter JSON file name/path: ";
        getline(cin, filename);
    }

    // Open JSON file
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    try {
        json data;

        // Read and parse JSON data
        file >> data;

        cout << "\nJSON File Data:\n";
        cout << "------------------------\n";

        displayJSON(data);

        cout << "------------------------\n";
    } catch (const json::parse_error &e) {
        cerr << "Error: Invalid JSON format!" << endl;
        cerr << "Details: " << e.what() << endl;
        return 1;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    file.close();

    return 0;
}
