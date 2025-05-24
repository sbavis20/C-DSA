#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(s);          // Push starting node to queue
    visited[s] = true;
    parent[s] = -1;

    // BFS
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    // Check if target was reached
    if (!visited[t]) {
        // No path found
        return ans;
    }

    // Reconstruct path from t to s using parent map
    int currentNode = t;
    while (currentNode != -1) {
        ans.push_back(currentNode);
        currentNode = parent[currentNode];
    }

    // Reverse to get path from s to t
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Test case 1
    vector<pair<int,int>> edges1 = {{1,2}, {2,3}, {3,4}, {1,4}};
    int n1 = 4, m1 = 4;
    int s1 = 1, t1 = 4;

    vector<int> path1 = shortestPath(edges1, n1, m1, s1, t1);
    if(path1.empty()) {
        cout << "No path found from " << s1 << " to " << t1 << "\n";
    } else {
        cout << "Shortest path from " << s1 << " to " << t1 << ": ";
        for(int node : path1) cout << node << " ";
        cout << "\n";
    }

    // Test case 2: No path
    vector<pair<int,int>> edges2 = {{1,2}, {2,3}, {4,5}};
    int n2 = 5, m2 = 3;
    int s2 = 1, t2 = 5;

    vector<int> path2 = shortestPath(edges2, n2, m2, s2, t2);
    if(path2.empty()) {
        cout << "No path found from " << s2 << " to " << t2 << "\n";
    } else {
        cout << "Shortest path from " << s2 << " to " << t2 << ": ";
        for(int node : path2) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
