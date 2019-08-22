#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, k, ans = -1, pre[100001];
bool visit[100001] = {};

void print(int x) {
  if (x != n)
    print(pre[x]);
  cout << x << (x == k ? "\n" : " ");
}

int main() {
  cin >> n >> k;

  queue<pair<int, int>> q({make_pair(n, 0)});
  fill_n(&pre[0], 100001, -1);

  while (!q.empty()) {
    auto [cur, day] = q.front();
    q.pop();

    if (visit[cur])
      continue;

    visit[cur] = true;

    if (cur == k) {
      ans = day;
      break;
    }

    if (cur > 0 && !visit[cur - 1]) {
      q.push(make_pair(cur - 1, day + 1));
      if (pre[cur - 1] == -1)
        pre[cur - 1] = cur;
    }
    if (cur < 100000 && !visit[cur + 1]) {
      q.push(make_pair(cur + 1, day + 1));
      if (pre[cur + 1] == -1)
        pre[cur + 1] = cur;
    }
    if (cur <= 50000 && !visit[cur * 2]) {
      q.push(make_pair(cur * 2, day + 1));
      if (pre[cur * 2] == -1)
        pre[cur * 2] = cur;
    }
  }

  cout << ans << "\n";
  print(k);
}
