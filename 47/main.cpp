#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // t: 테스트 데이터 수
  int t;
  cin >> t;
  // 버퍼 비우기
  cin.get();
  for (int i = 0; i < t; ++i) {
    // buf: 텍스트 버퍼
    string buf;
    getline(cin, buf);
    // depth: 괄호의 깊이
    int depth = 0;
    for (auto &c : buf) {
      // 열린 괄호는 depth를 증가시킨다.
      if (c == '(') {
        ++depth;
      }
      // 닫힌 괄호는 depth를 감소시킨다.
      if (c == ')') {
        --depth;
      }
      // depth가 음수인경우 올바른 괄호 문자열이 아니다.
      if (depth < 0) {
        break;
      }
    }
    // 괄호 문자열이 올바른지 출력한다.
    cout << (depth == 0 ? "YES" : "NO") << '\n';
  }
}
