#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++) {
        v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int ansEnd = v[0].second;

    for(int i = 1; i < n; i++) {
        if(v[i].first > ansEnd) {
            count++;
            ansEnd = v[i].second;
        }
    }

    return count;
}
int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    cout << maxMeetings(start, end, n);  // Output: 4
}
