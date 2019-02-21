#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  // n: 범위 [1...n] 중에 n과 서로소인 수의 개수를 구할 양의 정수 n
  ll n;
  cin >> n;
  // ans: 양의 정수 n에 대하여 범위 [1...n] 중에 n과 서로소인 수의 개수
  // (== 오일러 피 함수 ϕ(n))
  ll ans = n;
  // 소인수분해를 통해 ϕ(n)를 구한다.
  // https://ko.wikipedia.org/wiki/오일러_피_함수
  for (ll pf = 2; pf * pf <= n; ++pf) {
    // pf가 소인수인지 확인한다.
    if (n % pf == 0) {
      // pf가 소인수인 경우, n이 pf로 나누어떨어지지 않을 때 까지 나눈다.
      while (n % pf == 0) {
        n /= pf;
      }
      // ϕ(n)를 계산한다.
      ans = ans * (pf - 1) / pf;
    }
  }
  // sqrt(n)보다 큰 소인수가 있는 경우를 처리한다.
  if (n > 1) {
    ans = ans / n * (n - 1);
  }
  // 결과 출력
  cout << ans << '\n';
}
