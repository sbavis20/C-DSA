#include <bits/stdc++.h>
#define MOD 10000007
using namespace std;

int add(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solve(int n, int k, vector<int>& dp) {
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, mul(k, k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(
        mul(solve(n - 2, k, dp), k - 1),
        mul(solve(n - 1, k, dp), k - 1)
    );

    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}
int main() {
    int n = 5, k = 3;
    cout << "Number of ways to paint " << n << " posts with " << k << " colors: ";
    cout << numberOfWays(n, k) << endl;
    return 0;
}
