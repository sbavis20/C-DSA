#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> weight, vector<int> value, int index, int W,vector<vector<int>>&dp)
{
    //basecase
    if(index==0){
        if(weight[0]<=W){
            return value[0];
        }else{
            return 0;
        }
    }
        if(dp[index][W]!=-1){
            return dp[index][W];
        }
    int include=0;
    if(weight[index]<=W)
        include=value[index]+solve(weight,value,index-1,W-weight[index],dp);
        int exclude=0+solve(weight,value,index-1,W,dp);

        dp[index][W]=max(exclude,include);

    return dp[index][W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));

    return solve(weight,value,n-1,maxWeight,dp);
}
int main() {
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};
    int maxWeight = 7;
    int n = weights.size();

    cout << knapsack(weights, values, n, maxWeight) << endl; // Expected output: 9
}
