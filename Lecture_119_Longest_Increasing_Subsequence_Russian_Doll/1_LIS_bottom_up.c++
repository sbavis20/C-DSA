int solveTab(int n,int a[]){
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1);


for(int curr=n-1;curr>=0;curr--){
  for(int prev = curr-1;prev>=-1;prev){
    int take = 0;
    if(prev==-1||a[curr]>a[prev]){
      take = 1+dp[curr+1][curr+1];
    }


    int notTake = 0 + dp[curr+1][prev+1];


      dp[curr][prev+1]=max(take,notTake);
  }
}
return dp[0][0];
}
int longestSubSequence(int n,int a[]){


  return solveTab(n,a);
}
