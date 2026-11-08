// 3. Longest Substring Without Repeating Characters
#include <iostream>
#include <string>
using namespace std;

bool is_in(string s, char target) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == target)
            return true;
    }
    return false;
}

int index(string s, char target) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == target)
            return i;
    }
    return -1;
}

string split(int start_index, int end_index, string s) {
    string splited_s = "";
    for (int i = start_index; i < end_index; i++) {
        splited_s += s[i];
    }
    return splited_s;
}

int lengthOfLongestSubstring(string s) {
    string past = "", current = "";
    for (int i = 0; i < s.length(); i++) {
        if (!is_in(s, s[i])) {
            current += s[i];
        } else {
            int current_index = index(s, s[i]);
            if (current_index >= 0) {
                string new_current = split(current_index + 1, s.length(), s);
                new_current += s[i];
                if (past.length() < current.length()) {

                    past = current;
                }
                current = new_current;
            } else if (past.length() < current.length()) {
                past = current;
                current = s[i];
            }
        }
    }
    if (past.length() > current.length()) {
        return past.length();
    }
    return current.length();
}

int main() {
    string s = "abcabcbb";
    cout << "Longest Substring Without Repeating Characters: " << s << " = "
         << lengthOfLongestSubstring(s);
    return 0;
}