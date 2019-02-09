#include <iostream>

using namespace std;

int main() {
  // n: 배열의 크기 (n * n)
  // k: 찾아야 하는 원소의 번호
  int n, k;
  cin >> n >> k;
  // left, right, mid: 이분탐색을 위한 변수
  // ans: 배열의 k번째 수
  int left = 1, right = k, mid, ans = 0;
  // 이분탐색을 통해 배열에서 자신 이하의 수를 k개 이상 갖는 숫자 중 가장 작은
  // 숫자 ans를 찾는다.
  while (left <= right) {
    mid = (left + right) / 2;
    // count: mid보다 작거나 같은 원소의 수
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      count += min(mid / i, n);
    }
    if (count >= k) {
      right = mid - 1;
      ans = mid;
    } else {
      left = mid + 1;
    }
  }
  // 결과 출력
  cout << ans << '\n';
}
