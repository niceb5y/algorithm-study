#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // m, n: 완전제곱수의 범위
  int m, n;
  cin >> m >> n;
  // sq: [1...10000]범위의 완전제곱수
  vector<int> sq(100);
  for (int i = 0; i < 100; ++i) {
    sq[i] = (i + 1) * (i + 1);
  }
  // 이진탐색으로 범위를 구한다.
  auto lo = lower_bound(sq.begin(), sq.end(), m);
  auto hi = upper_bound(sq.begin(), sq.end(), n);
  if (lo == hi) {
    // 범위내에 완전제곱수가 존재하지 않으면 -1을 출력한다.
    cout << "-1\n";
  } else {
    // 범위내에 완전제곱수가 존재하면 합과 최소값을 출력한다.
    cout << accumulate(lo, hi, 0) << '\n' << *lo << '\n';
  }
}
