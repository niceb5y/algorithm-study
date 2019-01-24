#include <iostream>
#include <vector>

using namespace std;

// get_prime<N>(): [2...N]까지의 소수를 벡터로 반환하는 함수
template <int N> vector<int> get_prime() {
  // prime[]: 3부터 N까지의 홀수의 소수 여부를 저장
  bool prime[N / 2 - 1];
  // map(n): 3 이상의 홀수의 인덱스를 반환하는 람다식
  // 3, 5, 7, ... -> 0, 1, 2, ...
  auto map = [](int n) { return (n - 3) / 2; };
  // ret: 함수의 반환값. 2를 초기 원소로 갖는 벡터
  vector<int> ret({2});
  // prime[] 초기화
  for (auto &i : prime) {
    i = true;
  }
  // 에라토스테네스의 체 알고리즘을 이용하여 소수를 판별한다
  for (int i = 3; i < N; i += 2) {
    // 해당 수가 소수인지 확인
    if (prime[map(i)]) {
      // 벡터에 집어넣기
      ret.push_back(i);
      // 해당 수의 배수는 소수가 아님, 짝수배는 검사를 건너뛴다.
      for (int j = 3 * i; j < N; j += 2 * i) {
        prime[map(j)] = false;
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // primes: 1000 이하의 소수들의 집합
  vector<int> primes = get_prime<1000>();
  // n: 테스트 케이스의 개수
  // num: 소수인지 확인할 수
  // count: 소수인 num의 개수
  int n, num, count = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    // num이 소수인지 확인
    if (num == *lower_bound(primes.begin(), primes.end(), num)) {
      ++count;
    }
  }
  cout << count << endl;
}
