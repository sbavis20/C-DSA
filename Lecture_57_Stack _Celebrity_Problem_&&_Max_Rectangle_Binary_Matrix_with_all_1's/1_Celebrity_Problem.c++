#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(vector<vector<int>> &M, int a, int b) {
    return M[a][b] == 1;
}

int celebrity(vector<vector<int>> &M, int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(M, a, b)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    int candidate = s.top();

    bool rowCheck = true;
    for (int i = 0; i < n; i++) {
        if (M[candidate][i] != 0) {
            rowCheck = false;
            break;
        }
    }

    bool colCheck = true;
    for (int i = 0; i < n; i++) {
        if (i != candidate && M[i][candidate] != 1) {
            colCheck = false;
            break;
        }
    }

    if (rowCheck && colCheck) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    // Sample Input 1
    {
        vector<vector<int>> M1 = {
            {0, 1, 0},
            {0, 0, 0},
            {0, 1, 0}
        };
        int n1 = M1.size();
        cout << "Sample Input 1:" << endl;
        for (auto row : M1) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        int result1 = celebrity(M1, n1);
        cout << "Output: " << result1 << endl;
    }

    // Sample Input 2
    {
        vector<vector<int>> M2 = {
            {0, 1},
            {1, 0}
        };
        int n2 = M2.size();
        cout << "Sample Input 2:" << endl;
        for (auto row : M2) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        int result2 = celebrity(M2, n2);
        cout << "Output: " << result2 << endl;
    }

    return 0;
}
