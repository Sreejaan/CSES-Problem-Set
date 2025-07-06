#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
string conver(vector<vector<char>> &arr, int curr_x, int curr_y){
    string str = "";
    while (arr[curr_x][curr_y] != 'X') {
        char move = arr[curr_x][curr_y];
        str += move;
        if (move == 'D') curr_x--;
        else if (move == 'U') curr_x++;
        else if (move == 'R') curr_y--;
        else if (move == 'L') curr_y++;
    }
    reverse(str.begin(), str.end());
    return str;
}
 
string solve(){
    int n, m;
    cin >> n >> m;
    vector<string> path(n);
    for(auto &x : path) cin >> x;
 
    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(path[i][j] == 'A'){
                start_x = i;
                start_y = j;
            }
            if(path[i][j] == 'B'){
                end_x = i;
                end_y = j;
                path[i][j] = '.';
            }
        }
    }
 
    queue<pair<int, int>> qu;
    vector<vector<char>> par(n, vector<char>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
 
    qu.push({start_x, start_y});
    vis[start_x][start_y] = true;
    par[start_x][start_y] = 'X'; // unique marker for start
 
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};
 
    while(!qu.empty()){
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
 
        if(x == end_x && y == end_y){
            string ans = conver(par, x, y);
            cout << "YES\n" << ans.size() << "\n" << ans << "\n";
            return ans;
        }
 
        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && path[nx][ny] == '.' && !vis[nx][ny]){
                vis[nx][ny] = true;
                par[nx][ny] = dir[d];
                qu.push({nx, ny});
            }
        }
    }
 
    cout << "NO\n";
}
 
int main(){
    ll test = 1;
    while(test--){
        solve();
    }
    return 0;
}