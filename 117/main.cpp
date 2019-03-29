#include <iostream>
#include <vector>

using namespace std;

string str;

// pld[lo][hi] [lo, hi]가 팰린드롬인지 저장하는 변수
vector<vector<bool>> pld;
// pld_cache[lo][hi] chk(lo, hi)가 계산되었는지 저장하는 변수
vector<vector<bool>> pld_cache;
// cnt: [0...i]의 최소 팰린드롬 분할
vector<int> cnt;

// chk(lo, hi): [lo, hi]가 팰린드롬인지 확인
bool chk(const int &lo, const int &hi) {
  // 저당된 값이 있으면 출력
  if (pld_cache[lo][hi]) {
    return pld[lo][hi];
  }
  // 길이가 1인 문자열은 무조건 팰린드롬
  if (hi - lo == 0)
    return true;
  // 길이가 2인 문자열은 두 문자가 같아야 팰린드롬
  if (hi - lo == 1) {
    return str[lo] == str[hi];
  }
  // 이외의 경우 팰린드롬인지 재귀 호출을 통해 확인한다
  pld[lo][hi] = (str[lo] == str[hi]) ? chk(lo + 1, hi - 1) : false;
  // 메모이제이션 여부를 저장한다.
  pld_cache[lo][hi] = true;
  // 값 반환
  return pld[lo][hi];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  //  초기화
  getline(cin, str);
  int n = (int)str.length();
  pld.resize(n, vector<bool>(n));
  pld_cache.resize(n, vector<bool>(n, false));
  cnt.resize(n, 2501);

  // 문자열의 [0, i]구간을 검사한다.
  for (int i = 0; i < n; ++i) {
    // 문자열 [0, i] 전체가 팰린드롬이면 cnt[i] = 1
    if (chk(0, i)) {
      cnt[i] = 1;
      continue;
    }
    // 두 구간으로 나누어서 최소 분할을 구한다.
    for (int j = 1; j <= i; ++j) {
      if (chk(j, i)) {
        cnt[i] = min(cnt[i], cnt[j - 1] + 1);
      }
    }
  }

  // 결과 출력
  cout << cnt[n - 1] << '\n';
}
