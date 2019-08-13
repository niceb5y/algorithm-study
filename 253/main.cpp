#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> visit(n + 1, false);
  queue<int> q({1});
  int ans = -1;

  while (!q.empty()) {
    const int front = q.front();
    q.pop();
    if (visit[front])
      continue;
    visit[front] = true;
    ++ans;
    for (auto &node : adj[front]) {
      if (!visit[node])
        q.push(node);
    }
  }

  cout << ans << "\n";
}
