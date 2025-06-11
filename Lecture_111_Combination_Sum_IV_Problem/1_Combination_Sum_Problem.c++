#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int tar,vector<int>&dp){
    //base case
    if(tar<0){
        return 0;
    }

    if(tar==0){
        return 1;
    }

    if(dp[tar]!=-1){
        return dp[tar];
    }

    int ans =0;
    for(int i=0;i<num.size();i++){
        ans += solve(num,tar-num[i],dp);
    }
    dp[tar]=ans;
return dp[tar];
}

int findWays(vector<int> &num, int tar)
{   vector<int> dp(tar+1,-1);


    return solve(num,tar,dp);
}
int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << findWays(nums, target) << endl;  // Output: 7
    // 7 ways: (1,1,1,1), (1,1,2), (1,2,1), (2,1,1), (2,2), (1,3), (3,1)
}
