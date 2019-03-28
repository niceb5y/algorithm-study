#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// n: 수열의 크기
int n;
// seq: 수열
// pos[i]: 마지막 원소가 i인 LIS의 길이
// lis[i]: 길이가 i인 LIS의 마지막 원소의 최소값
vector<int> seq, pos, lis;

// print_lis(hi, count, next): 가장 긴 LIS를 출력한다.
// hi: 출력할 LIS 범위의 상한 [0,hi)
// count: 앞으로 출력해야 하는 LIS의 길이
// next: 다음 LIS원소
void print_lis(int hi, int count, int next) {
  for (int i = hi - 1; i >= 0; --i) {
    // 더 이상 출력해야 할 원소가 없으면 끝낸다
    if (count == 0)
      return;
    // LIS 원소를 찾는다.
    if (pos[i] == count && seq[i] <= next) {
      // 이전 LIS 원소를 찾아 출력한다.
      print_lis(i, count - 1, seq[i]);
      // 원소를 출력한다.
      cout << (count == 1 ? "" : " ") << seq[i];
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // 값 초기화
  cin >> n;
  seq.resize(n);
  pos.resize(n, 1);
  lis.resize(n + 1, 1001);
  lis[0] = -1001;
  for (auto &i : seq) {
    cin >> i;
  }
  int ans = 0;
  // 이분탐색을 이용해 n log n으로 LIS를 찾는다.
  for (int i = 0; i < n; ++i) {
    // lo: seq[i] 이하인 가장 큰 lis의 원소의 이터레이터
    auto lo = lower_bound(lis.begin(), lis.end(), seq[i]);
    // len: seq[i]를 마지막 원소로 하는 LIS의 길이
    int len = distance(lis.begin(), lo);
    // pos 갱신
    pos[i] = len;
    *lo = min(*lo, seq[i]);
    // LIS의 최대 길이를 구한다.
    ans = max(ans, len);
  }
  // LIS의 길이 출력
  cout << ans << '\n';
  // LIS의 원소 출력
  print_lis(n, ans, 1001);
  cout << '\n';
}
