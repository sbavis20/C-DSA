#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

static bool cmp(pair<double, Item> a, pair<double, Item> b) {
    return a.first > b.first; // Sort by value per weight in descending order
}

double fractionalKnapsack(int W, Item arr[], int n) {
    vector<pair<double, Item>> v;

    for (int i = 0; i < n; i++) {
        double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
        v.push_back({perUnitValue, arr[i]});
    }

    sort(v.begin(), v.end(), cmp);

    double totalValue = 0.0;
    for (int i = 0; i < n && W > 0; i++) {
        if (v[i].second.weight <= W) {
            totalValue += v[i].second.value;
            W -= v[i].second.weight;
        } else {
            totalValue += v[i].first * W;
            W = 0;
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Total capacity of the knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxVal = fractionalKnapsack(W, arr, n);
    cout << "Maximum value in Knapsack = " << fixed << setprecision(2) << maxVal << endl;

    return 0;
}
