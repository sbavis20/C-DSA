#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;

    // Create adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since it's an undirected graph
    }

    // Sort adjacency list for consistent traversal order
    for (auto &pair : adj) {
        pair.second.sort();
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            sort(component.begin(), component.end()); // Optional: sorted output
            ans.push_back(component);
        }
    }

    return ans;
}

// Example usage
int main() {
    int V = 5;
    int E = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 4},
        {1, 2}
    };

    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    for (const auto &component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
