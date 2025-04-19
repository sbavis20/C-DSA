#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSafe(int x, int y, vector<vector<int>>& visited, vector<vector<int>>& m, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
    }

    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y,
               vector<vector<int>>& visited, string path) {

        // Destination reached
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Movement directions: D, L, R, U
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isSafe(newX, newY, visited, m, n)) {
                path.push_back(dir[i]);
                solve(m, n, ans, newX, newY, visited, path);
                path.pop_back(); // Backtrack
            }
        }

        visited[x][y] = 0; // Backtrack
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;

        if (m[0][0] == 0) return ans; // Starting point is blocked

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";

        solve(m, n, ans, 0, 0, visited, path);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Main function for testing
int main() {
    Solution obj;

    vector<vector<int>> mat1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> res1 = obj.findPath(mat1, 4);
    cout << "Output 1:\n";
    for (string s : res1) cout << s << " ";
    cout << "\n";

    vector<vector<int>> mat2 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    vector<string> res2 = obj.findPath(mat2, 3);
    cout << "Output 2:\n";
    for (string s : res2) cout << s << " ";
    cout << "\n";

    vector<vector<int>> mat3 = {
        {1, 0},
        {1, 0}
    };

    vector<string> res3 = obj.findPath(mat3, 2);
    cout << "Output 3:\n";
    for (string s : res3) cout << s << " ";
    cout << "\n";

    return 0;
}
