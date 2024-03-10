// satya narayan
// 220001071

// using dfs as a subroutine so the time complexcity is again O(V + E)

#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>& adj, int src, vector<int>& vis){
    vis[src] = 1;
    for(auto adjNode : adj[src]){
        if(vis[adjNode] == 0){
            if(dfs(adj, adjNode, vis)) return true;
        }
        else if(vis[adjNode] == 1) return true;
    }
    return false;
}
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
    vector<int> vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            if(dfs(adj, i, vis) == true){
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
    return 0;
}
