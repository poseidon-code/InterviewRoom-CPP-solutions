// PROBLEM: Cycle in undirected graph
// https://www.interviewbit.com/problems/cycle-in-undirected-graph/
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?category{]=Graph&category[]=Graph&page=1&query=category[]Graphpage1category[]Graph

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
bool dfs (vector<int> adj[], bool v[], int p, int s) {
    v[s] = true;

    for(auto i : adj[s]) {
        if(v[i]==false) {
            if(dfs(adj,v,s,i))
                return true;
        } else if (i!=p) {
            return true;
        }
    }

    return false;
}

bool is_cycle (vector<vector<int>>& graph, int n) {
    bool v[n+1] = {false};
    vector<int> adj[n+1];
    adj[0].push_back(-1);
    
    for(int i=0; i<graph.size(); i++) {
        adj[graph[i][0]].push_back(graph[i][1]);
        adj[graph[i][1]].push_back(graph[i][0]);
    }

    for(int i=1; i<n+1; i++) {
        if (v[i]==false)
            if (dfs(adj, v, -1, i))
                return true;
    }

    return false;
}


int main() {
    // INPUT :
    int n = 5;
    vector<vector<int>> graph = {{1,2},{1,3},{2,3},{1,4},{4,5}};

    // OUTPUT :
    is_cycle(graph, n) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}