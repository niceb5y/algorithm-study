#include <algorithm>
#include <iostream>

using namespace std;

// n: 전구의 수
// k: 전구가 표현할 수 있는 색상의 수
// color[i]: (i + 1)번 전구의 색상
// dp[i]: (i + 1)번 전구의 색상
int n, k, color[200], dp[200][200];

// solve(lo, hi) [lo, hi] 범위의 전구의 색이 하나로 같아질 때까지 전구의 색을
// 바꾸는 횟수의 최솟값
int solve(int lo, int hi) {
  // ret: 함수의 반환값
  int &ret = dp[lo][hi];
  // ret값이 계산되어 있는 경우, 값을 반환한다.
  if (ret != -1) {
    return ret;
  }
  // 기저: 전구 1개에 대한 solve값은 0이다.
  if (lo == hi) {
    return 0;
  }
  // 상한: n * k번 조작하면 모든 전구를 충분히 색이 같아지게 만들 수 있다.
  ret = n * k;
  // 범위를 이분하여 최솟값을 구한다.
  for (int mid = lo; mid < hi; ++mid) {
    // 두 범위의 시작영역의 전구의 색이 서로 다른 경우 1을 더한다.
    ret = min(ret, solve(lo, mid) + solve(mid + 1, hi) +
                       (color[lo] != color[mid + 1]));
  }
  // 결과 반환
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 변수 초기화
  cin >> n >> k;
  fill_n(&dp[0][0], sizeof(dp) / sizeof(int), -1);
  for (int i = 0; i < n; ++i) {
    cin >> color[i];
  }

  // 결과 출력
  cout << solve(0, n - 1) << '\n';
}
