#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, long long int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v, d;
        cin>>u>>v>>d;
        adj[u].push_back({v, d});
    }
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, 1});
    vector<long long int> dis(n+1, LONG_MAX);
    dis[1]=0;
    while(!pq.empty()){
        auto x = pq.top(); pq.pop();
        if(x.first>dis[x.second])continue;
        for(auto child : adj[x.second]){
            if(dis[child.first]>dis[x.second] +  child.second){
                pq.push({dis[x.second] + child.second, child.first});
                dis[child.first] = dis[x.second] + child.second;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    return 0;
}