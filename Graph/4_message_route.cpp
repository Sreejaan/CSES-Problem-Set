#include<bits/stdc++.h>
using namespace std;
 
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
    queue<int> qu;
    qu.push(1);
    vector<int> par(n+1, 0);
    par[1]=-1;
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto x : adj[curr]){
            if(par[x]==0){
                par[x] = curr;
                qu.push(x);
            }
        }
    }
    if(par[n]==0){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int> ans;
        int curr=n;
        while(curr!=-1){
            ans.push_back(curr);
            curr = par[curr];
        }
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
    }
 
}
int main()
{
    int test=1;
    while(test--){
        solve();
    }
    return 0;
}