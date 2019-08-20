#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 987654321;

  int v, e;
  cin >> v >> e;

  vector<vector<int>> adj(v + 1, vector<int>(v + 1, INF));

  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
  }

  for (int k = 1; k <= v; ++k) {
    for (int i = 1; i <= v; ++i) {
      for (int j = 1; j <= v; ++j) {
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= v; ++i) {
    if (ans > adj[i][i]) {
      ans = adj[i][i];
    }
  }
  cout << (ans == INF ? -1 : ans) << "\n";
}
