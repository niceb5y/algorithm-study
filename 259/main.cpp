#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<vector<bool>>> visit;

int main() {

  int n, m;
  scanf("%d %d", &n, &m);
  map.resize(n, vector<int>(m));
  visit.resize(2, vector<vector<bool>>(n, vector<bool>(m, false)));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%1d", &map[i][j]);
    }
  }

  queue<tuple<int, int, int, bool>> q({make_tuple(0, 0, 1, true)});
  while (!q.empty()) {
    auto [r, c, d, x] = q.front();
    q.pop();

    if (visit[x][r][c])
      continue;
    visit[x][r][c] = true;

    if (r == n - 1 && c == m - 1) {
      printf("%d\n", d);
      return 0;
    }

    if (r > 0 && !visit[x][r - 1][c] && map[r - 1][c] == 0)
      q.push(make_tuple(r - 1, c, d + 1, x));
    if (c > 0 && !visit[x][r][c - 1] && map[r][c - 1] == 0)
      q.push(make_tuple(r, c - 1, d + 1, x));
    if (r < n - 1 && !visit[x][r + 1][c] && map[r + 1][c] == 0)
      q.push(make_tuple(r + 1, c, d + 1, x));
    if (c < m - 1 && !visit[x][r][c + 1] && map[r][c + 1] == 0)
      q.push(make_tuple(r, c + 1, d + 1, x));

    if (r > 0 && !visit[x][r - 1][c] && x)
      q.push(make_tuple(r - 1, c, d + 1, false));
    if (c > 0 && !visit[x][r][c - 1] && x)
      q.push(make_tuple(r, c - 1, d + 1, false));
    if (r < n - 1 && !visit[x][r + 1][c] && x)
      q.push(make_tuple(r + 1, c, d + 1, false));
    if (c < m - 1 && !visit[x][r][c + 1] && x)
      q.push(make_tuple(r, c + 1, d + 1, false));
  }

  printf("-1\n");
}
