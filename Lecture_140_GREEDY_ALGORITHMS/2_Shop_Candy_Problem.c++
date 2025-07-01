#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int K) {
    sort(candies, candies + N);  // sort in increasing order

    int mini = 0;
    int buy = 0;
    int free = N - 1;

    while (buy <= free) {
        mini += candies[buy];
        buy++;
        free -= K;
    }

    int maxi = 0;
    buy = N - 1;
    free = 0;

    while (free <= buy) {
        maxi += candies[buy];
        buy--;
        free += K;
    }

    return {mini, maxi};
}
int main() {
    int candies[] = {3, 2, 1, 4};
    int N = 4, K = 2;

    vector<int> result = candyStore(candies, N, K);
    cout << "Min cost: " << result[0] << ", Max cost: " << result[1] << endl;
    return 0;
}
