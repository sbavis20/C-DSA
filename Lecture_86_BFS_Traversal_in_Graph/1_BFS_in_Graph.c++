#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;

// Function to prepare adjacency list
void prepareAdjList(unordered_map<int, set<int>>& adjList, vector<pair<int, int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u); // For undirected graph
    }
}

// Single component BFS
void bfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

// Complete BFS traversal (handles disconnected components)
vector<int> bfsTraversal(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// Main function with test case
int main() {
    int V = 6;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {4, 5}
    };

    vector<int> result = bfsTraversal(V, edges);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
