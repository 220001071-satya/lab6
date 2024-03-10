// satya narayan 
//220001071

// we use the toposort of the dag in this as a subroutine 

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int src, stack<int>& s, vector<bool>& vis){
    for(int adjNode : adj[src]){
        if(vis[adjNode] == false){
            vis[adjNode] = true;
            dfs(adj, adjNode, s, vis);
        }
    }
    s.push(src);
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
    stack<int> s;
    vector<bool> vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            vis[i] = true;
            dfs(adj, i, s, vis);
        }
    }
    vector<int> ans;
    while(s.empty() == false){
        //cout << s.top() << " " ;
        ans.push_back(s.top());
        s.pop();
    }
    vector<int> distance(n);
    for(int i = 0; i < n; i++){
        int src = ans[i];
        for(auto j : adj[src]){
            distance[j] = max(distance[src] + 1, distance[j]);
        }
    }
    int maxi = 0;
    for(auto i : distance) maxi = max(maxi, i);
    cout << maxi;
    return 0;
    
}