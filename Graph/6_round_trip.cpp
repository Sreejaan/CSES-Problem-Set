#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
vector<vector<int>> adj;
vector<int> cycle;
bool dfs(int curr, int par, vector<bool> &vis, vector<int> &path, vector<int> &posInPath){
    vis[curr]=1;
    path.push_back(curr);
    posInPath[curr] = path.size()-1;
    for(auto child : adj[curr]){
        if(vis[child]==0){if(dfs(child, curr, vis, path, posInPath))return true;}
        else if(child!=par){
            cycle = vector<int>(path.begin() + posInPath[child], path.end());
            cycle.push_back(child);
            return true;
        }
    }
    path.pop_back();
    return false;
}
bool hasCycle(){
    int n = adj.size();
    vector<bool> vis(n, 0);
    vector<int> path;
    vector<int> posInPath(n, -1);
    for(int i=1;i<n;i++){
        if(vis[i]==0){
            if(dfs(i, -1, vis, path, posInPath))return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(!hasCycle()){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<cycle.size()<<endl;
        for(int i=0;i<(int)cycle.size();i++)cout<<cycle[i]<<" ";
    }
    return 0;
}