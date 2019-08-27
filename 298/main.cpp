#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), c(n), dp(10001, 0);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> c[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 10000; j >= c[i]; --j) {
      dp[j] = max(dp[j], dp[j - c[i]] + a[i]);
    }
  }
  for (int i = 0; i <= 10000; ++i) {
    if (dp[i] >= m) {
      cout << i << endl;
      break;
    }
  }
}
