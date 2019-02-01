#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

// chapter[i]: (i + 1)번째 장의 파일의 크기
int chapter[500];
// sum[i]: chapter [1...i]의 합
int sum[501] = {0};
// dp[i][j]: chapter [i...j]를 합치는 데 드는 비용
int dp[500][500];

int merge(const int &lo, const int &hi) {
  // ret: chapter [lo...hi]를 합치는 데 드는 비용
  int &ret = dp[lo][hi];
  // 값이 존재하면 반환한다.
  if (ret != -1) {
    return ret;
  }
  // 파일이 하나만 존재하는 경우에는 합치지 않는다.
  if (hi - lo == 0) {
    return dp[lo][hi] = 0;
  }
  // 파일이 둘 존재하면 합쳐서 반환한다.
  if (hi - lo == 1) {
    return dp[lo][hi] = chapter[lo] + chapter[hi];
  }
  // 그 외에 경우에는 큰 값으로 초기화
  ret = numeric_limits<int>::max();
  // 배열을 반으로 나눠 동적분할법으로 구한다.
  for (int mid = lo; mid < hi; ++mid) {
    ret = min(ret, merge(lo, mid) + merge(mid + 1, hi));
  }
  // 두 파일을 합칠 때 드는 비용 더하기
  ret += sum[hi + 1] - sum[lo];
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // t: 테스트케이스의 수
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    // k: 장의 수
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> chapter[j];
      // sum 초기화
      sum[j + 1] = sum[j] + chapter[j];
      // dp 초기화
      fill_n(dp[j], k, -1);
    }
    // 결과 출력
    cout << merge(0, k - 1) << '\n';
  }
}
