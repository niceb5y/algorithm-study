#include <algorithm>
#include <iostream>

using namespace std;

// n: 구해야 하는 좋은 수열의 자리수
// seq[0...n]: 좋은 수열[1...(n + 1)]
int n, seq[80];

// eval(d): seq[d...n]를 구한다.
void eval(const int &d) {
  // 인접한 두 부분수열이 반복하는지 검사한다.
  for (int i = 1; i <= d / 2; ++i) {
    if (equal(&seq[d - 2 * i], &seq[d - i], &seq[d - i])) {
      return;
    }
  }
  // 기저: d가 n이 되면 출력한다.
  if (d == n) {
    for (int i = 0; i < n; ++i) {
      cout << seq[i];
    }
    cout << '\n';
    exit(0);
  }
  // 백트래킹
  for (int i = 1; i <= 3; ++i) {
    seq[d] = i;
    eval(d + 1);
  }
}

int main() {
  cin >> n;
  eval(0);
}
