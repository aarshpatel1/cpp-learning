#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;

// function for displaying JSON data
void displayJSON(const json &data, int indent = 0) {
    string space(indent, ' ');

    /*  Check if the JSON data is an object and loop through each key-value
       pair. Print the key and recursively display nested objects or arrays.
        Otherwise, print the value directly. */
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

int main(int argc, char const *argv[]) {
    // if number of arguments are less than 2 than file name must be missing
    if (argc < 2) {
        cout << "missing file name in arguments" << endl;
        return 1;
    }

    string filename = argv[1];

    ifstream file(filename);

    // error handling if file did not open
    if (!file.is_open()) {
        cout << "file could not open" << endl;
        return 1;
    }

    try {
        json data;

        // reading and parsing JSON data
        file >> data;

        cout << "\nJSON File Data:\n";
        displayJSON(data);

    } catch (const json::parse_error &e) {
        cerr << "Error: Invalid JSON format!" << endl;
        cerr << "Details: " << e.what() << endl;
        return 1;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}