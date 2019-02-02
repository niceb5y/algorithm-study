#include <iostream>

using namespace std;
int main() {
  // grade: 점수
  string grade = "DCBAE";
  // a, b, c, d: 윷
  int a, b, c, d;
  for (int i = 0; i < 3; ++i) {
    cin >> a >> b >> c >> d;
    cout << grade[a + b + c + d] << '\n';
  }
}
