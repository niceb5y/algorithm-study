#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 987654321;

  int N, M;
  cin >> N >> M;

  vector<long long> dist(N + 1);
  for (int j = 1; j <= N; ++j) {
    dist[j] = INF;
  }
  dist[1] = 0;

  vector<vector<pair<int, int>>> path(N + 1);
  for (int j = 0; j < M; ++j) {
    int s, e, t;
    cin >> s >> e >> t;
    path[s].emplace_back(make_pair(e, t));
  }

  vector<bool> is_exists(N + 1, false);
  vector<int> cnt(N + 1, 0);

  queue<int> q({1});
  is_exists[1] = true;

  bool has_cycle = false;

  while (!q.empty()) {
    const int u = q.front();
    q.pop();
    is_exists[u] = false;
    if (++cnt[u] >= N) {
      has_cycle = true;
      break;
    }

    for (auto &p : path[u]) {
      const int v = p.first, w = p.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        if (!is_exists[v]) {
          q.emplace(v);
          is_exists[v] = true;
        }
      }
    }
  }
  if (has_cycle) {
    cout << -1 << "\n";
  } else {
    for (int i = 2; i <= N; ++i) {
      cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
  }
}
