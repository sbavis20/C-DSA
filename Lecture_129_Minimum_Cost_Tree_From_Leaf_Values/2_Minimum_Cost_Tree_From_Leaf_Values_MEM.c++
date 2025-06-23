class Solution {
public:
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {
        if (left == right) return 0;

        if (dp[left][right] != -1) return dp[left][right];

        int ans = INT_MAX;

        for (int i = left; i < right; i++) {
            int leftMax = maxi[{left, i}];
            int rightMax = maxi[{i + 1, right}];

            int cost = leftMax * rightMax + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i + 1, right, dp);
            ans = min(ans, cost);
        }

        return dp[left][right] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> maxi;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Precompute maximums in subarrays
        for (int i = 0; i < n; ++i) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        return solve(arr, maxi, 0, n - 1, dp);
    }
};
