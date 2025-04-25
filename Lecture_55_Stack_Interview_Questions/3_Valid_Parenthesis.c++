#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParenthesis(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    // Sample Input 1
    string input1 = "[()]{}{[()()]()}";
    cout << "Sample Input 1: " << input1 << endl;
    if (isValidParenthesis(input1)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    // Sample Input 2
    string input2 = "[[}[";
    cout << "Sample Input 2: " << input2 << endl;
    if (isValidParenthesis(input2)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
