class Solution {
public:
    int solve(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buyKaro = -prices[index] + next[0];
                    int skipKaro = 0 + next[1];
                    profit = max(buyKaro, skipKaro);
                } else {
                    int sellKaro = prices[index] + next[1] - fee;
                    int skipKaro = 0 + next[0];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];  // We start with buy = 1 (allowed to buy at beginning)
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};
