#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct vec {
  int x1;
  int y1;
  int x2;
  int y2;
};

int n, m, k;
vector<vector<long long>> arr;
vector<vec> disabled;

bool is_disabled(int x1, int y1, int x2, int y2) {
  for (int i = 0; i < k; ++i) {
    if (((disabled[i].x1 == x1) && (disabled[i].y1 == y1) &&
         (disabled[i].x2 == x2) && (disabled[i].y2 == y2)) ||
        ((disabled[i].x1 == x2) && (disabled[i].y1 == y2) &&
         (disabled[i].x2 == x1) && (disabled[i].y2 == y1)))
      return true;
  }
  return false;
}

int main() {
  cin >> n >> m >> k;

  arr.resize(n + 1, vector<long long>(m + 1, 0));
  disabled.resize(k);

  for (auto &d : disabled) {
    cin >> d.x1 >> d.y1 >> d.x2 >> d.y2;
  }

  arr[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (!is_disabled(i, 0, i - 1, 0))
      arr[i][0] = arr[i - 1][0];
  }
  for (int i = 1; i <= m; ++i) {
    if (!is_disabled(0, i, 0, i - 1))
      arr[0][i] = arr[0][i - 1];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!is_disabled(i, j, i - 1, j))
        arr[i][j] += arr[i - 1][j];
      if (!is_disabled(i, j, i, j - 1))
        arr[i][j] += arr[i][j - 1];
    }
  }

  cout << arr[n][m] << endl;
  return 0;
}
