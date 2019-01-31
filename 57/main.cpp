#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 동전의 수
  // k: 동전으로 만들 금액
  // coins[i]: (i + 1) 번째 동전의 금액
  // dp[i]: 동전으로 i원을 만들 수 있는 방법의 수
  int n, k, coins[100], dp[10001];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }
  // dp 초기화
  // dp[0] = 1, 나머지는 0으로 초기화한다.
  for (int i = 0; i <= k; ++i) {
    dp[i] = (i == 0) ? 1 : 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (j >= coins[i]) {
        dp[j] += dp[j - coins[i]];
      }
    }
  }
  // 결과 출력
  cout << dp[k] << '\n';
}
