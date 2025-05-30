#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    vector<int> testCases = {0, 1, 2, 5, 10, 20, 30};

    for (int n : testCases) {
        vector<int> dp(n + 1, -1);
        cout << "fib(" << n << ") = " << fib(n, dp) << endl;
    }

    return 0;
}
