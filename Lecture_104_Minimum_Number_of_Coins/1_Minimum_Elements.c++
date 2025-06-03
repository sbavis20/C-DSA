#include <bits/stdc++.h>
using namespace std;

int solveMem(vector<int>&num,int x,vector<int>&dp){
    //basecase
    if(x==0){
        return 0;
    }

    if(x<0){
        return INT_MAX;
    }

    if(dp[x]!=-1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans = solveMem(num,x-num[i],dp);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);
        }

    }
    dp[x]=mini;
    return mini;
}


int minimumElements(vector<int> &num, int x)
{
    vector<int>dp(x+1,-1);

    int ans = solveMem(num,x,dp);
    if(ans==INT_MAX){
        return -1;
    }else{
        return ans;
    }
}
int main() {
    vector<int> num1 = {1, 2, 3};
    int x1 = 7;
    cout << "Test 1 (Expected 3): " << minimumElements(num1, x1) << endl;

    vector<int> num2 = {2, 4};
    int x2 = 7;
    cout << "Test 2 (Expected -1): " << minimumElements(num2, x2) << endl;

    vector<int> num3 = {1};
    int x3 = 0;
    cout << "Test 3 (Expected 0): " << minimumElements(num3, x3) << endl;

    vector<int> num4 = {2, 3, 5};
    int x4 = 11;
    cout << "Test 4 (Expected 3): " << minimumElements(num4, x4) << endl;

    return 0;
}
