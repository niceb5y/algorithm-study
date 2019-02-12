#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // m: 공을 바꾼 횟수
  // pos: 공의 위치
  // x, y: 바꿀 컵의 위치
  int m, pos = 1, x, y;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    if (pos == x)
      pos = y;
    else if (pos == y)
      pos = x;
  }
  cout << pos << '\n';
}
