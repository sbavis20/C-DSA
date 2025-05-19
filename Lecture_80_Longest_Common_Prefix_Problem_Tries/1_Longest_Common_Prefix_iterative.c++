#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n) {
    string ans = "";

    if (n == 0) return ans; // Edge case: empty input

    for (int i = 0; i < arr[0].length(); i++) {
        char ch = arr[0][i];
        bool match = true;

        for (int j = 1; j < n; j++) {
            // Fix: arr[j].size() <= i (not just <i) to avoid out-of-bounds
            if (i >= arr[j].size() || arr[j][i] != ch) {
                match = false;
                break;
            }
        }

        if (!match)
            break;
        else
            ans.push_back(ch);
    }

    return ans;
}

int main() {
    vector<string> arr1 = {"flower", "flow", "flight"};
    vector<string> arr2 = {"dog", "racecar", "car"};
    vector<string> arr3 = {"apple", "applepie", "appletree"};

    cout << "Longest Common Prefix (Test 1): " << longestCommonPrefix(arr1, arr1.size()) << endl;
    cout << "Longest Common Prefix (Test 2): " << longestCommonPrefix(arr2, arr2.size()) << endl;
    cout << "Longest Common Prefix (Test 3): " << longestCommonPrefix(arr3, arr3.size()) << endl;

    return 0;
}
