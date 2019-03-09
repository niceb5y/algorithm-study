#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

// n: 구슬의 수
// m: 그룹의 수
// num[i]: (i + 1)번째 구슬의 숫자
int n, m, num[300];

// group(limit): 상한이 limit인 구슬의 그룹의 수를 계산하는 함수
int group(int limit) {
  // group: 그룹의 개수
  // sum: 현재 그룹의 숫자의 총 합
  int group = 1, sum = 0;
  for (int i = 0; i < n; ++i) {
    // limit이 그룹의 특정 원소보다 작은 경우
    // 이진탐색에서 limit을 증가시키도록 유도한다.
    if (num[i] > limit)
      return m + 1;
    if (sum + num[i] > limit) {
      // 그룹에 이번 원소를 추가할 수 없을 경우 새 그룹을 만든다.
      ++group;
      sum = num[i];
    } else {
      // 그렇지 않은 경우 그룹에 원소를 추가한다.
      sum += num[i];
    }
  }
  // 그룹의 수를 반환한다.
  return group;
}

// print(ans): 문제의 정답 ans를 형식에 맞게 출력하는 함수.
void print(int ans) {
  cout << ans << '\n';
  // group: 그룹의 개수
  // sum: 현재 그룹의 숫자의 총 합
  // count: 현재 그룹의 원소의 개수
  int group = 1, sum = 0, count = 0;
  for (int i = 0; i < n; ++i) {
    if (sum + num[i] > ans || m - group > n - i - 1) {
      // 그룹에 이번 원소를 추가할 수 없는 경우나,
      // 남은 그룹의 수가 남은 원소의 수와 같은 경우 새 그룹을 만든다.
      ++group;
      sum = num[i];
      cout << count << " ";
      count = 1;
    } else {
      // 그렇지 않은 경우 그룹에 원소를 추가한다.
      sum += num[i];
      ++count;
    }
  }
  cout << count << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
  }
  // left, right: 이진탐색의 하한과 상한
  int left = 0, right = 30000;
  // ans: 각 그룹의 합 중 최댓값이 최소가 되도록 m개의 그룹으로 나누었을 때 그
  // 최댓값
  int ans = 0;
  // 이진 탐색
  while (left <= right) {
    int mid = (left + right) / 2;
    // group()에따라 mid값을 조절한다.
    if (group(mid) > m) {
      left = mid + 1;
    } else {
      ans = mid;
      right = mid - 1;
    }
  }
  // 결과 출력
  print(ans);
}
