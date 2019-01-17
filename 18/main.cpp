#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 벡터에 저장될 수의 개수
  // m: 벡터에 들어있는지 확인할 수의 개수
  int n, m;
  cin >> n;
  vector<int> vec(n);
  // 벡터에 수를 입력받는다.
  for (auto &i : vec) {
    cin >> i;
  }
  // 벡터 정렬
  sort(vec.begin(), vec.end());
  cin >> m;
  // m번 입력받아 수가 있는지 없는지 확인한다.
  for (int i = 0; i < m; ++i) {
    int num;
    cin >> num;
    // 벡터를 검사하여 수가 있으면 1, 없으면 0을 출력한다.
    cout << (binary_search(vec.begin(), vec.end(), num) ? 1 : 0) << "\n";
  }
  cout << flush;
}
