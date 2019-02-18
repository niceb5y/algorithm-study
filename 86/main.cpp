#include <iostream>

using namespace std;

int main() {
  // n: 구하고자 하는 수열의 합
  // l: 구하고자 하는 수열의 길이의 하한 [l...100]
  int n, l;
  cin >> n >> l;
  // [l...100]범위의 수열을 구한다.
  for (int i = l; i <= 100; ++i) {
    // x: 수열의 첫번째 수
    int x = n / i - (i - 1) / 2;
    // x가 0 이상의 정수인 경우, 수열을 출력한다.
    if (n == i * x + i * (i - 1) / 2 && x >= 0) {
      for (int j = 0; j < i; ++j) {
        cout << x + j << (j != i - 1 ? ' ' : '\n');
      }
      // 수열을 출력한 경우 프로그램을 종료한다.
      exit(0);
    }
  }
  // 수열이 없는 경우 -1을 출력한다.
  cout << "-1\n";
}
