#include <iostream>
#include <list>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 전체 원소의 수
  // m: 지울 원소 사이의 간격
  // target: 이번 차례에 출력하고 지울 원소의 번호
  int n, m, target = 0;
  cin >> n >> m;
  // num: 숫자가 담길 리스트
  list<int> num;
  for (int i = 0; i < n; ++i) {
    num.push_back(i + 1);
  }
  cout << "<";
  // 사람이 남지 않게 될 때까지 반복
  while (num.size() != 0) {
    // 다음에 지울 원소 구하기
    target = (target + m - 1) % num.size();
    // it: 다음에 지울 원소의 이터레이터
    auto it = num.begin();
    // 이터레이터 이동시키기
    advance(it, target);
    // 원소 출력
    cout << *it;
    // 원소 지우기
    num.erase(it);
    if (num.size() != 0) {
      cout << ", ";
    }
  }
  cout << ">" << endl;
}
