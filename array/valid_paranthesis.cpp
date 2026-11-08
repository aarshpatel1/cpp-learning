// int main() {
//     string s = "(]";
//     Stack stack;
//     bool is_valid = true;

//     for (int i = 0; i < s.size(); i++) {
//         // 1. Push opening brackets
//         if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
//             stack.push(s[i]);
//         } 
//         // 2. Handle closing brackets
//         else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
//             // If stack is empty or brackets don't match, it's invalid
//             if ((s[i] == ')' && stack.peek() == '(') ||
//                 (s[i] == '}' && stack.peek() == '{') ||
//                 (s[i] == ']' && stack.peek() == '[')) {
//                 stack.pop();
//             } else {
//                 is_valid = false;
//                 break; // Stop checking immediately
//             }
//         }
//     }

//     // 3. To be valid, no mismatches occurred AND the stack must be empty
//     if (is_valid && stack.is_empty()) {
//         cout << "Valid Parenthesis\n";
//     } else {
//         cout << "NOT Valid Parenthesis\n";
//     }

//     return 0;
// }
