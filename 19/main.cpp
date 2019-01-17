#include <cmath>
#include <iostream>

using namespace std;

// z(n, c, r): 해당 위치를 몇번째로 순회하는지 계산하는 함수
// n: 해당 2차원 배열이 한 변이 2^n의 크기를 갖는 정사각형 모양의 2차원
// 배열임을 뜻한다.
// (r, c): 찾을 위치의 좌표
int z(const int &n, const int &r, const int &c) {
  // 기저: n가 1이면 순서를 바로 반환
  if (n == 1) {
    return 2 * r + c;
  }
  // half_legth: 해당 배열의 한 변의 길이의 절반.
  // pos: 찾는 위치가 사분면의 어느 지점인지 결정한다. 1, 2, 3, 4 사분면이 각각
  // 1, 0, 2, 3에 대응한다.
  int half_length = pow(2, n - 1), pos = 0;
  // pos 찾기
  if (c >= half_length)
    pos += 1;
  if (r >= half_length)
    pos += 2;
  // 2차원 배열을 4등분하여 재귀적으로 위치를 구한다.
  return pos * (pow(half_length, 2)) +
         z(n - 1, c % half_length, r % half_length);
}

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, r, c;
  cin >> n >> r >> c;
  cout << z(n, r, c) << endl;
}
