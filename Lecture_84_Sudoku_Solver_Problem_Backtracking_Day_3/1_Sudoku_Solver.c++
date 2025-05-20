#include <bits/stdc++.h>
using namespace std;

// Check if it's safe to place a value at board[row][col]
bool isSafe(int row, int col, vector<vector<int>>& board, int value) {
    int n = board.size();

    for (int i = 0; i < n; i++) {
        if (board[row][i] == value) return false;
        if (board[i][col] == value) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) return false;
    }

    return true;
}

// Backtracking function to solve the board
bool solve(vector<vector<int>>& board) {
    int n = board.size();

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;

                        if (solve(board))
                            return true;

                        // backtrack
                        board[row][col] = 0;
                    }
                }
                return false; // If no value fits
            }
        }
    }

    return true; // All cells filled
}

// Wrapper function
void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}

// Helper to print board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

// ------------------- MAIN FUNCTION WITH TEST CASE -------------------
int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku:\n";
    printBoard(board);

    solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    printBoard(board);

    return 0;
}
