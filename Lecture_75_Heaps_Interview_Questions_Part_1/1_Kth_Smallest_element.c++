#include <iostream>
#include <queue> // for priority_queue
#include <vector>
#include <algorithm> // for sort (for verification)
using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        // Create a max-heap
        priority_queue<int> pq;

        // Insert first k elements into the heap
        for(int i = l; i < k; i++) {
            pq.push(arr[i]);
        }

        // For remaining elements, compare with top of heap
        for(int i = k; i <= r; i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // The top of heap is the kth smallest element
        return pq.top();
    }
};

// Function to verify result using sorting
int verifyKthSmallest(int arr[], int l, int r, int k) {
    vector<int> vec(arr + l, arr + r + 1);
    sort(vec.begin(), vec.end());
    return vec[k-1];
}

int main() {
    Solution sol;

    // Test Case 1: Simple array
    int arr1[] = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int result1 = sol.kthSmallest(arr1, 0, n1-1, k1);
    int verify1 = verifyKthSmallest(arr1, 0, n1-1, k1);
    cout << "Test Case 1: " << result1 << " (Verification: " << verify1 << ")"
         << (result1 == verify1 ? " ✓" : " ✗") << endl;

    // Test Case 2: All elements same
    int arr2[] = {5, 5, 5, 5, 5};
    int k2 = 2;
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int result2 = sol.kthSmallest(arr2, 0, n2-1, k2);
    int verify2 = verifyKthSmallest(arr2, 0, n2-1, k2);
    cout << "Test Case 2: " << result2 << " (Verification: " << verify2 << ")"
         << (result2 == verify2 ? " ✓" : " ✗") << endl;

    // Test Case 3: Sorted array
    int arr3[] = {1, 2, 3, 4, 5, 6};
    int k3 = 4;
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    int result3 = sol.kthSmallest(arr3, 0, n3-1, k3);
    int verify3 = verifyKthSmallest(arr3, 0, n3-1, k3);
    cout << "Test Case 3: " << result3 << " (Verification: " << verify3 << ")"
         << (result3 == verify3 ? " ✓" : " ✗") << endl;

    // Test Case 4: Reverse sorted array
    int arr4[] = {9, 8, 7, 6, 5, 4};
    int k4 = 2;
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    int result4 = sol.kthSmallest(arr4, 0, n4-1, k4);
    int verify4 = verifyKthSmallest(arr4, 0, n4-1, k4);
    cout << "Test Case 4: " << result4 << " (Verification: " << verify4 << ")"
         << (result4 == verify4 ? " ✓" : " ✗") << endl;

    // Test Case 5: Large array with random elements
    int arr5[] = {12, 3, 5, 7, 19, 4, 8, 10, 2, 6, 11, 15, 1, 9, 13, 14};
    int k5 = 7;
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    int result5 = sol.kthSmallest(arr5, 0, n5-1, k5);
    int verify5 = verifyKthSmallest(arr5, 0, n5-1, k5);
    cout << "Test Case 5: " << result5 << " (Verification: " << verify5 << ")"
         << (result5 == verify5 ? " ✓" : " ✗") << endl;

    return 0;
}
