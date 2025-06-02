#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& cost, int n, vector<int>& dp) {
    // Base cases
    if (n == 0) return cost[0];
    if (n == 1) return cost[1];

    if (dp[n] != -1) return dp[n];

    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
