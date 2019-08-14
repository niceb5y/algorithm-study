#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n, h, ans = 0, unripe = 0;
  cin >> m >> n >> h;

  queue<tuple<int, int, int, int>> q;
  vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        cin >> box[i][j][k];
        if (box[i][j][k] == 1)
          q.push(make_tuple(i, j, k, 0));
        else if (box[i][j][k] == 0)
          ++unripe;
      }
    }
  }

  while (!q.empty()) {
    auto [z, r, c, d] = q.front();
    q.pop();

    if (d > 1 && box[z][r][c] > 0)
      continue;
    if (box[z][r][c] != 1)
      --unripe;

    box[z][r][c] = 1;
    ans = d;

    if (r > 0 && box[z][r - 1][c] == 0)
      q.push(make_tuple(z, r - 1, c, d + 1));
    if (r < n - 1 && box[z][r + 1][c] == 0)
      q.push(make_tuple(z, r + 1, c, d + 1));

    if (c > 0 && box[z][r][c - 1] == 0)
      q.push(make_tuple(z, r, c - 1, d + 1));
    if (c < m - 1 && box[z][r][c + 1] == 0)
      q.push(make_tuple(z, r, c + 1, d + 1));

    if (z > 0 && box[z - 1][r][c] == 0)
      q.push(make_tuple(z - 1, r, c, d + 1));
    if (z < h - 1 && box[z + 1][r][c] == 0)
      q.push(make_tuple(z + 1, r, c, d + 1));
  }

  cout << (unripe == 0 ? ans : -1) << "\n";
}
