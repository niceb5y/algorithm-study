#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    queue<pair<int, string>> q({make_pair(a, "")});
    bool visit[10000] = {};

    while (!q.empty()) {
      auto [x, op] = q.front();
      q.pop();

      if (x == b) {
        cout << op << "\n";
        break;
      }

      int D = (2 * x) % 10000, S = x == 0 ? 9999 : x - 1,
          L = (x * 10) % 10000 + x / 1000, R = x / 10 + (x % 10) * 1000;

      if (!visit[D]) {
        visit[D] = true;
        q.push(make_pair(D, op + "D"));
      }
      if (!visit[S]) {
        visit[S] = true;
        q.push(make_pair(S, op + "S"));
      }
      if (!visit[L]) {
        visit[L] = true;
        q.push(make_pair(L, op + "L"));
      }
      if (!visit[R]) {
        visit[R] = true;
        q.push(make_pair(R, op + "R"));
      }
    }
  }
}
