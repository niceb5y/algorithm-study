#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// prerequisite: 작업의 건설 순서 규칙을 정의
typedef pair<int, int> prerequisite;

bool compare(const prerequisite &l, const prerequisite &r) {
  return l.second < r.second;
}

// get_time(d, dp, rules, w): 해당 작업을 끝마치는데 걸리는 시간
// d[i]: 건물 (i + 1)의 건설에 걸리는 시간
// dp[i]: 건설 순서 규칙의 만족을 포함하여 건물 (i + 1)의 건설에 걸리는 최소
// 시간
// rules: 건물을 건설하는데 필요한 건설 순서 규칙
// w: 건설해야 할 건물의 번호
int get_time(const vector<int> &d, vector<int> &dp,
             const vector<prerequisite> &rules, const int &w) {
  //  ret: 함수의 반환값
  int &ret = dp[w - 1];
  // DP: 캐시가 있으면 값을 반환한다.
  if (ret != -1) {
    return ret;
  }
  // iter: 건설 순서 규칙의 lower_bound
  auto iter = lower_bound(rules.begin(), rules.end(), make_pair(0, w), compare);
  if (iter->second != w) {
    // 건설 순서 규칙이 존재하지 않는 경우
    // 현재 건물의 d값을 출력한다.
    ret = d[w - 1];
    return ret;
  } else {
    // 전제 조건이 존재하는 경우
    // 전제 조건을 처리하는 시간의 최소값과 현제 건물의 d값의 합을 구한다.
    ret = 0;
    while (iter->second == w && iter != rules.end()) {
      ret = max(ret, get_time(d, dp, rules, iter->first));
      ++iter;
    }
    ret = ret + d[w - 1];
    return ret;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // t: 테스트 케이스의 수
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    // n: 건물의 개수
    // k: 건설 순서 규칙의 개수
    // w: 건설해야 할 건물의 번호
    int n, k, w;
    cin >> n >> k;
    // d[i]: 건물 (i + 1)의 건설에 걸리는 시간
    // dp[i]: 건설 순서 규칙의 만족을 포함하여 건물 (i + 1)의 건설에 걸리는 최소
    // 시간
    vector<int> d(n), dp(n, -1);
    // rules: 건물을 건설하는데 필요한 건설 순서 규칙
    vector<prerequisite> rules(k);
    for (auto &j : d) {
      cin >> j;
    }
    for (auto &j : rules) {
      cin >> j.first >> j.second;
    }
    // 건설 순서 규칙을 정렬한다.
    sort(rules.begin(), rules.end(), compare);
    cin >> w;
    // 정답 출력
    cout << get_time(d, dp, rules, w) << "\n";
  }
}
