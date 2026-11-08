#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    string sanitized_s = "";
    for (int i = 0; i < s.length(); i++) {
        // if (s[i] != ' ' && s[i] != ',' && s[i] != ':' && s[i] != '\"' &&
        //     s[i] != '\'' && s[i] != '.') {
        //     sanitized_s += tolower(s[i]);
        // }

        switch (s[i]) {
        case '\'':
        case ',':
        case '\"':
        case ' ':
        case '.':
        case ':':
        case ';':
        case '[':
        case ']':
        case '{':
        case '}':
        case '(':
        case ')':
        case '=':
        case '-':
        case '+':
        case '!':
        case '@':
        case '&':
        case '*':
        case '_':
        case '?':
        case '#':
        case '\\':
        case '`':
            break;
        default:
            sanitized_s += tolower(s[i]);
        }
    }
    cout << sanitized_s << endl;
    for (int i = 0, j = sanitized_s.length() - 1; i < sanitized_s.length() / 2;
         i++, j--) {
        if (sanitized_s[i] != sanitized_s[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    // string s = "A man, a plan, a canal: Panama";
    // string s = "Marge, let's \"[went].\" I await {news} telegram.";
    // string s = "Was it\\ a rat I saw?";
    string s = "`l;`` 1o1 ??;l`";

    if (isPalindrome(s)) {
        cout << "palindrome\n";
    } else {
        cout << "NOT palindrome\n";
    }
    return 0;
}