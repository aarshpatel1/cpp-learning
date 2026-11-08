#include <cmath>
#include <iostream>
#include <string>
using namespace std;

bool check_palindrome(string s) {
    for (int i = 0, j = s.length() - 1; i < floor(s.length() / 2); i++, j--) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

string longest_palindrome(string s) {
    string temp = "", longest_substring = "";

    if (check_palindrome(s)) {
        return s;
    }

    if (s.length() <= 1) {
        return s;
    }

    for (int i = 0; i < s.length(); i++) {
        temp += s[i];
        for (int j = i + 1; j < s.length(); j++) {
            temp += s[j];
            if (check_palindrome(temp) &&
                longest_substring.length() <= temp.length()) {
                longest_substring = temp;
            }
        }
        temp = "";
    }

    if (longest_substring.length() == 0 && !check_palindrome(s)) {
        return {s[0]};
    }

    return longest_substring;
}

int main() {

    cout << longest_palindrome("babad") << endl;
    cout << longest_palindrome("cbbd") << endl;
    cout << longest_palindrome("a") << endl;
    cout << longest_palindrome("ac") << endl;
    cout
        << longest_palindrome(
               "glwhcebdjbdroiurzfxxrbhzibilmcfasshhtyngwrsnbdpzgjphujzuawbebyh"
               "vxfhtoozcitaqibvvowyluvdbvoqikgojxcefzpdgahujuxpiclrrmalncdrots"
               "gkpnfyujgvmhydrzdpiudkfchtklsaprptkzhwxsgafsvkahkbsighlyhjvbbur"
               "dfjdfvjbaiivqxdqwivsjzztzkzygcsyxlvvwlckbsmvwjvrhvqfewjxgefeowf"
               "hrcturolvfgxilqdqvitbcebuooclugypurlsbdfquzsqngbscqwlrdpxeahric"
               "vtfqpnrfwbyjvahrtosovsbzhxtutyfjwjbpkfujeoueykmbcjtluuxvmffwgqj"
               "grtsxtdimsescgahnudmsmyfijtfrcbkibbypenxnpiozzrnljazjgrftitldcu"
               "eswqitrcvjzvlhionutppppzxoepvtzhkzjetpfqsuirdcyqfjsqhdewswldawh"
               "dyijhpqtrwgyfmmyhhkrafisicstqxokdmynnnqxaekzcgygsuzfiguujyxowqd"
               "fylesbzhnpznayzlinerzdqjrylyfzndgqokovabhzuskwozuxcsmyclvfwkbim"
               "hkdmjacesnvorrrvdwcgfewchbsyzrkktsjxgyybgwbvktvxyurufsrdufcunnf"
               "swqddukqrxyrueienhccpeuqbkbumlpxnudmwqdkzvsqsozkifpznwapxaxdclx"
               "jxuciyulsbxvwdoiolgxkhlrytiwrpvtjdwsssahupoyyjveedgqsthefdyxvjw"
               "eaimadykubntfqcpbjyqbtnunuxzyytxfedrycsdhkfymaykeubowvkszzwmbbj"
               "ezrphqildkmllskfawmcohdqalgccffxursvbyikjoglnillapcbcjuhaxukfha"
               "lcslemluvornmijbeawxzokgnlzugxkshrpojrwaasgfmjvkghpdyxt")
        << endl;

    return 0;
}

/*
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) return s;

        int start = 0;
        int max_len = 1;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // Case 1: Odd length palindromes (e.g., "aba", centre is 'b')
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int current_len = right - left + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                    start = left;
                }
                left--;
                right++;
            }

            // Case 2: Even length palindromes (e.g., "0000", centre is between
'0' and '0') left = i; right = i + 1; while (left >= 0 && right < n && s[left]
== s[right]) { int current_len = right - left + 1; if (current_len > max_len) {
                    max_len = current_len;
                    start = left;
                }
                left--;
                right++;
            }
        }

        // Only slice the string ONCE at the very end
        return s.substr(start, max_len);
    }
};

*/