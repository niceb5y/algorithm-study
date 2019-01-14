#include <iostream>

using namespace std;

// shouldDraw:() *을 그릴지 말지 결정하는 함수
bool shouldDraw(const int &x, const int &y, const int &size) {
  // 기저: 사이즈가 1이면 그냥 출력한다.
  if (size == 1) {
    return true;
  }

  // height: 그릴 문양의 높이
  // width: 그릴 문양의 너비
  // 높이와 너비를 계산한다.
  int height = 1, width = 1;
  for (int i = 1; i < size; ++i) {
    height = height * 2 + 1;
  }
  width = 2 * height - 1;

  // height: size가 하나 작은 문양의 높이
  // width: size가 하나 작은 문양의 너비
  int prevHeight = (height - 1) / 2;
  int prevWidth = 2 * prevHeight - 1;
  // size가 홀수인 경우와 짝수인 경우를를 나누어 계산한다.
  if (size % 2 == 0) {
    // size가 짝수인 경우 뒤집힌 삼각형 모양이 된다.
    // 삼각형 외곽선 그리기
    if (y == 0 || x == width - y - 1 || x == y)
      return true;
    //안 삼각형이 그려질 범위인 경우, 재귀적으로 호출한다.
    if ((y >= 1 && y < prevHeight + 1) &&
        (x >= (width - prevWidth) / 2 && x < (width + prevWidth) / 2)) {
      return shouldDraw(x - (width - prevWidth) / 2, y - 1, size - 1);
    }
  } else {
    // size가 홀수인 경우 뒤집히지 않은 삼각형 모양이 된다.
    // 삼각형 외곽선 그리기
    if (x == width / 2 + y || x == width / 2 - y || y == height - 1)
      return true;
    //안 삼각형이 그려질 범위인 경우, 재귀적으로 호출한다.
    if ((y >= prevHeight && y < height - 1) &&
        (x >= (width - prevWidth) / 2 && x < (width + prevWidth) / 2)) {
      return shouldDraw(x - (width - prevWidth) / 2, y - prevHeight, size - 1);
    }
  }
  // 그 외의 값은 그리지 않는다.
  return false;
}
int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // n: 재귀의 횟수
  int n;
  cin >> n;

  // height: 그릴 문양의 높이
  // width: 그릴 문양의 너비
  // 높이와 너비를 계산한다.
  int height = 1, width = 1;
  for (int i = 1; i < n; ++i) {
    height = height * 2 + 1;
  }
  width = 2 * height - 1;

  // 높이와 너비만큼 shouldDraw()를 호출하여 별을 그린다.
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      // n이 홀수인 경우와 짝수인 경우에 따라 그 줄의 문양을 다 그렸으면 더이상
      // 출력하지 않도록 한다.
      if (n % 2 == 0) {
        if (j == width - i) {
          break;
        }
      } else {
        if (j == width / 2 + i + 1) {
          break;
        }
      }
      cout << (shouldDraw(j, i, n) ? '*' : ' ');
    }
    cout << '\n';
  }
  cout << flush;
}
