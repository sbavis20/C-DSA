#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, unordered_map<int, bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj);
        }
    }

    s.push(node); // Push after visiting all children
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    // Handle disconnected components
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
int main() {
    int v = 6;
    int e = 6;
    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = topologicalSort(edges, v, e);
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
