#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> match;

bool DFS(int a) {
  if (visited[a])
    return false;

  visited[a] = true;
  for (auto &b : adj[a]) {
    if (match[b] == -1 || DFS(match[b])) {
      match[b] = a;
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, cnt = 0;
  cin >> n >> m;
  adj.resize(n + 1);
  visited.resize(n + 1);
  match.resize(m + 1, -1);
  for (int i = 1; i <= n; ++i) {
    int sz;
    cin >> sz;
    adj[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      cin >> adj[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    fill(visited.begin(), visited.end(), false);
    if (DFS(i))
      ++cnt;
  }

  cout << cnt << "\n";
}
