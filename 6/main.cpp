#include <iostream>
#include <set>

using namespace std;

int main() {
  // cin/cout 속도향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  // 수를 저장할 집합
  set<int> s;

  // 집합에 넣기
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    s.insert(num);
  }
  // 빼기
  for (auto &i : s) {
    cout << i << '\n';
  }
  // 출력
  cout << flush;
}
