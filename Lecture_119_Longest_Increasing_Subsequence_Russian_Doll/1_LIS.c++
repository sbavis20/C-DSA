int solve(int n,int a[],int curr,int prev,vector<vector<int>>&dp){
  //base case
  if(curr==n){
    return 0;
  }

  if(dp[curr][prev+1]!=-1){
    return dp[curr][prev+1];
  }

  int take = 0;
  if(prev==-1||a[curr]>a[prev]){
    take = 1+solve(n,a,curr+1,curr,dp);
  }


  int notTake = 0 + solve(n,a,curr+1,prev,dp);


  return dp[curr][prev+1]=max(take,notTake);
}

int longestSubSequence(int n,int a[]){
  vector<vector<int>>dp(n,vector<int>(n+1,-1);

  return solve(n,a,0,-1,dp);
}
