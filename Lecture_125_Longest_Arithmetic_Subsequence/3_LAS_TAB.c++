#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestAP(int A[],int n){
        if(n<=2){
            return n;
        }

        int ans =0;
        unordered_map<int,int>dp[n+1];

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = A[i]-A[j];
                int cnt =1;

                if(dp[j].count(diff)){
                    cnt = max(ans,dp[i][diff]);
                }
            }
            return ans;
        }
}
