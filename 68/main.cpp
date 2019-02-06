#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, long long> node;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // map(k,v): 이진탐색트리를 만들었을 때 노드 k의 깊이 v
  map<int, long long> depth({node(0, -1), node(300001, -1)});
  // c: insert 연산의 카운터 (= 삽입된 노드의 깊이의 합)
  long long c = 0;
  // n: 수열의 크기
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    // x: 삽입할 숫자
    // d: x가 삽입되었을때의 깊이
    int x, d;
    cin >> x;
    // x 미만의 가장 큰 수, x 초과의 가장 작은 수를 구한다.
    auto [lo, hi] = depth.equal_range(x);
    lo--;
    // x의 깊이는 max(lo의 깊이, hi의 깊이) + 1
    d = max(lo->second, hi->second) + 1;
    // x를 삽입
    depth.insert(node(x, d));
    // 카운터 c에 추가
    c += d;
    // 결과 출력
    cout << c << "\n";
  }
}
