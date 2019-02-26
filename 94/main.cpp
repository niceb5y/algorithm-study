#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 사람의 수
  // ans: 각 사람이 ATM을 사용하는 데 걸리는 시간의 총합
  int n, ans = 0;
  cin >> n;
  // p[i]: (i + 1)번째 사람이 ATM을 사용하는 데 걸리는 시간
  vector<int> p(n);
  for (auto &i : p) {
    cin >> i;
  }
  // 걸리는 시간을 오름차순으로 정렬
  sort(p.begin(), p.end());
  // 걸리는 총 시간을 구한다.
  for (int i = 0; i < n; ++i) {
    ans += p[i] * (n - i);
  }
  // 결과 출력
  cout << ans << '\n';
}
