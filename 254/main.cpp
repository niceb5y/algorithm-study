#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visit;

int main() {

  int n;
  scanf("%d", &n);
  map.resize(n, vector<int>(n));
  visit.resize(n, vector<bool>(n, false));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%1d", &map[i][j]);
    }
  }

  vector<int> ans;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map[i][j] == 1 && !visit[i][j]) {
        queue<pair<int, int>> q({make_pair(i, j)});
        int size = 0;
        while (!q.empty()) {
          auto [r, c] = q.front();
          q.pop();
          if (visit[r][c])
            continue;
          visit[r][c] = true;
          ++size;
          if (r > 0 && !visit[r - 1][c] && map[r - 1][c] == 1)
            q.push(make_pair(r - 1, c));
          if (c > 0 && !visit[r][c - 1] && map[r][c - 1] == 1)
            q.push(make_pair(r, c - 1));
          if (r < n - 1 && !visit[r + 1][c] && map[r + 1][c] == 1)
            q.push(make_pair(r + 1, c));
          if (c < n - 1 && !visit[r][c + 1] && map[r][c + 1] == 1)
            q.push(make_pair(r, c + 1));
        }
        ans.push_back(size);
      }
    }
  }
  printf("%d\n", (int)ans.size());
  sort(ans.begin(), ans.end());
  for (auto &i : ans) {
    printf("%d\n", i);
  }
}
