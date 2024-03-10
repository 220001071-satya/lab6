// satya narayan
// 220001071

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
}