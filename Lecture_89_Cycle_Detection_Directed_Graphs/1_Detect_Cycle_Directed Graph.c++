#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (checkCycleDFS(neighbour, visited, dfsVisited, adj)) {
                return true;
            }
        } else if (dfsVisited[neighbour]) {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (checkCycleDFS(i, visited, dfsVisited, adj)) {
                return 1; // Cycle found
            }
        }
    }

    return 0; // No cycle found
}


int main() {
    int n = 4;
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2}  // Cycle: 2 -> 3 -> 4 -> 2
    };

    cout << (detectCycleInDirectedGraph(n, edges) ? "Cycle Detected" : "No Cycle") << endl;
    return 0;
}
