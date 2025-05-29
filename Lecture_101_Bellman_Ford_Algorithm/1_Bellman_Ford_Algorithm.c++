#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e9); // distance from src to all nodes
    dist[src] = 0;

    // Relax edges n - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            // Negative cycle detected
            return {-1};
        }
    }

    return dist;
}
int main() {
    int n = 5; // number of vertices
    int m = 8; // number of edges
    int src = 1;

    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1},
        {4, 3, 2},
        {5, 4, 2}
    };

    vector<int> result = bellmanFord(n, m, src, edges);

    if (result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected!" << endl;
    } else {
        cout << "Shortest distances from source " << src << ":" << endl;
        for (int i = 1; i <= n; i++) {
            cout << "Node " << i << " : ";
            if (result[i] == 1e9)
                cout << "Unreachable" << endl;
            else
                cout << result[i] << endl;
        }
    }

    return 0;
}
