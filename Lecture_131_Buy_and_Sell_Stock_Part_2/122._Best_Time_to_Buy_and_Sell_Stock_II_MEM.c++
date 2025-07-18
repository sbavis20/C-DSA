class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (index == prices.size()) {
            return 0;
        }

        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = 0;
        if (buy) {
            // Option 1: Buy now (-prices[index]), Option 2: Skip
            profit = max(-prices[index] + solve(index + 1, 0, prices, dp),
                         0 + solve(index + 1, 1, prices, dp));
        } else {
            // Option 1: Sell now (+prices[index]), Option 2: Skip
            profit = max(prices[index] + solve(index + 1, 1, prices, dp),
                         0 + solve(index + 1, 0, prices, dp));
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices); // Output: 7
}
