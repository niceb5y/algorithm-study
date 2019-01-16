#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// num: 양자화할 수를 저장할 배열
// cache: DP에 사용될 배열
// n: 입력받을 수의 크기
int num[100], cache[100][10], n = 0;

// min_error(lo, hi): [lo...hi]의 오차 제곱의 합을 구한다.
int min_error(int lo, int hi) {
  // sum: [lo...hi]의 합
  int sum = 0;
  for (int i = lo; i <= hi; ++i) {
    sum += num[i];
  }
  // avg: [lo...hi]의 평균
  int avg = round((double)sum / (hi - lo + 1));
  // error: [lo...hi]의 오차 제곱의 합
  int error = 0;
  for (int i = lo; i <= hi; ++i) {
    error += pow((num[i] - avg), 2);
  }
  return error;
}

// quantize(from, parts): num배열을 from부터 parts개의 수로 양자화 할 때, 오차
// 제곱의 합
int quantize(int from, int parts) {
  int ret = 1234567890;
  if (from == n) {
    return 0;
  }
  if (parts == 0) {
    return ret;
  }
  int &ret_cache = cache[from][parts - 1];
  if (ret_cache != -1) {
    return ret_cache;
  }
  for (int i = from + 1; i <= n; ++i) {
    ret = min(ret, min_error(from, i - 1) + quantize(i, parts - 1));
  }
  ret_cache = ret;
  return ret;
}

int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // c: 테스트 케이스의 수
  // s: 양자화 된 수의 종류
  int c, s;
  cin >> c;

  for (int i = 0; i < c; ++i) {
    cin >> n >> s;
    for (int j = 0; j < n; ++j) {
      cin >> num[j];
    }
    // 숫자 정렬
    sort(num, num + n);
    // 캐시 초기화
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 10; j++) {
        cache[i][j] = -1;
      }
    }
    // 양자화 한 뒤, 최소 오차 합을 출력한다.
    cout << quantize(0, s) << '\n';
  }
  cout << flush;
}
