#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// DP의 캐시를 담기 위한 벡터
vector<int> cache;

// DP를 이용한 구현
// 밑의 DP를 이용하지 않은 구현처럼 변형해서 사용하면 더 빨라질 여지가 있다.
int produce1_with_dp(const int &n) {
  // 캐시가 존재하는 경우 캐시를 리턴한다.
  if (cache[n - 1] != -1)
    return cache[n - 1];
  // 기저 사례. n = 1이면, 0을 리턴한다.
  if (n == 1)
    return 0;
  // ret: 반환할 값을 담기 위한 변수
  // 1을 뺐을때의 경우의 값을 먼저 집어넣는다.
  int ret = 1 + produce1_with_dp(n - 1);
  // 3으로 나누어 떨어지는 경우와 ret의 값을 비교하여 최소값을 집어넣는다.
  if (n % 3 == 0)
    ret = min(ret, 1 + produce1_with_dp(n / 3));
  // 2로 나누어 떨어지는 경우와 ret의 값을 비교하여 최소값을 집어넣는다.
  if (n % 2 == 0)
    ret = min(ret, 1 + produce1_with_dp(n / 2));
  // 값을 캐시에 저장하고 리턴한다.
  cache[n - 1] = ret;
  return ret;
}

// DP를 이용하지 않은 구현
// 위 구현처럼 3가지 경우를 각각 계산했을 때에는 타임 아웃이 발생하므로, 변형된
// 구현을 사용. 2또는 3으로 나누는 것이 1씩 빼는 것보다 숫자를 1로 만드는 데 더
// 효율적인 방법이므로 숫자를 2또는 3으로 나누어 떨어지도록 만들어 계산한다.
// 이 문제에서 같은 수의 계산이 자주 일어나지 않고, 매 테스트 케이스마다
// 프로그램이 새로 실행되므로, DP를 이용한 구현보다 이 구현이 더 빠르다. 캐시를
// 필요로 하지 않으니 메모리 소모도 적다. ~~위 함수는 왜 만들었지....~~
int produce1_without_dp(const int &n) {
  // 기저 사례. 2 이하인 경우 0을 리턴한다.
  if (n < 2)
    return 0;
  // div2: 2로 나누어 떨어질때까지 1을 뺀 후, 2로 나누었을때의 값
  // div3: 3으로 나누어 떨어질때까지 1을 뺀 후, 3으로 나누었을때의 값
  int div2 = produce1_without_dp(n / 2) + n % 2 + 1;
  int div3 = produce1_without_dp(n / 3) + n % 3 + 1;
  // div2와 div3의 최소값을 리턴한다.
  return min(div2, div3);
}

int main() {
  int n;
  cin >> n;
  // 캐시 초기화
  cache.resize(n, -1);
  cout << produce1_without_dp(n) << endl;
}
