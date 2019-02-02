#include <cmath>
#include <iostream>

using namespace std;

int main() {
  // π: atan(1) * 4
  const double PI = atan(1.0) * 4;
  // r: 반지름
  int r;
  cin >> r;
  // 정밀도 설정
  cout.precision(6);
  // 유클리드 기하학에서 원의 넓이
  cout << fixed << r * r * PI << '\n';
  // 택시 기하학에서 원의 넓이
  cout << fixed << r * r * (double)2 << '\n';
}
