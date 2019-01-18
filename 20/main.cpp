#include <iostream>
#include <vector>

using namespace std;
int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 동전 종류의 개수
  // k: 금액
  int n, k;
  cin >> n >> k;
  // coins: 동전의 금액을 저장할 벡터
  vector<int> coins(n);
  // ans: 문제의 정답
  int ans = 0;
  // coins에 동전의 값을 입력한다.
  for (auto &coin : coins) {
    cin >> coin;
  }
  // 큰 금액의 동전부터 금액에서 뺀다.
  for (int i = n - 1; i >= 0; --i) {
    auto coin = coins[i];
    while (k >= coin) {
      k -= coin;
      ++ans;
    }
  }
  // 정답 출력
  cout << ans << endl;
}
