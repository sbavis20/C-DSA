#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToRight(vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while(s.top() >= curr) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> result = nearestSmallerToRight(arr, n);
        for(int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
