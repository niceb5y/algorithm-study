#include <iostream>

using namespace std;
int main() {
  // n: n!를 구하고 싶은 정수 [0...12]
  // ans: n의 팩토리얼 값
  int n, ans = 1;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    ans *= i;
  }
  cout << ans << '\n';
}
