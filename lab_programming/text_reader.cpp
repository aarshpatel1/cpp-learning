#include <fstream>
#include <iostream>
#include <string>
using namespace std;

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

    string line;
    // printing every line
    while (getline(file, line)) {
        cout << line << endl;
    }

    // closing file after reading it
    file.close();

    return 0;
}
