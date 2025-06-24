class Solution {
public:
    int solve(vector<int>& prices) {
      vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));


      for(int index =n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit=0;
                 if (buy) {
                int buyKaro = -prices[index] + dp[index+1][0][limit];
                int skipKaro = 0 +dp[index+1][1][limit] ;
                profit = max(buyKaro, skipKaro);
                } else {
                    int sellKaro = prices[index] +dp[index+1][1][limit-1] ;
                    int skipKaro = 0 + dp[index+1][0][limit];
                    profit = max(sellKaro, skipKaro);
                }

            dp[index][buy][limit] = profit;
            }
        }
      }
      return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {


        return solve(prices);
    }
};
