#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n: 수열의 길이
  // cur: 스택에 이번에 추가될 숫자
  int n, cur = 0;
  cin >> n;
  // history: 수열을 만들기 위해 필요한 연산의 작업 내역
  vector<char> history;
  // num: 스택 수열이 담길 스택
  stack<int> num;
  history.reserve(2 * n);
  for (int i = 0; i < n; ++i) {
    // next: 다음에 출력해야 하는 숫자
    int next;
    cin >> next;
    // next와 같아질 때까지 스택에 push한다.
    while (cur < next) {
      ++cur;
      num.push(cur);
      history.push_back('+');
    }
    if (num.top() == next) {
      // 스택의 top과 next가 같으면 스택에서 값을 제거한다.
      num.pop();
      history.push_back('-');
    } else {
      // 스택의 top과 next가 다르면 불가능한 수열이므로 연산을 마친다.
      history.clear();
      break;
    }
  }
  if (history.size() > 0) {
    // 계산 가능한 수열인 경우 결과를 출력한다.
    for (auto &c : history) {
      cout << c << '\n';
    }
  } else {
    // 계산 불가능한 수열인 경우 NO를 출력한다.
    cout << "NO\n";
  }
}
