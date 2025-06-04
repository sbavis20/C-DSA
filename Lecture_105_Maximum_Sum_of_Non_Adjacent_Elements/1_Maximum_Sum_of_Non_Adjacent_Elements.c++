#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums){
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=i;i<n;i++){
       int incl = dp[i-2]+nums[i];
       int excl = dp[i-1]+0;
       dp[i]=max(incl,excl);
    }

    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
return solve(nums);
}
int main() {
    vector<int> nums1 = {2, 1, 4, 9}; // Output: 10
    vector<int> nums2 = {1, 2, 3, 1}; // Output: 4
    vector<int> nums3 = {5, 5, 10, 100, 10, 5}; // Output: 110
    vector<int> nums4 = {3};          // Output: 3
    vector<int> nums5 = {};           // Output: 0
    vector<int> nums6 = {4, 1, 1, 4, 2, 1}; // Output: 9

    cout << maximumNonAdjacentSum(nums1) << endl;
    cout << maximumNonAdjacentSum(nums2) << endl;
    cout << maximumNonAdjacentSum(nums3) << endl;
    cout << maximumNonAdjacentSum(nums4) << endl;
    cout << maximumNonAdjacentSum(nums5) << endl;
    cout << maximumNonAdjacentSum(nums6) << endl;

    return 0;
}
