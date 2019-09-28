#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> node;
vector<vector<node>> adj;

int n, m;
const int INF = 987654321;

void dijk(int source, vector<int> &dist) {
  priority_queue<node, vector<node>, greater<node>> pq;
  dist[source] = 0;
  pq.push(make_pair(0, source));

  while (!pq.empty()) {
    node top = pq.top();
    pq.pop();

    if (dist[top.second] < top.first)
      continue;

    dist[top.second] = top.first;
    for (auto &edge : adj[top.second]) {
      if (dist[edge.second] > edge.first + dist[top.second]) {
        dist[edge.second] = edge.first + dist[top.second];
        pq.push(make_pair(dist[edge.second], edge.second));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    adj[a].push_back(make_pair(t, b));
    adj[b].push_back(make_pair(t, a));
  }

  int u, v, w;
  cin >> u >> v >> w;

  vector<int> dist_u(n + 1, INF), dist_v(n + 1, INF), dist_w(n + 1, INF);
  dijk(u, dist_u);
  dijk(v, dist_v);
  dijk(w, dist_w);

  int ans = INF;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, max(dist_u[i], max(dist_v[i], dist_w[i])));
  }

  cout << ans << endl;
}
