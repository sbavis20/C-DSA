#include<bits/stdc++.h>
using namespace std;
long long solve(int dice,int faces,int target,vector<vector<long long>>&dp){
  //base case
  if(target<0){
    return 0;
  }

  if(dice==0&&target!=0){
    return 0;
  }

  if(target ==0&& dice !=0){
    return 0;
  }
  if(dice ==0&&taregt ==0){
    return 1;
  }

  if(dp[dice][target]!=-1){
    return dp[dice][target];
  }

  long long ans =0;
  for(int i=1;i<faces;i++){
    ans = ans +solve(dice-1,faces,target-i);
  }

  return dp[dice][target]=ans;
}

long long noOfWays(int dice,int faces,int target){
  vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
  return solve(N,M,X,dp);
}

int main() {
    // Test case 1
    int dice1 = 2, faces1 = 6, target1 = 7;
    cout << "Ways to get sum " << target1 << " with " << dice1 << " dice of " << faces1 << " faces: ";
    cout << noOfWays(dice1, faces1, target1) << endl;

    // Test case 2
    int dice2 = 3, faces2 = 4, target2 = 5;
    cout << "Ways to get sum " << target2 << " with " << dice2 << " dice of " << faces2 << " faces: ";
    cout << noOfWays(dice2, faces2, target2) << endl;

    // Test case 3
    int dice3 = 1, faces3 = 2, target3 = 3;
    cout << "Ways to get sum " << target3 << " with " << dice3 << " dice of " << faces3 << " faces: ";
    cout << noOfWays(dice3, faces3, target3) << endl;

    return 0;
}
