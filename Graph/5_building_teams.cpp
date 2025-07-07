#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int flag;
void dfs(int curr, vector<int> adj[], vector<int> &assign_team, int team){
    if(assign_team[curr]!=0){
        if(assign_team[curr]!=team)
            flag=1;
        return;
    }
    assign_team[curr]= team;
    for(auto child : adj[curr]){
        dfs(child, adj, assign_team, team==1 ? 2 : 1);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> assgin_team(n+1, 0);
    flag=0;
    for(int i=1;i<=n and flag==0;i++){
        if(assgin_team[i]==0){
            dfs(i, adj, assgin_team, 1);
        }
    }
    if(flag)cout<<"IMPOSSIBLE\n";
    else
    for(int i=1;i<=n;i++)cout<<assgin_team[i]<<" ";
}

int main()
{
    ll test=1;
    while(test--){
        solve();
    }
    return 0;
}