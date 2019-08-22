#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push(make_pair(0, n));
  bool visit[100001] = {};

  while (!pq.empty()) {
    auto [day, cur] = pq.top();
    pq.pop();

    visit[cur] = true;

    if (cur == k) {
      cout << day << "\n";
      return 0;
    }

    if (cur > 0 && !visit[cur - 1])
      pq.push(make_pair(day + 1, cur - 1));
    if (cur < 100000 && !visit[cur + 1])
      pq.push(make_pair(day + 1, cur + 1));
    if (cur <= 50000 && !visit[cur * 2])
      pq.push(make_pair(day, cur * 2));
  }
}
