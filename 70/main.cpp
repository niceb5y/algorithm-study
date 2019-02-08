#include <iostream>

using namespace std;

int main() {
  // ans: 다이얼로 전화를 걸기 위해 필요한 시간
  int ans = 0;
  // line: 전화를 걸기 위한 문자열
  string line;
  getline(cin, line);
  // 한문자씩 다이얼을 돌리는 데 드는 시간을 구해서 더한다.
  for (auto &c : line) {
    ans += (c - 'A' - (c > 'R') - (c == 'Z')) / 3 + 3;
  }
  // 결과 출력
  cout << ans << '\n';
}
