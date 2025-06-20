#include<bits/stdc++.h>
using namespace std;

int solve(int index,int diff,int A[]){
        if(index<0){
            return 0;
        }

        int ans =0;
        for(int j=index-1;j>=0;j--){
            if(A[index]-A[j]==diff){
                ans = max(ans,1+solve(j,diff,A));
            }
        }
        return ans;
}

int lengthOfLongestAP(int A[],int n){
        if(n<=2){
            return n;
        }

        int ans= 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,2+solve(i,A[j]-A[i],A));
            }
        }

        return ans;
}
