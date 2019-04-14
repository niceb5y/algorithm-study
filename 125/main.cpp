#include <algorithm>
#include <iostream>

using namespace std;

int n, cost[21], joy[21], dp[21][101];

int solve(int m, int e) {
  int ret = dp[m][e];
  if (ret != -1)
    return ret;
  if (m == 0 || e <= 0)
    return 0;
  ret = solve(m - 1, e);
  if (cost[m] < e) {
    ret = max(ret, solve(m - 1, e - cost[m]) + joy[m]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> joy[i];
  }
  fill_n(&dp[0][0], 21 * 101, -1);
  cout << solve(n, 100) << endl;
}
