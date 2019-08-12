#include <iostream>

using namespace std;

int dp[1001][1001] = {};

int bc(int n, int k) {
  int &ret = dp[n][k];
  if (ret != -1)
    return ret;

  if (k == 0 || k == n)
    return 1;

  ret = (bc(n - 1, k - 1) + bc(n - 1, k)) % 10007;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  fill_n(&dp[0][0], 1001 * 1001, -1);

  int n, k;
  cin >> n >> k;

  cout << bc(n, k) << "\n";
}
