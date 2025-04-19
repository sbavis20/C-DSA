#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mappings[]) {
        // Base condition
        if (index >= digit.length()) {
            ans.push_back(output);
            return;
        }

        int number = digit[index] - '0';
        string value = mappings[number];

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index + 1, ans, mappings);
            output.pop_back();  // backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;

        string output;
        int index = 0;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, ans, mapping);
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    string digits1 = "23";
    vector<string> result1 = sol.letterCombinations(digits1);
    cout << "Input: " << digits1 << "\nOutput: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << "\"" << result1[i] << "\"";
        if (i != result1.size() - 1) cout << ",";
    }
    cout << "]\n\n";

    // Example 2
    string digits2 = "";
    vector<string> result2 = sol.letterCombinations(digits2);
    cout << "Input: \"" << digits2 << "\"\nOutput: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << "\"" << result2[i] << "\"";
        if (i != result2.size() - 1) cout << ",";
    }
    cout << "]\n\n";

    // Example 3
    string digits3 = "2";
    vector<string> result3 = sol.letterCombinations(digits3);
    cout << "Input: " << digits3 << "\nOutput: [";
    for (int i = 0; i < result3.size(); ++i) {
        cout << "\"" << result3[i] << "\"";
        if (i != result3.size() - 1) cout << ",";
    }
    cout << "]\n";

    return 0;
}
