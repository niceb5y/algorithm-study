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
    adj[a][b] = min(adj[a][b], c);
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

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (adj[i][j] == INF ? 0 : adj[i][j]) << (j == n ? "\n" : " ");
    }
  }
}
