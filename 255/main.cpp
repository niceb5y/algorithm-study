#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int m, n, k, ans = 0;
    cin >> m >> n >> k;
    vector<vector<bool>> area(n, vector<bool>(m, false)),
        visit(n, vector<bool>(m, false));
    while (k--) {
      int r, c;
      cin >> c >> r;
      area[r][c] = true;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (area[i][j] && !visit[i][j]) {
          queue<pair<int, int>> q({make_pair(i, j)});
          while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (visit[r][c])
              continue;
            visit[r][c] = true;
            if (r > 0 && !visit[r - 1][c] && area[r - 1][c])
              q.push(make_pair(r - 1, c));
            if (c > 0 && !visit[r][c - 1] && area[r][c - 1])
              q.push(make_pair(r, c - 1));
            if (r < n - 1 && !visit[r + 1][c] && area[r + 1][c])
              q.push(make_pair(r + 1, c));
            if (c < m - 1 && !visit[r][c + 1] && area[r][c + 1])
              q.push(make_pair(r, c + 1));
          }
          ++ans;
        }
      }
    }
    cout << ans << "\n";
  }
}
