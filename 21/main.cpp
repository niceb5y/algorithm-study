#include <iostream>
#include <utility>

using namespace std;

// result: fibonacci_count()함수의 반환값 타입
// .first는 0이 호출된 횟수, .second는 1이 호출된 횟수
typedef pair<int, int> result;
// result_cache: 위 결과값을 DP를 위해 저장할때 사용되는 타입
// .first는 반환값, .second는 캐시 여부
typedef pair<result, bool> result_cache;
// cache[n]: n=[2...40]에 대하여 fibonacci_count(n)값을 저장한다.
result_cache cache[41];

// 더하기 연산자 재지정
result operator+(const result &l, const result &r) {
  return {l.first + r.first, l.second + r.second};
}

// 출력 연산자 재지정
ostream &operator<<(ostream &os, const result &res) {
  os << res.first << " " << res.second;
  return os;
}

// fibonacci_count(n): fibonacci(n)에서 fibonacci(0)과 fibonacci(1)이 호출된
// 횟수를 계산한다.
result fibonacci_count(int n) {
  // 기저: n = 0
  if (n == 0) {
    return make_pair(1, 0);
    // 기저: n = 1
  } else if (n == 1) {
    return make_pair(0, 1);
  } else {
    result_cache &ref = cache[n];
    if (ref.second)
      return ref.first;
    ref.first = fibonacci_count(n - 1) + fibonacci_count(n - 2);
    ref.second = true;
    return ref.first;
  }
}

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // t: 테스트 케이스의 개수
  // n: fibonacci_count(n)의 인자
  int t, n;
  cin >> t;
  // 캐시 초기화
  for (auto &i : cache) {
    i.second = false;
  }
  // t번 반복하여 결과값을 출력한다.
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cout << fibonacci_count(n) << '\n';
  }
  cout << flush;
}
