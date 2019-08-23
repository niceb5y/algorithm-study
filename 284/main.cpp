#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, m, a, b, c, s, e;
vector<vector<pair<int, int>>> adj;
vector<int> dist, pre;

void print_cnt(int x) {
  int ans = 1;
  while (x != s) {
    ++ans;
    x = pre[x];
  }
  cout << ans << "\n";
}

void print_path(int x) {
  if (x != s)
    print_path(pre[x]);
  cout << x << (x == e ? "\n" : " ");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 987654321;

  cin >> n >> m;

  adj.resize(n + 1);
  dist.resize(n + 1, INF);
  pre.resize(n + 1);

  while (m--) {
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(c, b));
  }

  cin >> s >> e;

  priority_queue<pair<int, int>> pq;
  pq.push({0, s});
  dist[s] = 0;

  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (dist[v] < d)
      continue;

    dist[v] = d;

    for (auto &edge : adj[v]) {
      auto [ed, ev] = edge;
      if (dist[ev] > ed + dist[v]) {
        dist[ev] = ed + dist[v];
        pq.push(make_pair(dist[ev], ev));
        pre[ev] = v;
      }
    }
  }

  cout << dist[e] << "\n";
  print_cnt(e);
  print_path(e);
}
