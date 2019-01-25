#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 수의 개수
  // x: x보다 작은 수만 출력
  int n, x;
  // first: 첫번째 변수 출력인지 확인하는 변수
  bool first = true;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    if (num < x) {
      cout << (first ? "" : " ") << num;
      first = false;
    }
  }
  cout << '\n';
}
