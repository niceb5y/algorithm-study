#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  queue<pair<int, int>> q({make_pair(n, 0)});
  bool visit[100001] = {};

  while (!q.empty()) {
    auto [cur, day] = q.front();
    q.pop();

    if (visit[cur])
      continue;

    visit[cur] = true;

    if (cur == k) {
      cout << day << "\n";
      return 0;
    }

    if (cur > 0 && !visit[cur - 1])
      q.push(make_pair(cur - 1, day + 1));
    if (cur < 100000 && !visit[cur + 1])
      q.push(make_pair(cur + 1, day + 1));
    if (cur <= 50000 && !visit[cur * 2])
      q.push(make_pair(cur * 2, day + 1));
  }
}
