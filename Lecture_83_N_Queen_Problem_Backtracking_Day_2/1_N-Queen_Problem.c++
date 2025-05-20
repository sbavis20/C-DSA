#include <bits/stdc++.h>
using namespace std;

// Adds current board configuration to the answer
void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

// Checks if it's safe to place a queen at board[row][col]
bool issafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    // Check this row on the left side
    while (y >= 0) {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    // Check upper diagonal on the left
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // Check lower diagonal on the left
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

// Recursively tries to place queens
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    if (col == n) {
        addSolution(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (issafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0; // backtrack
        }
    }
}

// Main function to solve N-Queens
vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}

// ------------------ Main Function with Test Cases ------------------
int main() {
    int n = 4; // You can change N here
    vector<vector<int>> solutions = nQueens(n);

    cout << "Total solutions for " << n << "-Queens: " << solutions.size() << "\n\n";

    for (int k = 0; k < solutions.size(); k++) {
        cout << "Solution " << k + 1 << ":\n";
        for (int i = 0; i < n * n; i++) {
            if (i % n == 0) cout << endl;
            cout << solutions[k][i] << " ";
        }
        cout << "\n\n";
    }

    return 0;
}
