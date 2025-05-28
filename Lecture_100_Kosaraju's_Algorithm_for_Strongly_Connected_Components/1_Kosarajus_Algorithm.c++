#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool>& vis, stack<int>& st,
         unordered_map<int, list<int>>& adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool>& vis,
            unordered_map<int, list<int>>& transpose) {
    vis[node] = true;
    for (auto nbr : transpose[node]) {
        if (!vis[nbr]) {
            revDfs(nbr, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;

    // Create original graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int vv = edges[i][1];
        adj[u].push_back(vv);
    }

    // Step 1: Topological sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // Step 2: Transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Step 3: DFS on transpose graph using stack order
    for (int i = 0; i < v; i++) {
        vis[i] = false; // reset visited
    }

    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!vis[top]) {
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}
int main() {
    int v = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    int result = stronglyConnectedComponents(v, edges);
    cout << "Number of Strongly Connected Components: " << result << endl;
    return 0;
}
