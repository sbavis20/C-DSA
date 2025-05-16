#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find the element with maximum frequency
int maximumFrequency(vector<int>& arr, int n) {
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < n; i++) {
        if (count[arr[i]] == maxFreq) {
            maxAns = arr[i];
            break;
        }
    }

    return maxAns;
}

// Main function with test cases
int main() {
    vector<int> test1 = {1, 3, 2, 1, 4, 1};
    vector<int> test2 = {5, 2, 2, 5, 5, 2};
    vector<int> test3 = {7, 8, 8, 7, 9, 7};

    cout << "Most frequent in test1: " << maximumFrequency(test1, test1.size()) << endl;
    cout << "Most frequent in test2: " << maximumFrequency(test2, test2.size()) << endl;
    cout << "Most frequent in test3: " << maximumFrequency(test3, test3.size()) << endl;

    return 0;
}
