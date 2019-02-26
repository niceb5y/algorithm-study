#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 로프의 수
  // ans: 각 로프들을 이용해서 들 수 있는 중량의 최대값
  int n, ans = 0;
  cin >> n;
  // rope[i]: (i + 1)번째 로프가 들 수 있는 최대 중량
  vector<int> rope(n);
  for (auto &i : rope) {
    cin >> i;
  }
  // 각 로프가 버틸 수 있는 최대 중량을 내림차순으로 정렬한다.
  sort(rope.begin(), rope.end(), greater());
  for (int i = 0; i < n; ++i) {
    // 각 로프들을 이용해서 들 수 있는 중량의 최대값을 구한다.
    ans = max(ans, rope[i] * (i + 1));
  }
  // 결과 출력
  cout << ans << '\n';
}
