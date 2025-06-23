class Solution {
public:
    int solve(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int index = n-1;index >=0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index]+dp[index+1][0];
                    int skipKaro = 0 + dp[index+1][1];
                    profit = max(buyKaro,skipKaro);
                }else{
                    int sellKaro = prices[index]+dp[index+1][1];
                    int skipKaro = 0+dp[index+1][0];
                    profit = max(sellKaro,skipKaro);
                }
                return dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {

        return solve(prices);
    }
};
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices); // Output: 7
}
