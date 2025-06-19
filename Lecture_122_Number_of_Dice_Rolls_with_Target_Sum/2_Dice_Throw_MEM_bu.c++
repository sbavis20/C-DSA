#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;  // Optional, for large outputs

long long solve(int dice, int faces, int target) {
    vector<vector<long long>> dp(dice + 1, vector<long long>(target + 1, 0));
    dp[0][0] = 1;

    for (int d = 1; d <= dice; d++) {
        for (int t = 1; t <= target; t++) {
            long long ans = 0;
            for (int f = 1; f <= faces; f++) {
                if (t - f >= 0) {
                    ans = (ans + dp[d - 1][t - f]) % MOD;
                }
            }
            dp[d][t] = ans;
        }
    }

    return dp[dice][target];
}

long long noOfWays(int dice, int faces, int target) {
    return solve(dice, faces, target);
}

int main() {
    // Test case 1
    int dice1 = 2, faces1 = 6, target1 = 7;
    cout << "Ways to get sum " << target1 << " with " << dice1 << " dice of " << faces1 << " faces: ";
    cout << noOfWays(dice1, faces1, target1) << endl;

    // Test case 2
    int dice2 = 3, faces2 = 4, target2 = 5;
    cout << "Ways to get sum " << target2 << " with " << dice2 << " dice of " << faces2 << " faces: ";
    cout << noOfWays(dice2, faces2, target2) << endl;

    // Test case 3
    int dice3 = 1, faces3 = 2, target3 = 3;
    cout << "Ways to get sum " << target3 << " with " << dice3 << " dice of " << faces3 << " faces: ";
    cout << noOfWays(dice3, faces3, target3) << endl;

    return 0;
}
