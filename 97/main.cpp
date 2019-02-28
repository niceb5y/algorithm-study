#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;
  // i: x가 속해있는 그룹의 번호
  // n: x가 속해있는 그룹의 최대 숫자
  int i = 1, n = 1;
  // x가 몇번째 그룹에 속해있는지 계산한다.
  while (n < x) {
    ++i;
    n = i * (i + 1) / 2;
  }
  // i가 짝수/홀수 여부에 따라 분모와 분자의 순서를 다르게 출력한다.
  if (i % 2 == 0) {
    cout << i - n + x << "/" << n - x + 1 << endl;
  } else {
    cout << n - x + 1 << "/" << i - n + x << endl;
  }
}
