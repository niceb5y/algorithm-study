#include <algorithm>
#include <iostream>
#include <list>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 큐의 크기
  // m: 뽑아내려고 하는 수의 개수
  // ans: 원소를 주어진 순서대로 뽑아내는데 드는 2, 3번 연산의 최솟값
  int n, m, ans = 0;
  cin >> n >> m;
  // q: 양방향 순환 큐의 원소를 저장할 리스트
  list<int> q(n, -1);
  // 뽑아낼 순서를 리스트의 원소에 입력한다.
  // 뽑아낼 필요가 없는 수는 -1이며, 뽑아내는 순서는 0부터 시작하는 정수이다.
  for (int i = 0; i < m; ++i) {
    int target;
    cin >> target;
    auto cur = q.begin();
    for (int j = 1; j < target; ++j) {
      ++cur;
    }
    *cur = i;
  }
  for (int i = 0; i < m; ++i) {
    // cost: 2번, 3번 연산을 하는 데 드는 비용
    int cost = 0;
    // 해당 차례에 뽑아내야 하는 원소까지 이동한다.
    while (q.front() != i) {
      ++cost;
      q.emplace_back(q.front());
      q.pop_front();
    }
    // 2번 연산을 사용했을 경우와 3번 연산을 사용했을 경우를 비교하여 최소인
    // 쪽을 ans에 더한다.
    ans += min((int)(q.size() - cost), cost);
    // 원소를 뽑아낸다.
    q.pop_front();
  }
  // 결과 출력
  cout << ans << "\n";
}
