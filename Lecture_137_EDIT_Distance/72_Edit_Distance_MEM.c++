class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        // Base cases
        if (i == a.length()) {
            return b.length() - j;
        }
        if (j == b.length()) {
            return a.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (a[i] == b[j]) {
            return dp[i][j] = solve(a, b, i + 1, j + 1, dp);  // ✅ Add return here
        } else {
            int insertAns = 1 + solve(a, b, i, j + 1, dp);
            int deleteAns = 1 + solve(a, b, i + 1, j, dp);
            int replaceAns = 1 + solve(a, b, i + 1, j + 1, dp);
            return dp[i][j] = min(insertAns, min(deleteAns, replaceAns));
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
