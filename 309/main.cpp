#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int LIMIT = 62501, MAX = 987654321;

  int n;
  cin >> n;

  vector<pii> time(n);
  for (auto &t : time) {
    cin >> t.first >> t.second;
  }

  vector<vector<int>> dp(2, vector<int>(LIMIT, MAX));
  dp[0][time[0].first] = 0;
  dp[0][0] = time[0].second;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < LIMIT; ++j) {
      if (j >= time[i].first)
        dp[1][j] = dp[0][j - time[i].first];
      dp[1][j] = min(dp[1][j], dp[0][j] + time[i].second);
    }

    for (int j = 0; j < LIMIT; ++j) {
      dp[0][j] = dp[1][j];
      dp[1][j] = MAX;
    }
  }

  int ans = MAX;
  for (int i = 0; i < LIMIT; i++)
    ans = min(ans, max(i, dp[0][i]));

  cout << ans << '\n';
}
