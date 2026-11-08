// zig zag conversion

#include <iostream>
#include <string>
using namespace std;


string convert(string s, int numRows) {
    string answer;
    int count = numRows % 2 == 0 ? numRows + 2 : numRows + 1;

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < s.length(); j += count) {
            answer += s[j];
        }
        if (count > numRows) {
            count = numRows % 2 == 0 ? numRows % count : count / 2;
        } else {
            count = numRows % 2 == 0 ? numRows + 2 : numRows + 1;
        }
    }

    return answer;
}


int main() {

    cout << convert("PAYPALISHIRING", 3) << endl;
    cout << convert("PAYPALISHIRING", 4) << endl;
    cout << convert("A", 1) << endl;

    return 0;
}
