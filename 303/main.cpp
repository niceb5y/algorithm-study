#include <algorithm>
#include <iostream>
using namespace std;

int sq[320];
int dp[100001];

int solve(int n) {
  int &ret = dp[n];
  if (ret != -1)
    return ret;
  ret = 987654321;
  if (n == 0) {
    ret = 0;
    return ret;
  }
  for (int i = 1; i < 320; ++i) {
    if (n < sq[i])
      continue;
    if (n == sq[i]) {
      ret = 1;
      return ret;
    }
    ret = min(ret, 1 + solve(n - sq[i]));
  }
  return ret;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 320; ++i) {
    sq[i] = (320 - i) * (320 - i);
  }
  for (int i = 0; i <= 100000; ++i) {
    dp[i] = -1;
  }

  int n;
  cin >> n;

  cout << solve(n) << "\n";
  return 0;
}
