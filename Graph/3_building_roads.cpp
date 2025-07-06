#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

vector<ll> find_prime(ll n){
    vector<bool> prime(n+1, 1);
    for(ll i=2;i*i<=n;i++){
        if(prime[i]==0)continue;
        for(ll j=i*i;j<=n;j+=i)prime[j]=0;
    }
    vector<ll> p;
    for(ll i=2;i<=n;i++)if(prime[i])p.push_back(i);
    return p;
}
void dfs(int curr, vector<bool> &vis, vector<int> adj[]){
    if(vis[curr])return;
    vis[curr]=1;
    for(auto x : adj[curr]){
        dfs(x, vis, adj);
    }
}
void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1, 0);
    queue<int> road;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            road.push(i);
            dfs(i, vis, adj);
        }
    }
    cout<<road.size()-1<<endl;
    int prev=-1;
    if(prev==-1){
            prev = road.front();
            road.pop();
    }
    while(!road.empty()){
        cout<<prev<<" "<<road.front()<<endl;
        prev = road.front();
        road.pop();
    }
    
}
int main()
{
    ll test=1;
 
    while(test--){
        solve();
    }
    return 0;
}