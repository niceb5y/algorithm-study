#include <iostream>

using namespace std;

int main() {
  // n: 입력받을 명령어의 개수
  int n;
  int stack[10000], top = -1;
  cin >> n;
  // 버퍼 지우기
  cin.get();
  // buf: 텍스트 버퍼
  string buf;
  // n번 명령을 받아 명렁에 맞게 처리한다.
  for (int i = 0; i < n; ++i) {
    getline(cin, buf);
    if (buf.compare("pop") == 0) {
      cout << ((top != -1) ? stack[top] : -1) << '\n';
      if (top != -1) {
        --top;
      }
    } else if (buf.compare("size") == 0) {
      cout << (top + 1) << '\n';
    } else if (buf.compare("empty") == 0) {
      cout << ((top != -1) ? 0 : 1) << '\n';
    } else if (buf.compare("top") == 0) {
      cout << ((top != -1) ? stack[top] : -1) << '\n';
    } else if (buf.rfind("push ", 0) == 0) {
      ++top;
      stack[top] = stoi(buf.substr(5));
    }
  }
  cout << flush;
}
