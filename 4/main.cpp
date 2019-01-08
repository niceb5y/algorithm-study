#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // n: 수열의 길이
  int n;
  cin >> n;

  // num: 수열을 저장할 벡터
  // cache: x번째 항부터 i번째 항까지의 부분수열(x < i)의 최대 연속합을 저장할
  // 벡터
  vector<int> num(n), cache(n);
  for (auto &i : num) {
    cin >> i;
  }
  // 캐시의 첫번째 값을 초기화한다.
  cache[0] = num[0];
  // ret: 최대 연속합을 저장할 변수
  int ret = cache[0];
  for (int i = 1; i < n; ++i) {
    // 캐시의 i번째 값은 이전까지의 연속합에 자기를 더한 값이나 자신의 값 중 더
    // 큰 값으로 정한다.
    cache[i] = max(cache[i - 1] + num[i], num[i]);
    // 최대 연속합을 ret에 저장한다.
    ret = max(ret, cache[i]);
  }
  cout << ret << endl;
}
