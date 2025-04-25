#include<iostream>
#include<stack>

using namespace std;

int findMinimumCost(string str) {
    // Odd length condition
    if(str.length() % 2 == 1) {
        return -1;
    }

    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if(ch == '{') {
            s.push(ch);
        } else {
            // ch is '}'
            if(!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push(ch);
            }
        }
    }

    int a = 0, b = 0;
    while(!s.empty()) {
        if(s.top() == '{') {
            b++;
        } else {
            a++;
        }
        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    // Sample Input 1
    {
        string s1 = "{{{";
        cout << "Sample Input 1: " << s1 << endl;
        int result = findMinimumCost(s1);
        cout << "Sample Output 1: " << result << endl;
    }
    {
        string s2 = "{{}{}}";
        cout << "Sample Input 1: " << s2 << endl;
        int result = findMinimumCost(s2);
        cout << "Sample Output 1: " << result << endl;
    }

    // Sample Input 2
    {
        string s3 = "{}}{}}";
        cout << "Sample Input 2: " << s3 << endl;
        int result = findMinimumCost(s3);
        cout << "Sample Output 2: " << result << endl;
    }
    {
        string s4 = "{{{{";
        cout << "Sample Input 2: " << s4 << endl;
        int result = findMinimumCost(s4);
        cout << "Sample Output 2: " << result << endl;
    }
    {
        string s5 = "{{{}}";
        cout << "Sample Input 2: " << s5 << endl;
        int result = findMinimumCost(s5);
        cout << "Sample Output 2: " << result << endl;
    }

    return 0;
}
