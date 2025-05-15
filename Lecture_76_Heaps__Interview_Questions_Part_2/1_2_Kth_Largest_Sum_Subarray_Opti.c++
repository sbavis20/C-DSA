#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to get Kth largest subarray sum
int getKthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (minHeap.size() < k) {
                minHeap.push(sum);
            } else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }

    return minHeap.top();
}

// Main function with test case
int main() {
    vector<int> arr = {10, -10, 20, -40};
    int k = 6;

    int ans = getKthLargest(arr, k);
    cout << "The " << k << "th largest subarray sum is: " << ans << endl;

    return 0;
}
