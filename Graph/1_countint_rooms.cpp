#include<bits/stdc++.h>
using namespace std;
#define v vector<long long>
#define pb push_back
#define ll long long int

void dfs(vector<string> &arr, int i, int j){
    if(i<0 || j<0 || arr.size()==i || arr[0].size()==j)return ;
    if(arr[i][j]=='#')return ;
    arr[i][j] = '#';
    dfs(arr, i+1, j);
    dfs(arr, i, j+1);
    dfs(arr, i-1, j);
    dfs(arr, i, j-1);
}
void solve(){
    int n, m;
    cin>>n>>m;
    vector<string> arr(n);
    for(auto &x : arr)cin>>x;
 
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.')dfs(arr, i, j), count++;
        }
    }
    cout<<count<<endl;
}
int main()
{
    ll test=1;
    while(test--){
        solve();
    }
    return 0;
}