#include <iostream>

using namespace std;

// shouldDraw:() *을 그릴지 말지 결정하는 함수
bool shouldDraw(int x, int y, int size) {
  // 기저: size = 1일때는 항상 참이다.
  if (size == 1)
    return true;
  // 기저: 사각형의 한가운데는 항상 비어있다.
  if ((x >= size / 3 && x < size / 3 * 2) &&
      (y >= size / 3 && y < size / 3 * 2))
    return false;
  // 재귀호출을 통해 작은 사각형으로 나누어 그린다
  return shouldDraw(x % (size / 3), y % (size / 3), size / 3);
}

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 정사각형 한 변의 길이
  int n;
  cin >> n;
  // n * n번 반복하면서 shouldDraw()함수를 호출하여 사각형을 그린다
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      // shouldDraw()의 값이 참이면 "*", 아니면 " "를 그린다.
      cout << (shouldDraw(j, i, n) ? '*' : ' ');
    }
    cout << '\n';
  }
  cout << flush;
}
