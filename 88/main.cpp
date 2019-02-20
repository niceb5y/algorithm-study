#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // m, d: 날짜 (월, 일)
  // offset: 요일 계산을 위해 월마다 더해줘야 하는 숫자
  int m, d, offset[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
  // date: 요일 배열
  string date[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  // 날짜를 입력받는다.
  cin >> m >> d;
  // 결과 출력
  cout << date[(offset[m - 1] + d) % 7] << '\n';
}
