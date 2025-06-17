#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int> &base, vector<int> &newBox) {
        return newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2];
    }

    int solveTab(int n, vector<vector<int>> &cuboids) {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int take = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev])) {
                    take = cuboids[curr][2] + nextRow[curr + 1];
                }
                int notTake = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>> &cuboids) {
        // Sort dimensions of each cuboid
        for (auto &c : cuboids) {
            sort(c.begin(), c.end());
        }

        // Sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        return solveTab(cuboids.size(), cuboids);
    }
};
