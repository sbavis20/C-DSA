#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution {
private:
    vector<int> nextSmallerElement(int *arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int *arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int *heights, int n) {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = largestRectangleArea(M[0], m);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] != 0) {
                    M[i][j] += M[i - 1][j];
                } else {
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};

int main() {
    Solution obj;
    int M1[MAX][MAX] = {{1, 1}, {1, 1}};
    cout << "Test Case 1 (All 1's): " << obj.maxArea(M1, 2, 2) << endl; // Expected: 4

    int M2[MAX][MAX] = {{0, 0}, {0, 0}};
    cout << "Test Case 2 (All 0's): " << obj.maxArea(M2, 2, 2) << endl; // Expected: 0

    int M3[MAX][MAX] = {{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
    cout << "Test Case 3 (Mixed 1's and 0's): " << obj.maxArea(M3, 3, 3) << endl; // Expected: 4

    int M4[MAX][MAX] = {{1, 1, 0, 1, 1}};
    cout << "Test Case 4 (Single Row): " << obj.maxArea(M4, 1, 5) << endl; // Expected: 2

    int M5[MAX][MAX] = {{1}, {1}, {0}, {1}};
    cout << "Test Case 5 (Single Column): " << obj.maxArea(M5, 4, 1) << endl; // Expected: 2

    int M6[MAX][MAX] = {{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};
    cout << "Test Case 6 (Large Alternating): " << obj.maxArea(M6, 3, 4) << endl; // Expected: 1

    int M7[MAX][MAX] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "Test Case 7 (Single 1): " << obj.maxArea(M7, 3, 3) << endl; // Expected: 1

    int M8[MAX][MAX] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}};
    cout << "Test Case 8 (Increasing Rows): " << obj.maxArea(M8, 3, 3) << endl; // Expected: 4

    return 0;
}
