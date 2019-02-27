#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p1, p2, round = 1;
  // n: 사람의 수
  // p1, p2: 서로 대결하는 라운드를 알아보고 싶은 사람들의 번호 p1, p2
  cin >> n >> p1 >> p2;
  // 같은 라운드인지 확인
  while ((p1 + 1) / 2 != (p2 + 1) / 2) {
    // 다음 라운드로 이동
    p1 = (p1 + 1) / 2;
    p2 = (p2 + 1) / 2;
    ++round;
  }
  // 결과 출력
  cout << round << '\n';
}
