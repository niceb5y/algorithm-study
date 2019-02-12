#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // line: 긴 형태 이름
  string line;
  getline(cin, line);
  for (auto &c : line) {
    // 대문자만 출력한다.
    if (c >= 'A' && c <= 'Z') {
      cout << c;
    }
  }
  cout << '\n';
}
