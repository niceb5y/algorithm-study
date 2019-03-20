#include <iostream>
#include <map>
#include <vector>

using namespace std;

// get_prime(n): n 이하의 소수의 벡터를 반환하는 함수
vector<int> get_prime(const int &n) {
  // prime: 소수 여부를 저장하는 함수
  bool prime[249999];
  // map: n을 배열의 인덱스로 사상하는 함수
  auto map = [](const int &n) { return (n - 3) / 2; };
  // ret: n 이하의 소수
  vector<int> ret({2});
  // 변수 초기화
  for (auto &i : prime) {
    i = true;
  }
  // 에라토스테네스의 체로 소수를 구한다.
  for (int i = 3; i <= n; i += 2) {
    if (prime[map(i)]) {
      // 소수인 경우 벡터에 추가
      ret.push_back(i);
      for (int j = 3 * i; j <= n; j += 2 * i) {
        prime[map(j)] = false;
      }
    }
  }
  // 결과 반환
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 사탕 종류의 수
  // sum_price: 사탕 가격의 총 합
  int n, sum_price = 0;
  // dp[i]: 사탕을 골라 가격 i를 만들 수 있는 방법의 수
  long long dp[500001] = {};
  // 0원 짜리 사탕 초기화
  dp[0] = 1;
  // candy: 사탕의 가격과 개수를 저장하는 맵
  map<int, int> candy;
  // 0원짜리 사탕의 개수 초기화
  candy[0] = 0;
  cin >> n;
  // map에 사탕의 가격과 개수를 저장한다.
  for (int i = 0; i < n; ++i) {
    int price;
    cin >> price;
    sum_price += price;
    ++candy[price];
  }
  // 사탕을 순회하면서 dp를 갱신한다.
  for (auto iter = candy.begin(); iter != candy.end(); ++iter) {
    const int price = iter->first, count = iter->second;
    // 가격이 0인 사탕은 마지막에 따로 계산한다.
    if (price == 0)
      continue;
    // 1차원 배열을 사용하기 위해 역방향으로 계산한다.
    for (int i = sum_price; i >= 0; --i) {
      // 같은 가격의 사탕이 여러 개 있는 경우를 고려한다.
      for (int j = 1; j <= count; ++j) {
        // dp를 이용해 계산
        if (i >= j * price) {
          dp[i] += dp[i - j * price];
        }
      }
    }
  }
  // ans: 사탕 가격의 합이 소수가 되는 방법의 수
  long long ans = 0;
  // primes: sum_price를 상한으로 하는 소수의 벡터
  vector<int> primes = get_prime(sum_price);
  // ans에 답을 더한다
  for (auto &prime : primes) {
    ans += dp[prime];
  }
  // 0원짜리 사탕의 처리
  // 0원짜리 사탕의 수 + 1만큼 ans에 곱한다.
  ans *= (candy[0] + 1);
  // 결과 출력
  cout << ans << "\n";
}
