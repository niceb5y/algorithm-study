#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 계단 수의 자리수
  // last_digit[i]: 마지막 자리수 i를 가지는 길이 n의 계단 수의 개수
  int n, last_digit[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  cin >> n;
  for (int i = 1; i < n; ++i) {
    // tmp: last_digit[i + 1]을 임시로 저장할 변수
    int tmp[10] = {0};
    // 마지막 자리 수가 그 전 자리 수보다 1 증가하는 경우
    for (int j = 0; j < 9; ++j) {
      tmp[j + 1] = last_digit[j];
    }
    // 마지막 자리 수가 그 전 자리 수보다 1 감소하는 경우
    for (int j = 1; j < 10; ++j) {
      tmp[j - 1] = (tmp[j - 1] + last_digit[j]) % 1000000000;
    }
    // tmp를 last_digit에 대입한다.
    for (int j = 0; j < 10; ++j) {
      last_digit[j] = tmp[j];
    }
  }
  // sum: 계단 수의 개수를 1000000000로 나눈 나머지
  int sum = 0;
  for (int i = 0; i < 10; ++i) {
    sum = (sum + last_digit[i]) % 1000000000;
  }
  // 결과 출력
  cout << sum << '\n';
}
