#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 가진 숫자 카드의 개수
  // m: 가진 숫자 카드인지 구분해야 하는 숫자의 개수
  // buf: 가진 숫자 카드인지 구분해야 하는 숫자를 입력받을 버퍼
  int n, m, buf;
  cin >> n;
  // cards: 가진 숫자 카드들의 벡터
  vector<int> cards(n);
  for (auto &i : cards) {
    cin >> i;
  }
  // 정렬
  sort(cards.begin(), cards.end());
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> buf;
    // 숫자 카드를 가졌는지 확인해서 출력
    cout << (i != 0 ? " " : "")
         << (binary_search(cards.begin(), cards.end(), buf) ? 1 : 0);
  }
  cout << "\n";
}
