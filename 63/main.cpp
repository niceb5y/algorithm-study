#include <iostream>

using namespace std;
int main() {
  // a, b, c: 곱할 숫자
  // count[i]: 숫자 i가 사용된 횟수
  int a, b, c, count[10] = {};
  cin >> a >> b >> c;
  // 세 숫자의 곱에 숫자가 사용된 횟수 구하기
  for (auto &i : to_string(a * b * c)) {
    ++count[i - '0'];
  }
  // 결과 출력
  for (auto &i : count) {
    cout << i << '\n';
  }
}
