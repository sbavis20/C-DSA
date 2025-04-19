#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;

    for (int col = 0; col < mCols; col++) {
        if (col & 1) {
            // odd col: bottom to top
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else {
            // even col: top to bottom
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

int main() {
    // Test Case 1
    vector<vector<int>> mat1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> result1 = wavePrint(mat1, 3, 4);
    for (int val : result1) cout << val << " ";
    cout << endl;

    // Test Case 2
    vector<vector<int>> mat2 = {
        {1, 2, 4, 5},
        {3, 6, 8, 10},
        {11, 12, 13, 15},
        {16, 14, 9, 7}
    };

    vector<int> result2 = wavePrint(mat2, 4, 4);
    for (int val : result2) cout << val << " ";
    cout << endl;

    return 0;
}
