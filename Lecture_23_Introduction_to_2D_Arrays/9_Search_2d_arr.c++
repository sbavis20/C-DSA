#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex = 0;
        int colIndex = col - 1;

        while (rowIndex < row && colIndex >= 0) {
            int element = matrix[rowIndex][colIndex];

            if (element == target) {
                return true;
            }

            if (element < target) {
                rowIndex++;
            } else {
                colIndex--;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1,  4,  7, 11, 15},
        {2,  5,  8, 12, 19},
        {3,  6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target1 = 5;
    int target2 = 20;

    cout << "Searching for " << target1 << ": "
         << (obj.searchMatrix(matrix, target1) ? "true" : "false") << endl;

    cout << "Searching for " << target2 << ": "
         << (obj.searchMatrix(matrix, target2) ? "true" : "false") << endl;

    return 0;
}
