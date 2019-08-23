#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj;

pair<int, int> bfs(int x) {
  int v, d = 0;
  queue<pair<int, int>> q({make_pair(x, 0)});
  vector<bool> visit(10001, false);

  while (!q.empty()) {
    auto [cv, cd] = q.front();
    q.pop();

    if (cd > d) {
      d = cd;
      v = cv;
    }

    for (auto edge : adj[cv]) {
      auto [ev, ed] = edge;
      if (!visit[ev]) {
        visit[cv] = true;
        q.push(make_pair(ev, cd + ed));
      }
    }
  }

  return make_pair(v, d);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  adj.resize(10001);
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  auto [a, tmp] = bfs(1);
  auto [b, ans] = bfs(a);

  cout << ans << "\n";
}
