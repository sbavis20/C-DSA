class Solution {
public:
int solve(int index,int buy,vector<int>&prices){
    if(index==prices.size()){
        return 0;
    }

    int profit = 0;
    if(buy){
        profit = max((-prices[index]+solve(index+1,0,prices),(0+solve(index+1,1,prices))));
    }else{
        profit = max ((+prices[index]+solve(index+1,1,prices))+(0+solve(index+1,0,prices)));
    }
    return profit;
}
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices);
    }
};
