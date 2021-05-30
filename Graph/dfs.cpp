#include <bits/stdc++.h>
using namespace std;

void DFSRecur(vector<int> adj[],vector<bool> &vis,int u){
    vis[u]=true;
    cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i]] == false){
           DFSRecur(adj,vis,adj[u][i]); 
        }
    }
}

void DFS(vector<int> adj[],int n){
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false)
            DFSRecur(adj,vis,i);
    }
}
void print(vector<int> adj[],int n){
     for(int i=0;i<n;i++){
        cout<<"Adjacency list of node: "<<i<<" is :\n";
        for(auto x:adj[i]){
            cout<<"->"<<x<<endl;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(adj,n);
  // print(adj,n);
    return 0;
    /*
7 7
0 1
0 2
1 4
4 5
5 6
2 3
1 6
0 1 4 5 6 2 3*/
/*

int dfs(int node) {
    int visCount = 1;
    visited[node] = true;
    for (auto neighbour: graph[node]) {
        if (!visited[neighbour]) {
            visCount += dfs(neighbour);
        }
    }
    return visCount;
}
    
    */

/*
First it visits the starting node, which we call the root, and pushes it in a stack.
While the stack is not empty, the node at the top is examined and one of these two actions takes place:
If the node has unvisited neighbours, one of them is chosen, visited and pushed in the stack.
Otherwise, if all the node's neighbours had previously been visited the node presents no further interest and it is popped from the stack.
When the stack becomes empty it means that all the accessible nodes have been visited, so the algorithm ends.

*/
}
