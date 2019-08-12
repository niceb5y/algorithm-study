#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, w, v;
  cin >> n >> k;

  vector<int> dp(k + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> w >> v;
    for (int i = k; i > 0; --i) {
      if (i < w)
        break;
      dp[i] = max(dp[i], dp[i - w] + v);
    }
  }

  cout << dp[k] << "\n";
}
