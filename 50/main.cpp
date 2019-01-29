#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 계단의 수
  int n;
  cin >> n;
  // pt: 해당 계단을 밟았을 때 얻을 수 있는 점수
  // dp: 해당 계단까지 밟았을 때 얻을 수 있는 점수의 총합
  vector<int> pt(n), dp(n, 0);
  for (auto &i : pt) {
    cin >> i;
  }
  // 초기화
  dp[0] = pt[0];
  dp[1] = dp[0] + pt[1];
  dp[2] = max(dp[0] + pt[2], pt[1] + pt[2]);
  // 분할 정복
  for (int i = 3; i < n; ++i) {
    // 전 계단을 밟았을 때의 경우와, 전전 계단을 밟았을때의 경우로 나누어 계산한
    // 뒤, 최대값을 구한다.
    dp[i] = max(dp[i - 3] + pt[i - 1] + pt[i], dp[i - 2] + pt[i]);
  }
  // 정답 출력
  cout << dp[n - 1] << '\n';
}
