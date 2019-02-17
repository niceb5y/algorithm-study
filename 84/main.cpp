#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // x: 만들어야 하는 막대 X의 길이를 만드는 데 필요한 길이
  // min: 자른 막대 중 가장 작은 막대의 길이
  // count: 막대 X를 이루는 막대의 수
  int x, min = 64, count = 0;
  cin >> x;
  while (x > 0) {
    if (min > x) {
      // 가장 작은 막대가 x보다 크면 막대를 반으로 자른다.
      min /= 2;
    } else {
      // 그렇지 않은 경우 가장 작은 막대는 막대 X를 만드는 데 사용될 수 있다.
      x -= min;
      ++count;
    }
  }
  // 결과 출력
  cout << count << '\n';
}
