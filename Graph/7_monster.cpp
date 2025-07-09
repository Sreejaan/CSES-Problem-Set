#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;
const vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
const vector<char> dir_char = {'D', 'U', 'R', 'L'};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& row : grid) cin >> row;

    queue<pair<int, int>> q;
    vector<vector<int>> monster_time(n, vector<int>(m, INF));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pair<int, int> start;

    // Monster BFS
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                monster_time[i][j] = 0;
                visited[i][j] = true;
            } else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    int step = 1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int x= q.front().first, y = q.front().second;  q.pop();
            for (auto &d: directions) {
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    !visited[nx][ny] && grid[nx][ny] != '#') {
                    visited[nx][ny] = true;
                    monster_time[nx][ny] = step;
                    q.push({nx, ny});
                }
            }
        }
        ++step;
    }

    // A's BFS with parent tracking
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> path(n, vector<char>(m, 0));
    q.push(start);
    parent[start.first][start.second] = {-2, -2}; // Mark start
    step = 1;
    pair<int, int> end = {-1, -1};

    while (!q.empty() && end.first == -1) {
        int sz = q.size();
        while (sz--) {
            int x= q.front().first, y = q.front().second; q.pop();

            if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                end = {x, y};
                break;
            }

            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d].first, ny = y + directions[d].second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    parent[nx][ny].first == -1 &&
                    grid[nx][ny] == '.' && monster_time[nx][ny] > step) {
                    parent[nx][ny] = {x, y};
                    path[nx][ny] = dir_char[d];
                    q.push({nx, ny});
                }
            }
        }
        ++step;
    }

    if (end.first == -1) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string result_path;
    for (auto p = end; parent[p.first][p.second] != make_pair(-2, -2);) {
        result_path += path[p.first][p.second];
        p = parent[p.first][p.second];
    }
    reverse(result_path.begin(), result_path.end());

    cout << "YES\n" << result_path.size() << "\n" << result_path << "\n";
    return 0;
}
