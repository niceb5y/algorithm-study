#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, p, c[401][401] = {}, f[401][401] = {};
  vector<int> adj[401];

  cin >> n >> p;
  for (int i = 0; i < p; ++i) {
    int u, v;
    cin >> u >> v;
    c[u][v] = c[v][u] += 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0, prev[401];
  const int s = 1, t = 2;

  while (true) {
    fill_n(&prev[0], 401, -1);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto &next : adj[cur]) {
        if (c[cur][next] > f[cur][next] && prev[next] == -1) {
          prev[next] = cur;
          q.push(next);
          if (next == t)
            break;
        }
      }
    }

    if (prev[t] == -1)
      break;

    int flow_limit = 10001, cur = t;
    while (cur != s) {
      flow_limit = min(flow_limit, c[prev[cur]][cur] - f[prev[cur]][cur]);
      cur = prev[cur];
    }
    cur = t;
    while (cur != s) {
      f[prev[cur]][cur] += flow_limit;
      f[cur][prev[cur]] -= flow_limit;
      cur = prev[cur];
    }

    ans += flow_limit;
  }

  cout << ans << "\n";
}
