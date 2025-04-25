#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else if (ch == ')') {
            bool isRedundant = true;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                st.pop();
            }
            if (st.empty()) {
                // Unmatched closing bracket
                return true;
            }
            st.pop(); // Pop the '('
            if (isRedundant) {
                return true;
            }
        }
    }

    // Check for unmatched opening brackets
    while (!st.empty()) {
        if (st.top() == '(') {
            return true;
        }
        st.pop();
    }

    return false;
}

int main() {
    // Sample Input 1
    {
        string s1 = "(a+b)";
        cout << "Sample Input 1: " << s1 << endl;
        if (findRedundantBrackets(s1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    {
        string s2 = "(a+c*b)+(c))";
        cout << "Sample Input 1: " << s2 << endl;
        if (findRedundantBrackets(s2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    // Sample Input 2
    {
        string s3 = "(a*b+(c/d))";
        cout << "Sample Input 2: " << s3 << endl;
        if (findRedundantBrackets(s3)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    {
        string s4 = "((a/b))";
        cout << "Sample Input 2: " << s4 << endl;
        if (findRedundantBrackets(s4)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
