#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
typedef pair<int, int> node;

vector<int> dijk(const vector<vector<node>> &adj, const int n, const int src) {
  vector<int> dist(n + 1, INF);
  dist[src] = 0;

  priority_queue<node, vector<node>, greater<node>> pq;
  pq.push(make_pair(0, src));

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
      }
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;

    vector<vector<node>> adj(n + 1);
    int gh = INF;
    while (m--) {
      int a, b, d;
      cin >> a >> b >> d;
      adj[a].push_back(make_pair(d, b));
      adj[b].push_back(make_pair(d, a));
      if ((a == g && b == h) || (a == h && b == g)) {
        gh = d;
      }
    }

    vector<int> ds(dijk(adj, n, s)), dg(dijk(adj, n, g)), dh(dijk(adj, n, h)),
        ans;
    while (t--) {
      int x;
      cin >> x;
      if (ds[x] == ds[g] + gh + dh[x] || ds[x] == ds[h] + gh + dg[x])
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());

    for (size_t i = 0; i < ans.size(); ++i) {
      cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
  }
}
