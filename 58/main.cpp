#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  // w[i]: i번째 포도주 잔에 들어있는 포도주의 양
  // dp[i]: 포도주 잔 [1...i]에서 최대로 마실 수 있는 포도주의 양
  vector<int> w(n + 1), dp(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  dp[1] = w[1];
  if (n > 1) {
    dp[2] = dp[1] + w[2];
    for (int i = 3; i <= n; ++i) {
      // 잔 2개를 연속으로 선택하는 경우, 잔 1개를 선택하는 경우, 잔을 선택하지
      // 않는 경우
      dp[i] =
          max(max(dp[i - 3] + w[i - 1] + w[i], dp[i - 2] + w[i]), dp[i - 1]);
    }
  }
  // 결과 출력
  cout << dp[n] << '\n';
}
