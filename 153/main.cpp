#include <algorithm>
#include <iostream>

using namespace std;

int dp[30][30];

int comb(int n, int k) {
  if (k == 1)
    return n;
  if (n == k)
    return 1;
  int &ret = dp[n][k];
  if (ret != -1)
    return ret;
  ret = comb(n - 1, k) + comb(n - 1, k - 1);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  fill_n(&dp[0][0], 900, -1);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;
    cout << comb(m, n) << "\n";
  }
}
