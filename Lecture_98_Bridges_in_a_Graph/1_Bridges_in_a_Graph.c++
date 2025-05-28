#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis) {

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent)
            continue;

        if (!vis[nbr]) {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // Check for bridge
            if (low[nbr] > disc[node]) {
                result.push_back({node, nbr});
            }
        } else {
            // Back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    int timer = 0;
    vector<vector<int>> result;

    // Run DFS for all components
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, -1, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}
int main() {
    int v = 5, e = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "Bridges in the graph:\n";
    for (auto &bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << "\n";
    }

    return 0;
}
