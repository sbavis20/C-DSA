#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    void printAdj() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    void topoSort(int node, unordered_map<int, bool>& visited, stack<int>& topo) {
        visited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour.first]) {
                topoSort(neighbour.first, visited, topo);
            }
        }

        topo.push(node);
    }

    void shortestPathDAG(int src, int n) {
        unordered_map<int, bool> visited;
        stack<int> topo;

        // Topological sort for all nodes (in case of disconnected components)
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                topoSort(i, visited, topo);
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!topo.empty()) {
            int top = topo.top();
            topo.pop();

            if (dist[top] != INT_MAX) {
                for (auto neighbour : adj[top]) {
                    if (dist[top] + neighbour.second < dist[neighbour.first]) {
                        dist[neighbour.first] = dist[top] + neighbour.second;
                    }
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX)
                cout << i << " : INF" << endl;
            else
                cout << i << " : " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g;

    // DAG with 6 nodes
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();
    cout << "\n";

    int source = 1;
    g.shortestPathDAG(source, 6);

    return 0;
}
