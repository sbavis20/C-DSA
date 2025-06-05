#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++) {
        int incl = prev2 + nums[i];
        int excl = prev1;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    vector<int> first(valueInHouse.begin(), valueInHouse.end() - 1);
    vector<int> second(valueInHouse.begin() + 1, valueInHouse.end());

    return max(solve(first), solve(second));
}
int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},      // Output: 4
        {2, 3, 2},         // Output: 3
        {5, 1, 1, 5},      // Output: 10
        {4},               // Output: 4
        {200, 3, 140, 20, 10} // Output: 340
    };

    for (auto& houses : testCases) {
        cout << houseRobber(houses) << endl;
    }
}
