#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

vector<vector<int>> maze;
vector<vector<bool>> visit;

int main() {

  int n, m;
  scanf("%d %d", &n, &m);
  maze.resize(n, vector<int>(m));
  visit.resize(n, vector<bool>(m, false));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%1d", &maze[i][j]);
    }
  }

  queue<tuple<int, int, int>> q({make_tuple(0, 0, 1)});
  while (!q.empty()) {
    auto [r, c, d] = q.front();
    q.pop();
    if (visit[r][c])
      continue;
    if (r == n - 1 && c == m - 1) {
      printf("%d\n", d);
      return 0;
    }
    visit[r][c] = true;
    if (r > 0 && !visit[r - 1][c] && maze[r - 1][c] == 1)
      q.push(make_tuple(r - 1, c, d + 1));
    if (c > 0 && !visit[r][c - 1] && maze[r][c - 1] == 1)
      q.push(make_tuple(r, c - 1, d + 1));
    if (r < n - 1 && !visit[r + 1][c] && maze[r + 1][c] == 1)
      q.push(make_tuple(r + 1, c, d + 1));
    if (c < m - 1 && !visit[r][c + 1] && maze[r][c + 1] == 1)
      q.push(make_tuple(r, c + 1, d + 1));
  }
}
