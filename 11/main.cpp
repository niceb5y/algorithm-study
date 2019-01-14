#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  // cin / cout 속도 향상
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 입력의 크기
  int n;
  cin >> n;
  // vec: 수를 저장할 벡터
  vector<int> vec(n);
  // n번 줄을 읽어들여 벡터에 저장한다.
  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }
  // 정렬
  sort(vec.begin(), vec.end());
  // 정렬된 벡터를 차례대로 출력한다.
  for (auto &i : vec) {
    cout << i << '\n';
  }
  cout << flush;
}
