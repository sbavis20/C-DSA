#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int main() {
    vector<vector<int>> testCases = {
        {10, 15, 20},
        {1, 100, 1, 1, 1, 100, 1, 1, 100, 1},
        {0, 2, 2, 1},
        {1, 2},
        {0, 0, 0, 0}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        int result = minCostClimbingStairs(testCases[i]);
        cout << "Minimum Cost = " << result << endl;
    }

    return 0;
}
