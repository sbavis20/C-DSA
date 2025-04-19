#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row * col - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int element = matrix[mid / col][mid % col];

            if (element == target) {
                return true;
            }
            if (element < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    int target2 = 13;

    cout << "Search for " << target1 << ": "
         << (obj.searchMatrix(matrix1, target1) ? "true" : "false") << endl;

    cout << "Search for " << target2 << ": "
         << (obj.searchMatrix(matrix1, target2) ? "true" : "false") << endl;

    return 0;
}
