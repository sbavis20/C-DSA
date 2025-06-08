#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int x, int y, int z, vector<int>& dp) {
    // Base cases
    if (n == 0) return 0;
    if (n < 0) return INT_MIN;

    // Memoization check
    if (dp[n] != -1) return dp[n];

    // Recurrence
    int a = solve(n - x, x, y, z, dp) + 1;
    int b = solve(n - y, x, y, z, dp) + 1;
    int c = solve(n - z, x, y, z, dp) + 1;

    dp[n] = max({a, b, c});
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    return ans < 0 ? 0 : ans;
}
int main() {
    cout << cutSegments(7, 5, 2, 2) << endl;  // Output: 3
    cout << cutSegments(5, 5, 3, 2) << endl;  // Output: 1
    cout << cutSegments(11, 5, 3, 2) << endl; // Output: 5
    cout << cutSegments(0, 2, 3, 5) << endl;  // Output: 0
    cout << cutSegments(7, 4, 2, 6) << endl;  // Output: 2
}
