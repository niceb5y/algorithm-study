#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> node;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 987654321;

  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> day(n + 1, vector<int>(m + 1, INF));
    day[1][0] = 0;

    vector<vector<node>> adj(n + 1);
    while (k--) {
      int u, v, c, d;
      cin >> u >> v >> c >> d;
      adj[u].emplace_back(make_tuple(d, v, c));
    }

    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push(make_tuple(0, 1, 0));

    bool path_exist = false;

    while (!pq.empty()) {
      auto [d, u, c] = pq.top();
      pq.pop();

      if (day[u][c] < d)
        continue;

      if (u == n) {
        cout << d << "\n";
        path_exist = true;
        break;
      }

      for (auto edge : adj[u]) {
        auto [ed, ev, ec] = edge;
        if (day[ev][ec + c] > ed + d && ec + c <= m) {
          day[ev][ec + c] = ed + d;
          pq.push(make_tuple(day[ev][ec + c], ev, ec + c));
        }
      }
    }

    if (!path_exist)
      cout << "Poor KCM\n";
  }
}
