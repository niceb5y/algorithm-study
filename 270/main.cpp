#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 987654321;

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
    adj[b][a] = c;
  }

  for (int i = 1; i <= n; ++i) {
    adj[i][i] = 0;
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }

  int a, b;
  cin >> a >> b;

  int ans = INF;
  if (adj[1][a] != INF && adj[a][b] != INF && adj[b][n] != INF) {
    ans = min(ans, adj[1][a] + adj[a][b] + adj[b][n]);
  }
  if (adj[1][b] != INF && adj[b][a] != INF && adj[a][n] != INF) {
    ans = min(ans, adj[1][b] + adj[b][a] + adj[a][n]);
  }

  cout << (ans == INF ? -1 : ans) << "\n";
}
