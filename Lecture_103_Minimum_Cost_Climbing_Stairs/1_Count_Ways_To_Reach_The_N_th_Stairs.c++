#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

int countDistinctWays(int nStairs) {
    if(nStairs == 0 || nStairs == 1) return 1;

    long long prev1 = 1;  // Ways to reach 0th stair
    long long prev2 = 1;  // Ways to reach 1st stair

    for(int i = 2; i <= nStairs; i++) {
        long long curr = (prev1 + prev2) % MOD;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
int main() {
    int nStairs = 100000;
    cout << countDistinctWays(nStairs) << endl;
    return 0;
}
