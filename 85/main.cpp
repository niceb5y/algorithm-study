#include <algorithm>
#include <iostream>

using namespace std;

short cards[1000];
int cache[2][1000][1000];

// solve(lo, hi, is_my_turn): [lo...hi]까지 최선의 전략으로 얻을 수 있는 점수
// lo, hi: 카드의 범위
// is_my_turn: 누구의 차례인지 계산
int solve(const int &lo, const int &hi, const bool &is_my_turn) {
  // ret: DP를 위해 함수의 반환값을 저장하는 변수
  int &ret = cache[is_my_turn][lo][hi];
  if (ret != -1) {
    return ret;
  }
  // 기저: 카드의 범위가 1개이면 바로 점수를 반환한다.
  // 내 차례이면 카드의 점수만큼, 아니면 0점을 얻는다.
  if (lo == hi) {
    return is_my_turn ? cards[lo] : 0;
  }
  // a: 다음 차례의 [lo + 1...hi]범위의 solve값
  // a: 다음 차례의 [lo...hi - 1]범위의 solve값
  int a = solve(lo + 1, hi, !is_my_turn), b = solve(lo, hi - 1, !is_my_turn);
  // 내 차례인지 여부에 따라 점수를 계산한다.
  // 내 차례에는 점수가 최대가 되고, 상대의 차례에는 최소가 되도록 선택한다.
  ret = is_my_turn ? max(cards[lo] + a, cards[hi] + b) : min(a, b);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // t: 테스트 케이스의 수
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    // n: 카드의 수
    int n;
    cin >> n;
    // 메모리 초기화
    fill_n(&cache[0][0][0], sizeof(cache) / sizeof(int), -1);
    for (int j = 0; j < n; ++j) {
      cin >> cards[j];
    }
    // 결과 출력
    cout << solve(0, n - 1, true) << "\n";
  }
}
