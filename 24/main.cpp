#include <iostream>

using namespace std;

bool shouldDraw(const int &x, const int &y, const int &size) {
  // 기저: size가 3일때 삼각형의 모양을 정의한다.
  if (size == 3) {
    return y == 2 || (x == 2 && y == 0) || ((x == 1 || x == 3) && y == 1);
  }
  // 프랙탈의 상단 중앙 삼각형
  if ((y >= 0 && y <= size / 2 - 1) &&
      (x > size / 2 - 1 && x < 3 * size / 2 - 1)) {
    return shouldDraw(x - size / 2, y, size / 2);
  }
  // 프랙탈의 하단 좌측 삼각형
  if ((y >= size / 2 && y <= size - 1) && (x >= 0 && x < size - 1)) {
    return shouldDraw(x, y - size / 2, size / 2);
  }
  // 프랙탈의 하단 우측 삼각형
  if ((y >= size / 2 && y <= size - 1) && (x >= size && x < 2 * size - 1)) {
    return shouldDraw(x - size, y - size / 2, size / 2);
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 재귀의 횟수
  int n;
  cin >> n;
  // height: 그릴 문양의 높이
  // width: 그릴 문양의 너비
  // 높이와 너비를 계산한다.
  int height = n, width = 2 * n - 1;
  // 높이와 너비만큼 shouldDraw()를 호출하여 별을 그린다.
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      cout << (shouldDraw(j, i, n) ? '*' : ' ');
    }
    cout << '\n';
  }
}
