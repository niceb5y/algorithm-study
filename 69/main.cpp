#include <cmath>
#include <iostream>

using namespace std;
int main() {
  // min, max: "제곱ㄴㄴ수"의 범위 [min, max]
  // ans: 범위 [min, max]의 "제곱ㄴㄴ수"의 개수
  long long min, max, ans = 0;
  // sq[i]: 숫자 (i + min)이 제곱수의 배수인지 여부
  bool sq[1000001] = {};
  cin >> min >> max;
  // 제곱수의 배수를 구하여 sq에 기록한다.
  for (long long i = 2; i * i <= max; ++i) {
    // 제곱수(i * i)의 j배수 (j * i * i)는 min 이상일때만 계산해도 된다.
    for (long long j = ceill((long double)min / i / i); j * i * i <= max; ++j) {
      sq[j * i * i - min] = true;
    }
  }
  // sq에서 "제곱ㄴㄴ수"를 모두 구한다.
  for (long long i = 0; i <= max - min; ++i) {
    if (!sq[i])
      ++ans;
  }
  cout << ans << '\n';
}
