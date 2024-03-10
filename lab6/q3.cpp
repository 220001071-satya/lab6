// satya narayan 
// 220001071

// strongly connected components using kosaraju algorithm
// using dfs as a subroutine so the time complexcity is again O(V + E)
#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void dfs(vector<vector<int>>& adj, vector<bool>& vis, int src){
    vis[src] = true;
    for(auto adjNode : adj[src]){
        if(vis[adjNode] == false){
            dfs(adj, vis, adjNode);
        }
    }
    s.push(src);
}
void DFS(vector<vector<int>>& adj, vector<bool>& vis, int src){
    vis[src] = true;
    for(auto adjNode : adj[src]){
        if(vis[adjNode] == false){
            DFS(adj, vis, adjNode);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges;
    int k; 
    cin >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<vector<int>> adj(n); // making the adjaceny list for the given graph
    for(auto ve : edges){
        int u = ve[0];
        int v = ve[1];
        adj[u].push_back(v);
    }
            vector<bool> visited(n); 
        for(int i = 0; i < n; i++){
            if(visited[i] == false) dfs(adj, visited, i);
        }
        vector<vector<int>> T_adj(n);
        for(int i = 0; i < n; i++){
            for(auto u : adj[i]){
                T_adj[u].push_back(i);
            }
        }
        vector<bool> vis(n, false);
        int count = 0;
        while(s.empty() == false){
            if(vis[s.top()] == false) {DFS(T_adj, vis, s.top()); count++;}
            s.pop();
        }
        cout << count;
        return 0;
}