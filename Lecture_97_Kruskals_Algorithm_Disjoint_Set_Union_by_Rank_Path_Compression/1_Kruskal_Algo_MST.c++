#include <bits/stdc++.h>
using namespace std;

// Comparator to sort edges based on weight
bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

// Initialize parent and rank
void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find parent with path compression
int findParent(vector<int> &parent, int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

// Union by rank
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v) return;

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal’s MST Algorithm
int kruskalMST(vector<vector<int>> &edges, int n) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (findParent(parent, u) != findParent(parent, v)) {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}
int main() {
    int n = 5; // number of vertices (0 to 4)
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mstWeight = kruskalMST(edges, n);
    cout << "Total weight of Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}
