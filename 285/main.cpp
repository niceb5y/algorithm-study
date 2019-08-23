#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int V;
vector<vector<pair<int, int>>> adj;

pair<int, int> bfs(int x) {
  int v, d = 0;
  queue<pair<int, int>> q({make_pair(x, 0)});
  vector<bool> visit(V + 1, false);

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

  cin >> V;

  adj.resize(V + 1);
  for (int i = 0; i < V; ++i) {
    int n;
    cin >> n;
    while (true) {
      int x, d;
      cin >> x;
      if (x == -1)
        break;
      cin >> d;
      adj[n].push_back(make_pair(x, d));
    }
  }

  auto [a, tmp] = bfs(1);
  auto [b, ans] = bfs(a);

  cout << ans << "\n";
}
