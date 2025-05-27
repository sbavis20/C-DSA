#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Adjacency list: node -> {neighbour, weight}
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Because it's undirected
    }

    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> st; // {distance, node}

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty()) {
        auto top = *(st.begin());
        st.erase(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        for (auto neighbour : adj[topNode]) {
            int newDist = nodeDistance + neighbour.second;

            if (newDist < dist[neighbour.first]) {
                // If previously in set, remove it
                auto record = st.find({dist[neighbour.first], neighbour.first});
                if (record != st.end()) {
                    st.erase(record);
                }

                // Update distance and reinsert
                dist[neighbour.first] = newDist;
                st.insert({newDist, neighbour.first});
            }
        }
    }

    return dist;
}

int main() {
    int vertices = 5;
    int edges = 6;
    vector<vector<int>> edgeList = {
        {0, 1, 7},
        {0, 2, 1},
        {1, 2, 3},
        {1, 3, 2},
        {2, 3, 2},
        {3, 4, 1}
    };

    int source = 0;
    vector<int> result = dijkstra(edgeList, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << " : " << result[i] << endl;
    }

    return 0;
}
