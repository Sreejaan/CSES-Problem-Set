#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

  for (int i = 1; i <= n; i++) dist[i][i] = 0;

  for (int i = 0; i < m; i++) {
    int u, v;
    long long c;
    cin >> u >> v >> c;
    dist[u][v] = min(dist[u][v], c);
    dist[v][u] = min(dist[v][u], c);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    if (dist[u][v] < INF) cout << dist[u][v] << "\n";
    else cout << -1 << "\n";
  }
}
