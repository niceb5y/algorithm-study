#include <iostream>
#include <limits>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // k: 가지고 있는 랜선의 개수
  // n: 만들어야 하는 랜선의 개수
  int k, n;
  cin >> k >> n;
  vector<int> length(k);
  for (auto &i : length) {
    cin >> i;
  }
  // left, right: 이분탐색을 위한 랜선의 길이의 범위
  long long left = 0, right = numeric_limits<int>::max();
  // ans: 만들어진 랜선의 길이
  int ans = 0;
  while (left <= right) {
    // mid: 이분탐색을 위한 변수
    long long mid = (left + right) / 2;
    // count: 만들어진 랜선의 개수
    int count = 0;
    for (auto &i : length) {
      count += i / mid;
    }
    // 이분탐색
    if (count >= n) {
      left = mid + 1;
      ans = mid;
    } else {
      right = mid - 1;
    }
  }
  // 결과 출력
  cout << ans << '\n';
}
