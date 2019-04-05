#include <algorithm>
#include <iostream>

using namespace std;

// n: 대나무 숲의 크기
// ans: 판다가 최대한 살 수 있는 일수
// arr[i][j]: 대나무 숲[i][j]의 대나무의 양
// dp[i][j]: 대나무 숲[i][j]에서 판다가 최대한 살 수 있는 일수
int n, ans = 0, arr[500][500], dp[500][500];

// solve(i, j): 좌표 (i, j)에서 판다가 최대한 살 수 있는 일수를 구함
int solve(const int &i, const int &j) {
  int &ret = dp[i][j];
  if (ret != -1) {
    return ret;
  }
  ret = 1;
  // 4방향 탐색
  if (i > 0 && arr[i][j] < arr[i - 1][j])
    ret = max(ret, solve(i - 1, j) + 1);
  if (j > 0 && arr[i][j] < arr[i][j - 1])
    ret = max(ret, solve(i, j - 1) + 1);
  if (i + 1 < n && arr[i][j] < arr[i + 1][j])
    ret = max(ret, solve(i + 1, j) + 1);
  if (j + 1 < n && arr[i][j] < arr[i][j + 1])
    ret = max(ret, solve(i, j + 1) + 1);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 초기화
  cin >> n;
  fill_n(&dp[0][0], 500 * 500, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  // 판다가 최대한 살 수 있는 일수를 구함
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = max(ans, solve(i, j));
    }
  }

  // 결과 출력
  cout << ans << '\n';
}
