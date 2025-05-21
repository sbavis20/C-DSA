#include <iostream>
#include <unordered_map>
#include<list>
using namespace std;

class Graph {


public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    // Print the adjacency matrix
    void display() {
        cout << "Adjacency list:\n";
        for(auto i: adj){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << j << " ";
            }

            cout << endl;
        }
    }
};

// ------------------ MAIN FUNCTION WITH TEST CASE ------------------
int main() {
    int vertices = 4;
    Graph g;
    // 0->1, 0->2, 1->2, 2->3
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    // 0->1, 0->2, 1->2, 2->3
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);

    g.display();

    return 0;
}
