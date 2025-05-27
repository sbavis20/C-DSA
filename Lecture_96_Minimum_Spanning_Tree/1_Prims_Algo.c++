#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Build adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // because it's undirected
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0; // Start from node 1

    for (int count = 1; count <= n - 1; count++) {
        int mini = INT_MAX, u;

        for (int v = 1; v <= n; v++) {
            if (!mst[v] && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        mst[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}
int main() {
    int n = 5, m = 6;
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 2},
        {{1, 3}, 3},
        {{1, 4}, 6},
        {{2, 3}, 5},
        {{2, 5}, 4},
        {{3, 5}, 7}
    };

    auto mst = calculatePrimsMST(n, m, edges);

    cout << "Minimum Spanning Tree edges:\n";
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << "\n";
    }

    return 0;
}
