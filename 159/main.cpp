#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b, c, cost = 0;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
  vector<int> dist(n + 1, INF);
  vector<bool> visited(n + 1, false);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    adj[a][b] = adj[b][a] = c;
  }
  dist[1] = 0;
  visited[1] = true;
  for (int i = 2; i <= n; ++i) {
    dist[i] = min(dist[i], adj[1][i]);
  }
  for (int i = 0; i < n - 1; ++i) {
    int near = 0, near_dist = INF;
    for (int j = 2; j <= n; ++j) {
      if (!visited[j] && dist[j] < near_dist) {
        near_dist = dist[j];
        near = j;
      }
    }
    dist[near] = 0;
    visited[near] = true;
    cost += near_dist;
    for (int i = 2; i <= n; ++i) {
      dist[i] = min(dist[i], adj[near][i]);
    }
  }
  cout << cost << endl;
}
