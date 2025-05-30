#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;

bool checkCycleDFS(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    dfsVisited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour,visited,dfsVisited,adj);
            if(cycleDetected){
                return true;
            }
        }else if(dfsVisited[neighbour]){
                    return true;
            }

    }
    dfsVisited[node]=false;
    return false;

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    unordered_map<int,list<int> >adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first-1;
        int v = edges[i].second-1;

        adj[u].push_back(v);

    }

    vector<int>indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int cnt =0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;

        for(auto neighbour: adj[front]){
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }

    }

    if(cnt==n){
        return false;
    }else{
        return true;
    }

}

