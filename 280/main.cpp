#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, k, ans = -1, cnt = 0;
  cin >> n >> k;

  queue<pair<int, int>> q({make_pair(n, 0)});
  bool visit[100001] = {};

  while (!q.empty()) {
    auto [cur, day] = q.front();
    q.pop();

    visit[cur] = true;

    if (ans != -1 && ans < day)
      break;

    if (cur == k) {
      ans = day;
      ++cnt;
    }

    if (cur > 0) {
      if (!visit[cur - 1])
        q.push(make_pair(cur - 1, day + 1));
    }
    if (cur < 100000) {
      if (!visit[cur + 1])
        q.push(make_pair(cur + 1, day + 1));
    }
    if (cur <= 50000) {
      if (!visit[cur * 2])
        q.push(make_pair(cur * 2, day + 1));
    }
  }

  cout << ans << "\n" << cnt << endl;
}
