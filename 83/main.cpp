#include <iostream>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // ans: 열차의 최대 승객 수
  // cur: 열차의 현재 승객 수
  int ans = 0, cur = 0;
  while (cin.peek() != EOF) {
    // n: 열차에서 내린 사람의 수
    // m: 열차에서 탄 사람의 수
    int n, m;
    cin >> n >> m;
    cur = cur - n + m;
    ans = ans < cur ? cur : ans;
  }
  cout << ans << endl;
}
