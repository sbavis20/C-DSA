#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n) {
    return (newx >= 0 && newx < n && newy >= 0 && newy < n &&
            !vis[newx][newy] && arr[newx][newy] == 1);
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<bool>> &vis, string path) {

    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = true;

    // Down
    if (isSafe(x + 1, y, vis, arr, n)) {
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }

    // Left
    if (isSafe(x, y - 1, vis, arr, n)) {
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
    }

    // Right
    if (isSafe(x, y + 1, vis, arr, n)) {
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }

    // Up
    if (isSafe(x - 1, y, vis, arr, n)) {
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
    }

    vis[x][y] = false; // backtrack
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    if (arr[0][0] == 0)
        return ans;

    solve(0, 0, arr, n, ans, visited, path);
    sort(ans.begin(), ans.end()); // optional
    return ans;
}

// ------------------ Main Function with Test Cases ------------------
int main() {
    vector<vector<int>> maze1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<vector<int>> maze2 = {
        {1, 1},
        {0, 1}
    };

    vector<vector<int>> maze3 = {
        {1, 0},
        {0, 1}
    };

    vector<string> result1 = searchMaze(maze1, 4);
    vector<string> result2 = searchMaze(maze2, 2);
    vector<string> result3 = searchMaze(maze3, 2);

    cout << "Maze 1 Paths:" << endl;
    for (string s : result1)
        cout << s << endl;

    cout << "\nMaze 2 Paths:" << endl;
    for (string s : result2)
        cout << s << endl;

    cout << "\nMaze 3 Paths:" << endl;
    if (result3.empty()) {
        cout << "No path found." << endl;
    } else {
        for (string s : result3)
            cout << s << endl;
    }

    return 0;
}
